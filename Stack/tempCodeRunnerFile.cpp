#include<bits/stdc++.h>
using namespace std;
class Queue1{
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

int main(){
    Queue1 q1;
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
                    q1.enQueue(data);
                    break;
            case 2: q1.deQueue();
                    break;
            case 3: cout<<"Bye"<<endl;
                    break;
            default: cout<<"Wrong Choice"<<endl;
        }
    }
}