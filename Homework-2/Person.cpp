//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "Person.h"

//Person Class Members

Person::Person(const string &n, const string &sn) : name(n), surname(sn) {}

string Person::getName() const
{
    return this->name;
}

string Person::getSurname() const
{
    return this->surname;
}

//Passenger Class Members

Passenger::Passenger(const string &n, const string &sn, int c, bool t) : Person(n, sn)
{
    if (c < 0)
    {
        cerr << "Passenger cash can't be negative. It is set to 0." << endl;
        this->cash = 0;
    }
    else
        this->cash = c;
    this->ticket = t;
}

bool Passenger::buyTicket(int price)
{
    if (this->cash >= price)
    {
        this->ticket = true;
        this->cash -= price;
    }
    return this->ticket;
}

bool Passenger::getTicket() const
{
    return this->ticket;
}

int Passenger::getCash() const
{
    return this->cash;
}

//Astronaut Class Memebers

Astronaut::Astronaut(const string &n, const string &sn, int nm) : Person(n, sn)
{
    if (nm < 0)
    {
        cerr << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
        this->numMissions = 0;
    }
    else
        this->numMissions = nm;
}

void Astronaut::completeFlight()
{
    this->numMissions++;
}

int Astronaut::getNumMissions() const
{
    return this->numMissions;
}