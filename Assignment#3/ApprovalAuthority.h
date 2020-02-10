//
//  ApprovalAuthority.h
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#ifndef ApprovalAuthority_h
#define ApprovalAuthority_h
#include <random>
#include <iostream>
class ApprovalAuthority
{
private:
    static std::random_device   m_rd;
    static std::mt19937         m_rng;
    
public:
    static bool isApproved() 
    {
        std::uniform_real_distribution<> randomizer(0, 1);
        return (randomizer(m_rng) > 0.1) ? true : false;
    }
};
#endif /* ApprovalAuthority_h */
