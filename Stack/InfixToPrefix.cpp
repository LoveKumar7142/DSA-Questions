class Solution {
private:
    int priority(char ch){
        return ch=='^' ? 3 :
               ch=='*' || ch=='/' ? 2 :
               ch=='+' || ch=='-' ? 1 :
               ch=='=' ? 0 : -1;
    }

public:
    string infixToPrefix(string &s) {
        stack<char> st;
        string ans = "";
        int n = s.size();
        reverse(s.begin(),s.end());
        for(char& c : s){
            if(c == ')') c = '(';
            else if(c == '(') c = ')';
        }
        
        for(int i = 0;i<n;i++){
            if(isalnum(s[i])){
                ans += s[i];
            }else if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }else{
                if(s[i] == '^'){
                    while(!st.empty() && priority(s[i]) <= priority(st.top())){
                        ans += st.top();
                        st.pop();
                    }
                }else{
                    while(!st.empty() && priority(s[i]) < priority(st.top())){
                        ans += st.top();
                        st.pop();
                    }
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};




class Solution {
private:
    int priority(char ch){
        return ch=='^' ? 3 :
               ch=='*' || ch=='/' ? 2 :
               ch=='+' || ch=='-' ? 1 :
               ch=='=' ? 0 : -1;
    }

public:
    string infixToPrefix(string &s) {

        stack<char> ops;
        stack<string> vals;

        for(char c : s){

            if(isalnum(c)){
                vals.push(string(1,c));
            }
            else if(c == '('){
                ops.push(c);
            }
            else if(c == ')'){
                while(!ops.empty() && ops.top() != '('){
                    char op = ops.top(); ops.pop();

                    string b = vals.top(); vals.pop();
                    string a = vals.top(); vals.pop();

                    vals.push(string(1,op) + a + b);
                }
                ops.pop();
            }
            else{ // operator

                while(!ops.empty() &&
                      ((priority(ops.top()) > priority(c)) ||
                       (priority(ops.top()) == priority(c) && c != '^')) &&
                      ops.top()!='(')
                {
                    char op = ops.top(); ops.pop();

                    string b = vals.top(); vals.pop();
                    string a = vals.top(); vals.pop();

                    vals.push(string(1,op) + a + b);
                }

                ops.push(c);
            }
        }

        while(!ops.empty()){
            char op = ops.top(); ops.pop();

            string b = vals.top(); vals.pop();
            string a = vals.top(); vals.pop();

            vals.push(string(1,op) + a + b);
        }

        return vals.top();
    }
};


