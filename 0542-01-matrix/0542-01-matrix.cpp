class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); // Get the number of rows in the matrix
        int n = mat[0].size(); // Get the number of columns in the matrix
        
        // Create a result matrix of the same size as 'mat' and initialize all cells to maximum value
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        queue<pair<int, int>> q; // Create a queue to store cell coordinates
        
        // Initialize the queue with 0 cells and mark them as visited by setting distance to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j}); // Add cell coordinates to the queue
                }
            }
        }
        
        // Define the possible movements to adjacent cells (up, down, left, right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS loop: process each cell in the queue
        while (!q.empty()) {
            pair<int, int> cell = q.front(); // Get the front cell from the queue
            q.pop(); // Remove the front cell from the queue
            
            // Iterate through all possible directions
            for (const auto& dir : directions) {
                int newRow = cell.first + dir.first; // Calculate the new row coordinate
                int newCol = cell.second + dir.second; // Calculate the new column coordinate
                
                // Check if the new coordinates are within matrix boundaries
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    // Check if the distance to the new cell can be reduced
                    if (result[newRow][newCol] > result[cell.first][cell.second] + 1) {
                        // Update the distance to the new cell and add it to the queue for further processing
                        result[newRow][newCol] = result[cell.first][cell.second] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        
        return result; // Return the matrix with updated distances
    }
};