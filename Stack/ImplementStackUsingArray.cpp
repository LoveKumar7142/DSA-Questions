#include <iostream>
using namespace std;

class Stack {
public:
    int tp = -1;
    int arr[6];
    void push (int x){
        if(tp>=5) {
            cout << "stack is full!"<<endl;
            return;
        }
        tp += 1;
        arr[tp] = x;
    }
    void pop(){
        if(tp == -1){
            cout<< "Stack is empty!"<<endl;
            return;
        }
        tp -= 1;
    }
    int top (){
        return tp == -1 ? -1 : arr[tp];
    }
    int size(){
        return tp + 1;
    }
    bool isEmpty(){
        return tp == -1;
    }
    bool isFull (){
        return tp == 5;
    }
    void display() {
        if(tp == -1) {
            cout<<"stack is empty!"<<endl; 
            return;
        }
        for(int i = tp;i>=0;i--)
            cout<< arr[i] << " ";
        cout <<endl;
    }
};

int main () {
    
    Stack obj;
    obj.push(10);
    obj.push(1);
    obj.push(540);
    obj.push(1045);
    obj.push(15);
    obj.push(18);
    cout<< obj.top() <<endl;
    obj.display();
    return 0;
}