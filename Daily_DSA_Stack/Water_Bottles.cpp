// brute force Approach
// tc = O(n)
// sc = O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consume = 0;
        while(numBottles>=numExchange){
            consume += numExchange;

            numBottles -= numExchange;

            numBottles += 1;
        }
        return consume + numBottles;
    }
};

// Better Approach

// tc = O(log(n))
// sc = O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consume = numBottles;
        int emp_bottles = numBottles;

        while(emp_bottles >= numExchange){
            int extra_full_bot = emp_bottles / numExchange;

            int remain = emp_bottles % numExchange;

            consume += extra_full_bot;
            emp_bottles = extra_full_bot + remain;

        }
        return consume;
    }
};


// Best Approach 
// TC = O(1)
// SC = O(1)

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + ((numBottles - 1)/(numExchange - 1));
    }
};