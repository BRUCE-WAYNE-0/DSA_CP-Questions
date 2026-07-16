class Solution {
    vector<int> rank;
    vector<int> Upar;
public:

    int FindUpar(int i){
        if(Upar[i] == i) return i;
        return Upar[i] = FindUpar(Upar[i]);
    }
    void Union_by_rank(int a,int b){
        int PA = FindUpar(a);
        int PB = FindUpar(b);

        if(rank[PA] < rank[PB]){
            Upar[PA] = PB;
        }else if(rank[PB] < rank[PA]){
            Upar[PB] = PA;
        }else{
            Upar[PB] = PA;
            rank[PA]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int s = stones.size();
        int maxRow = 0, maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        int n = maxCol + maxRow +2;
        rank.resize(n,0);
        Upar.resize(n);
        for(int i=0;i<n;i++) Upar[i] = i;
        unordered_set<int> nodes;
        for(auto it : stones){
            Union_by_rank(it[0],it[1]+maxRow+1);
            nodes.insert(it[0]);
            nodes.insert(it[1]+maxRow+1);
        }
        int cnt = 0;
        for(auto node : nodes){
            if(FindUpar(node)==node) cnt++;
        }

        return s-cnt;
    }
};