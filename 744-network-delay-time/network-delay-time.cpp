class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0 ;i<times.size();i++){
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            adj[s].push_back({d,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            int node = p.second;
            int d = p.first;
            if(d>dist[node]) continue;
            for(int i=0 ;i<adj[node].size(); i++){
                int neighbour = adj[node][i].first;
                int wt = adj[node][i].second;
                if(d+wt<dist[neighbour]){
                    dist[neighbour] = d+wt;
                    pq.push({d+wt,neighbour});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i=1 ;i<dist.size(); i++){
            maxi = max(maxi,dist[i]);
        }
        if(maxi == INT_MAX) return -1;
        return maxi;

    }
};