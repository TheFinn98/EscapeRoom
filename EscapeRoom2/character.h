#ifndef CHARACTER_H
#define CHARACTER_H
#include "item.h"
#include <string>
#include <vector>
using namespace std;
using std::vector;

class Character
{
protected:
    int oxygenLevel;
    vector <Item> itemsInCharacter;

public:
    Character(int oxygenLevel);
    vector <Item> getItems();
    void addItem(Item item);
};

#endif // CHARACTER_H
