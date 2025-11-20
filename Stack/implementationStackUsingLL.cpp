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



class Stack{
private:
    Node* topNode;
    int cnt;
    
public:
    Stack(){
        topNode = nullptr;
        cnt = 0;
    }

    void push(int x){
        Node* temp = new Node(x);   
        temp->next = topNode;
        topNode = temp;
        cnt = cnt+1;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int x = topNode->data;
        Node* del = topNode;
        topNode = topNode->next;
        delete del;
        return x;
    }

    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return topNode->data;
    }
    int size(){
        return cnt;
    }
    bool isEmpty(){
        return topNode == nullptr;
    }
};