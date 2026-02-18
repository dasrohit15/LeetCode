class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //first finding the transposed matrix
        for (int i = 0; i<n-1; i++){           //i = 0 to n-2
            for (int j = i+1; j<n; j++){       // j= i+1 to n-1  
                swap(matrix[i][j], matrix[j][i]);
            }      
        }

        //reversing the each row of transposed matrix
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
};