//
//  main.cpp
//  inventory_array
//
//  Created by Tyree Stevenson on 3/9/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
#include "Item_Type.hpp"
#include "Inventory.hpp"
using namespace std;

const int MAXIMUM_QUANTITY = 2147483647;
const int MINIMUM_QUANTITY = -2147483647;
const int MAXIMUM_INVENTORY_SIZE = 100;
const int MINIMUM_INVENTORY_SIZE = 1;
const int MENU_LOWER_BOUND = 1;
const int MENU_UPPER_BOUND = 6;
const string ITEM_QUANTITY_PROMPT = "Enter the quantity of the item: ";
const string INVALID_INPUT = "Please enter a number!";
const string ITEM_INVALID_QUANTITY = "Item quantity is out of range!";
const string CREATE_INVENTORY_PROMPT = "enter the size of the inventory must be up to 100: ";
const string INVENTORY_INVALID_SIZE = "Enter a number between 0 and 100!";
const string MENU_PROMPT = "1. Add new item \n2. Check if inventory is empty \n3. Print inventory \n4. Get item quantity \n5. Update item quantity \n6. Delete item \n";
const string MENU_INVALID_BOUNDS = "Please enter a number between 1 and 6!";
Item_Type create_item();
int String_To_Int(const char *str);
void menu(Inventory &inventory);
int user_inputted_number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds);

int main()
{
    int size_of_inventory = user_inputted_number(CREATE_INVENTORY_PROMPT, INVALID_INPUT, INVENTORY_INVALID_SIZE, MINIMUM_QUANTITY, MAXIMUM_QUANTITY);
    Inventory inventory;
    string continue_using_menu;
    inventory.create_investory(size_of_inventory);
    
    do
    {
        menu(inventory);
        cout << "If you wish to continue enter yes or YES. If you wish to quit enter anything \n";
        getline(cin, continue_using_menu);
    } while (continue_using_menu == "YES" || continue_using_menu == "yes");
    return 0;
}

Item_Type create_item()
{
    string name;
    string key;
    int quantity;
    
    cout << "enter the items name: ";
    getline(cin, name);
    cout << "enter the items key: ";
    getline(cin, key);
    quantity = user_inputted_number(ITEM_QUANTITY_PROMPT, INVALID_INPUT, ITEM_INVALID_QUANTITY, MINIMUM_QUANTITY, MAXIMUM_QUANTITY);
    
    Item_Type created_item;
    created_item.name = name;
    created_item.key = key;
    created_item.quantity = quantity;
    
    return created_item;
}

//============================================================================================
// Takes constant char pointer and converts it into a string.
// If one of the characters are not a digit the function returns -1.
//============================================================================================

int String_To_Int(const char *str)
{
    int result = 0;
    
    if (str[0] == '\0')
    {
        return -1;
    }
    
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            result = result*10 + str[i] - '0';
        }
        
        else
        {
            return -1;
        }
    }
    
    return result;
}

void menu(Inventory &inventory)
{
    int user_inputted_action = user_inputted_number(MENU_PROMPT, INVALID_INPUT, MENU_INVALID_BOUNDS, MENU_LOWER_BOUND, MENU_UPPER_BOUND);
    
    switch (user_inputted_action)
    {
        case 1:
            {
            Item_Type new_item = create_item();
            inventory.add_new_item(new_item);
            break;
            }
            
        case 2:
            cout << "Is the invetory empty: " << inventory.is_empty() << " " << endl;
            break;
        
        case 3:
            inventory.print_inventory();
            break;
        
        case 4:
            {
                string key;
                cout << "enter key: ";
                getline(cin, key);
                int amount_of_item = inventory.get_quantity(key);
                
                if (amount_of_item == -1)
                {
                    cout << "The key you entered is not attached to a item \n";
                }
                
                else
                {
                    cout << "The items quanity is " << amount_of_item << "\n";
                }
            }
            
        case 5:
            {
                string key;
                cout << "enter key: ";
                getline(cin, key);
                int new_amount = user_inputted_number(ITEM_QUANTITY_PROMPT, INVALID_INPUT, ITEM_INVALID_QUANTITY, MINIMUM_QUANTITY, MAXIMUM_QUANTITY);
                inventory.update_quantity(key, new_amount);
            }
            
        default:
            break;
    }
}

int user_inputted_number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds)
{
    int number = -1;
    string user_entered_number;

    while (number == -1 && number >= lower_bounds && number <= upper_bounds)
    {
        cout << prompt;
        getline(cin, user_entered_number);
        number = String_To_Int(user_entered_number.c_str());
        
        if (number == -1)
        {
            cout << invalid_prompt;
        }
        
        else if (number >= lower_bounds && number <= upper_bounds)
        {
            cout << out_of_bounds_prompt;
        }
    }
    
    return number;
}
