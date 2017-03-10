//
//  Inventory.cpp
//  inventory_array
//
//  Created by Tyree Stevenson on 3/9/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Inventory.hpp"

bool Inventory:: is_empty()
{
    return length >= 1;
}

void Inventory:: add_new_item(Item_Type new_item)
{
    if (length == 0)
    {
        length = 1;
    
    }
    
    invetory[length - 1] = new_item;
    length++;
}
