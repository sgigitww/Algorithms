#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{

	unordered_map<T,vector<T>> mp;
	int v;
public:

	graph(int v){
		this->v=v;
	}

	void addedge(T x,T y){
		mp[x].push_back(y);
	}

	void toposort(){

		int *indegree = new int[v];
		for(int i=0;i<v;++i){
			indegree[i]=0;
		}

		//update indegree by traversing
		for(auto x:mp){
			vector<T> v = x.second;
			for(auto y:v){
				indegree[y]++;
			}
		}

		queue<T> q;
		for(int i=0;i<v;++i){
			if(indegree[i]==0){
				q.push(i);
			}
		}
		
		while(!q.empty()){

			T node = q.front();
			cout<<node<<" ";
			q.pop();
			for(auto x:mp[node]){
				indegree[x]--;
				if(indegree[x]==0){
					q.push(x);
				}
			}

		}

	}

};

int main(){

	graph<int> g(6);
	g.addedge(0,2);
	g.addedge(2,3);
	g.addedge(3,5);
	g.addedge(4,5);
	g.addedge(2,5);
	g.addedge(1,4);
	g.addedge(1,2);

	g.toposort();cout<<'\n';

	return 0;
}