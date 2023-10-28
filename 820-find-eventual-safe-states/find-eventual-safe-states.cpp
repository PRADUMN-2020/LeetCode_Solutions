class Solution {
public:
    void dfs(vector<int>&visited,vector<vector<int>>&al,int u)
    {
        visited[u]=1;
        for(int i=0;i<al[u].size();i++)
        {
            if(visited[al[u][i]]==0)
            {
                dfs(visited,al,al[u][i]);
                if(visited[al[u][i]]==-1)
                {
                   visited[u]=-1;
                    return;
                }
            }
            else if(visited[al[u][i]]!=2)
            {
                visited[u]=-1;
                return;
            }
        }
        visited[u]=2;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Time:O(n)  Space:O(n)
        int n=graph.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                dfs(visited,graph,i);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};