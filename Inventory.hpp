//
//  Inventory.hpp
//  inventory_array
//
//  Created by Tyree Stevenson on 3/9/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <string>
#include "Item_Type.hpp"

using namespace std;
const int MAXIMUM_INVETORY_SIZE = 100;
class Inventory
{
public:
    
    bool is_empty();
    void add_new_item(Item_Type new_item);
private:
    
    int length;
    Item_Type invetory[MAXIMUM_INVETORY_SIZE];
};
#endif /* Inventory_hpp */
