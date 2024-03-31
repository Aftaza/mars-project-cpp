#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

struct node
{
    string cmd;
    struct node *next;
};
typedef struct node node;

struct nodePerson{
    string nama;
    int rate;
    int age;
    string tensi;
    struct nodePerson *next;
};
typedef struct nodePerson nodePerson;

node *headIn, *tailIn, *headOut, *tailOut;
nodePerson *headVip1, *tailVip1, *headVip2, *tailVip2, *headCom, *tailCom;
string command;
int countIn = 0;
int countOut = 0;
int vip = 0;
int com = 0;
int wait_list = 0;
int vip1_count = 0;
int vip2_count = 0;
int com_count = 0;

void enqueue(string command, char type);

void dequeue(char type);

void printAll();

void input();

void mainProcess();

int getLenText(string txt);

vector<string> getWords(string s);

void procCommand(string cmd);

void addVip(nodePerson *temp, int type);

void addCom(nodePerson *temp);

void output();
