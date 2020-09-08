#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
using namespace std;

class graph{

	unordered_map<string,vector<pair<string,int>>> mp;
	int v;

public:

	void addedge(string x,string y,bool bidir,int w){

		mp[x].push_back(make_pair(y,w));
		if(bidir){
			mp[y].push_back(make_pair(x,w));
		}
	}

	void print(){

		for(auto x:mp){
			cout<<x.first<<"-->";
			vector<pair<string,int>> v = x.second;
			for(auto y:v){
				cout<<"("<<y.first<<","<<y.second<<"), ";
			}cout<<'\n';
		}
	}

};


int main(){

	graph g;
	g.addedge("A","B",true,20);
	g.addedge("B","D",true,30);
	g.addedge("A","C",true,10);
	g.addedge("C","D",true,40);
	g.addedge("A","D",false,50);

	g.print();

	return 0;
}