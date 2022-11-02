// https://leetcode.com/problems/where-will-the-ball-fall/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int curr_pos, next_pos;
        vector<int> ans;
        
        for(int c=0; c<col; c++){
            curr_pos = c;
            next_pos = -1;
            for(int r=0; r<row; r++){
                next_pos = curr_pos + grid[r][curr_pos];
                if(next_pos < 0 || next_pos >= col || grid[r][curr_pos] != grid[r][next_pos]){
                    curr_pos = -1;
                    break;
                }
                curr_pos = next_pos;
            }
            ans.push_back(curr_pos);
        }
        return ans;
    }
};