//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "Elves.h"

Elves::Elves(const string &n, int nou, int attackPt, int healthPt, int urn) : Faction(n, nou, attackPt, healthPt, urn) {}

void Elves::PerformAttack()
{
    //When attacking Dwarves, attack point is increased to 150%.
    Faction *orcs = NULL;
    Faction *dwarves = NULL;
    //Identify enemies
    if (this->enemy1st->getName() == "Orcs")
    {
        orcs = this->enemy1st;
        dwarves = this->enemy2nd;
    }
    else
    {
        orcs = this->enemy2nd;
        dwarves = this->enemy1st;
    }

    //If both enemy factions are alive
    if (orcs->IsAlive() && dwarves->IsAlive())
    {
        //Attack to orcs with 60% of total unit
        int toOrcs = (this->numberOfUnits * 6) / 10;
        //Attack to dwarves with the rest. Since stated as rest do subtraction, do not take the 40%.
        int toDwarves = this->numberOfUnits - toOrcs;
        orcs->RecieveAttack(this->name, toOrcs, this->attackPoint);
        //When attacking Dwarves, attack point is increased to 150%.
        dwarves->RecieveAttack(this->name, toDwarves, (15 * this->attackPoint) / 10);
    }
    //Just Orcs faction is alive
    else if (orcs->IsAlive())
        orcs->RecieveAttack(this->name, this->numberOfUnits, this->attackPoint);
    //Just Dwarves faction is alive
    else if (dwarves->IsAlive())
        //When attacking Dwarves, attack point is increased to 150%.
        dwarves->RecieveAttack(this->name, this->numberOfUnits, (15 * this->attackPoint) / 10);
}

void Elves::RecieveAttack(const string &attackerFaction, int attackerNumOfUnits, int attackerAttackPoint)
{
    //If attacking faction is Orcs, incoming attack point is increased to 125% of its original value.
    if (attackerFaction == "Orcs")
        attackerAttackPoint = (attackerAttackPoint * 125) / 100;
    //If attacking faction is Dwarves, incoming attack point is reduced to 75% of its original value.
    else if (attackerFaction == "Dwarves")
        attackerAttackPoint = (attackerAttackPoint * 75) / 100;

    //Calculate total damage recieved
    int totalDamage = attackerNumOfUnits * attackerAttackPoint;
    //Decrease the number of units
    this->numberOfUnits -= totalDamage / this->healthPoint;
}

int Elves::PurchaseWeapons(int weapons)
{
    this->attackPoint = this->attackPoint + (2 * weapons);
    return (15 * weapons);
}

int Elves::PurchaseArmors(int armors)
{
    this->healthPoint = this->healthPoint + (4 * armors);
    this->totalHealth = this->numberOfUnits * this->healthPoint;
    return (5 * armors);
}

void Elves::Print() const
{
    cout << "\"You cannot reach our elegance.\"" << endl;
    Faction::Print();
}