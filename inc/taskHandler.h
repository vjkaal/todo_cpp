#include<iostream>

#ifndef TASKHANDLER_H
#define TASKHANDLER_H


class taskHandler
{
    private:

        struct task
        {
            bool completed = false;
            std::string text = "";
        };

    protected:

    public:
        task t;
        taskHandler();
        virtual ~taskHandler();

        void createTask();
        void displayTask();
        void deleteTask();

        void setJob();
        std::string getJob();

        void setCompleted();
        std::string getCompleted();

};

#endif // TASKHANDLER_H
