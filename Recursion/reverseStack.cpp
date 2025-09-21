class Solution {
  private:
    void insertAtBottom(stack<int> &st, int el){
        // base case
        if(st.empty()){
            st.push(el);
            return;
        }
        // recursive call
        int top = st.top();
        st.pop();
        insertAtBottom(st,el);
        st.push(top);
        
    }
  public:
    void reverseStack(stack<int> &st) {
        // code here
        // base case
        if(st.empty()) return;
        
        // recursive call
        int top = st.top();
        st.pop();
        reverseStack(st);
        
        // insertion at bottom
        insertAtBottom(st,top);
    }   
};