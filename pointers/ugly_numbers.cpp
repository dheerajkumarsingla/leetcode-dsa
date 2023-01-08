// https://leetcode.com/problems/super-ugly-number
#define ll long long int
class Solution {
public:
    int getPrimeNumberIndex(vector<int> &primes, vector<ll> &multiplierIndex, vector<ll> &uglyNumbers) {
        int currentIndex = 0;
        for(int i=1;i<primes.size(); i++) {
            if(uglyNumbers[multiplierIndex[currentIndex]]*primes[currentIndex] > uglyNumbers[multiplierIndex[i]]*primes[i]) {
                currentIndex = i;
            }
        }
        return currentIndex;
    }
    ll getNthUglyNumber(vector<ll> &uglyNumbers,vector<ll> &multiplierIndex, int n, vector<int> &primes) {
        if(uglyNumbers.size() == n) {
            return uglyNumbers[n-1];
        }
        int primeNumberIndex = getPrimeNumberIndex(primes, multiplierIndex, uglyNumbers);
        if(uglyNumbers[uglyNumbers.size()-1] < primes[primeNumberIndex]*uglyNumbers[multiplierIndex[primeNumberIndex]]) {
            uglyNumbers.push_back(primes[primeNumberIndex]*uglyNumbers[multiplierIndex[primeNumberIndex]]);
        }
        multiplierIndex[primeNumberIndex] = multiplierIndex[primeNumberIndex] + 1;
        return getNthUglyNumber(uglyNumbers, multiplierIndex, n, primes);
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        int numberOfPrimes = primes.size();
        vector<ll> uglyNumbers({1});
        vector<ll> multiplierIndex(numberOfPrimes, 0);

        ll ans = getNthUglyNumber(uglyNumbers, multiplierIndex, n, primes);

        return (int)ans;
    }
};