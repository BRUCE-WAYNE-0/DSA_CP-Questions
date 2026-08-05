class Solution {
public:
    bool recc(int i,vector<vector<int>> &adj,vector<int> &vis,vector<int> &sus){
        vis[i] = true;
        for(auto x : adj[i]){
            if(sus[x]) return false;
            if(!vis[x] && !recc(x,adj,vis,sus)) return false;
        }
        return true;
    } 

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> sus(n,0);
        queue<int> q;
        q.push(k);
        sus[k] = 1;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto x : adj[i]){
                if(!sus[x]){
                    sus[x] = 1;
                    q.push(x);
                }
            }
        }
        vector<int> vis(n,0);
        bool removed = true;
        for(int i = 0; i < n; i++){
            if(!sus[i] && !vis[i]){
                if(!recc(i, adj, vis, sus)){
                    removed = false;
                    break;
                }
            }
        }
        vector<int> ans;
        if(!removed){
            ans.resize(n);
            iota(ans.begin(),ans.end(),0);
        }else{
            for(int i=0;i<n;i++){
                if(!sus[i]) ans.push_back(i);
            }
        }

        return ans;

    }
};