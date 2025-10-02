class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int consume = numBottles;
        int emp_bottles = numBottles;
        while(emp_bottles >= numExchange){
            emp_bottles = emp_bottles - numExchange + 1;
            numExchange ++; 
            consume ++;
        }
        return consume;
    }
};