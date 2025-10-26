class Solution {
public:
    int countPrimes(int n) {
        if(n <=2) return 0;
        vector<bool> arr(n,true);
        arr[0] = arr[1] = false;
        for(int i = 2;i*i<n;i++){
            if(!arr[i]) continue; 
            for(int j = i*i;j<n;j+=i){
                arr[j] = false;
            }
        }
        
        return count(arr.begin()+2,arr.end(),true);
    }
};
