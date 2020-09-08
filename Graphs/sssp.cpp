#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<climits>
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

	void sssp(T src){

		unordered_map<T,int> dis;
		queue<T> q;
		q.push(src);

		for(auto x:mp){
			dis[x.first]=INT_MAX;	
		}
		dis[src]=0;

		while(!q.empty()){

			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(auto x:mp[node]){

				if(dis[x]==INT_MAX){
					q.push(x);
					dis[x]=1 + dis[node];
				}
			}

		}cout<<'\n';
		cout<<"From src node 0\n" ;
		for(auto x:dis){
			cout<<x.first<<" "<<x.second<<"\n";
		}
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
	g.sssp(0);

	return 0;
}