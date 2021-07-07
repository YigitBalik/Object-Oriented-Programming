//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#pragma once
#include <iostream>
#include <string>
#include "Faction.h"
using namespace std;

class Elves : public Faction
{
private:
public:
    //Constructor with default parameters
    Elves(const string & = "Default", int = 0, int = 0, int = 0, int = 0);

    //Performs attack
    void PerformAttack();

    //Recieves attack from given enemy
    void RecieveAttack(const string &, int, int);

    //Purchases weapons for Orcs
    int PurchaseWeapons(int);

    //Purchases armor for Orcs
    int PurchaseArmors(int);

    //Prints informations of Orcs Faction
    void Print() const;
};