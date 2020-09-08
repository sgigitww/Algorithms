#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class graph{

	unordered_map<T,vector<T>> mp;
	int v;
public:

	void addedge(T x,T y){
		mp[x].push_back(y);
		mp[y].push_back(x);
	}

	void bfs(T src){

		unordered_map<T,int> vis;
		queue<T> q;
		q.push(src);
		vis[src]=1;

		while(!q.empty()){

			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto x:mp[node]){
				if(!vis[x]){
					q.push(x);
					vis[x]=1;
				}
			}
		}cout<<'\n';
	}

	void print(){

		for(auto x:mp){
			cout<<x.first<<"-->";
			vector<int> v = x.second;
			for(auto y:v){
				cout<<y<<" ";
			}cout<<'\n';
		}
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

	g.print();
	g.bfs(0);

	return 0;
}