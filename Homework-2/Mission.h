//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include "Person.h"
using namespace std;

/*
* New classes has been implemented for the linked list node for the simplicity of adding an Astronaut or a Passenger
* to the multiple missions. If the 'next' attiribute has been added to the Astronaut or Passenger classes, the instance of
* these classes could not be in the multiple missions because they have just one 'next'.
* By implementing these node classes same Astronaut or Passenger can join many missions.
*/

class PassengerNode
{
    //In order to access all the members freely, Mission class has been set as friend
    friend class Mission;
    //Pointer to the Passenger which is created in the main function
    Passenger *passenger;
    //Pointer to next node
    PassengerNode *next;

    //Constructor with pointer to Passenger parameter
    PassengerNode(Passenger *ptr = NULL)
    {
        passenger = ptr;
        next = NULL;
    }
};

class AstronautNode
{
    //In order to access all the members freely, Mission class has been set as friend
    friend class Mission;
    //Pointer to the Astronaut which is created in the main fucntion
    Astronaut *astronaut;
    //Pointer to the next node
    AstronautNode *next;

    //Constructor with pointer to the Astronaut parameter
    AstronautNode(Astronaut *ptr = NULL)
    {
        astronaut = ptr;
        next = NULL;
    }
};

class Mission
{
private:
    string name;
    int missionNumber;
    int cost;
    int faultProbability;
    bool completed;
    int numOfPassengers;
    PassengerNode *passengers; // Pointer to the head of the Passenger(Node) List
    int sizeOfCrew;
    AstronautNode *crew; // Pointer to the head of the Astronaut(Node) List
    static int numMissions;
    Mission *next; //Pointer to the Next mission

public:
    //Constructor with default parameters
    Mission(const string & = "AA-00", int = 0, int = 0);

    //Copy constructor
    Mission(const Mission &);

    //Destructor
    ~Mission();

    //Parses the given name and returns true if it satisfies the mission name conditions, else returns false
    bool checkMissionName(const string &) const;

    //Adds Passenger to the Passengers list if they have valid ticket
    void operator+=(Passenger *);

    //Adds Astronaut to the Crew, directly.
    void operator+=(Astronaut *);

    //Returns name of the Mission
    string getName() const;

    //Sets name of the Mission
    void setName(string);

    //Executes the Mission
    bool executeMission();

    //Calculates and returnes profit
    int calculateProfit(int) const;

    //Returns name of the Mission
    int getMissionNumber() const;

    //Returns cost of the Mission
    int getCost() const;

    //Sets next Mission
    void setNext(Mission *);

    //Return pointer to the next Mission
    Mission *getNext() const;
};
