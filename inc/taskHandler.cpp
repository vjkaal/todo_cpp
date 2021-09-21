#include "taskHandler.h"

#include<iostream>
#include<cstring>
#include<string>



taskHandler::taskHandler()
{
    //ttor
}

taskHandler::~taskHandler()
{
    //dtor
}


// basic task operations here
void taskHandler::createTask()
{
    setJob();
}

void taskHandler::displayTask()
{
    std::cout<<"\nTask: "<<getJob()<<"\nStatus: "<<getCompleted();


    /*
    choose:

    int choice = 0;

    std::cout<<"Alter task? 1";
    std::cout<<"\nDelete task? 2";
    std::cin>>choice;
    std::cin.ignore();
    if(choice == 1) alterTask();
    else if(choice == 2) deleteTask();
    else{
        std::cout<<"plz be reasonable in life!\n";
        goto choose;
    }
    */
}


bool taskHandler::alterTask()
{
    int choice = 0;


    taskAlteration:
    std::cout<<"\n\nChange Job? (Press 1)";
    std::cout<<"\nJob Completed?: (Press 2)";
    std::cout<<"\nDelete Job? (Press 3)";
    std::cout<<"\nBack: (Press 0)";
    std::cout<<"\nEnter your choice";
    try
    {
        std::cin>>choice;
        std::cin.ignore();
        if(choice < 0 || choice > 3) throw(choice);
    }
    catch(int wrong)
    {
        std::cout<<"Plz be reasonable in life\n";
        goto taskAlteration;
    }



    switch(choice)
    {
        case 1: setJob();break;
        case 2: setCompleted(true);break;
        case 3: deleteTask(); return true;
        default:
        case 0: break;
    }

    displayTask();
}


void taskHandler::deleteTask()
{
    this->t->text = "";
    this->t->completed = false;
    std::cout<<"\nTask Deleted Successfully\n";
}



// task text here
void taskHandler::setJob()
{
    std::string job = "";

    taskCreation:
    std::cout<<"Enter task: ";
    try
    {
        std::getline(std::cin,job);
        if(job.size() == 0) throw(0);
    }
    catch(int stringlength)
    {
        std::cout<<"Empty String passed, plz mention job...\n";
        goto taskCreation;
    }


    this->t->text = job;
}


std::string taskHandler::getJob()
{
    return this->t->text;
}



// task completed status here
std::string taskHandler::getCompleted()
{
    if(this->t->text == "") return "";
    return (this->t->completed)?"finished":"plz finish This";
}


void taskHandler::setCompleted(bool value)
{
    this->t->completed = value;
}
