#include <iostream>
using namespace std;

class Q {
    int arr[6];
    int start = -1;
    int end = -1;
    int curr;

    void push(int x){
        if(curr == 6){
            cout<<"Queue is Full";
        }
        if(curr == 0){
            end = 0;
            start = 0;
        }
        else
            end = (end+1)%6;
        arr[end] = x;
        curr++;
    }
    void pop(){
        if(curr == 0) cout<< "Queue is empty"<<endl;
        // int el = arr[start];
        if(curr == 1){
            start = end = 1;
        }
        else{
            start = (start+1)%6;
        }
        curr-=1;

    }

    int top(){
        if(curr == 0) cout<< "Queue is empty"<<endl;
        return arr[start];
    }
    int size(){
        return curr;
    }

};

