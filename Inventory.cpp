//
//  Inventory.cpp
//  inventory_array
//
//  Created by Tyree Stevenson on 3/9/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include "Inventory.hpp"
#include <iostream>

using namespace std;
Inventory:: Inventory()
{
    length = 0;
}
bool Inventory:: is_empty()
{
    return length == 0;
}

void Inventory:: add_new_item(Item new_item)
{
    if (length == upper_bounds)
    {
        cout << "\nCannot append new item to inventory array is full \n";
    }
    
    else
    {
        inventory[length] = new_item;
        length++;
    }
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
    for (int i = 0; i < length; i++)
    {
        if (inventory[i].key == key)
        {
            Item temp = inventory[i + 1];
            inventory[i + 1] = inventory[i];
            inventory[i] = temp;
        }
    }
    length -= 1;
}

void Inventory:: print_inventory()
{
    sort_inventory();
    for (int i = 0; i < length; i++)
    {
        cout << "item #" << i + 1 << "\n";
        cout << "item name: " << inventory[i].name << "\n";
        cout << "item key: " << inventory[i].key << "\n";
        cout << "item quantity: " << inventory[i].quantity << "\n\n";
    }
}

void Inventory:: sort_inventory()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inventory[i].name < inventory[j].name) {
                Item temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}
