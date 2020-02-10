//
//  Inventory.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef Inventory_h
#define Inventory_h

#include "Item.h"
#include <array>
#include <utility>
#include <iostream>
#include "Error.h"

class Inventory
{

    
    
public:
    
    
    
    Inventory() : numberOfItems(0)
    {
        for(auto& item : items)
            item.first = nullptr;
    }
    
    ~Inventory()
    {
        for(auto& item : items)
            if(item.first != nullptr) delete item.first;
    }
    
    /*
     param:
        item to be added
        quantity of the item to be added
     
     This function adds quantity to an item in the inventory.
     If the item already exist, the quantity will  be added to existing quantity.
     If the item does not exist, a new item is added with the given quantity.
     
     An error inventoryFull will be returned if the item does not exist already
     and the inventory is full.
    */
    Error addItem(Item item, unsigned int quantity);
    
    /*
     param:
     item to be removed
     quantity of the item to be removed
     
     This function removes quantity to an item in the inventory.
     If the item already exist, the quantity specified will  be deduced.
     If the existing item's quantity is less than the quantity requested to remove,
     the quantity of item will become 0 and an error notEnoughQuantity will be returned
     If the item does not exist, an error itemNotFound will be returned
     
     */
    Error removeItem(unsigned int itemID, unsigned int quantity);
    
    /*
        returns True if item is in stock
                False if not
        the item is identified by its ID.
     */
    bool isItemInStock(unsigned int itemID, unsigned int quantity=1) const;
    int getQuantity(unsigned int itemID) const;
    std::string getItemDescription(unsigned int itemID) const;
    double getItemPrice(unsigned int itemID, bool withTax=false) const;

    void print() const;
    
private:
    const static int inventorySize = 50;
    std::array<std::pair<Item*, unsigned int>, inventorySize> items;
    int numberOfItems;
    //returns index of item in inventory. if item not found -1 is returned.
    int getItemIndex(unsigned int itemID) const;
    
    
};
#endif /* Inventory_h */
