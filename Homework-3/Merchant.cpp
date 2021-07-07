//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "Merchant.h"

Merchant::Merchant(int SWP, int SAP) : startingWP(SWP), startingAP(SAP)
{
    WP = startingWP;
    AP = startingAP;
    revenue = 0;
    orcs = NULL;
    elves = NULL;
    dwarves = NULL;
}

void Merchant::AssignFactions(Faction *faction1, Faction *faction2, Faction *faction3)
{
    //Identify the factions
    if (faction1->getName() == "Orcs")
    {
        this->orcs = faction1;
        if (faction2->getName() == "Elves")
        {
            this->elves = faction2;
            this->dwarves = faction3;
        }
        else
        {
            this->elves = faction3;
            this->dwarves = faction2;
        }
    }
    else if (faction1->getName() == "Elves")
    {
        this->elves = faction1;
        if (faction2->getName() == "Orcs")
        {
            this->orcs = faction2;
            this->dwarves = faction3;
        }
        else
        {
            this->orcs = faction3;
            this->dwarves = faction2;
        }
    }
    else
    {
        this->dwarves = faction1;
        if (faction2->getName() == "Orcs")
        {
            this->orcs = faction2;
            this->elves = faction3;
        }
        else
        {
            this->orcs = faction3;
            this->elves = faction2;
        }
    }
}

bool Merchant::SellWeapons(const string &factionName, int weaponPoints)
{
    bool sold = false; // Shows that weapons are sold or not
    bool dead = false; // Shows that the faction is dead or not
    if (factionName == "Orcs")
    {
        // If orcs are alive
        if (orcs->IsAlive())
        {
            // Check WP is enough or not
            if (this->WP >= weaponPoints)
            {
                //If enough, weapons sold
                this->revenue += orcs->PurchaseWeapons(weaponPoints);
                sold = true;
            }
            //If not enough sold flag is still false
        }
        // If they are defeated then set dead flag as true (sold flag is still false)
        else
            dead = true;
    }
    else if (factionName == "Elves")
    {
        // If elves are alive
        if (elves->IsAlive())
        {
            // Check WP is enough or not
            if (this->WP >= weaponPoints)
            {
                //If enough, weapons sold
                this->revenue += elves->PurchaseWeapons(weaponPoints);
                sold = true;
            }
            //If not enough sold flag is still false
        }
        // If they are defeated then set dead flag as true (sold flag is still false)
        else
            dead = true;
    }
    else
    {
        // If dwarves are alive
        if (dwarves->IsAlive())
        {
            // Check WP is enough or not
            if (this->WP >= weaponPoints)
            {
                //If enough, weapons sold
                this->revenue += dwarves->PurchaseWeapons(weaponPoints);
                sold = true;
            }
            //If not enough sold flag is still false
        }
        // If they are defeated then set dead flag as true (sold flag is still false)
        else
            dead = true;
    }
    //Handle flags
    //If sold
    if (sold)
    {
        //Decrease WP and return true
        WP -= weaponPoints;
        cout << "Weapons sold!" << endl;
        return true;
    }
    //If not sold because the faction is dead
    else if (dead)
    {
        cout << "The faction you want to sell weapons is dead!" << endl;
        return false;
    }
    //If faction is alive but not sold (means trying to sell more than available)
    else
    {
        cout << "You try to sell more weapons than you have in possession." << endl;
        return false;
    }
}

bool Merchant::SellArmors(const string &factionName, int armorPoints)
{
    bool sold; // Shows that armors are sold or not
    bool dead; // Shows that the faction is dead or not
    if (factionName == "Orcs")
    {
        // If orcs are alive
        if (orcs->IsAlive())
        {
            // Check AP is enough or not
            if (this->AP >= armorPoints)
            {
                //If enough, armors sold
                this->revenue += orcs->PurchaseArmors(armorPoints);
                sold = true;
            }
            //If not enough sold flag is still false
        }
        // If they are defeated then set dead flag as true (sold flag is still false)
        else
            dead = true;
    }
    else if (factionName == "Elves")
    {
        // If elves are alive
        if (elves->IsAlive())
        {
            // Check AP is enough or not
            if (this->AP >= armorPoints)
            {
                //If enough, armors sold
                this->revenue += elves->PurchaseArmors(armorPoints);
                sold = true;
            }
            //If not enough sold flag is still false
        }
        // If they are defeated then set dead flag as true (sold flag is still false)
        else
            dead = true;
    }
    else
    {
        // If dwarves are alive
        if (dwarves->IsAlive())
        {
            // Check AP is enough or not
            if (this->AP >= armorPoints)
            {
                //If enough, armors sold
                this->revenue += dwarves->PurchaseArmors(armorPoints);
                sold = true;
            }
            //If not enough sold flag is still false
        }
        // If they are defeated then set dead flag as true (sold flag is still false)
        else
            dead = true;
    }
    //Handle flags
    //If sold
    if (sold)
    {
        //Decrease AP and return true
        AP -= armorPoints;
        cout << "Armors sold!" << endl;
        return true;
    }
    //If not sold because the faction is dead
    else if (dead)
    {
        cout << "The faction you want to sell armors is dead!" << endl;
        return false;
    }
    //If faction is alive but not sold (means trying to sell more than available)
    else
    {
        cout << "You try to sell more armors than you have in possession." << endl;
        return false;
    }
}

void Merchant::EndTurn()
{
    WP = startingWP;
    AP = startingAP;
}

int Merchant::GetRevenue() const { return revenue; }

int Merchant::GetWeaponPoints() const { return WP; }

int Merchant::GetArmorPoints() const { return AP; }
