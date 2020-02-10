//
//  main.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include <iostream>
#include "Item.h"
#include "Error.h"
#include "Inventory.h"
#include "CashPayment.h"
#include "CreditCardPayment.h"
#include "DebitCardPayment.h"
#include "ApprovalAuthority.h"
#include "Sale.h"
#include "Registry.h"

int main(int argc, const char * argv[]) {
   /*
    std::cout << "---------\nItem class test\n---------\n";
    std::cout << "Test case: Static tax rate\n";
    std::cout << Item::getTaxRate() << "\n";
    Item::setTaxRate(0.20);
    std::cout << Item::getTaxRate()<<"\n\n";
    
    std::cout << "Test case: auto incremented id with 2 default Item objects\n";
    Item item1;
    item1.print();
    std::cout << "\n";
    Item item2;
    item2.print();
    std::cout << "\n";

    std::cout << "Test case: regular constructor with desc: 'productX', price: 20\n";
    Item item3("productX", 20);
    item3.print();
    std::cout << "\n";
    
    std::cout << "Test case: setters for item1 with desc: 'productX', price: 20\n";
    item1.setDescription("productX");
    item1.setPrice(20.0);
    item1.print();
    std::cout << "\n";

    std::cout << "---------\nInventory class test: add items\n---------\n";
    
    Error error;
    Inventory inventory;
    
    std::cout << "Test case: add item1 to inventory with 10 quantity\n";
    
    error = inventory.addItem(item1, 10);
    inventory.print();
    std::cout << "Error: ";
    printError(error);
    
    std::cout << "\n";
    
    std::cout << "Test case: add another 10 to item1\n";
    
    error = inventory.addItem(item1, 10);
    inventory.print();
    std::cout << "Error: ";
    printError(error);
    
    std::cout << "\n";

    std::cout << "Test case: add 51 new items to a new inventory then output error for last add\n";
    Inventory inventory1;
    for(int i=0; i < 51; i++)
        error = inventory1.addItem(Item(), 10);
    std::cout << "Error: ";
    printError(error);
    
    std::cout << "\n";
    
    std::cout << "---------\nInventory class test: remove items\n---------\n";
    
    std::cout << "Test case: remove item1 from inventory with 10 quantity\n";
    
    error = inventory.removeItem(item1.getID(), 10);
    inventory.print();
    std::cout << "Error: ";
    printError(error);
    
    std::cout << "\n";
    
    std::cout << "Test case: remove item1 from inventory with 20 quantity\n";
    
    error = inventory.removeItem(item1.getID(), 20);
    inventory.print();
    std::cout << "Error: ";
    printError(error);
    
    std::cout << "\n";
    
    std::cout << "---------\nInventory class test: is item available for sale\n---------\n";
    
    std::cout << "Test case: check item1\n";
    if(inventory.isItemInStock(item1.getID())) std::cout << "item1 is available.\n";
    else    std::cout << "item1 is not available.\n";
    std::cout << "\n";

    
    std::cout << "Test case: check item2\n";
    if(inventory.isItemInStock(item2.getID())) std::cout << "item2 is available.\n";
    else    std::cout << "item2 is not available.\n";
    std::cout << "\n";

    
    std::cout << "Test case: add 10 of item2 then check item2\n";
    inventory.addItem(item2, 10);
    if(inventory.isItemInStock(item2.getID())) std::cout << "item2 is available.\n";
    else    std::cout << "item2 is not available.\n";
    std::cout << "\n";

    

    std::cout << "---------\nPayment test: CashPayment\n---------\n";
    Payment* payment;
    std::cout << "Test case: create new CashPayment with 400 amount \n";
    
    payment = new CashPayment(400.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";

    std::cout << "Test case: set amount to 200 \n";
    
    payment->setAmount(200.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";
    
    std::cout << "Test case: set amount to 100 \n";
    
    payment->setAmount(100.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";
    

    std::cout << "---------\nPayment test: CreditCardPayment\n---------\n";
    delete payment;
    std::cout << "Test case: create new CreditCardPayment with 400 amount \n";
    payment = new CreditCardPayment(400.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";
    
    std::cout << "Test case: set amount to 50 \n";
    
    payment->setAmount(50.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";
    
    std::cout << "Test case: set amount to 20 \n";
    
    payment->setAmount(20.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";
    
    std::cout << "---------\nPayment test: DebitCardPayment\n---------\n";
    delete payment;
    std::cout << "Test case: create new DebitCardPayment with 400 amount \n";
    payment = new DebitCardPayment(400.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";
    
    std::cout << "Test case: set amount to 1000 \n";
    
    payment->setAmount(1000.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";
    
    std::cout << "Test case: set amount to 5000\n";
    
    payment->setAmount(5000.0);
    std::cout << "The amount to be paid: " << payment->calculateAmountToBePaid();
    std::cout << "\n\n";
  
    
    std::cout << "---------\nSale test: add items\n---------\n";
    
    Sale sale;
    sale.addItem(item1.getID(), 5);
    sale.addItem(item2.getID(), 10);
    sale.print();

    std::cout << "---------\nSale test: test complete\n---------\n";
    
    std::cout << "printing inventory: \n";
    inventory.print();
    double total = 0.0;
    std::cout << "amount to be paid with tax + payment type: " << (total = sale.getAmountToBePaid(inventory, true, true)) << "\n";
    std::cout << "complete sale: ";
    if(sale.completeSale(total, inventory))
        std::cout << "completed\n";
    else std::cout << "not completed\n";
    
    std::cout << "---------\nSale test: add 10 item1 to inven then test complete\n---------\n";
    
    inventory.addItem(item1, 10);
    std::cout << "printing inventory: \n";
    inventory.print();
    total = 0.0;
    std::cout << "amount to be paid with tax + payment type: " << (total = sale.getAmountToBePaid(inventory, true, true)) << "\n";
    std::cout << "complete sale: ";
    if(sale.completeSale(total, inventory))
        std::cout << "completed\n";
    else std::cout << "not completed\n";
    
    
    std::cout << "---------\nSale test: add items not in stock to sale then test complete\n---------\n";
    Sale sale2;
    Item item4;
    item4.setPrice(100);
    inventory.addItem(item4, 3);
    sale2.addItem(item4.getID(), 10);
    sale2.addItem(item1.getID());
    std::cout << "printing inventory: \n";
    inventory.print();
    total = 0.0;
    std::cout << "amount to be paid with tax + payment type: " << (total = sale2.getAmountToBePaid(inventory, true, true)) << "\n";
    std::cout << "complete sale: ";
    if(sale2.completeSale(total, inventory))
        std::cout << "completed\n";
    else std::cout << "not completed\n";
    
    std::cout << "---------\nSale test: try to complete again with new amount updated\n---------\n";
    
    total = 0.0;
    std::cout << "amount to be paid with tax + payment type: " << (total = sale2.getAmountToBePaid(inventory, true, true)) << "\n";
    std::cout << "complete sale: ";
    if(sale2.completeSale(total, inventory))
        std::cout << "completed\n";
    else std::cout << "not completed\n";
    */
    
    
    /**------------------------
     A bit on the design:
     ---
     Items are only sotred in the inventory.
     Any other class that requires the use of items, stores item IDs.
     and then access the items from the inventory that is passed by referenc
     whenever is needed.
     ---
     All IDs are auto incremeneted and can not be modified.
     As we are using ID to trace back all our information.
     ---
     
     Registry stores Sale*
     if a sale is added to registry, Registry becomes the owner of that pointer.
     We should not delete the sale our selves anymore, until Registry is done with it
     
     if a sale was not completed and not added to the Registry,
     then we are responsible for deleting that sale.
     ---
     
     In some cases like in the inventory methods, enum Error is returned.
     Which is simply different errors that can be printed using the printError function.
     This can be improved by using Exceptions
     ---
     
     ApprovedAuthority uses a C++ random generator. I'd advice everyone to learn how to use it.
     It's a much better random generator than the C rand();
     ---
     
     Instead of having multiple functions for getting the price, with tax/without tax, with PaymentType/Without
     I used one function that takes a bool to specofy the price I want to get.
     Which works well to not recheck every time the conditions yourselves and get the right price.
     In this case you just pass the bool to the other functions.
     ---
     
     Testing every little step as you are implementing is very important.
     It doesn't matter how good you are, you will always have bugs.
     In case you find bugs in my implementation please report it to me to fix it
     tawjaw@gmail.com
     
     *************/
    
    Registry registry;
    
    Inventory invent;
    
    Item itemX;
    itemX.setPrice(20);
    Item itemY;
    itemY.setPrice(100);
    Item itemZ;
    itemZ.setPrice(400);
    
    invent.addItem(itemX, 10);
    invent.addItem(itemY, 5);
    invent.addItem(itemZ, 1);
    
    Sale* sale = new Sale();
    sale->addItem(itemX.getID(), 5);
    sale->addItem(itemZ.getID(), 2);
    sale->addItem(itemY.getID(), 10);
    
    std::cout << "Invenotry items: \n";
    invent.print();
    
    sale->changePaymentType(2);
    
    double total = 0.0;
    std::cout << "\namount to be paid with tax + payment type: " << (total = sale->getAmountToBePaid(invent, true, true)) << "\n";
    sale->completeSale(total, invent);
    if(registry.addSale(sale))
        std::cout << "sale completed and added to registry";
    else
    {
        delete sale;
        std::cout << "not completed and deleted\n";
    }
    
    sale = new Sale();
    sale->addItem(itemX.getID(), 1);
    sale->addItem(itemZ.getID(), 1);
    sale->addItem(itemY.getID(), 1);
    
    std::cout << "\nInvenotry items: \n";
    invent.print();
    
    sale->changePaymentType(2);
    
    total = 0.0;
    std::cout << "\namount to be paid with tax + payment type: " << (total = sale->getAmountToBePaid(invent, true, true)) << "\n";
    sale->completeSale(total, invent);
    if(registry.addSale(sale))
        std::cout << "sale completed and added to registry";
    else
    {
        std::cout << "not completed and deleted\n";
        delete sale;
    }
    
    std::cout << "\n\nInventory now: \n";
    invent.print();
    
    sale = new Sale();
    sale->addItem(itemX.getID(), 1);
    sale->addItem(itemY.getID(), 3);
    
    std::cout << "\nInvenotry items: \n";
    invent.print();
    
    sale->changePaymentType(1);
    
    total = 0.0;
    std::cout << "\namount to be paid with tax + payment type: " << (total = sale->getAmountToBePaid(invent, true, true)) << "\n";
    sale->completeSale(total, invent);
    if(registry.addSale(sale))
        std::cout << "sale completed and added to registry";
    else
    {
        std::cout << "not completed and deleted\n";
        delete sale;
    }
    
    
    
    
    std::cout << "\n\n\nRegistry Report: \n\n";
    registry.printReport();
    return 0;
}
