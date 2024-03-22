#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
vector<pair<int,int> > adj[N];
int par[21][N],pset[N],up[21][N],high[N],ans[N];
bool visited[N];
struct dAtA{
	int w,u,v,id;
};
dAtA edge[N];
bool cmp(dAtA &a,dAtA &b){
	return a.w<b.w;
}
void init(int n){
	for(int i=0;i<=n;i++){
		pset[i]=i;
	}
}
int find(int x){
	if(x==pset[x]) return pset[x];
	pset[x]=find(pset[x]);
	return pset[x];
}
bool issameset(int x,int y){
	return find(x)==find(y);
}
void Union(int x,int y){
	if(!issameset(x,y)){
		pset[find(x)]=find(y);
	}
}
void dfs(int u){
	visited[u]=1;
	for(int i=0;i<adj[u].size();i++){
		pair<int,int> v=adj[u][i];
		if(!visited[v.first]){
			par[0][v.first]=u;
			high[v.first]=high[u]+1;
			up[0][v.first]=v.second;
			dfs(v.first);
		}
	}
}
void prepare(){
	for(int j=1;j<=19;j++){
		for(int i=1;i<=n;i++){
			par[j][i]=par[j-1][par[j-1][i]];
			up[j][i]=max(up[j-1][i],up[j-1][par[j-1][i]]);
		}
	}
}
int lca(int x,int y){
	if(high[x]>high[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(high[par[i][y]]>=high[x]) y=par[i][y];
	}
	for(int i=19;i>=0;i--){
		if(par[i][y]!=par[i][x]){
			x=par[i][x];
			y=par[i][y];
		}
	}
	if(x==y) return x;
	return par[0][x];
}
int maxedge(int x,int y){
	int mx=0;
	for(int i=19;i>=0;i--){
		if(high[par[i][x]]>=high[y]){
			mx=max(mx,up[i][x]);
			x=par[i][x];
		}
	}
	return mx;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	init(n);
	for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        edge[i].id=i;
    }
    int mst_cost=0;
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;i++){
        if(!issameset(edge[i].u,edge[i].v)){
            mst_cost+=edge[i].w;
            Union(edge[i].u,edge[i].v);
            adj[edge[i].u].push_back(make_pair(edge[i].v,edge[i].w));
            adj[edge[i].v].push_back(make_pair(edge[i].u,edge[i].w));
        }
    }
    high[1]=1;
    dfs(1);
    prepare();
    for(int i=0;i<m;i++){
        int gg=lca(edge[i].u,edge[i].v);
        ans[edge[i].id]=mst_cost-max(maxedge(edge[i].u,gg),maxedge(edge[i].v,gg))+edge[i].w;
    }
    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}