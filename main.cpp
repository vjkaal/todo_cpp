#include<iostream>
#include<list>
#include<iterator>
#include<stdlib.h>

#include "inc/taskHandler.h"

/*

to be done: remove from list when deleted

*/

std::list<taskHandler* > l;

void createNewElem()
{
    //std::cout<<"here\n";
    taskHandler *i = new taskHandler();
    i->createTask();
    l.push_back(i);
    i++;
}


void readList()
{
    int i = 1;
    std::cout<<"\nTask Status...";
    for(taskHandler *x:l)
    {
        x->displayTask();
        std::cout<<"\nAlter task? (Press "<<i<<")\n";
        i++;
    }
    std::cout<<"\nEnter 0 if you wish to alter no task!";
    int choice = 0;


    list_input:
    std::cout<<"\nEnter your choice ";
    try
    {
        std::cin>>choice;
        std::cin.ignore();

        if(choice < 0 || choice > i) throw(choice);
    }
    catch(int choice)
    {
        std::cout<<"Plz be reasonable in life";
        goto list_input;
    }

    if(choice > 0)
    {
        int i=0;
        for(taskHandler *x:l)
        {
            if(i == choice-1)
            {
                x->alterTask();
                break;
            }
            i++;
        }

        /*
        std::list<taskHandler* >::iterator it = l.begin();
        std::advance(it, choice-1);
        std::cout<<*it<<std::endl;
        */
    }

}


int menuBar()
{

    std::cout<<"\n----------------TO DO----------------\n\n";
    std::cout<<"Create new Deadline: Press 1\n";
    std::cout<<"See all Deadlines: Press 2\n";
    std::cout<<"Exit: Press 0\n\n";

    auto choice = 0;

    input:
    std::cout<<"Enter choice: ";
    try
    {
        std::cin>>choice;
        std::cin.ignore();
        //std::string type = typeid(choice).name();
        //std::cout<<type<<std::endl;


        //this here needs dire ATTENTION
        if(choice < 0 || choice > 2) throw choice;
    }
    catch(int wrong)
    {
        std::cout<<"Plz be reasonable in life\n";
        goto input;
    }
    /*
    catch(char wrong)
    {
        std::cout<<"Plz be reasonable in life\n";
        goto input;
    }
    catch(char* wrong)
    {
        std::cout<<"Plz be reasonable in life\n";
        goto input;
    }
    */

    //std::cout<<"here"<<choice<<"\n";
    return choice;

}


int main()
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

    return 0;

}
