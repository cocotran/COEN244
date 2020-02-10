//
//  DebitCardPayment.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef DebitCardPayment_h
#define DebitCardPayment_h

#include "Payment.h"

class DebitCardPayment : public Payment
{
public:
    DebitCardPayment() {};
    DebitCardPayment(double am) : Payment(am) {};
    double calculateAmountToBePaid() const;
    int getType() const {return 2;}
    
};
#endif /* DebitCardPayment_h */
