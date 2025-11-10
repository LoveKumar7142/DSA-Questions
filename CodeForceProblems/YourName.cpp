#include<iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    bool yourName(string& s, string& t){
        if(s.size() != t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin>>T)) return 0;
    
    Solution obj;
    while(T--){
        int size;
        string s,t;
        cin>>size>>s>>t;
        cout<<(obj.yourName(s,t)?"Yes":"No")<<endl;
    }
    return 0;
}