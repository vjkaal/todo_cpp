#include<iostream>
#include<list>
#include<stdlib.h>

#include "inc/taskHandler.h"


std::list<taskHandler* > l;

void createNewElem()
{
    taskHandler *i = new taskHandler();
    i->createTask();
    l.push_back(i);
    i++;
}


void readList()
{
    std::cout<<"sorry for inconvenience\n";
    //for(taskHandler *x:l) *x->displayTask();
}


int menuBar()
{

    std::cout<<"\n----------------TO DO----------------\n\n";
    std::cout<<"Create new Deadline: Press 1\n";
    std::cout<<"See all Deadlines: Press 2\n";
    std::cout<<"Exit: Press 0\n\n";

    int choice = 0;

input:
    std::cout<<"Enter choice: ";
    try
    {
        std::cin>>choice;
        std::cin.ignore();
        if(choice < 0 || choice > 2) throw choice;
    }
    catch(int wrong)
    {
        std::cout<<"Plz be reasonable in life\n";
        goto input;
    }

    return choice;

}


void start()
{

    //int res = menuBar();

    while(1)
    {

        switch(menuBar())
        {
            case 1: createNewElem(); break;

            case 2: readList(); break;

            case 0: exit(86); break;

            default: break;
        }

    }

}
