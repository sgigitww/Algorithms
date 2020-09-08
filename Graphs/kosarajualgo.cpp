#include<bits/stdc++.h>
using namespace std;

vector<int> g[100001],grr[1000001];
stack<int> st;
int vis[100001],comp[100001];

void dfs(int u){

	vis[u]=1;
	for(auto x:g[u]){

		if(!vis[x]){
			dfs(x);
		}
	}
	st.push(u);
}

void rdfs(int u,int col){

	comp[u]=col;
	vis[u]=1;
	for(auto x:grr[u]){
		if(!vis[x]){
			rdfs(x,col);
		}
	}

}

int main(){

	int n,m;
	cin>>n>>m;
	while(m--){

		int x,y;
		cin>>x>>y;
		x--;
		y--;
		g[x].push_back(y);
		grr[y].push_back(x);
	}

	for(int i=0;i<n;++i){
		if(!vis[i]){
			dfs(i);
		}
	}

	memset(vis,0,sizeof(vis));
	int col=1;
	while(!st.empty()){

		if(!vis[st.top()]){
			rdfs(st.top(),col);
			col++;
		}
		st.pop();
	}

	for(int i=0;i<n;++i){
		cout<<i+1<<"->"<<comp[i]<<'\n';
	}

	return 0;
}