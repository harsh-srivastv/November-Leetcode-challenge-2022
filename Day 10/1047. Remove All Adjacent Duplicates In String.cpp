// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans = "";
        
        for(int i=0; i<s.size(); i++){
            if(st.empty() || s[i] != st.top()){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        
        while(!st.empty()){
            char ele = st.top();
            st.pop();
            ans = ele + ans;
        }
        
        return ans;
    }
};