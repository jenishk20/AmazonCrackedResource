class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        int i,j;
        int dis[r][c];
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                dis[i][j]=INT_MAX;
            }
        }
        queue<pair<int,int>>q;
        
       
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        int time=0;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            time=dis[x][y];
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                
                if(nx>=0 && ny>=0 &&nx<r && ny<c && grid[nx][ny]==1 && dis[nx][ny]==INT_MAX)
                {
                    dis[nx][ny]=1+time;
                    q.push({nx,ny});
                    grid[nx][ny]=2;
                }
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cout<<dis[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    return -1;
                //cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return time;
        
    }
};
