//
//  CashPayment.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef CashPayment_h
#define CashPayment_h
#include "Payment.h"

class CashPayment : public Payment
{
    
public:
    CashPayment() {};
    CashPayment(double am) : Payment(am) {};
    double calculateAmountToBePaid() const;
    int getType() const { return 0;}
};
#endif /* CashPayment_h */
