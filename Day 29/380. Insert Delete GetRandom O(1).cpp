// https://leetcode.com/problems/insert-delete-getrandom-o1/

#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)){
            return false;
        }
        arr.push_back(val);
        mp[val] = arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int index = mp[val];
            int value = arr.back();
            arr[index] = value;
            mp[value] = index;
            arr.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int index = rand()%arr.size();
        return arr[index];
    }
};