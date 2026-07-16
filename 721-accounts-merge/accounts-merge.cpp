class DSU {
    vector<int> rank,Upar;
public:
    DSU(int n){
        Upar.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            Upar[i] = i;
        }
    }

    int FindUpar(int i){
        if(Upar[i] == i) return i;
        return Upar[i] = FindUpar(Upar[i]);
    }

    void UnionByRank(int a, int b){
        int PA = FindUpar(a);
        int PB = FindUpar(b);

        if(PA == PB) return;
        if(rank[PA] < rank[PB]){
            Upar[PA] = PB;
        }else if(rank[PB] < rank[PA]){
            Upar[PB] = PA;
        }else{
            Upar[PB] = PA;
            rank[PA]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string,int> mp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i; 
                }else{
                    ds.UnionByRank(mp[accounts[i][j]],i);
                }
            }
        }
        vector<string> merge[n]; 
        for(auto it : mp){
            string mail = it.first;
            int acc = ds.FindUpar(it.second);

            merge[acc].push_back(mail);
        }
        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(merge[i].size() == 0) continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};