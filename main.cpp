#include<iostream>
#include<list>


void readList()
{

    std::cout<<"Plz be patient\n";
}

void createNewElem()
{
    std::cout<<"Plz be patient\n";
}


int menuBar()
{

    std::cout<<"\n----------------TO DO----------------\n\n";
    std::cout<<"See all Deadlines: Press 0\n";
    std::cout<<"Create new Deadline: Press 1\n";

    int choice = 0;

    input:
    std::cout<<"Enter choice: ";
    try
    {
        std::cin>>choice;
        if(choice < 0 || choice > 1) throw choice;
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
    std::list<int> l;

    //int res = menuBar();

    switch(menuBar())
    {
        case 0: readList();break;

        case 1: createNewElem();break;

        default: break;
    }

}
