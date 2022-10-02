#include<bits/stdc++.h>
using namespace std;
int parent[10];
int Find(int parent[],int x) {
	if(parent[x]==-1){
		return x;
	}
	return Find(parent,parent[x]);
}
void Union(int p, int q) {
	if(Find(parent, p) == Find(parent, q)){
		cout<<"error";
		exit(0);
	}
	parent[p]=q;
}
int main(){
	for(int i=0;i<10;i++){
		parent[i]=-1;
	}
	int a,b;
	while(cin>>a>>b){
		Union(a,b);
	}
	return 0;
}

