#include <bits/stdc++.h>
using namespace std;
int main(){
	int node=0;							//下一個點 
	bool check[9]={1};					//標記走過的點 
	vector<int> Distance(9);			//起點到各個點的距離 
	vector<vector<int> > graph(9);		//留一個空格，否則會判定會 ">>"
	
	cout<<"請輸入Graph："<<endl;
	for(int i=0;i<9;i++){				//依輸入決定n的數量 
		for(int j=0;j<9;j++){
			graph[i].resize(9);
			cin>>graph[i][j];
		}
	}
	
	Distance.clear();
	for(int i=1;i<9;i++)
		Distance[i]=1e9;
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(graph[node][j]!=0){
				Distance[j] = min(Distance[j], Distance[node]+graph[node][j]);
			}
		}
		check[node]=1;
		int Min=1e9;
		for(int k=0;k<9;k++){
			if(Distance[k]<Min && check[k]!=1){
				Min=Distance[k];
				node=k;
			}
		}
	}
	
	int cnt = 0;
	cout<<endl<<"輸出每個點的最短路徑總和:"<<endl<<endl; 
	for(int i=0; i<9; i++){
		cout<<"起點 ~ 第"<<i<<"點: "; 
		cout << Distance[i]<<endl;
	}
	cout<<endl;
	system("pause");
	return 0;
}

