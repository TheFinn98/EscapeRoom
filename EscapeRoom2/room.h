#ifndef ROOM_H_
#define ROOM_H_


#include <QMainWindow>
#include <string>
#include <map>
#include <string>
#include <vector>
#include "item.h"
using namespace std;
using std::vector;


class Room {

private:
    string description;
    string itemDescription;
    map<string, Room*> exits;
    string roomSetting;
    vector <Item> itemsInRoom;

public:
    string exitString();

    Room(string description, string roomSetting);
    void setExits(Room *forward, Room *backward, Room *right, Room *left);

    Room* nextRoom(string direction);
    string shortDescription();
    string longDescription();
    string getItem();
    string getRoomSetting();
    string getRoomItem();
    string roomDesc();
    void addItem(Item *item);
    void removeItem(Item *rItem);
    string displayItem();
    int isItemInRoom(string inString);
    int numberOfItems();
    string itemDesc();



};

#endif



