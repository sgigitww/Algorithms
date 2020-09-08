#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class graph{

	unordered_map<int,vector<int>> mp;
	int v;
public:

	graph(int v){
		this->v=v;
	}

	void addedge(int x,int y){

		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	bool cycle_helper(int node,bool*vis,int parent){

		vis[node]=1;
		for(auto x:mp[node]){

			if(vis[x]&&parent!=x){
				return true;
			}else if(!vis[x]){

				bool ok = cycle_helper(x,vis,node); 
				if(ok){
					return 1;
				}
			}
		}

		return 0;
	}

	bool cycle(){

		bool*vis = new bool[v];

		for(auto x:mp){
			vis[x.first]=0;
		}

		return cycle_helper(0,vis,-1);

	}
};

int main(){

	graph g(5);
	g.addedge(0,1);
	g.addedge(0,4);
	g.addedge(2,1);
	g.addedge(4,3);
	g.addedge(3,2);

	g.cycle()?cout<<"Yes\n":cout<<"No\n";

	return 0;
}