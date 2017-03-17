//
//  constants.h
//  inventory_array
//
//  Created by Tyree Stevenson on 3/17/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef constants_h
#define constants_h

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
const string CREATE_INVENTORY_PROMPT = "Enter the size of the inventory must be up to 100: ";
const string INVENTORY_INVALID_SIZE = "Enter a number between 1 and 100!\n";
const string MENU_PROMPT = "1. Add new item \n2. Check if inventory is empty \n3. Print inventory \n4. Get item quantity \n5. Update item quantity \n6. Delete item \n\nEnter a number for the action you wish to do on your inventory: ";
const string MENU_INVALID_BOUNDS = "Please enter a number between 1 and 6!";
const string PROMPT_BY_KEY_OR_NAME = "1. Sort by Name \n2. Sort by Key \n\nEnter a number for how you want to sort your inventory: ";
const string PROMPT_SORT_ASCENDING_OR_DESCENDING = "0. Descending order \n1. Ascending order \n\nEnter a number for the order you want: ";
const string INVALID_INPUT_ORDER_PROMPTS = "Invalid Input!";


#endif /* constants_h */
