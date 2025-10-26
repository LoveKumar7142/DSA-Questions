// User function Template for C++
Best way
class Solution {
  public:
    void sieve() {
    }

    vector<int> findPrimeFactors(int N) {
        vector<int> ans;
        
        for(int i = 2;i*i<=N;i++){
            while(N%i == 0){
                ans.push_back(i);
                N/=i;
            }
        }
        if(N>1) ans.push_back(N);
        
        return ans;
    }
};




Normal way

// User function Template for C++

class Solution {
  public:
    void sieve() {
    }

    vector<int> findPrimeFactors(int N) {
        vector<int> ans;
        
        // Step 1: Create sieve
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = false;
            }
        }
        
        // Step 2: Check each prime if it divides N
        for (int i = 2; i <= N; i++) {
            if (isPrime[i]){
                while( N % i == 0){
                    ans.push_back(i);
                    N /= i;
                }
            }
        }
        
        return ans;
    }
};