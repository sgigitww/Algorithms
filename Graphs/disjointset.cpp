#include<iostream>
#include<vector>
using namespace std;

struct dsu
{
	vector<int> par;
	vector<int> sz;
	int total_comp;
	void init(int n){
		par.resize(n);
		sz.resize(n);
		for(int i = 0; i < n; ++i){
			par[i]=i;
			sz[i]=1;
		}
		total_comp=n;
	}

	int get(int x){

		if(x==par[x]){
			return x;
		}

		else return par[x]= get(par[x]);
	}

	void unite(int x,int y){

		int supx=get(x);
		int supy=get(y);
		if(supy!=supx){
			par[supx]=supy;
			sz[supy]+=sz[supx];
			sz[supx]=0;
			total_comp--;
		}
	}
}g;



int main(){

	int n,m;
	cin>>n>>m;
	g.init(n);
	for(int i=0;i<m;++i){

		int x;int y;
		cin>>x>>y;
		g.unite(x,y);
	}	

	int ans=0;
	for(int i=0;i<n;++i){

		int supi=g.get(i);
		ans+=n-g.sz[supi];
	}

	cout<<ans/2<<'\n';
	return 0;
}