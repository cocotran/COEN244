//
//  Registry.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "Registry.h"

Registry::~Registry()
{
    for(auto& sale: completedSales)
        delete sale;
}

bool Registry::addSale(Sale *sale)
{
    if(sale->getComplete())
    {
        completedSales.push_back(sale);
        return true;
    }
    
    return false;
}

void Registry::printReport() const
{
    std::cout << "Number of sales of made: " << completedSales.size();
    double totalBeforeTax = 0.0;
    double totalAfterTax = 0.0;
    double totalTax = 0.0;
    for(const auto& sale: completedSales)
    {
        Sale::SaleInformation info = sale->getInfo();
        totalBeforeTax += info.amountBeforeTax;
        totalAfterTax += info.amountAfterTax;
        totalTax += info.amountOfTax;
    }
    
    std::cout << "\nTotal value of all sales (before tax): " << totalBeforeTax;
    std::cout << "\nTotal amount of tax applied: " << totalTax;
    std::cout << "\nTotal value of all sales (after tax): " << totalAfterTax << "\n";
    
}
