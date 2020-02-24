#include <iostream>

struct Friend 
{
private:
    char gender;
    char actor[32];
    char name[32];
    int  age;
    char job[32];
public:

    void setGender(char newGender);
    char getGender()const;

    void setActor(char newActor[32]);
    char* getActor();

    void setName(char newName[32]);
    char* getName();

    void setAge(int newAge);
    int getAge()const;

    void setJob(char newJob[32]);
    char* getJob();

    void input();
    void output()const;
};

void Friend::setGender(char newGender)
{
    this->gender = newGender;
}
char Friend::getGender()const
{
    return this->gender;
}
void Friend::setActor(char newActor[32])
{
    strcpy_s(this->actor, 32, newActor);
}
char* Friend::getActor()
{
    return this->actor;
}

void Friend::setName(char newName[32])
{
    strcpy_s(this->name, 32, newName);
}
char* Friend::getName()
{
    return this->name;
}

void Friend::setAge(int newAge)
{
    this->age = newAge;
}
int Friend::getAge()const
{
    return this->age;
}

void Friend::setJob(char newJob[32])
{
    strcpy_s(this->job, 32, newJob);
}
char* Friend::getJob()
{
    return this->job;
}

void Friend::input()
{
    //todo
}
void Friend::output()const
{
    //todo
}
int main()
{
    char name[32];
    std::cin.getline(name, 32);
    Friend* monica = new Friend();
    monica->setName(name);
    std::cout<<monica->getName();
    
}

