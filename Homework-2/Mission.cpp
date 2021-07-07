//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "Mission.h"

Mission::Mission(const string &n, int c, int fp)
{
    this->cost = c;
    this->faultProbability = fp;
    this->completed = false;
    numMissions++;
    this->missionNumber = numMissions;
    this->numOfPassengers = 0;
    this->sizeOfCrew = 0;
    this->crew = NULL;
    this->passengers = NULL;
    this->next = NULL;
    //Check the validation of the given name
    if (!checkMissionName(n))
    {
        cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
        this->name = "AA-00";
    }
    else
    {
        this->name = n;
    }
}

Mission::Mission(const Mission &cpyMis)
{
    this->name = string(cpyMis.name);
    this->missionNumber = cpyMis.missionNumber;
    this->cost = cpyMis.cost;
    this->faultProbability = cpyMis.faultProbability;
    this->completed = cpyMis.completed;
    this->numOfPassengers = 0;
    this->sizeOfCrew = 0;
    this->next = NULL;
    this->passengers = NULL;
    this->crew = NULL;
    //Add the exactly the same Astronauts and Passengers to the propriate list
    AstronautNode *aPtr = cpyMis.crew;
    while (aPtr)
    {
        *this += aPtr->astronaut; //Reach the pointer to the Astronaut (created in main) and add it into list
        aPtr = aPtr->next;
    }
    PassengerNode *pPtr = cpyMis.passengers;
    while (pPtr)
    {
        *this += pPtr->passenger; //Reach the pointer to the Passenger (created in main) and add it into list
        pPtr = pPtr->next;
    }
}

Mission::~Mission()
{
    //Delete all the nodes
    PassengerNode *pPtr;
    AstronautNode *aPtr;
    while (this->crew)
    {
        aPtr = this->crew;
        this->crew = this->crew->next;
        delete aPtr;
    }
    this->sizeOfCrew = 0;
    this->crew = NULL;
    while (this->passengers)
    {
        pPtr = this->passengers;
        this->passengers = this->passengers->next;
        delete pPtr;
    }
    this->passengers = NULL;
    this->numOfPassengers = 0;
    //Content of the nodes not deleted here because Astronauts and Passengers have been created in the main
}

bool Mission::checkMissionName(const string &n) const
{
    //Format of the Mission Name: XX-YY (X is uppercase letter, Y is digit)
    int hyphen = 2;
    if (n[hyphen] != '-' || n.length() != 5)
    {
        return false;
    }
    else
    {
        //Here given string n satifies length and hyphen condition (SS-SS)
        //Check left of the hyphen
        for (int i = 0; i < hyphen; i++)
        {
            //If even one of the characters in the left substring is not an uppercase letter, return false
            //According to the ASCII table, 'A' = 65 and 'Z' = 90
            //If character not in the range of [65,90], return false
            if (!(n[i] >= 65 && n[i] <= 90))
            {
                return false;
            }
        }
        //Here given string n satisfies length, hyphen and left substring conditions (XX-SS)
        //Check right of the hyphen until the end. Length is known and it is 5.
        for (int i = hyphen + 1; i < 5; i++)
        {
            //If even one of the characters in the right substring is not a number, return false
            //According to the ASCII table, '0' = 48 and '9' = 57
            //If character not in the range of [48,57], return false
            if (!(n[i] >= 48 && n[i] <= 57))
            {
                return false;
            }
        }
    }
    //given name satisfied all the conditions
    return true;
}

void Mission::operator+=(Passenger *ps)
{
    if (ps->getTicket())
    {
        //Create new node which consist of the given Passenger pointer (created in the main)
        PassengerNode *toadd = new PassengerNode(ps);
        //If head of the list is empty
        if (!this->passengers)
        {
            this->passengers = toadd; //Add to head
        }
        else
        {
            PassengerNode *ptr = this->passengers;
            while (ptr->next)
            {
                ptr = ptr->next;
            }
            ptr->next = toadd; //Add to end
        }
        this->numOfPassengers++;
    }
    else
    {
        cerr << "Passenger " << ps->getName() << " " << ps->getSurname() << " does not have a valid ticket!" << endl;
    }
}

void Mission::operator+=(Astronaut *ast)
{
    // Create new node which consist of the given Astronaut pointer (created in main)
    AstronautNode *toadd = new AstronautNode(ast);
    if (!this->crew)
    {
        this->crew = toadd; //Add to head
    }
    else
    {
        AstronautNode *ptr = this->crew;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = toadd; //Add to end
        this->sizeOfCrew++;
    }
}

void Mission::setName(string newName)
{
    if (!checkMissionName(newName))
    {
        cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
    }
    else
    {
        this->name = newName;
    }
}

string Mission::getName() const
{
    return this->name;
}

bool Mission::executeMission()
{
    //Generate random number in the range (0,100] (0 means always successful)
    //rand() % (UpperLimit - LowerLimit + 1) + LowerLimit. UpperLimit = 100 and LowerLimit = 1
    int chance = (rand() % 100) + 1;
    if (chance > faultProbability)
    {
        //MISSION _MissionName_ SUCCESSFUL!
        cout << "MISSION " << name << " SUCCESSFUL!" << endl;
        AstronautNode *ptr = crew; // Pointer to node
        Astronaut *ast;            // Pointer to the Astronaut which will be printed in the while loop below
        while (ptr)
        {
            //Astronaut _AstronautName_ successfully completed _AstronautNumMissions_ missions.
            ast = ptr->astronaut; //Reach the node's Astronaut
            ast->completeFlight();
            cout << "Astronaut " << ast->getName() << " " << ast->getSurname() << " successfully completed " << ast->getNumMissions() << " missions." << endl;
            ptr = ptr->next;
        }
        this->completed = true;
    }
    else
    {
        //MISSION _MissionName_ FAILED!
        //Agency reschedules the mission.
        cout << "MISSION " << name << " FAILED!" << endl;
        cout << "Agency reschedules the mission." << endl;

        //Completed is already set to false
    }

    return this->completed;
}

int Mission::calculateProfit(int ticketPrice) const
{
    int profit = 0;
    if (this->completed)
    {
        profit += (this->numOfPassengers * ticketPrice);
    }
    profit -= cost;

    return profit;
}

int Mission::getMissionNumber() const
{
    return this->missionNumber;
}
int Mission::getCost() const
{
    return this->cost;
}

Mission *Mission::getNext() const
{
    return this->next;
}

void Mission::setNext(Mission *nextMission)
{
    this->next = nextMission;
}