//
//  Error.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef Error_h
#define Error_h


enum class Error : char { noError, itemNotFound, notEnoughQuantity, itemIsOutOfStock, inventoryFull, saleCompleted};
void printError(Error errorType);



#endif /* Error_h */
