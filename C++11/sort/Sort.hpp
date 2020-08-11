/*
 * Sort.h
 *
 * Created by zhouruibin734 on 2020/08/11.
 * Copyright (c) 2020年 zhouruibin734 All rights reserved.
 */

#ifndef SORT_H
#define SORT_H

#include "Macros.h"
#include <iostream>
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"

NAMESPACE_START
void testSort()
{
    std::cout<<'\n';
    std::cout<<"---------------------------testSort start--------------------------------"<<std::endl;
    
    SPACE::testBubbleSort();
    SPACE::testSelectionSort();

    std::cout<<"---------------------------testSort end--------------------------------"<<std::endl;
}
NAMESPACE_END

#endif /* !SORT_H */
