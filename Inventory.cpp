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

//============================================================================================
// Inventory constructor and sets the length of the inventory as zero.
//============================================================================================

Inventory:: Inventory()
{
    length = 0;
}

//============================================================================================
// Returns true if the inventory is empty and false if it is not empty.
//============================================================================================

bool Inventory:: Is_Empty()
{
    return length == 0;
}

void Inventory:: Add_New_Item(Item new_item)
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

//============================================================================================
// Sets the maxium length of the inventory.
//============================================================================================

void Inventory:: Create_Investory(int desired_upper_bound)
{
    upper_bounds = desired_upper_bound;
}

int Inventory:: Get_Quantity(string key)
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

//============================================================================================
// Pass in a key and int value positive or negative.
// The function then finds the item by the key and adds the int value to the item quantity.
//============================================================================================

void Inventory:: Update_Quantity(string key, int new_quantity)
{
    for (int i = 0; i < length; i++)
    {
        if (inventory[i].key == key)
        {
            inventory[i].quantity += new_quantity;
        }
    }
}

//============================================================================================
// Deletes item from the inventory.
//============================================================================================

void Inventory:: Delete_Item(string key)
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

//============================================================================================
// prints the items in the inventory in different orders
// order code: 1: by name, 2: by key
// bool: true=ascending order, false=descending order
//============================================================================================

void Inventory:: Print_Inventory(int order_code, bool ascending_order)
{
    if (order_code == 1 && ascending_order)
    {
        Ascending_Sort_Inventory_By_Name();
    }
    
    else if (order_code == 1 && !ascending_order)
    {
        Descending_Sort_Inventory_By_Name();
    }
    
    else if (order_code == 2 && ascending_order)
    {
        Ascending_Sort_Inventory_By_Key();
    }
    
    else if (order_code == 2 && !ascending_order)
    {
        Descending_Sort_Inventory_By_Key();
    }
    
    for (int i = 0; i < length; i++)
    {
        cout << "item #" << i + 1 << "\n";
        cout << "item name: " << inventory[i].name << "\n";
        cout << "item key: " << inventory[i].key << "\n";
        cout << "item quantity: " << inventory[i].quantity << "\n\n";
    }
}

//============================================================================================
// Sorts items in ascending baised off of their name.
//============================================================================================

void Inventory:: Ascending_Sort_Inventory_By_Name()
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

//============================================================================================
// Sorts items in ascending baised off of their key.
//============================================================================================

void Inventory:: Ascending_Sort_Inventory_By_Key()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inventory[i].key < inventory[j].key) {
                Item temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}

//============================================================================================
// Sorts items in descending baised off of their name.
//============================================================================================

void Inventory:: Descending_Sort_Inventory_By_Name()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inventory[i].name > inventory[j].name) {
                Item temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}

//============================================================================================
// Sorts items in descending baised off of their key.
//============================================================================================

void Inventory:: Descending_Sort_Inventory_By_Key()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (inventory[i].key > inventory[j].key) {
                Item temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
}
