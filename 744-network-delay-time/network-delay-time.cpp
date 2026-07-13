class Solution {
public:
    using pi = pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pi,vector<pi>,greater<pi>> q;
        q.push({0,k});
        vector<int> dist(n+1,1e9);
        dist[k] = 0;

        while(!q.empty()){
            auto p = q.top();
            q.pop();
            int cost = p.first;
            int node = p.second;
            if(cost > dist[node]) continue;

            for(auto it : adj[node]){
                if(cost + it.second < dist[it.first]){
                    dist[it.first] = cost+it.second;
                    q.push({cost+it.second,it.first});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<n+1;i++) maxi = max(maxi,dist[i]);

        if(maxi == 1e9) return -1;
        return maxi;
    }
};