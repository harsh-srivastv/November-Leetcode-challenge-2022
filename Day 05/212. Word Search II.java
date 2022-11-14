// import java.util.HashMap;

// // https://leetcode.com/problems/word-search-ii/

// class Solution {
//     class Trie{
//         char c;
//         boolean word = false;
//         String w;
//         map<Character, Trie> children = new hashmap<>();
//     }
//     void add(String s){
//         Trie dummy = root;
//         for(char c: s.toCharArray()){
//             if(!dummy.children.containsKey(c)){
//                 dummy.children.put(c, new Trie());
//             }
//             dummy = dummy.children.get(c);
//         }
//         dummy.word = true;
//         dummy.w = s;
//     }
//     Trie root = new Trie();
//     public List<String> findWords(char[][] board, String[] words) {
//         root.c = '*';
//         for(String w: words)
//             add(w);
        
//         Set<String> result = new HashSet<>();
//         for(int i=0; i<board.length; i++){
//             for(int j=0; j<board[0].length; j++){
//                 backtrack(result, board, root, i, j);
//             }
//         }
//         return new ArrayList<>(result);
//     }
//     int[][] coord = new int[][]{{0,1},{0,-1},{1,0},{-1,0}};
//     void backtrack(Set<String> list, char[][] board, Trie trie, int i, int j){
//         if(i < 0 || j < 0) return;
//         if(i >= board.length || j >= board[0].length) return;
//         if(!trie.children.containsKey(board[i][j])) return;
//         trie = trie.children.get(board[i][j]);
//         if(trie.word) list.add(trie.w);
//         char temp =  board[i][j];
//         board[i][j] = '*';
//         for(int[] c: coord){
//             backtrack(list, board, trie, i+c[0], j+c[1]);
//         }
//         board[i][j] = temp;
//     }

// }