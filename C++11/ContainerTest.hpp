/*
 * ContainerTest.h
 *
 * Created by zhouruibin734 on 2020/08/03.
 * Copyright (c) 2020年 zhouruibin734 All rights reserved.
 */

#ifndef CONTAINERTEST_H
#define CONTAINERTEST_H

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

#include <array>
#include <vector>

void testArray(void);
void testVector(void);


void testMainContainer(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMainContainer start--------------------------------"<<std::endl;
    testArray();
    testVector();
    
    
    
    
    
    std::cout<<"---------------------------testMainContainer end--------------------------------"<<std::endl;
}


void testArray(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testArray start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/array

    std::array<int, 3> a1{1, 2, 3};
    std::array<int, 3> a2 = {1, 2, 3};
    std::array<std::string, 2> a3 = {std::string("a"), "b"};
    
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), 
                        std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    
    for(const auto &s : a3) {
        std::cout<<s<<" ";
    }

    std::cout<<'\n';
    std::cout<<"---------------------------testArray end--------------------------------"<<std::endl;
}

void testVector(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testVector start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/vector

    std::vector<int> v1 = {1, 3, 5, 7};

    v1.push_back(6);
    v1.push_back(2);

    v1.at(1) = 10;
    v1[2] = 20;

    for(int i : v1) {
        std::cout<<i<<" ";
    }
    std::cout<<'\n';
    std::cout << "size: " << v1.size()
                << " max_size: " << v1.max_size()
                << " capacity: " << v1.capacity()
                << " is_empty: " << v1.empty()
                << std::endl;

    std::cout << "front: " << v1.front() << " back: " << v1.back() << std::endl;

    v1.pop_back();
    for(int i : v1) {
        std::cout<<i<<" ";
    }
    std::cout<<'\n';

    v1.erase(v1.begin()+1, v1.begin()+2);
    for(int i : v1) {
        std::cout<<i<<" ";
    }
    std::cout<<'\n';

    v1.clear();
    std::cout << "clear -> " << "size: " << v1.size()
                << " max_size: " << v1.max_size()
                << " capacity: " << v1.capacity()
                << " is_empty: " << v1.empty()
                << std::endl;
    
    v1.shrink_to_fit();
    std::cout << "shrink_to_fit -> " << "size: " << v1.size()
                << " max_size: " << v1.max_size()
                << " capacity: " << v1.capacity()
                << " is_empty: " << v1.empty()
                << std::endl;
                
    std::cout<<"---------------------------testVector end--------------------------------"<<std::endl;   
}


#endif /* !CONTAINERTEST_H */
