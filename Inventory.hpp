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
    void create_investory(int desired_upper_bound);
    int get_quantity(string key);
    void update_quantity(string key, int new_quantity);
    void delete_item(string key);
    void print_inventory();
private:
    
    int length;
    int upper_bounds;
    Item_Type inventory[MAXIMUM_INVETORY_SIZE];
};
#endif /* Inventory_hpp */
