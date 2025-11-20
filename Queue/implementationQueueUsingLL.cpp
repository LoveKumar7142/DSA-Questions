#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Queue{
private:
    Node* front;
    Node* end;
    int cnt;
public:
    Queue(){
        front = nullptr;
        end = nullptr;
        cnt = 0;
    }

    void push(int x){
        Node* temp = new Node(x);
        if(front == nullptr){
            front = temp;
            end = temp;
        }else{
            end->next = temp;
            end = temp;
        }
        cnt++;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        int x = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        cnt--;
        if(cnt== 0){
            end = nullptr;
        }
        return x; 

    }
    int peek(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        return cnt ==0;
    }
    int size(){
        return cnt;
    }
};