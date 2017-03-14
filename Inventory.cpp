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
    
    inventory[length - 1] = new_item;
    length++;
}

void Inventory:: create_investory(int desired_upper_bound)
{
    upper_bounds = desired_upper_bound;
}

int Inventory::get_quantity(string key)
{
    for (int i = 0; i < length; i++)
    {
        if (inventory[i].key == key)
        {
            return inventory[i].quantity;
        }
    }
    return -1;
}

void Inventory::update_quantity(string key, int new_quantity)
{
    for (int i = 0; i < length; i++)
    {
        if (inventory[i].key == key)
        {
            inventory[i].quantity += new_quantity;
        }
    }
}

void Inventory:: delete_item(string key)
{
    
}

void Inventory:: print_inventory()
{
    for (int i = 0; i < length; i++)
    {
        cout << "item #" << i + 1 << "\n";
        cout << "item name: " << inventory[i].name << "\n";
        cout << "item key: " << inventory[i].key << "\n";
        cout << "item quantity: " << inventory[i].quantity << "\n";
    }
}
