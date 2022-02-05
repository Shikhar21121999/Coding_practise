#include <bits/stdc++.h>
using namespace std;

// Brute force Approach
/*
Brute force approach is to check for each character in string s
and count freq of it in s and in t, compare them and see if condition
is not voilated if at any point get voilated we return NO else YES
TC => O(N^2)
SC = O(1)
*/

// Optimized Approach => Use 2 HashMap (less optimized and More Code required)
/*
use 1 hashMap to count frequency of characters in S
second one to count frequency of characters in t,
compare if characters frequency condition is not voilated 
(Tell if you need implementation for this)
TC => O(N)
SC => O(N^2) 
*/

// Optimized Approach => Use 1 hashMap (Optimized)
/*
Main observation is that we need to find relative difference for characters
in s and t
So we use a single hashMap for characters in s we increment count
for characters in t we decrement count
At the end for each character in string s and t we will have relative frequency
Check if abs value is atleast k for all
*/

// Possible Optimization in previous
/*
We can use an array as a hashMap and use its index for counting,
we will track characters frequency as
relFreq[ch - 'a'] ++ or relFreq[ch - 'a']--
*/
// Single HashMap implementation 
string similarString(int n, int m, string s, string t, int k) {
    // hashMap of pair char and int to store relative Frequency
    // of each character
    unordered_map <char, int> relFreq;

    // incrementing freq for characters of s
    for (auto ch: s) {
        relFreq[ch]++;
    }
    // decrementing freq for characters of t
    for (auto ch: t) {
        relFreq[ch]--;
    }

    // traverse hashMap and ensure abs(relFreq) for each char <=k
    // in cpp implementation hashMap is stored as a container of pair
    // here we traverse these pair of <char, int>
    // first element is acessed as .first and second as .second
    // we ensure that abs(second) <= k for every pair
    for (pair <char, int> chFreqPair: relFreq) {
        // cout << chFreqPair.first << " " << chFreqPair.second << endl;
        if (abs(chFreqPair.second) > k) {
            return "NO";
        }
    }
    return "Yes";
}

int main () {
    string s = "xyzzzbbbbbxx";
    string t = "bxy";
    int k = 3;
    cout << similarString(s.length(), t.length(), s, t, k);
}