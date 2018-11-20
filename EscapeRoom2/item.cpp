#include "item.h"
#include "room.h"

Item::Item (string itemDescription)
{
    this->itemDescription = itemDescription;
}

string Item::getShortDescription()
{
    return itemDescription;
}

string Item::getLongDescription()
{
    return " item(s), " + itemDescription + ".\n";
}
string Room:: getItem()
{
    return itemDescription;
}











