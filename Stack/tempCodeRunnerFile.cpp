#include<bits/stdc++.h>
using namespace std;

//By making DeQueue Costly
class Queue1{
    public:
        stack <int> s1,s2;
        void enQueue(int data);
        void deQueue();
};


//By making Enqueue Costly
class Queue2{
    public:
        stack <int> s1,s2;
        void enQueue(int data);
        void deQueue();
};


void Queue1 :: enQueue(int data){
    s1.push(data);
}
void Queue1 :: deQueue(){
    if(s1.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        cout<<"Dequeue Item --> "<<s2.top()<<endl;
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
}

void Queue2 :: enQueue(int data){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(data);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}
void Queue2 :: deQueue(){
    if(s1.empty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"DeQueued element is"<<s1.top()<<endl;
    s1.pop();
}

int main(){
    int temp;
    cout<<"Want to use the queue where"<<endl;
    cout<<"1. EnQueue is costly or"<<endl;
    cout<<"2. DeQueue is costly"<<endl;
    cin>>temp;
    Queue1 q1;
    Queue2 q2;
    int x,data;
    while(x!=3){
        cout<<"Enter your choice: "<<endl;
        cout<<"1. EnQueue"<<endl;
        cout<<"2. DeQueue"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>x;
        switch(x){
            case 1: cout<<"Enter data to EnQueue"<<endl;
                    cin>>data;
                    if (temp ==1 ) q1.enQueue(data);
                    else q2.enQueue(data);
                    break;
            case 2: if (temp ==1 ) q1.deQueue();
                    else q2.deQueue();
                    break;
            case 3: cout<<"Bye"<<endl;
                    break;
            default: cout<<"Wrong Choice"<<endl;
        }
    }
}