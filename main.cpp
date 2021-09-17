#include<iostream>
#include<list>
#include<stdlib.h>


std::list<int> l;
int i = 0;

void createNewElem()
{
    l.push_back(i);
    i++;
}


void readList()
{
    for(int x:l) std::cout<<x<<std::endl;
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
