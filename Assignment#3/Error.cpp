//
//  Error.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "Error.h"
#include <iostream>
void printError(Error errorType)
{
    switch (errorType)
    {
        case Error::noError:
            std::cout <<  "No Error.\n";
            break;
        case Error::itemNotFound:
            std::cout << "Item was not found in inventory.\n";
            break;
        case Error::notEnoughQuantity:
            std::cout << "Requesting quantity more than availble.\n";
            break;
        case Error::itemIsOutOfStock:
            std::cout << "Item is out of stock.\n";
            break;
        case Error::inventoryFull:
            std::cout << "Inventory is full.";
            break;
        case Error::saleCompleted:
            std::cout << "Sale is completed.";
            break;
            
            }
}
