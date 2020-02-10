//
//  CreditCardPayment.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "CreditCardPayment.h"

double CreditCardPayment::calculateAmountToBePaid() const
{
    if(amount > 50)
        return amount + amount*0.02;
    else
        return 0.0;
}
