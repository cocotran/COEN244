//
//  CashPayment.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "CashPayment.h"

double CashPayment::calculateAmountToBePaid() const
{
    if(amount > 200)
        return amount - amount*0.05;
    else
        return amount;
}
