#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//MST	
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
	vector<vector<int>> edges(m);
	for(int i=0;i<m;++i){
		int x,y,w;
		cin>>x>>y>>w;
		x--;
		y--;
		edges[i]={w,x,y};
	}

	sort(edges.begin(),edges.end());
	g.init(n);
	int sum=0;
	for(int i=0;i<m;++i){

		int x=edges[i][1];
		int y=edges[i][2];
		int w=edges[i][0];

		//check for cycle detection
		if(g.get(x)!=g.get(y)){
			//can take this edge
			g.unite(x,y);
			sum+=w;
			//MST that we get
			cout<<x+1<<" "<<y+1<<" "<<w<<'\n';
		}
	}

	cout<<sum<<'\n';

	return 0;
}