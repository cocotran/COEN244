//
//  Sale.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "Sale.h"
#include <math.h>
#include "ApprovalAuthority.h"

unsigned int Sale::idCounter = 0;


Sale::Sale(unsigned int paymentType, Date d, Time t): id(idCounter), payment(nullptr), date(d), time(t), isComplete(false)
{
    idCounter++;
    changePaymentType(paymentType);
}

void Sale::changePaymentType(unsigned int type)
{
    if(isComplete)  return;
    if(payment != nullptr)
        delete payment;
    if(type == 1)
        payment = new CreditCardPayment();
    else if(type == 2)
        payment = new DebitCardPayment();
    else
        payment = new CashPayment();
    
}

void Sale::addItem(unsigned int itemID, unsigned int quantity)
{
    if(isComplete) return;
    
    for(auto& item : items)
    {
        if(item.first == itemID)
        {
            item.second+=quantity;
            return;
        }
    }
    
    items.push_back(std::make_pair(itemID, quantity));
    
}

Error Sale::removeItem(unsigned int itemID, unsigned int quantity)
{
    if(isComplete)  return Error::saleCompleted;
    
    for(auto& item : items)
    {
        if(item.first == itemID)
        {
            if(item.second < quantity)
            {
                item.second = 0;
                return Error::notEnoughQuantity;
            }
            item.second-=quantity;
            return Error::noError;
        }
    }
    return Error::itemNotFound;
}

double Sale::getAmountToBePaid(const Inventory& inventory, bool withTax, bool withPaymentType)
{
    double total = 0.0;
   
    for(const auto& item: items)
    {
        double price = inventory.getItemPrice(item.first, withTax);
        if(price != -1.0)   //if item not found
            total += price*item.second;
    }
    
    if(withPaymentType)
    {
        payment->setAmount(total);
        total = payment->calculateAmountToBePaid();
    }
    
    return total;
}


bool Sale::completeSale(double amount, Inventory &inventory)
{
    if(isComplete) return false;
    
    double total = 0.0;
    //check if item is out of stock and remove it
    //if in stock calculate the total with tax
    for(auto it = items.begin(); it != items.end();)//we will iterate inside the body because we are erasing)
    {
        int stock = inventory.getQuantity(it->first);
        //if stock not available erase from vector
        if(stock == 0)
            it = items.erase(it); //erase returns the next iterator
        else if(stock < it->second)
        {
            it->second = stock;
            total += inventory.getItemPrice(it->first, true)*it->second;
            ++it;
        }
        else
        {
            //item is in stock.
            //add the total
            total += inventory.getItemPrice(it->first, true)*it->second;
            ++it;
            
        }
    }
    //if vector is empty return false
    if(items.size() == 0)   return false;
    
    //calculate the total with payment
    payment->setAmount(total);
    double temp = total;
    total = payment->calculateAmountToBePaid();
    
    if(total == 0 && temp!=0)   return false;
    //check if amount is equal to total. if not return false
    if(fabs(total-amount) > 0.001 ) return false;
    
    //if debit or credit get authority
    if(payment->getType() != 0 && !ApprovalAuthority::isApproved())
        return false;
    
    //if we reached this part it means it is all good and we can complete the sale
    for(const auto& item: items)
        inventory.removeItem(item.first, item.second);
    
    //save information:
    SaleInformation info;
    info.amountBeforeTax = 0.0;
    info.amountOfTax =0.0;
    info.amountAfterTax = 0.0;
    info.valueOfSale = 0.0;
    
    for(const auto& item : items)
    {
        double beforeTax = inventory.getItemPrice(item.first, false);
        info.amountBeforeTax += beforeTax;
        
        double afterTax = inventory.getItemPrice(item.first, true);
        info.amountAfterTax += afterTax;
        
        info.amountOfTax += afterTax - beforeTax;
        
    }
    
    info.valueOfSale = total;
    
    isComplete = true;
    return true;
}


void Sale::print() const
{
    std::cout << "Sale id: " << id << "\nitems: \n";
    
    for(const auto& item : items)
        std::cout << "item ID: " << item.first << " quantity: " << item.second << "\n";
}
