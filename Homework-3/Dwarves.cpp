//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "Dwarves.h"

Dwarves::Dwarves(const string &n, int nou, int attackPt, int healthPt, int urn) : Faction(n, nou, attackPt, healthPt, urn) {}

void Dwarves::PerformAttack()
{
    Faction *elves = NULL;
    Faction *orcs = NULL;
    //Identify enemies
    if (this->enemy1st->getName() == "Elves")
    {
        elves = this->enemy1st;
        orcs = this->enemy2nd;
    }
    else
    {
        elves = this->enemy2nd;
        orcs = this->enemy1st;
    }

    //If both enemy factions are alive
    if (elves->IsAlive() && orcs->IsAlive())
    {
        //If both enemy factions are alive, attacks each enemy faction with half of its units with attack point.
        int toElves = this->numberOfUnits / 2;
        int toOrcs = this->numberOfUnits - toElves;
        elves->RecieveAttack(this->name, toElves, this->attackPoint);
        orcs->RecieveAttack(this->name, toOrcs, this->attackPoint);
    }
    //Just elves faction is alive
    else if (elves->IsAlive())
        elves->RecieveAttack(this->name, this->numberOfUnits, this->attackPoint);
    else if (orcs->IsAlive())
        orcs->RecieveAttack(this->name, this->numberOfUnits, this->attackPoint);
}

void Dwarves::RecieveAttack(const string &attackerFaction, int attackerNumOfUnits, int attackerAttackPoint)
{
    //Calculate total damage
    int totalDamage = attackerNumOfUnits * attackerAttackPoint;
    //Decrease the number of units
    this->numberOfUnits -= totalDamage / this->healthPoint;
}

int Dwarves::PurchaseWeapons(int weapons)
{
    this->attackPoint = this->attackPoint + weapons;
    return (10 * weapons);
}

int Dwarves::PurchaseArmors(int armors)
{
    this->healthPoint = this->healthPoint + (2 * armors);
    this->totalHealth = this->numberOfUnits * this->healthPoint;
    return (3 * armors);
}

void Dwarves::Print() const
{
    cout << "\"Taste the power of our axes!\"" << endl;
    Faction::Print();
}