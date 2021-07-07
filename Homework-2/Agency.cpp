//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "Agency.h"

Agency::Agency(const string &n, int c, int tp) : name(n), cash(c)
{
    if (tp >= 0)
    {
        this->ticketPrice = tp;
    }
    else
    {
        cerr << "Ticket price can't be negative. It is set to 0." << endl;
        this->ticketPrice = 0;
    }
    this->nextMissions = NULL;
    this->completedMissions = NULL;
}

Agency::~Agency()
{
    //Delete the missions
    Mission *ptr;
    while (this->nextMissions)
    {
        ptr = this->nextMissions;
        this->nextMissions = this->nextMissions->getNext();
        delete ptr;
    }
    while (this->completedMissions)
    {
        ptr = this->completedMissions;
        this->completedMissions = this->completedMissions->getNext();
        delete ptr;
    }
}

void Agency::setTicketPrice(int tp)
{
    if (tp >= 0)
    {
        this->ticketPrice = tp;
    }
    else
    {
        cerr << "Ticket price can't be negative. It is set to 0." << endl;
        this->ticketPrice = 0;
    }
}

int Agency::getTicketPrice() const
{
    return this->ticketPrice;
}

void Agency::addMission(const Mission &nMission)
{
    Mission *toAdd = new Mission(nMission); //Convert given mission to Mission Pointer
    if (!this->nextMissions)
    {
        this->nextMissions = toAdd; //Add to head
    }
    else
    {
        Mission *ptr = this->nextMissions;
        while (ptr->getNext())
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(toAdd); //Add to end
    }
}

void Agency::addCompletedMission(Mission *toAdd)
{
    if (!this->completedMissions)
    {
        this->completedMissions = toAdd; //Add to head
    }
    else
    {
        Mission *ptr = this->completedMissions;
        while (ptr->getNext())
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(toAdd); //Add to end
    }
}

void Agency::moveMissionEnd(Mission *move)
{
    if (!this->nextMissions)
    {
        this->nextMissions = move; //Add to head
    }
    else
    {
        Mission *ptr = this->nextMissions;
        while (ptr->getNext())
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(move); //Move to end
    }
}

void Agency::executeNextMission()
{
    Mission *mission = this->nextMissions; //Reach the next mission
    if (mission)
    {
        this->nextMissions = this->nextMissions->getNext(); //Set the linked list head as next mission
        // Set next of the mission as NULL because this mission either will be executed and added to Completed Missions
        // or will be moved to end of the Next Missions List
        mission->setNext(NULL);
        if (mission->executeMission())
        {
            //Mission executed successfully, add it to the Completed Missions List
            this->addCompletedMission(mission);
        }
        else
        {
            //Mission could not executed, move it end of the Next Missions List
            this->moveMissionEnd(mission);
        }
        this->cash += mission->calculateProfit(this->ticketPrice);
    }
    else
    {
        cerr << "No available mission to execute!" << endl;
    }
}

ostream &operator<<(ostream &os, const Agency &A)
{
    //Agency name: _name_, Total cash: _cash_, Ticket Price: _ticketprice_
    os << "Agency name: " << A.name << ", Total cash: " << A.cash << ", Ticket Price: " << A.ticketPrice << endl;

    //Next Missions:
    os << "Next Missions:" << endl;
    Mission *ptr = A.nextMissions;
    if (ptr)
    {
        while (ptr)
        {
            // Mission number: _missionNum_ Mission name: _name_ Cost: _cost_
            os << "Mission number: " << ptr->getMissionNumber() << " Mission name: " << ptr->getName() << " Cost: " << ptr->getCost() << endl;
            ptr = ptr->getNext();
        }
    }
    else
    {
        os << "No missions available." << endl;
    }
    //Completed Missions:
    os << "Completed Missions:" << endl;
    ptr = A.completedMissions;
    if (ptr)
    {
        while (ptr)
        {
            os << "Mission number: " << ptr->getMissionNumber() << " Mission name: " << ptr->getName() << " Cost: " << ptr->getCost() << endl;
            ptr = ptr->getNext();
        }
    }
    else
    {
        os << "No missions completed before." << endl;
    }
    return os;
}