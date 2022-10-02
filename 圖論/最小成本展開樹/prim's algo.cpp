//.................還需要再修改.................... 
#include<bits/stdc++.h>
using namespace std;
bool check[9]={0};					//標記走過的點 
vector<int> Distance(9);			//起點到各個點的距離 
vector<vector<int> > graph(9);		//留一個空格，否則會判定會 ">>"

void Prim(int node, int begin){
	int minweight=0;
	check[begin]=1;
	int tot=node;
	while(tot-->0){
		int Min=1e9,v=0;
		
		for(int i=0; i<node; i++)
            Distance[i] = min(Distance[i], graph[begin][i]);
            
        for(int i=0; i<node; i++){
            if(!check[i] && Distance[i] < Min){
                Min= Distance[i];
                v = i;
            }
        }
        minweight += Distance[v];
        node = v;
	}
	cout<<"Total Minimum weight： "<<minweight<<endl;
}
int main(){
	int n,begin;
	cin>>n>>begin;
	
	for(int i=0;i<n;i++){			 
		for(int j=0;j<n;j++){
			graph[i].resize(n);
			cin>>graph[i][j];
		}
	}
	
	Distance.clear();
	for(int i=1;i<n;i++)
		Distance[i]=1e9;
		
	Prim(n,begin);
	return 0;
}


