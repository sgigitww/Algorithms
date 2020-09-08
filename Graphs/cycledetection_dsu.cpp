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

		else return par[x]= get(par[x]);//path compression
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
		int x,y;
		cin>>x>>y;
		x--;
		y--;///make 0 based indexing
		if(g.get(x)!=g.get(y)){
			//different components
			g.unite(x,y);//create an edge b/w x and y
		}else{
			//same component
			//there was a path from x to y
			cout<<"This edge will give me a cycle\n"; 
			return 0;;
		}
	}
	cout<<"No cycle is present\n";
	return 0;
}