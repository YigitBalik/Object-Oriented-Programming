//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    string surname;

public:
    //Constructor with default parameters
    Person(const string & = "name", const string & = "surname");

    //Returns name of Person
    string getName() const;

    //Returns surname of Person
    string getSurname() const;
};

class Passenger : public Person
{
private:
    int cash;    //Money that Passenger has
    bool ticket; //If true, it indicates that Passenger has a ticket

public:
    //Constructor with default parameters
    Passenger(const string & = "name", const string & = "surname", int = 0, bool = false);

    //Buys ticket if Passenger has enough cash and returns true if the ticket has been bought, else returns false
    bool buyTicket(int);

    //Returns true if passenger has a valid ticket, else returns false
    bool getTicket() const;

    //Returns cash of the Passenger
    int getCash() const;
};

class Astronaut : public Person
{
private:
    int numMissions; //Number of the missions that Astronaut has completed

public:
    //Constructor with default parameters
    Astronaut(const string & = "name", const string & = "surname", int = 0);

    //Increases num of missions of the Astronaut by 1
    void completeFlight();

    //Returns the number of completed missions by the Astronaut
    int getNumMissions() const;
};
