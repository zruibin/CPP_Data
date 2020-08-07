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
#include <deque>
#include <forward_list>
#include <list>
#include <set>

#include "Macros.h"

NAMESPACE_START
template<typename T>
void print(T t)
{
    for(auto &i : t) {
        std::cout << i << " ";
    }
    std::cout<<'\n';
}
NAMESPACE_END

void testArray(void);
void testVector(void);
void testDeque(void);
void testForward_list(void);
void testList(void);
void testSet(void);
void testMultiset(void);

void testMainContainer(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMainContainer start--------------------------------"<<std::endl;
    testArray();
    testVector();
    testDeque();
    testForward_list();
    testList();
    testSet();
    testMultiset();
    
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
    
    SPACE::print(a3);

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

    SPACE::print(v1);
    std::cout << "size: " << v1.size()
                << " max_size: " << v1.max_size()
                << " capacity: " << v1.capacity()
                << " is_empty: " << v1.empty()
                << std::endl;

    std::cout << "front: " << v1.front() << " back: " << v1.back() << std::endl;

    v1.pop_back();
    SPACE::print(v1);

    v1.erase(v1.begin()+1, v1.begin()+2);
    SPACE::print(v1);

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

void testDeque(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testDeque start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/deque

    std::deque<int> d1 = {1, 3, 5, 7};

    d1.push_front(11);
    d1.push_back(2);

    d1.at(1) = 10;
    d1[2] = 20;

    SPACE::print(d1);
    std::cout << "size: " << d1.size()
                << " max_size: " << d1.max_size()
                << " is_empty: " << d1.empty()
                << std::endl;

    std::cout << "front: " << d1.front() << " back: " << d1.back() << std::endl;

    d1.pop_back();
    SPACE::print(d1);

    d1.erase(d1.begin()+1, d1.begin()+2);
    SPACE::print(d1);

    d1.clear();
    std::cout << "clear -> " << "size: " << d1.size()
                << " max_size: " << d1.max_size()
                << " is_empty: " << d1.empty()
                << std::endl;
    
    d1.shrink_to_fit();
    std::cout << "shrink_to_fit -> " << "size: " << d1.size()
                << " max_size: " << d1.max_size()
                << " is_empty: " << d1.empty()
                << std::endl;

    std::cout<<"---------------------------testDeque end--------------------------------"<<std::endl;
}

void testForward_list(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testForward_list start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/forward_list
    //实现为单链表

    std::forward_list<int> fl = {1, 1, 3, 5, 7};

    fl.insert_after(fl.begin(), 30);
    fl.push_front(22);

    SPACE::print(fl);
    std::cout << "max_size: " << fl.max_size()
                << " is_empty: " << fl.empty()
                << std::endl;
    std::cout << "front: " << fl.front() << std::endl;

    fl.pop_front();
    SPACE::print(fl);
    std::cout << "max_size: " << fl.max_size()
                << " is_empty: " << fl.empty()
                << std::endl;


    fl.resize(10);
    SPACE::print(fl);

    fl.remove(1); // 移除两个等于 1 的元素
    fl.remove_if([](int n){ return n == 0; }); // 移除全部等于 0 的元素
    SPACE::print(fl);

    fl.clear();
    std::cout << "max_size: " << fl.max_size()
                << " is_empty: " << fl.empty()
                << std::endl;

    std::forward_list<int> list1 = { 5,9,0,1,3 };
    std::forward_list<int> list2 = { 8,7,2,6,4 };
    list1.sort();
    list2.sort();
    SPACE::print(list1);
    SPACE::print(list2);
    list1.merge(list2);
    SPACE::print(list1);

    std::cout<<"---------------------------testForward_list start--------------------------------"<<std::endl;
}

void testList(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testList start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/list
    //不支持快速随机访问。它通常实现为双向链表。
    
    std::list<int> list1 = {1, 1, 3, 5, 7};

    std::cout << "front: " << list1.front() << " back: " << list1.back() << std::endl;

    // 添加整数到 list 开头
    list1.push_front(25);
    // 添加整数到 list 结尾
    list1.push_back(13);
    SPACE::print(list1);

    list1.pop_front();
    list1.pop_back();
    SPACE::print(list1);
    std::cout << "size: " << list1.size()
                << " max_size: " << list1.max_size()
                << " is_empty: " << list1.empty()
                << std::endl;

    auto it = std::find(list1.begin(), list1.end(), 5);
    if (it != list1.end()) {
        list1.insert(it, 42);
    }
    SPACE::print(list1);

    list1.clear();
    std::cout << "size: " << list1.size()
                << " max_size: " << list1.max_size()
                << " is_empty: " << list1.empty()
                << std::endl;

    std::cout<<"---------------------------testList start--------------------------------"<<std::endl;
}

void testSet(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testSet start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/set
    //含有 Key 类型对象的已排序集。用比较函数 比较 (Compare) 进行排序。搜索、移除和插入拥有对数复杂度。 set 通常以红黑树实现。

    std::set<int> set1 = {1, 1, 3, 5, 7};
    SPACE::print(set1);
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << std::endl;
    
    std::set<int>::iterator search = set1.find(5);
    if (search != set1.end()) {
        std::cout << (*search) << std::endl;
        set1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::print(set1);

    set1.insert(33);
    set1.insert(23);
    SPACE::print(set1);

    set1.clear();
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << std::endl;

    std::cout<<"---------------------------testSet start--------------------------------"<<std::endl;
}

void testMultiset(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMultiset start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/multiset
    //不同于 set ，它允许多个关键拥有等价的值。

    std::multiset<int> set1 = {1, 1, 2, 2, 3, 5, 7};
    SPACE::print(set1);
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << std::endl;
    
    std::set<int>::iterator search = set1.find(5);
    if (search != set1.end()) {
        std::cout << (*search) << std::endl;
        set1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::print(set1);

    set1.insert(33);
    set1.insert(23);
    set1.insert(23);
    SPACE::print(set1);

    set1.clear();
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << std::endl;

    std::cout<<"---------------------------testMultiset start--------------------------------"<<std::endl;
}

#endif /* !CONTAINERTEST_H */
