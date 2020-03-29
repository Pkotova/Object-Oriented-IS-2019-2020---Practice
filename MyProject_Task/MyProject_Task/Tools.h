#pragma once
#include"MyProject.h"

MyProject& merge(MyProject& other, MyProject& another, const char* newTeamName);
MyProject& hasTheMostContributors(MyProject* projects, int size);
void swap(MyProject* other, MyProject* another);
void sort(MyProject** projects, int size);