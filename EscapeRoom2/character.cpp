#include "character.h"

Character::Character(int oxygenLevel)
{
    this->oxygenLevel = oxygenLevel;
}

vector <Item> Character::getItems() {
    return this->itemsInCharacter;
}

void Character::addItem(Item item) {
    this->itemsInCharacter.push_back(item);
}
