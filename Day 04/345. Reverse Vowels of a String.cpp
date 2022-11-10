// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char i){
        return i=='a' || i=='e' || i=='i' || i=='o' || i=='u' || i=='A' || i=='E' || i=='I' || i=='O' || i=='U';
    }
    string reverseVowels(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!isVowel(s[i])){
                i++;
            }
            else if(!isVowel(s[j])){
                j--;
            }
        }
        return s;
    }
};