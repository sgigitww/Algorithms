#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<map>
using namespace std;

template<typename T>
class graph{

	unordered_map<T,vector<T>> mp;
	
public:

	void addedge(T x,T y){
		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	void dfs_helper(T src,map<T,bool> &vis){

		cout<<src<<" ";
		vis[src]=true;
		for(auto x:mp[src]){
			if(!vis[x]){
				dfs_helper(x,vis);
			}
		}
		return;
	}

	void dfs(T src){

		map<T,bool> vis;
		for(auto x:mp){
			vis[x.first]=false;
		}

		dfs_helper(src,vis);
	}

};



int main(){

	graph<int> g;
	g.addedge(0,1);
	g.addedge(0,3);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,4);
	g.addedge(5,4);

	g.dfs(0);
	

	return 0;
}