// brute force approach
// tc = O(n*k*log(K))
class Solution {
private:
    bool isAnagram(string a, string b){
        if(a.size() != b.size()) return false;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        for(auto& word : words){
            if(res.empty() || !isAnagram(res.back(),word)){
                res.push_back(word);
            }
        }
        return res;
    }
};

// Best Approach
// tc = O(n*k)
class Solution {
public:
    string getSignature(const string& s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        // Convert frequency vector into a unique string signature
        string signature;
        for (int f : freq) {
            signature += to_string(f) + "#";  // "#" separates counts
        }
        return signature;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string lastSignature = "";

        for (auto &word : words) {
            string currentSignature = getSignature(word);
            if (result.empty() || currentSignature != lastSignature) {
                result.push_back(word);
                lastSignature = currentSignature;
            }
        }
        return result;
    }
};