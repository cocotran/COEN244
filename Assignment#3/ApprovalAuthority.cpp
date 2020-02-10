//
//  ApprovalAuthority.cpp
//  Coen244-Ass3
//
//  Created by Tawfiq Jawhar on 2019-08-05.
//  Copyright © 2019 Tawfiq Jawhar. All rights reserved.
//

#include "ApprovalAuthority.h"

std::random_device   ApprovalAuthority::m_rd;
std::mt19937         ApprovalAuthority::m_rng(ApprovalAuthority::m_rd());
