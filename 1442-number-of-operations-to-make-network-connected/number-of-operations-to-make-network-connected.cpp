class Solution {
public:
    vector<int> parent;
    int find(int a)
    {
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void union_set(int a, int b)
    {
        int parent_A = find(a);
        int parent_B = find(b);
        if(parent_A != parent_B)
        {
            parent[parent_B] = parent_A;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int m = connections.size();
        if(m < n -1)
        {
            return -1;
        }
        parent.resize(n);
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        int components = n;
        for(auto &edge : connections)
        {
            int u = edge[0];
            int v = edge[1];

            if(find(u) != find(v))
            {
                union_set(u,v);
                components--;
            }
        }
        return components-1;
    }
};