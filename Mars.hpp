#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    string cmd;
    struct node *next;
};
typedef struct node node;

struct nodePerson{
    string name;
    int rate;
    int age;
    string tensi;
    struct nodePerson *next;
};
typedef struct nodePerson nodePerson;

node *headIn, *tailIn, *headOut, *tailOut;
string command;
int countIn = 0;
int countOut = 0;

void enqueue(string command, char type);

void dequeue(char type);

void printAll();

void input();

void mainProcess();

void output();
