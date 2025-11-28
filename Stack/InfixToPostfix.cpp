class Solution {
  private:
    int priority(char ch){
        return ch == '^' ? 3 : ch == '*' || ch == '/' ? 2 : ch == '-' || ch == '+' ? 1 : ch == '='?0:-1;
    }
  public:
    string infixToPostfix(string& s) {
        // code here
        int i = 0;
        stack<char>st;
        string ans = "";
        int n = s.size();
        
        while(i<n){
            // if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            //     ans += s[i];
            // }
            if(isalnum(s[i])){
                ans+=s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }else{
                if(!st.empty() && ((st.top() == '=' && s[i] == '=') || (st.top() == '^' && s[i] == '^'))){
                    st.push(s[i]);
                }else{
                    while(!st.empty() && priority(s[i]) <= priority(st.top())){
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
