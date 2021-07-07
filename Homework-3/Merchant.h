//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#pragma once

#include <iostream>
#include <string>
#include "Faction.h"

using namespace std;

class Merchant
{
private:
    //Since the Factions cannot be different than 3 factions implemented, specify pointer names as the faction names for the sake of simplicity
    Faction *orcs;
    Faction *elves;
    Faction *dwarves;
    const int startingWP; //Starting Weapon Point
    const int startingAP; //Starting Armor Point
    int revenue;
    int WP; //Weapon Point
    int AP; //Armor Point

public:
    //Constructor with default parameters
    Merchant(int = 0, int = 0);

    //Assigns Factions
    void AssignFactions(Faction *, Faction *, Faction *);

    //Sells weapon to the given faction
    bool SellWeapons(const string &, int);

    //Sells armor to the given faction
    bool SellArmors(const string &, int);

    //Ends turn
    void EndTurn();

    //Returns Revenue
    int GetRevenue() const;

    //Returns Weapon Point
    int GetWeaponPoints() const;

    //Returns Armor Points
    int GetArmorPoints() const;
};