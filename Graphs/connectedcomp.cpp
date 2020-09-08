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
		int cnt=0;
		for(auto x:mp){
			vis[x.first]=false;
		}	

		for(auto x:mp){

			if(!vis[x.first]){

				dfs_helper(x.first,vis);
				cnt++;
				cout<<"Component "<<cnt<<'\n';
			}
		}
		cout<<"Total Components are "<<cnt<<'\n';
	}

};



int main(){

	graph<int> g;
	g.addedge(0,1);
	g.addedge(0,3);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(0,4);

	g.addedge(5,6);
	g.addedge(6,7);

	g.addedge(8,8);

	g.dfs(0);
	

	return 0;
}