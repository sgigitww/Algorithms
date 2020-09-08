#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> floydwarshall(int n,vector<vector<pair<int,int>>> &adj){

	vector<vector<int>> dis(n+1,vector<int>(n+1,2e9));
	for(int i=1;i<=n;++i){

		dis[i][i]=0;
		for(auto p:adj[i]){
			dis[i][p.first]=p.second;
		}
	}

	for(int k=1;k<=n;++k){

		//kth phase
		for(int i=1;i<=n;++i){

			for(int j=1;j<=n;++j){

				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}

	return dis;
}

int main(){





	return 0;
}