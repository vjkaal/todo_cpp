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
    std::cout<<"\n\nTask Status...\n";
    std::cout<<"\nJob: "<<getJob();
    std::cout<<"\nCompleted: "<<getCompleted();
    std::cout<<"\n"<<std::endl;


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
}

void taskHandler::alterTask()
{
    char boolean = 'n';
    //boolean variable to store bool

    std::cout<<"Change job? y/n ";
    std::cin>>boolean;
    std::cin.ignore();
    if(tolower(boolean) == 'y') setJob();

    std::cout<<"Job Completed?: y/n ";
    std::cin>>boolean;
    std::cin.ignore();
    if(tolower(boolean) == 'y') setCompleted(true);

    displayTask();
}


void taskHandler::deleteTask()
{
    t->text = "";
    t->completed = false;
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


    t->text = job;
}


std::string taskHandler::getJob()
{
    return t->text;
}



// task completed status here
std::string taskHandler::getCompleted()
{
    return (t->completed)?"true":"false";
}


void taskHandler::setCompleted(bool value)
{
    t->completed = value;
}
