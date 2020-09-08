#include<iostream>
#include<list>
using namespace std;

class graph{

	int v;
	//array of list
	list<int> *l;
public:

	graph(int v){
		this->v=v;
		l = new list<int>[v];
	}

	void addedge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void print(){

		for(int i=0;i<v;++i){
			cout<<i<<"->";
			for(auto x:l[i]){
				cout<<x<<" ";
			}cout<<'\n';
		}
	}
};

int main(){

	graph g(4);
	g.addedge(0,1);
	g.addedge(0,2);
	g.addedge(2,3);
	g.addedge(1,2);

	g.print();

	return 0;
}