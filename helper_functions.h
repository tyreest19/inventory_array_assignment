//
//  helper_functions.h
//  inventory_array
//
//  Created by Tyree Stevenson on 3/17/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef helper_functions_h
#define helper_functions_h
#include <iostream>
#include <string>

using namespace std;

int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds);
int String_To_Int(const char *str);
void Menu(Inventory &inventory);

//============================================================================================
// Creates a new item.
//============================================================================================

Item Create_Item()
{
    string name;
    string key;
    int quantity;
    
    cout << "Enter the items name: ";
    getline(cin, name);
    cout << "Enter the items key: ";
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
    string enter_key_prompt = "Enter key: ";
    string item_not_found_prompt = "\nItem was not found!\n";
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
            cout << enter_key_prompt;
            getline(cin, key);
            int amount_of_item = inventory.Get_Quantity(key);
            
            if (amount_of_item == -1)
            {
                cout << item_not_found_prompt;
            }
            
            else
            {
                cout << "\nThe items quanity is " << amount_of_item << "\n";
            }
            break;
        }
            
        case 5:
        {
            string key;
            cout << enter_key_prompt;
            getline(cin, key);
            
            if (inventory.Does_Item_Exist(key))
            {
                int new_amount = User_Inputted_Number(ITEM_QUANTITY_PROMPT, INVALID_INPUT, ITEM_INVALID_QUANTITY, MINIMUM_QUANTITY, MAXIMUM_QUANTITY);
                inventory.Update_Quantity(key, new_amount);
                cout << "\nItem was successfully updated!\n";
            }
            
            else
            {
                cout << item_not_found_prompt;
            }
            break;
        }
            
        case 6:
        {
            string key;
            cout << enter_key_prompt;
            getline(cin, key);
            
            if (inventory.Does_Item_Exist(key))
            {
                inventory.Delete_Item(key);
                cout << "Item was successfully deleted!\n";
            }
            
            else
            {
                cout << item_not_found_prompt;
            }
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
            cout << invalid_prompt << "\n\n";
        }
        
        else if (number < lower_bounds || number > upper_bounds)
        {
            cout << out_of_bounds_prompt << "\n";
        }
    }
    
    return number;
}

#endif /* helper_functions_h */
