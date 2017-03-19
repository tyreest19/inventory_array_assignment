//
//  main.cpp
//  inventory_array
//
//  Created by Tyree Stevenson on 3/9/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
#include "Item.hpp"
#include "Inventory.hpp"
#include "constants.h"
#include "helper_functions.h"

using namespace std;

int main()
{
    cout << "This is an inventory program which mimics an inventory! \n\n";
    
    int size_of_inventory = User_Inputted_Number(CREATE_INVENTORY_PROMPT, INVALID_INPUT, INVENTORY_INVALID_SIZE, MINIMUM_INVENTORY_SIZE, MAXIMUM_INVETORY_SIZE);
    Inventory inventory;
    string continue_using_menu;
    inventory.Create_Investory(size_of_inventory);
    
    do
    {
        Menu(inventory);
        cout << "\nIf you wish to continue enter yes or YES. If you wish to quit enter anything: ";
        getline(cin, continue_using_menu);
        cout << "\n";
    } while (continue_using_menu == "YES" || continue_using_menu == "yes");
    return 0;
}
