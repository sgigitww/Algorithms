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
	}

	bool cycle_helper(int node,bool*vis,bool*stack){

		vis[node]=1;
		stack[node]=1;
		for(auto x:mp[node]){
			if(stack[x]){
				return 1;
			}
			else if(!vis[x]){
				bool ok = cycle_helper(x,vis,stack);
				if(ok){
					return 1;
				}
			}
		}

		//leave a node
		stack[node]=0;
		return 0;
	}

	bool cycle(){

		bool *stack = new bool[v];
		bool*vis = new bool[v];
		for(auto x:mp){
			vis[x.first]=0;
		}

		return cycle_helper(0,vis,stack);
	}
};

int main(){

	graph g(7);
	g.addedge(0,1);
	g.addedge(1,5);
	g.addedge(5,6);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,4);
	g.addedge(4,2);
	g.addedge(4,5);

	g.cycle()?cout<<"Yes\n":cout<<"No\n";

	return 0;
}