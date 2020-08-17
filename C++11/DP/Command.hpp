/*
 * Command.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "Macros.h"


NAMESPACE_START

class Command 
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0; 
};

class Receiver 
{
public:
    void Action()
    {
        std::cout << "Receiver Action\n";
    }
};

class Invoker 
{
public:
    Invoker(Command *pCommand) : m_pCommand(pCommand) {}

    ~Invoker()
    {
        delete m_pCommand;
        m_pCommand = NULL;
    }

    void Invoke()
    {
        if (NULL != m_pCommand) {
            m_pCommand->Execute(); 
        }
    }

private:
    Command *m_pCommand; 
};

class ConcreateComand : public Command
{ 
public:
    ConcreateComand(Receiver* pReceiver) : m_pReceiver(pReceiver) {}

    virtual ~ConcreateComand()
    {
        delete m_pReceiver;
        m_pReceiver = NULL;
    }

    virtual void Execute()
    {
        if (NULL != m_pReceiver) {
            m_pReceiver->Action(); 
        }
        std::cout << "Execute by ConcreateComand\n";
    }

private:
    Receiver* m_pReceiver;
};


void testCommand(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testCommand start--------------------------------"<<std::endl;
    
    Receiver *pReceiver = new Receiver();
    Command *pCommand = new ConcreateComand(pReceiver); 
    Invoker *pInvoker = new Invoker(pCommand);
    pInvoker->Invoke(); 
    delete pInvoker;

    std::cout<<"---------------------------testCommand end--------------------------------"<<std::endl;
}

NAMESPACE_END



#endif /* !COMMAND_HPP */
