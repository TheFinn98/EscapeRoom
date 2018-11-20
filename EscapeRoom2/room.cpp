#include "Room.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

Room::Room(string description, string roomSetting) {
    this->description = description;
    this->roomSetting = roomSetting;
}

void Room::setExits(Room *forward, Room *backward, Room *right, Room *left) {
    if (forward != NULL)
        exits["forward"] = forward;
    if (backward != NULL)
        exits["backward"] = backward;
    if (right != NULL)
        exits["right"] = right;
    if (left != NULL)
        exits["left"] = left;
}


string Room::shortDescription() {
    return description;
}
string Room::getRoomSetting(){
    return roomSetting;
}

string Room::longDescription() {
    return   description + "\n" + displayItem() + exitString();
}

/*string Room:: getItem()
{
    return itemDescription;
}*/
string Room::exitString() {
    string returnString = "\nexits =";
    for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
    return returnString;
}

Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
        return NULL; // if exits.end() was returned, there's no room in that direction.
    return next->second; // If there is a room, remove the "second" (Room*)
                // part of the "pair" (<string, Room*>) and return it.
}
void Room::addItem(Item *inItem) {

    itemsInRoom.push_back(*inItem);
}

string Room::displayItem() {
    string tempString = "Item(s) in room = ";

    if (itemsInRoom.size() < 1) {
        tempString = "No item in room";
        }
    else  {
        tempString = tempString + itemsInRoom.front().getShortDescription();
        for (std::size_t n = 1; n < itemsInRoom.size(); ++n) {
        tempString += ", " + itemsInRoom[n].getShortDescription();
             }
            }

    return tempString;
}
int Room::numberOfItems() {
    return itemsInRoom.size();
}
int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return false;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( itemsInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}


