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
#include "Item.hpp"

using namespace std;
const int MAXIMUM_INVETORY_SIZE = 100;


class Inventory
{
public:
    
    Inventory();
    bool Is_Empty();
    void Add_New_Item(Item new_item);
    void Create_Investory(int desired_upper_bound);
    int Get_Quantity(string key);
    void Update_Quantity(string key, int new_quantity);
    void Delete_Item(string key);
    void Print_Inventory(int order_code, bool ascending_order);
    bool Is_Full();
private:
    
    int length;
    int upper_bounds;
    void Ascending_Sort_Inventory_By_Name();
    void Descending_Sort_Inventory_By_Name();
    void Ascending_Sort_Inventory_By_Key();
    void Descending_Sort_Inventory_By_Key();
    Item inventory[MAXIMUM_INVETORY_SIZE];
};
#endif /* Inventory_hpp */
