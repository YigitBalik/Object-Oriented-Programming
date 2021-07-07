//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "Faction.h"

Faction::Faction(const string &n, int nou, int attackPt, int healthPt, int urn) : name(n),
                                                                                  numberOfUnits(nou),
                                                                                  attackPoint(attackPt),
                                                                                  healthPoint(healthPt),
                                                                                  unitRegenerationNumber(urn)
{
    enemy1st = NULL;
    enemy2nd = NULL;
    Alive = true;
    totalHealth = numberOfUnits * healthPoint;
}

void Faction::AssignEnemies(Faction *enemy1, Faction *enemy2)
{
    this->enemy1st = enemy1;
    this->enemy2nd = enemy2;
}

void Faction::Print() const
{
    //Spaces should be modified
    cout << "Faction Name:         " << this->name << endl;
    cout << "Status:               " << (this->Alive ? "Alive" : "Defeated") << endl;
    cout << "Number of Units:      " << this->numberOfUnits << endl;
    cout << "Attack Point:         " << this->attackPoint << endl;
    cout << "Health Point:         " << this->healthPoint << endl;
    cout << "Unit Regen Number:    " << this->unitRegenerationNumber << endl;
    cout << "Total Faction Health: " << this->totalHealth << endl;
}

void Faction::EndTurn()
{
    if (this->numberOfUnits < 0)
        this->numberOfUnits = 0;
    if (this->numberOfUnits == 0)
        Alive = false;
    else
        this->numberOfUnits += this->unitRegenerationNumber;
    this->totalHealth = this->numberOfUnits * this->healthPoint;
}