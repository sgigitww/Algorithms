#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<climits>
#include<list>
using namespace std;


template<typename T>
class graph{

	unordered_map<T,vector<T>> mp;
	
public:

	void addedge(T x,T y){
		mp[x].push_back(y);
	}

	void dfs_helper(T src,list<T> &ordering,map<T,bool> &vis){

		vis[src]=true;
		for(auto x:mp[src]){
			if(!vis[x]){
				dfs_helper(x,ordering,vis);
			}
		}

		ordering.push_front(src);
		return;
	}

	void dfs(){

		map<T,bool> vis;
		list<T> ordering;

		for(auto x:mp){
			vis[x.first]=false;
		}

		for(auto x:mp){
			if(!vis[x.first]){
				dfs_helper(x.first,ordering,vis);
			}
		}

		for(auto x:ordering){
			cout<<x<<" ";
		}cout<<'\n';
	}

};

int main(){


	graph<char> g;
	g.addedge('x','a');
	g.addedge('x','b');
	g.addedge('x','c');
	g.addedge('z','x');
	g.addedge('z','y');
	g.addedge('y','a');

	g.dfs();

	return 0;
}