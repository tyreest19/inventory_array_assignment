//
//  main.cpp
//  inventory_array
//
//  Created by Tyree Stevenson on 3/9/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
//#include "Item_Type.hpp"
#include "Inventory.hpp"
using namespace std;

const int MAXIMUM_QUANTITY = 2147483647;
const int MINIMUM_QUANTITY = -2147483647;
const int MAXIMUM_INVENTORY_SIZE = 100;
const int MINIMUM_INVENTORY_SIZE = 1;
const int MENU_LOWER_BOUND = 1;
const int MENU_UPPER_BOUND = 6;
const int SORT_BY_NAME = 1;
const int SORT_BY_KEY = 2;
const int ASCENDING_ORDER = 1;
const int DESCENDING_ORDER = 0;
const string ITEM_QUANTITY_PROMPT = "Enter the quantity of the item: ";
const string INVALID_INPUT = "Please enter a number!";
const string ITEM_INVALID_QUANTITY = "Item quantity is out of range!";
const string CREATE_INVENTORY_PROMPT = "enter the size of the inventory must be up to 100: ";
const string INVENTORY_INVALID_SIZE = "Enter a number between 1 and 100!\n";
const string MENU_PROMPT = "\n1. Add new item \n2. Check if inventory is empty \n3. Print inventory \n4. Get item quantity \n5. Update item quantity \n6. Delete item \n\nEnter a number for the action you wish to do on your inventory: ";
const string MENU_INVALID_BOUNDS = "Please enter a number between 1 and 6!";
const string PROMPT_BY_KEY_OR_NAME = "Enter 1 to sort by name or enter 2 to sort by key: ";
const string PROMPT_SORT_ASCENDING_OR_DESCENDING = "Enter 1 to sort by ascending order or enter 0 to sort by descending order: ";
const string INVALID_INPUT_ORDER_PROMPTS = "Invalid Input !";

Item Create_Item();
int String_To_Int(const char *str);
void Menu(Inventory &inventory);
int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds);

int main()
{
    cout << "This is an inventory program which minincs an inventory! \n\n";
    
    int size_of_inventory = User_Inputted_Number(CREATE_INVENTORY_PROMPT, INVALID_INPUT, INVENTORY_INVALID_SIZE, MINIMUM_INVENTORY_SIZE, MAXIMUM_INVETORY_SIZE);
    Inventory inventory;
    string continue_using_menu;
    inventory.Create_Investory(size_of_inventory);
    
    do
    {
        Menu(inventory);
        cout << "\nIf you wish to continue enter yes or YES. If you wish to quit enter anything: ";
        getline(cin, continue_using_menu);
    } while (continue_using_menu == "YES" || continue_using_menu == "yes");
    return 0;
}

//============================================================================================
// Creates a new item.
//============================================================================================

Item Create_Item()
{
    string name;
    string key;
    int quantity;
    
    cout << "enter the items name: ";
    getline(cin, name);
    cout << "enter the items key: ";
    getline(cin, key);
    quantity = User_Inputted_Number(ITEM_QUANTITY_PROMPT, INVALID_INPUT, ITEM_INVALID_QUANTITY, MINIMUM_QUANTITY, MAXIMUM_QUANTITY);
    
    Item created_item;
    created_item.Quantity = quantity;
    created_item.Name = name;
    created_item.Key = key;
    
    return created_item;
}

//============================================================================================
// Takes constant char pointer and converts it into a string.
// If one of the characters are not a digit the function returns -1.
//============================================================================================

int String_To_Int(const char *str)
{
    int result = 0;
    int prefix = 0;
    
    if (str[0] == '\0')
    {
        return -1;
    }
    
    else if (str[0] == '-' || str[0] == '+')
    {
        prefix = 1;
    }
    
    for (int i = prefix; str[i] != '\0'; ++i)
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
    
    if (str[0] == '-')
    {
        result *= -1;
    }
    
    return result;
}

//============================================================================================
// Allows the user to perform operations on the menu.
//============================================================================================

void Menu(Inventory &inventory)
{
    int user_inputted_action = User_Inputted_Number(MENU_PROMPT, INVALID_INPUT, MENU_INVALID_BOUNDS, MENU_LOWER_BOUND, MENU_UPPER_BOUND);
    cout << "\n";
    
    switch (user_inputted_action)
    {
        case 1:
            {
            if (inventory.Is_Full())
            {
                cout << "Cannot add a new item the inventory is full!\n\n";
            }
            else
            {
                Item new_item = Create_Item();
                inventory.Add_New_Item(new_item);
            }
                break;
            }
            
        case 2:
            {
            cout << "Is the invetory empty: ";
               if (inventory.Is_Empty())
                    cout << "true\n";
               else
                   cout << "false\n";
            break;
            }
        
        case 3:
            {
                int name_or_key = User_Inputted_Number(PROMPT_BY_KEY_OR_NAME, INVALID_INPUT_ORDER_PROMPTS, INVALID_INPUT_ORDER_PROMPTS, SORT_BY_NAME, SORT_BY_KEY);
                int descending_or_ascending = User_Inputted_Number(PROMPT_SORT_ASCENDING_OR_DESCENDING, INVALID_INPUT_ORDER_PROMPTS, INVALID_INPUT_ORDER_PROMPTS, DESCENDING_ORDER, ASCENDING_ORDER);
            inventory.Print_Inventory(name_or_key, descending_or_ascending);
            break;
            }
        
        case 4:
            {
                string key;
                cout << "enter key: ";
                getline(cin, key);
                int amount_of_item = inventory.Get_Quantity(key);
                
                if (amount_of_item == -1)
                {
                    cout << "The key you entered is not attached to a item \n";
                }
                
                else
                {
                    cout << "The items quanity is " << amount_of_item << "\n";
                }
                break;
            }
            
        case 5:
            {
                string key;
                cout << "enter key: ";
                getline(cin, key);
                int new_amount = User_Inputted_Number(ITEM_QUANTITY_PROMPT, INVALID_INPUT, ITEM_INVALID_QUANTITY, MINIMUM_QUANTITY, MAXIMUM_QUANTITY);
                inventory.Update_Quantity(key, new_amount);
                break;
            }
            
        case 6:
            {
                string key;
                cout << "enter key: ";
                getline(cin, key);
                inventory.Delete_Item(key);
                break;
            }
            
        default:
            break;
    }
}

//============================================================================================
// Takes user inputted number as a string and returns the number if its fits the parameters.
// If the number does not fit the parameters the user is prompted to enter a new number.
//============================================================================================

int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds)
{
    int number = -1;
    string user_entered_number;

    while (number == -1 || (number < lower_bounds || number > upper_bounds))
    {
        cout << prompt;
        getline(cin, user_entered_number);
        number = String_To_Int(user_entered_number.c_str());
        cout << "\n";
        if (number == -1)
        {
            cout << invalid_prompt << "\n";
        }
        
        else if (number < lower_bounds || number > upper_bounds)
        {
            cout << out_of_bounds_prompt << "\n";
        }
    }
    
    return number;
}
