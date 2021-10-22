#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> adj;
public:
    unordered_set<int> s;
    int dia=0;
    int dfs(int u)
    {
        s.erase(u);
        int max1=0,max2=0;
        for(int v:adj[u])
        {
            if(s.find(v)!=s.end())
            {
               int t = dfs(v);
                if(t>max2)
                {
                    if(t>max1)
                        max2=max1,max1=t;
                    else
                        max2=t;
                }
            }
        }
        dia=max(dia,max1+max2);
        return max(max1,max2)+1;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n+1);
        vector<int> res(n+1,0);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);adj[v].push_back(u);
        }
        // generating all subsets
        for(int i=1;i<(1<<n);i++)
        {
            s.clear();
            for(int j=0;(1<<j)<=i;j++)
            {
                if(i&(1<<j))
                    s.insert(j+1);
            }
            if(s.size()<=1)
                continue;
            dia = 0;
            // dfs is for checking if this subset is a valid subtree or not along with finding the max dist btn two nodes
            dfs(*s.begin());
            // checking s.size() is for checking subtree is valid or not if s.size()!=0 means i was not able to travers throuh all nodes of subset
            if(s.size()==0)
                res[dia]++;
        }
        
        return res;
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> edges={{1,2},{2,3},{2,4}};
    int n=4;
    sol.countSubgraphsForEachDiameter(n,edges);
    return 0;
}