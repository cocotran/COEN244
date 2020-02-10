//
//  Inventory.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "Inventory.h"

int Inventory::getItemIndex(unsigned int itemID) const
{
    if(!numberOfItems) return -1;
    
    for(auto i=0; i < numberOfItems; i++)
    {
        if(itemID == items[i].first->getID())
            return i;
    }
    
    return -1;
        
}
Error Inventory::addItem(Item item, unsigned int quantity)
{
    int index = getItemIndex(item.getID());
    if(index == -1)
    {
        //item not found. add new item to inventory with quantity
        if(numberOfItems == inventorySize)
            return Error::inventoryFull;
        
        items[numberOfItems].first = new Item(item);
        items[numberOfItems].second = quantity;
        numberOfItems++;
    }
    else
        items[index].second += quantity;
       
       
    return Error::noError;
    
}

Error Inventory::removeItem(unsigned int itemID, unsigned int quantity)
{
    int index = getItemIndex(itemID);
    if(index == -1)
        return Error::itemNotFound;
    else
    {
        if(items[index].second >= quantity)
        {
            items[index].second-=quantity;
            return Error::noError;
        }
        else
        {
            items[index].second = 0;
            return Error::notEnoughQuantity;
        }
    }
    
}

bool Inventory::isItemInStock(unsigned int itemID, unsigned int quantity) const
{
    int index = getItemIndex(itemID);
    
    if(index == -1 || items[index].second < quantity)
        return false;
    else return true;
        
}




double Inventory::getItemPrice(unsigned int itemID, bool withTax) const
{
    int index = getItemIndex(itemID);
    if(index == -1)
        return -1;
    else
        return items[index].first->getPrice(withTax);
}

int Inventory::getQuantity(unsigned int itemID) const
{
    int index = getItemIndex(itemID);
    if(index == -1) return -1;
    else
        return items[index].second;
}

void Inventory::print() const
{
    for(int i=0; i< numberOfItems; i++)
    {
        std::cout << "\nitem " << i << "\n";
        items[i].first->print();
        std::cout << "Quantity: " << items[i].second << "\n";
    }
}
