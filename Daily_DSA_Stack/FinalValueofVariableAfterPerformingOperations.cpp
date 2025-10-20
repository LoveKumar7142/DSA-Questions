class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt = 0;
        for(auto& word : operations){
            if(word == "X++") cnt++;
            else if(word == "++X") ++cnt;
            else if(word == "--X") --cnt;
            else cnt--;
        }
        return cnt;
    }
};