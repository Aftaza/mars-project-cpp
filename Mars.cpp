#include "Mars.hpp"

void enqueue(string command, char type)
{
    node *temp = new node;
    temp->cmd = command;
    temp->next = NULL;
    switch (type)
    {
    case 'i':
        if (headIn == NULL)
        {
            headIn = temp;
            tailIn=temp;
            temp = NULL;
        }
        else
        {
            tailIn->next = temp;
            tailIn = temp;
        }
        countIn++;
        break;
    case 'o':
        if (headOut == NULL)
        {
            headOut = temp;
            tailOut=temp;
            temp = NULL;
        }
        else
        {
            tailOut->next = temp;
            tailOut = temp;
        }
        countOut++;
        break;
    default:
        break;
    }
    delete temp;
}

void dequeue(char type)
{
    switch (type) 
    {
    case 'i':
        if (headIn==NULL)
            cout << "\n## Queue kosong";
        else
        { 
            string command=headIn->cmd;
            node *temp=headIn->next;
            headIn=temp;
            --countIn;
            delete temp;
        }
        break;
    case '0':
        if (headOut==NULL)
            cout << "\n## Queue kosong";
        else
        { 
            string command=headOut->cmd;
            node *temp=headOut->next;
            headOut=temp;
            --countOut;
            delete temp;
        }
        break;
    default:
        break;
    }
}

void printAll()
{
    cout << "\n## Queue Size : " << countIn;
    node *temp=new node;
    temp=headIn;
    int i=0;
    while(temp!=NULL)
    {
        cout << "\n## No Urut/index : " << i << ", Value :" << temp->cmd;
        temp=temp->next;
        i++;
    }
    delete temp;
}

void input()
{
    while (1) 
    {
        getline(cin, command);
        if (command == "")
        {
            break;
        }
        enqueue(command, 'i');
        cin.ignore(0);
    }
}

void mainProcess(){
    
}

void output(){

}