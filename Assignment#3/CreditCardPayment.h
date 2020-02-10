//
//  CreditCardPayment.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef CreditCardPayment_h
#define CreditCardPayment_h

#include "Payment.h"

class CreditCardPayment : public Payment
{
public:
    CreditCardPayment() {};
    CreditCardPayment(double am) : Payment(am) {};
    double calculateAmountToBePaid() const;
    int getType() const {return 1;}
    
};
#endif /* CreditCardPayment_h */
