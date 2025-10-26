class Solution {
  public:
    void print_divisors(int n) {
        set<int> divisors;  // stores divisors in sorted order automatically
        
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.insert(i);
                divisors.insert(n / i);
            }
        }
        
        // print all elements of set
        for (int d : divisors)
            cout << d << " ";
    }
};


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void print_divisors(int n) {
        set<int> divisors;
        
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.insert(i);
                divisors.insert(n / i);
            }
        }
        
        // print all elements of the set
        for (int d : divisors)
            cout << d << " ";
    }
};


class Solution {
  public:
    void print_divisors(int n) {
        int i;
        // First loop: print smaller divisors
        for (i = 1; i * i <= n; i++) {
            if (n % i == 0)
                cout << i << " ";
        }

        // Second loop: print larger divisors in reverse order
        i--; // because last i*i > n
        for (; i >= 1; i--) {
            if (n % i == 0 && n / i != i)
                cout << n / i << " ";
        }
    }
};



class Solution {
  public:
    void print_divisors(int n) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                cout << i << " ";
        }
    }
};





