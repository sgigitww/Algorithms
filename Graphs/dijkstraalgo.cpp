#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<climits>
using namespace std;

template<typename T>
class graph{

	unordered_map<T,vector<pair<T,int>>> mp;

public:

	void addedge(T u,T v,int wt,bool bidir=1){

		mp[u].push_back(make_pair(v,wt));
		mp[v].push_back(make_pair(u,wt));
	}

	void print(){

		for(auto x:mp){
			cout<<x.first<<"->";
			vector<pair<T,int>> v=x.second;
			for(auto y:v){
				cout<<"("<<y.first<<','<<y.second<<") ";
			}cout<<'\n';
		}
	}

	void dijkstra(T src){

		unordered_map<T,int> dis;
		for(auto x:mp){
			dis[x.first]=INT_MAX;
		}
		dis[src]=0;
		set<pair<int,T>> s;//dis,node
		s.insert(make_pair(0,src));
		while(!s.empty()){

			//find the front pair
			auto p = *s.begin();//most promising node
			T node = p.second;
			int ndis = p.first;
			s.erase(s.begin());
			//iterate children
			for(auto x:mp[node]){
				//dis[parent]+wt<dis[child]
				//update
				if(ndis + x.second < dis[x.first]) {

					//remove the old pair and insert a new pair
					auto f = s.find(make_pair(dis[x.first],x.first));
					if(f!=s.end()){
						//erase
						s.erase(f);
					}
					//insert
					dis[x.first] = ndis + x.second;
					s.insert(make_pair(dis[x.first],x.first));
				}
			}
		}

		for(auto x:dis){
			cout<<"city "<<x.first<<" distance:"<<x.second<<'\n';
		}

	}


};

int main(){


	graph<int> g;
	g.addedge(1,2,1);
	g.addedge(1,3,4);
	g.addedge(2,3,1);
	g.addedge(3,4,2);
	g.addedge(1,4,7);
	g.print();

	g.dijkstra(1);

	return 0;
}