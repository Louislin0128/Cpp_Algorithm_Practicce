#include<iostream>
#include<queue>
#include<vector>
#include<time.h>
int first=0;		//first是起頭的位址 
int n,num[100][100];
using namespace std;
void bfs(){
	queue<int> q;		
	vector<bool> vis;	//創一個是否拜訪過的陣列 		
	for(int i=0;i<n;i++){
		vis.push_back(0);
	}
	vis[first]=1;		//1代表==>標示為已拜訪 
	q.push(first);
	cout<<q.front();
	while(q.size()!=0){ 
		for(int i=0;i<n;i++){
			if(num[q.front()][i]!=0){
				if(vis[i]==0){
					vis[i]=1;
					q.push(i);
				}	
			}
		}
		q.pop();
		if(q.size()!=0){
			cout<<"->"<<q.front();
		}
	}
	return;
}
int main(){
	int t;		//測資數量 
	cin>>t;
	while(t-->0){	
		cin>>n>>first;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>num[i][j];
			}
		}
		double START,END;
		START = clock();
		bfs();
		END = clock();
		cout << endl << "進行運算所花費的時間：" << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	}
} 
