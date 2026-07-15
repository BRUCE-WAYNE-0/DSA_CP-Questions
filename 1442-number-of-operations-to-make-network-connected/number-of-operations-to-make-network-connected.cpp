class DSU{
    vector<int> Upar;
    vector<int> rank;
    int disconn_comp;
    int extra_cables;
public:
    DSU(int n){
        disconn_comp = n;
        extra_cables = 0;
        Upar.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++) Upar[i] = i;
    }

    int FindUpar(int i){
        if(Upar[i] == i) return i;
        return Upar[i] = FindUpar(Upar[i]);
    }

    void Union_by_rank(int a,int b){
        int PA = FindUpar(a);
        int PB = FindUpar(b);

        if(PA == PB){
            extra_cables++;
            return ;
        }

        disconn_comp--;

        if(rank[PA] < rank[PB]){
            Upar[PA] = PB;
        }else if(rank[PB] < rank[PA]){
            Upar[PB] = PA;
        }else{
            Upar[PB] = PA;
            rank[PA]++;
        }
    }
    int Not_Connected(){
        return disconn_comp;
    }

    int Cables(){
        return extra_cables;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        DSU ds(n);
        for(auto it : connections){
            ds.Union_by_rank(it[0],it[1]);
        }
        int extra_cables = ds.Cables();
        int disconn_comp = ds.Not_Connected();

        if(disconn_comp == 1) return 0;

        if(extra_cables >= disconn_comp-1) return disconn_comp-1;
        else return -1;
    }
};