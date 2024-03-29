void dfs(vector<vector<int>> &image, int row, int col, int newColor, int initialColor,
         vector<vector<int>> &ans, vector<int> &delRow, vector<int> &delCol)
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int r = row + delRow[i];
        int c = col + delCol[i];
        if (r >= 0 && r < n && c >= 0 && c < m && image[r][c] == initialColor && ans[r][c] != newColor)
            dfs(image, r, c, newColor, initialColor, ans, delRow, delCol);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int initialColor = image[sr][sc];
    vector<vector<int>> ans = image;
    vector<int> delRow = {-1, 0, +1, 0};
    vector<int> delCol = {0, +1, 0, -1};
    dfs(image, sr, sc, newColor, initialColor, ans, delRow, delCol);
    return ans;
}