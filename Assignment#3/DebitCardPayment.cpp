//
//  DebitCardPayment.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "DebitCardPayment.h"

double DebitCardPayment::calculateAmountToBePaid() const
{
    if(amount < 1000.0)
        return amount + 3.0;
    else
        return 0.0;
}
