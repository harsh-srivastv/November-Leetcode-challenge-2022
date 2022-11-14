// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class DisjoinSet{
    List<Integer> size = new ArrayList<>();
    List<Integer> parent = new ArrayList<>();
    
    DisjoinSet(int n){
        for(int i=0; i<n+1; i++){
            size.add(1);
            parent.add(i);
        }
    }
    
    int findUPar(int node){
        if(node == parent.get(node)) return node;
        
        int ulp = findUPar(parent.get(node));
        parent.set(node, ulp);
        
        return parent.get(node);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size.get(ulp_u) < size.get(ulp_v)){
            parent.set(ulp_u, ulp_v);
            size.set(ulp_v, size.get(ulp_v) + size.get(ulp_u));
        }
        else{
            parent.set(ulp_v, ulp_u);
            size.set(ulp_u, size.get(ulp_u) + size.get(ulp_v));
        }
    }
}


class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        
        int maxRow = 0;
        int maxCol = 0;
        for(int[] it : stones){
            maxRow = Math.max(maxRow, it[0]);
            maxCol = Math.max(maxCol, it[1]);
        }
        
        DisjoinSet ds = new DisjoinSet(maxRow + maxCol + 1);
        
        for(int[] it : stones){
            int rowNo = it[0];
            int colNo = it[1] + maxRow + 1;
            
            ds.unionBySize(rowNo, colNo);
        }
        
        int cnt = 0;
        for(int i=0; i<maxRow + maxCol + 1; i++){
            if(ds.findUPar(i) == i && ds.size.get(i) > 1){
                cnt++;
            }
        }
        
        return n - cnt;
    }
}