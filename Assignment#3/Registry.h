//
//  Registry.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef Registry_h
#define Registry_h
#include <vector>
#include "Sale.h"

class Registry
{
public:
    Registry() {}
    ~Registry();
    bool addSale(Sale* sale);
    void printReport() const;
private:
    std::vector<Sale*> completedSales;
    
};
#endif /* Registry_h */
