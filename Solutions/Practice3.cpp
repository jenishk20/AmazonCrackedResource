class Solution {
public:
	int dx[4] = { -1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	int visited[400][400];
	int r, c;
	bool valid(int x, int y, vector<vector<char>>& grid)
	{
		return x >= 0 && x < r && y >= 0 && y < c && visited[x][y] == 0 && grid[x][y] == '1';
	}
	void dfs(int x, int y, vector<vector<char>>& grid)
	{
		visited[x][y] = 1;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (valid(nx, ny, grid))
				dfs(nx, ny, grid);
		}
	}
	int numIslands(vector<vector<char>>& grid) {

		memset(visited, 0, sizeof(visited));
		int i;
		r = grid.size();
		c = grid[0].size();
		int j;

		int co = 0;
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				if (grid[i][j] == '1' && !visited[i][j])
				{
					co++;
					dfs(i, j, grid);
				}
			}
		}
		return co;
	}
};