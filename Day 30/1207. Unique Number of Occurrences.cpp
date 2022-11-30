// https://leetcode.com/problems/unique-number-of-occurrences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> s;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(auto x:mp){
            s.insert(x.second);
        }
        
        if(s.size() == mp.size()){
            return true;
        }
        return false;
    }
};