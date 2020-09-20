class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
        vector<int> answer;
        int rows = matrix.size();
        if(rows == 0)
            return answer;
        
        int cols = matrix[0].size();
        
        int rowStart = 0, rowEnd = rows-1;
        int colStart = 0, colEnd = cols-1;
        
        int total = rows*cols;
        int count = 0;
        
        while(rowStart <= rowEnd && colStart <= colEnd){
            
            for(int i = colStart; i <= colEnd && count < total; i++, count++)
                answer.push_back(matrix[rowStart][i]);
            rowStart++;

            
            for(int i = rowStart; i <= rowEnd && count < total; i++, count++)
                answer.push_back(matrix[i][colEnd]);
            colEnd--;

            for(int i = colEnd; i >= colStart && count < total; i--, count++)
                answer.push_back(matrix[rowEnd][i]);
            rowEnd--;
            
            for(int i = rowEnd; i >= rowStart && count < total; i--, count++)
                answer.push_back(matrix[i][colStart]);
            colStart++;
        }
        return answer;
    }
};
