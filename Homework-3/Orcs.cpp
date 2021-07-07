//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "Orcs.h"

Orcs::Orcs(const string &n, int nou, int attackPt, int healthPt, int urn) : Faction(n, nou, attackPt, healthPt, urn) {}

void Orcs::PerformAttack()
{
    Faction *elves = NULL;
    Faction *dwarves = NULL;
    //Identify enemy for specific attacks
    if (this->enemy1st->getName() == "Elves")
    {
        elves = this->enemy1st;
        dwarves = this->enemy2nd;
    }
    else
    {
        elves = this->enemy2nd;
        dwarves = this->enemy1st;
    }

    //If both enemy factions are alive
    if (elves->IsAlive() && dwarves->IsAlive())
    {
        //Attack to elves with 70% of total unit
        int toElves = (this->numberOfUnits * 7) / 10;
        //Attack to dwarves with the rest
        //Rest is not euquivalent to %30 in some cases because of the int division e.g. 101 * 7 / 10 = 70 (toElves), 101 * 3 / 10 = 30 (this is not rest. Rest is 31 toDwarves)
        int toDwarves = this->numberOfUnits - toElves;
        elves->RecieveAttack(this->name, toElves, this->attackPoint);
        dwarves->RecieveAttack(this->name, toDwarves, this->attackPoint);
    }
    //Just Elves faction is alive
    else if (elves->IsAlive())
        elves->RecieveAttack(this->name, this->numberOfUnits, this->attackPoint);
    //Just Dwarves faction is alive
    else if (dwarves->IsAlive())
        dwarves->RecieveAttack(this->name, this->numberOfUnits, this->attackPoint);
}

void Orcs::RecieveAttack(const string &attackerFaction, int attackerNumOfUnits, int attackerAttackPoint)
{
    //If attacker is Elves then decrease the attacker point to 75% of original
    if (attackerFaction == "Elves")
        attackerAttackPoint = (attackerAttackPoint * 75) / 100;
    //If attacker is Dwarves then decrease the attacker point to 80% of original
    else if (attackerFaction == "Dwarves")
        attackerAttackPoint = (attackerAttackPoint * 80) / 100;

    //Calculate total damage recieved
    int totalDamage = attackerNumOfUnits * attackerAttackPoint;
    //Decrease the number of units
    this->numberOfUnits -= totalDamage / this->healthPoint;
}

int Orcs::PurchaseWeapons(int weapons)
{
    this->attackPoint = this->attackPoint + (2 * weapons);
    return (20 * weapons);
}

int Orcs::PurchaseArmors(int armors)
{
    this->healthPoint = this->healthPoint + (3 * armors);
    this->totalHealth = this->numberOfUnits * this->healthPoint;
    return armors;
}

void Orcs::Print() const
{
    cout << "\"Stop running, you'll only die tired!\"" << endl;
    Faction::Print();
}