class disjointset{
    public:
    vector<int>size,parent;
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findpar(int node){
        if(parent[node]==node){
            return node;

        }
        return parent[node]=findpar(parent[node]);
    }
    void unions(int u,int v){
        int ul_u=findpar(u);
        int ul_v=findpar(v);
        if(ul_u==ul_v) return ;
        if(size[ul_u]<size[ul_v]){
            size[ul_v]+=size[ul_u];
            parent[ul_u]=ul_v;
        }
        else{
            parent[ul_v]=ul_u;
             size[ul_u]+=size[ul_v];
        }
        return ;
    }
};
class Solution {
    private:
    bool isvalid(int newr,int newc,int n){
        return newr>=0&&newr<n&&newc>=0&&newc<n;
    }
public:

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        disjointset d(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int idx=0;idx<4;idx++){
                    int newr=i+dr[idx];
                    int newc=j+dc[idx];
                    if(isvalid(newr,newc,n)&&grid[newr][newc]){
                        int nodeno=i*n+j;
                        int adjno=newr*n+newc;
                        d.unions(nodeno,adjno);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int>components;
                if(grid[i][j]==1) continue;
                for(int idx=0;idx<4;idx++){
                    int newr=i+dr[idx];
                    int newc=j+dc[idx];


                    if(isvalid(newr,newc,n)&&grid[newr][newc]){
                        components.insert(d.findpar(newr*n+newc));
                    }
                }
                int sizes=0;
                for(auto it:components){
                    sizes+=d.size[it];
                }
                mx=max(mx,sizes+1);
            }
        }
        for(int cellno=0;cellno<n*n;cellno++){
            mx=max(mx,d.size[d.findpar(cellno)]);
        }
        return mx;
        
    }
};