//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include "Person.h"
#include "Mission.h"
using namespace std;

//No need for new node class for the missions. Missions must belong to 1 Agency

class Agency
{
private:
    string name;
    int cash;
    int ticketPrice;
    Mission *completedMissions; //Pointer to the head of the Compleated Missions List
    Mission *nextMissions;      // Pointer to the head of the Uncompleated Missions List

public:
    //Constructor with default parameters
    Agency(const string & = "Name", int = 0, int = 0);

    //Destructor
    ~Agency();

    //Sets ticket price
    void setTicketPrice(int);

    //Returns ticket price
    int getTicketPrice() const;

    //Adds mission to the nextMissions List
    void addMission(const Mission &);

    //Adds mission to the completedMissions List
    void addCompletedMission(Mission *);

    //Moves a Mission, which could not executed, to the end of the nextMissions List
    void moveMissionEnd(Mission *);

    //Executes next Mission
    void executeNextMission();

    //Puts Agency information to out stream
    friend ostream &operator<<(ostream &, const Agency &);
};