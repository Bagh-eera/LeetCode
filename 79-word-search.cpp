class Solution {
public:
    int rows;
    int cols;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int idx){
        if(idx >= word.size())
            return true;
        if(i < 0 || j < 0 || i == rows || j == cols || word[idx] != board[i][j])
            return false;
        
        board[i][j] = '#';
        bool ret = false;
        for(int d = 0; d < 4; d++){
            ret = backtrack(board, word, i+dx[d], j+dy[d], idx+1);
            if(ret)
                break;
        }
        board[i][j] = word[idx];
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(backtrack(board, word, i, j, 0))
                    return true;
        return false;
    }
};
