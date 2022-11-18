// https://leetcode.com/problems/online-stock-span/

#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    int i;
    stack<int> st;
    vector<int> v;
    StockSpanner() {
        i=0;
        st.push(-1);
    }
    
    int next(int price) {
        v.push_back(price);
        while(st.size()>1 and v[st.top()]<=price){
            st.pop();
        }
        int span = i - st.top();
        st.push(i);
        i++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */