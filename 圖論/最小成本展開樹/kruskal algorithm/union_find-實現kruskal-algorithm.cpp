#include<bits/stdc++.h>
#define Max 50
using namespace std;
typedef struct {
	int begin, end, weight;
}Edge;
Edge G[Max];
int parent[Max];

void sort(int n){		//演算法的sort無法使用，原因是資料型態是自訂的，內部沒有此資料型態的比較方法 ，重key。 
    for(int i=0;i<n-1;i++){
    	for(int j=i+1;j<n;j++){
    		if(G[i].weight > G[j].weight){
        		Edge t=G[j];
        		G[j]=G[i];
        		G[i]=t;
     		}
		}
	}		
}

int Find(int parent[],int x) {	//並查集函式 
	return parent[x] == -1? x : Find(parent,parent[x]);
}

void Kruskal(Edge e[] ,int n){
	int v1,v2,sum=0;
	int minuscnt=0;
	for(int i=0;i<n;i++){		//初始化，之後只要有加入的邊就標記 
		parent[i]=-1;
	}
	for(int i=0;i<n;i++){
		v1=Find(parent, G[i].begin);	
		v2=Find(parent, G[i].end);
		//如果V1 == V2，代表偵測到環，則找下一條 
		if(v1 != v2){				
			cout<<"("<<G[i].begin<<","<<G[i].end<<") -> 權重為："<<G[i].weight<<endl;
			sum+=G[i].weight;
			parent[v1]=v2;
		}else
			minuscnt++;
	}
	cout<<"偵測到環的次數："<<minuscnt<<" 次"<<endl;
	cout<<"Total Minimum Weight："<<sum<<endl;
}
int main() {
	int edge;		//邊的個數 
	cin >> edge;
		
	for(int i=0;i<edge;i++)
		cin >> G[i].begin >> G[i].end >> G[i].weight;
			
	sort(edge);			//進Loop之前，先排序(由小到大) 
	
	Kruskal(G, edge);	//利用並查集實現kruskal演算法 
	return 0;
}

