// https://leetcode.com/problems/divide-two-integers/description/
#define ll long long int
class Solution {
public:
    int divide(int dividend, int divisor) {
        // false means positive and true means negative
        bool sign = (dividend >= 0 ^ divisor >=0); 
        ll divis = abs((ll)divisor);
        ll remainingDivi = abs((ll)dividend);
        ll q = 0;
        ll currentBitCheck = 31;

        while(currentBitCheck >= 0) {
            ll val = ((ll)1<<currentBitCheck);
            if(remainingDivi - divis*((ll)1<<currentBitCheck) >= 0) {
                remainingDivi = remainingDivi - divis*((ll)1<<currentBitCheck);
                q += ((ll)1<<currentBitCheck);
            }
            currentBitCheck--;
        }
        q = sign == true? (-1)*q: q;
        q = q > INT_MAX? INT_MAX: q;
        q = q < INT_MIN? INT_MIN: q;
        return q;
    }
};