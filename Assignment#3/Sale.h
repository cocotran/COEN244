//
//  Sale.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef Sale_h
#define Sale_h
#include <utility>
#include "Item.h"
#include <vector>
#include "CashPayment.h"
#include "CreditCardPayment.h"
#include "DebitCardPayment.h"
#include "Error.h"
#include "Inventory.h"

class Sale
{

public:
    struct Date
    {
        int day;
        int month;
        int year;
        Date(int d, int m, int y) : day(d), month(m), year(y) {}
    };
    
    struct Time
    {
        int hour;
        int minute;
        int second;
        Time(int h, int m, int s) : hour(h), minute(m), second(s) {}
    };
    
    Sale() : id(idCounter), payment(new CashPayment()), date(Date(0,0,0)), time(Time(0,0,0)), isComplete(false)
    {
        idCounter++;
    }
    Sale(unsigned int paymentType, Date d, Time t);
    ~Sale() { delete payment;}
    
    Date getDate() { return date;}
    void setDate(Date d) {date = d;}
    
    Time getTime() {return time;}
    void setTime(Time t) { time=t;}
    
    void changePaymentType(unsigned int type); //0 cash, 1 credit, 2 debit
    
    void addItem(unsigned int itemID, unsigned int quantity=1);
    Error removeItem(unsigned int itemID, unsigned int quantity=1);
    double getAmountToBePaid(const Inventory& inventory, bool withTax=false, bool withPaymentType=false);
    /*
     This function will check if the items are available in the inventory
     if not, they will be dropped.
     if quantity is less in invenotry, the quantity of sale will change
     to the avaialble quantity
     
     if the amount passed is the same to the total price including taxes
     and taking into consideration the payment type
     then the sale will be completed and the inventory will be updated
     
     */
    bool completeSale(double amount, Inventory& inventory);
    
    bool getComplete() const {return isComplete;}
    
    
    void print() const;
    
    struct SaleInformation
    {
        //to save information when completed
        double amountBeforeTax;
        double amountOfTax;
        double amountAfterTax;
        double valueOfSale;
    };
    
    SaleInformation getInfo() const { return info;}
private:
    static unsigned int idCounter;
    const unsigned int id;
    Date date;
    Time time;
    std::vector<std::pair<int,int>> items; //store <item ids, quantity>
    Payment* payment;
    bool isComplete;
    SaleInformation info;

    
    
    
    
};
#endif /* Sale_h */
