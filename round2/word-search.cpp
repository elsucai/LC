class Solution {
public:
    
    bool helper(vector<vector<bool> > &visited, vector<vector<char> > &board, int i, int j, int m, int n, string word, int s, int e){
        if(s > e)
            return true;
        if(i < 0 || i >=m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[s])
            return false;
      
        visited[i][j] = true;
        bool ret = helper(visited, board, i, j-1, m, n, word, s+1, e) || helper(visited, board, i, j+1, m, n, word, s+1, e) || helper(visited, board, i+1, j, m, n, word, s+1, e) || helper(visited, board, i-1, j, m, n, word, s+1, e);
        if(!ret)
            visited[i][j] = false;
        return ret;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        if(word.empty())
            return true;
        if(board.empty())
            return false;
        int m = board.size();
        int n = board[0].size();
       
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(helper(visited, board, i, j, m, n, word, 0, word.size()-1))
                    return true;
            }
        }
        return false;
    }
};
