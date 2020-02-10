//
//  item.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "Item.h"
#include <iostream>

unsigned int Item::idCounter = 0;
float Item::taxRate = 0.19;

void Item::print() const
{
    std::cout << "Item id: " << id <<
    "\nDescription: " << description <<
    "\nPrice: " << getPrice() <<
    "\nTaxRate: " << taxRate <<
    "\nTaxes: " << getTax() <<
    "\nTotal: " << getPrice(true) << "\n";
}
