//////////////////////////////////
/*        <Mehmet Yigit Balik>  */
/*        <150180099>           */
//////////////////////////////////
#include "GreatWarrior.h"

//-----Character members----------------
Character::Character()
{
    this->name = "";
    this->manpower = 3;
    this->gold = 20;
    this->numOfLands = 0;
    lands = NULL;
}

Character::Character(string name, int manpower, int money, int numoflands)
{
    this->name = name;
    this->manpower = manpower;
    this->gold = money;
    this->numOfLands = numoflands;
    lands = NULL;
}

Character::Character(const Character &cChar)
{
    this->name = string(cChar.name);
    this->manpower = cChar.manpower;
    this->gold = cChar.gold;
    this->numOfLands = cChar.numOfLands;
    lands = NULL;
    //Travers pointer
    Land *ptr = cChar.lands;
    while (ptr)
    {
        //Create exactly the same land with different memory location
        Land *land = new Land(ptr->getname(), ptr->getHolding());
        this->addLand(land);
        ptr = ptr->nextNode();
    }
}

void Character::getTaxes()
{
    Land *ptr = this->lands;
    while (ptr)
    {
        if (ptr->getHolding() == "village")
            this->gold += 5;
        else if (ptr->getHolding() == "castle")
            this->gold += 7;
        else if (ptr->getHolding() == "city")
            this->gold += 10;
        ptr = ptr->nextNode();
    }
}

void Character::addLand(Land *land)
{
    if (!lands)
    {
        // If head of the list is empty then assign land to the head of the list "lands"
        lands = land;
    }
    else
    {
        Land *ptr = lands;
        while (ptr->nextNode())
        {
            ptr = ptr->nextNode();
        }
        // Add land to the last one's next
        ptr->setNext(land);
    }
    numOfLands++;
}

Character::~Character()
{
    Land *ptr;
    // Clear the land list
    while (lands)
    {
        ptr = lands;
        lands = lands->nextNode();
        delete ptr;
    }
}

string Character::getName() const
{
    return this->name;
}

Land *Character::getLands()
{
    return this->lands;
}

Land *Character::searchLand(string s) const
{
    Land *ptr = lands;
    while (ptr)
    {
        if (ptr->getname() == s)
            return ptr;
        ptr = ptr->nextNode();
    }
    return NULL;
}
Land *Character::removeLand(string s)
{
    Land *pre = NULL;
    Land *ptr = lands;
    //Traverse until finding the land or ptr to be NULL
    while (ptr && ptr->getname() != s)
    {
        pre = ptr;
        ptr = ptr->nextNode();
    }
    //If land with the given name exists
    if (ptr)
    {
        //If it is not the head of the list
        if (pre)
            pre->setNext(ptr->nextNode());
        //Else it is the head of the list
        else
        {
            lands = ptr->nextNode();
        }
        //This ptr will be transferred to the another player or will be deleted make sure next is NULL
        ptr->setNext(NULL);
        numOfLands--;
    }

    return ptr; //will be deleted or transferred in where the fucntion called
}

int Character::getManPower() const
{
    return this->manpower;
}

void Character::setManPower(int nManPower)
{
    this->manpower = nManPower;
}

int Character::getGold() const
{
    return this->gold;
}

void Character::setGold(int gold)
{
    this->gold = gold;
}

int Character::getNumOfLands() const
{
    return this->numOfLands;
}
//---------------------------------------

//-----CharacterList members----------------
CharacterList::CharacterList()
{
    this->size = 0;
    this->array = NULL;
}

CharacterList::~CharacterList()
{
    if (array)
    {
        for (int i = 0; i < size; i++)
        {
            // Delete the individual character, this line calls the destructor of object and cleares Linked List in there
            delete array[i];
        }
        // Free the memory allocated
        delete[] array;
        size = 0;
    }
}

void CharacterList::addCharacter(Character *ch)
{
    // Allocate new memory for the resized array
    Character **resized = new Character *[size + 1];
    for (int i = 0; i < size; i++)
    {
        // Transfer the content
        resized[i] = array[i]; // Transferring the addresses, NOT using the object assignment operator
    }
    if (array)
        delete[] array; // If memory allocated for the present array, then free it

    // Set resized array as the attribute
    array = resized;
    array[size++] = ch; // Add the new character's address to the array
}

void CharacterList::delCharacter(Character *ch)
{
    // Allocate new memory for the resized array
    Character **resized = new Character *[size - 1];
    int index = 0; // Index of the resized array
    for (int i = 0; i < size; i++)
    {
        if (ch != array[i])
        {
            // Transfer the content
            resized[index++] = array[i]; // Transferring the addresses, NOT using the object assignment operator
        }
        else
        {
            delete array[i]; // Delete the character
        }
    }
    delete[] array;  // Free the allocated memory for the present array
    array = resized; // Set resized array as attribute
    size--;
}

Character *CharacterList::getLandOwner(string land)
{
    int i;
    //For every character in the array serch the given land
    for (i = 0; i < size; i++)
    {
        if (array[i]->searchLand(land) != NULL)
            return array[i];
    }
    return NULL;
}

int CharacterList::getSize() const
{
    return this->size;
}

Character *CharacterList::getPlayer() const
{
    return array[size - 1];
}