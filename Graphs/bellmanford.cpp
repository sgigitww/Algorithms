#include<bits/stdc++.h>
using namespace std;

vector<int> bellamnford(int n,int src,vector<vector<int>> edges){

	//min dis from src to i
	vector<int> dis(n+1,INT_MAX);
	dis[src]=0;
	//relax all the edges atmost n-1 times
	for(int i=0;i<n-1;++i){

		for(auto t:edges){

			int x=t[0],y=t[1],w=t[2];
			if(dis[x]!=INT_MAX && dis[x]+w<dis[y]){
				dis[y]=dis[x]+w;
			}
		}
	}

	for(auto t:edges){

		int x=t[0],y=t[1],w=t[2];
		if(dis[x]+w<dis[y]){
			cout<<"Negative cycle is present!\n";
			exit(0);
		}
	}

	return dis;
}

int main(){


	int n,m;
	cin>>n>>m;

	vector<vector<int>> edges;
	for(int i=0;i<m;++i){
		int x,y,w;
		cin>>x>>y>>w;
		edges.push_back({x,y,w});
	}

	vector<int> ans = bellamnford(n,1,edges);
	
	for(int i=1;i<=n;++i){
		cout<<"dis from src to i is "<<ans[i]<<'\n';
	}

	return 0;
}