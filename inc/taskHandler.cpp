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


void taskHandler::createTask()
{
    setJob();
}

void taskHandler::displayTask()
{
    std::cout<<"Task Status...\n";
    std::cout<<"\nJob: "<<getJob();
    std::cout<<"\nCompleted: "<<getCompleted();
    std::cout<<"\n"<<std::endl;
}


void taskHandler::setJob()
{
    std::string job = "";
    std::cout<<"Enter task: ";
    std::getline(std::cin,job);

    t.text = job;
}


std::string taskHandler::getJob()
{
    return t.text;
}


std::string taskHandler::getCompleted()
{
    return (t.completed)?"true":"false";
}
