#include<bits/stdc++.h>
#define Max 50
using namespace std;
typedef struct {
	int begin, end, weight;
}Edge;
Edge G[Max];
int parent[Max];

void sort(int n){		//�t��k��sort�L�k�ϥΡA��]�O��ƫ��A�O�ۭq���A�����S������ƫ��A�������k �A��key�C 
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

int Find(int parent[],int x) {	//�ìd���禡 
	return parent[x] == -1? x : Find(parent,parent[x]);
}

void Kruskal(Edge e[] ,int n){
	int v1,v2,sum=0;
	int minuscnt=0;
	for(int i=0;i<n;i++){		//��l�ơA����u�n���[�J����N�аO 
		parent[i]=-1;
	}
	for(int i=0;i<n;i++){
		v1=Find(parent, G[i].begin);	
		v2=Find(parent, G[i].end);
		//�p�GV1 == V2�A�N���������A�h��U�@�� 
		if(v1 != v2){				
			cout<<"("<<G[i].begin<<","<<G[i].end<<") -> �v�����G"<<G[i].weight<<endl;
			sum+=G[i].weight;
			parent[v1]=v2;
		}else
			minuscnt++;
	}
	cout<<"�������������ơG"<<minuscnt<<" ��"<<endl;
	cout<<"Total Minimum Weight�G"<<sum<<endl;
}
int main() {
	int edge;		//�䪺�Ӽ� 
	cin >> edge;
		
	for(int i=0;i<edge;i++)
		cin >> G[i].begin >> G[i].end >> G[i].weight;
			
	sort(edge);			//�iLoop���e�A���Ƨ�(�Ѥp��j) 
	
	Kruskal(G, edge);	//�Q�Ψìd����{kruskal�t��k 
	return 0;
}

