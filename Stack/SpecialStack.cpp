#include<bits/stdc++.h>
using namespace std;
class SpecialStack{
    public: 
        stack<int> stk , auxStk;
        int pop();
        void push(int data);
        bool isEmpty();
        int getMin();
};

int SpecialStack :: pop(){
    if(stk.empty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    int val = stk.top();
    stk.pop();
    auxStk.pop();
    return val;
}
void SpecialStack :: push(int data){
    if(stk.empty()){
        stk.push(data);
        auxStk.push(data);
        return;
    }
    int auxTop = auxStk.top();
    if(data > auxTop){
        auxStk.push(auxTop);
        stk.push(data);
    }
    else{
        auxStk.push(data);
        stk.push(data);
    }
}
bool SpecialStack :: isEmpty(){
    return stk.empty();
}

int SpecialStack :: getMin(){
    if(stk.empty()){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return auxStk.top();
}

int main(){
    SpecialStack s;
    int x,val;

    while(x!=5){
        cout<<"Enter your choice:"<<endl;
        cout<<"1. Push in stack"<<endl;
        cout<<"2. Pop from stack"<<endl;
        cout<<"3. Check if stack is empty"<<endl;
        cout<<"4. Get minimum element of Stack"<<endl;
        cin>>x;
        switch(x){
            case 1: 
                    cout<<"\tEntervalue to push"<<endl;
                    cin>>val;
                    s.push(val);
                    break;
            case 2:
                    val = s.pop();
                    if(val!= -1) cout<<"\tPoped value:"<<val<<endl;
                    break;
            case 3:
                    if(s.isEmpty()) cout<<"\tEmpty"<<endl;
                    else cout<<"\tNot empty";
                    break;
            case 4:  
                    val = s.getMin();
                    if(val !=-1) cout<<"\tMinimum element: "<<val<<endl;
                    break;
            case 5:
                    cout<<"Bye"<<endl;
                    break;
            default:
                    cout<<"\tEnter a correct choice"<<endl;
        }
    }
}

