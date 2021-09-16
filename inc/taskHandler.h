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
        task *t = new task;
        taskHandler();
        virtual ~taskHandler();

        void createTask();
        void displayTask();
        void alterTask();
        void deleteTask();

        void setJob();
        std::string getJob();

        void setCompleted(bool);
        std::string getCompleted();

};

#endif // TASKHANDLER_H
