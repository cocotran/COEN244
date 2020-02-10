//
//  item.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef item_h
#define item_h
#include<string>


class Item
{
private:
    static unsigned int idCounter;
    static float taxRate;

    const unsigned int id;
    std::string description;
    double price;
    
public:
    Item() : id(idCounter), price(0.0), description("") { idCounter++; }
    
    Item(std::string desc, double pri) : id(idCounter),
    description(desc), price(pri)  { idCounter++;}
    
    static float getTaxRate()  {return taxRate;}
    static void setTaxRate(float tax)  {taxRate = tax; }
    
    unsigned int getID() const {return id;}
    
    double getPrice(bool withTax=false) const { return (withTax) ?  price + getTax() : price;}
    void setPrice(double pri) { price = pri;}
    
    std::string getDescription() const { return description;}
    void setDescription(std::string desc) { description = desc;}
    
    double getTax() const {return price*taxRate;}
    
    void print() const;
    
    
};
#endif /* item_h */
