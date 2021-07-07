//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Land
{
private:
    string name;
    string holding;
    Land *next;

public:
    //Deafault constructor
    Land()
    {
        name = "";
        holding = "";
        next = NULL;
    }

    //Constructor with parameters
    Land(string n, string h = "village") : name(n), holding(h)
    {
        next = NULL;
    }

    //Copy constructor
    Land(const Land &cLand)
    {
        this->name = string(cLand.name);
        this->holding = string(cLand.holding);
        // NULL is assigned to next because we want to copy just the Land not the whole Land list
        this->next = NULL;
    }

    //Destructor
    ~Land()
    {
        next = NULL;
    }

    //Returns holding of the land
    string getHolding() const
    {
        return this->holding;
    }

    //Returns pointer to the next node
    Land *nextNode() const
    {
        return this->next;
    }

    //Sets next node
    void setNext(Land *node)
    {
        this->next = node;
    }

    //Returns the name of land
    string getname() const
    {
        return this->name;
    }
};

class Character
{
private:
    string name;
    int manpower;
    int gold;
    int numOfLands;
    Land *lands;

public:
    //Default constuctor
    Character();

    //Constructor with parameters
    Character(string, int = 3, int = 20, int = 0);

    //Copy constructor
    Character(const Character &);

    //Destructor
    ~Character();

    //Collects tax
    void getTaxes();

    //Adds new land to the land list
    void addLand(Land *);

    //Removes land from the land list
    Land *removeLand(string);

    //Returns the name of character
    string getName() const;

    //Searchs the land with given name. Returns pointer to the land if found and returns NULL if not found
    Land *searchLand(string) const;

    //Returns pointer to the first land of the land list
    Land *getLands();

    //returns man power of the character
    int getManPower() const;

    //Sets man power of the character to the given value
    void setManPower(int);

    //returns money of the character
    int getGold() const;

    //Sets money of the character to the given value
    void setGold(int);

    //Returns number of lands of the character
    int getNumOfLands() const;
};

class CharacterList
{
private:
    int size;
    Character **array; //Array which holds references of characters
    friend void listCharacters(CharacterList &);
    friend void listLands(CharacterList &);

public:
    //Default constructor
    CharacterList();

    //Destructor
    ~CharacterList();

    //Adds Character (as pointer) to the array
    void addCharacter(Character *);

    //Deletes Character from the array
    void delCharacter(Character *);

    //Returns pointer to the Player
    Character *getPlayer() const;

    //Returns pointer to the Landowner of the given land(name)
    Character *getLandOwner(string);

    //Return size of the array
    int getSize() const;
};
