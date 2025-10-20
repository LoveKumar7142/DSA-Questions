class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) throw runtime_error("Divide by 0");
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long divi = llabs((long long)dividend);
        long long div = llabs((long long)divisor);

        long long ans = 0;

        while(divi >= div){
            long long temp = div;
            long long multiple = 1;
            while((temp << 1) <= divi){
                temp <<= 1;
                multiple <<= 1;
            }

            divi -= temp;
            ans += multiple;
        }

        return negative ? -ans : ans;
    }
};
