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
    cout << "\n## Queue Size : " << vip1_count;
    nodePerson *temp = new nodePerson;
    temp=headVip1;
    int i=0;
    while(temp!=NULL)
    {
        cout << "\n## No Urut/index : " << i << ", Name : " << temp->nama;
        temp=temp->next;
        i++;
    }
    delete temp;
}

void input()
{
    int i = 0;
    while (1) 
    {
        getline(cin, command);
        if (command == "")
        {
            break;
        }
        command.append(" " + i);
        enqueue(command, 'i');
        cin.ignore(0);
        i++;
    }
}

void mainProcess(){
    node *temp = new node;
    temp = headIn;
    int i = 0;
    while (temp != NULL) 
    {
        procCommand(temp->cmd);
        temp = temp->next;
        // dequeue('i');
        i++;
    }
}

int getLenText(string txt, string delim = " "){
    int count = 0;
    string text = txt;
    size_t pos = 0;
    while ((pos = text.find(delim)) != std::string::npos)
    {
        count++;
        text.erase(0, pos + delim.length());
    }
    return count;
}

vector<string> getWords(string s, string delim){
    vector<string> res;
    int pos = 0;
    while(pos < s.size()){
        pos = s.find(delim);
        res.push_back(s.substr(0,pos));
        s.erase(0,pos+delim.length());
    }
    return res;
}

void addVip(nodePerson *temp, int type){
    switch (type) {
    case 1:
        if (vip1_count == vip)
        {
            break;
        }
        if (headVip1 == NULL)
        {
            headVip1 = temp;
            tailVip1 = temp;
            temp = NULL;
        }
        else
        {
            tailVip1->next = temp;
            tailVip1 = temp;
        }
        vip1_count++;
        break;
    case 2:
        if (vip1_count == vip)
        {
            break;
        }
        if (headVip2 == NULL)
        {
            headVip2 = temp;
            tailVip2 =temp;
            temp = NULL;
        }
        else
        {
            tailVip2->next = temp;
            tailVip2 = temp;
        }
        vip2_count++;
        break;
    default:
        break;
    }
}

void addCom(nodePerson *temp){

}

void registerPerson(vector<string> cmd){
    nodePerson *temp = new nodePerson;
    temp->nama = cmd[1];
    temp->rate = atoi(cmd.at(2).c_str());
    temp->age = atoi(cmd.at(3).c_str());
    temp->tensi = cmd[4];
    cout << temp->nama << endl;
    if (temp->rate >= 9 && temp->rate <= 10 ){
        addVip(temp, 1);
    }else if (temp->rate >= 7 && temp->rate <= 8){
        addVip(temp, 2);
    }else if(temp->rate >= 1 && temp->rate <= 6){
        addCom(temp);
    }else{
        cout << "ERROR param register" << endl;
    }
    delete temp;
}

void procCommand(string cmd){
    vector<string> words = getWords(cmd, " ");
    string command = words[0];

    if (command == "REGISTER")
    {
        cout << "Register" << endl;
        registerPerson(words);
    }else if (command == "RESIZE")
    {
        cout << "Resize" << endl;
    }else if (command == "INJECT")
    {
        cout << "Inject" << endl;
    }else if (command == "SKIP")
    {
        cout << "Skip" << endl;
    }else if (command == "PRINT_MANIFEST")
    {
        cout << "Print" << endl;
    }else if (command == ""){
        cout << "Unknown" << endl;
    }else{
        vip = atoi(words.at(0).c_str());
        com = atoi(words.at(1).c_str());
        cout << "test: " << words[1] << endl;
    }
}

void output(){
    vip = 2;
    procCommand("REGISTER afta 9 20 120/70");
}