//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Faction
{
protected:
    string name;
    Faction *enemy1st;
    Faction *enemy2nd;
    int numberOfUnits;
    int attackPoint;
    int healthPoint;
    int unitRegenerationNumber;
    int totalHealth;
    bool Alive;

public:
    //Constructor with default parameters
    Faction(const string & = "Default", int = 0, int = 0, int = 0, int = 0);

    //Assigns Enemy pointers
    void AssignEnemies(Faction *, Faction *);

    //Prints information about the faction
    virtual void Print() const;

    //Updates the Number of Units and isAlive attirbutes according to the conditions
    void EndTurn();

    //----Pure Virtual Methods----//
    //Performs attack according to the specific behaviours of derived classes
    virtual void PerformAttack() = 0;

    //Recieves attack according to the specific behaviours of derived classes. Params(Attacking Faction, attacking unit,attack point)
    virtual void RecieveAttack(const string &, int, int) = 0;

    //Purchases weapons from the merchant and returns the porfit
    virtual int PurchaseWeapons(int) = 0;

    //Purchases armor from the merchant and returns the porfit
    virtual int PurchaseArmors(int) = 0;

    //----Additional Methods----//
    //Returs Alive
    bool IsAlive() const { return Alive; }

    //Returns faction name
    string getName() const { return name; }
};
