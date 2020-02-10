//
//  Payment.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef Payment_h
#define Payment_h

class Payment
{
protected:
    static unsigned int idCounter;
    const unsigned int id;
    double amount;
public:
    Payment() : id(idCounter), amount(0.0) { idCounter++;}
    Payment(double am) : id(idCounter), amount(am) { idCounter++;}

    double getAmount() const {return amount;}
    void setAmount(double am) {amount=am;}
    double virtual calculateAmountToBePaid() const=0;
    int virtual getType() const=0;
};
#endif /* Payment_h */
