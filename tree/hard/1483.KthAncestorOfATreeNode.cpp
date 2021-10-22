// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
#include<bits/stdc++.h>
using namespace std;
class TreeAncestor {
    vector<vector<int>> up;
    int LOG=0;
    vector<int> depth;
public:
    TreeAncestor(int n, vector<int>& parent) {
        // finding log of n
        while((1<<LOG)<=n)
            LOG++;
        // building the ancestors of every node which are at power of 2s
        up = vector<vector<int>>(n,vector<int>(LOG,-1));
        depth = vector<int>(n,-1);
        depth[0]=0;
        for(int j=0;j<n;j++)
            up[j][0]=parent[j];
        for(int i=1;i<LOG;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(depth[j]==-1&&depth[parent[j]]!=-1)
                    depth[j] = depth[parent[j]]+1;
                // to see 8th ancestor go to 4th ancestor and to his 4th ancestor
                if(up[j][i-1]!=-1)
                up[j][i] = up[up[j][i-1]][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        // cheking if kth ancestor exists or not
        if(k>depth[node])
            return -1;
        for(int j=0;j<LOG;j++)
            if(k&(1<<j))
                node = up[node][j];
        return node;
        
    }
};