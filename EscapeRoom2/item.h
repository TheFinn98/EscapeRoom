#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string itemDescription;
    string longDescription;


public:
    Item (string itemDescription);
    string getShortDescription();
    string getLongDescription();
    string getItem();
};

#endif /*ITEM_H_*/

