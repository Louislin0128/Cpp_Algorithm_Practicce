#include <bits/stdc++.h>
using namespace std;
int main(){
	int node=0;							//�U�@���I 
	bool check[9]={1};					//�аO���L���I 
	vector<int> Distance(9);			//�_�I��U���I���Z�� 
	vector<vector<int> > graph(9);		//�d�@�ӪŮ�A�_�h�|�P�w�| ">>"
	
	cout<<"�п�JGraph�G"<<endl;
	for(int i=0;i<9;i++){				//�̿�J�M�wn���ƶq 
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
	cout<<endl<<"��X�C���I���̵u���|�`�M:"<<endl<<endl; 
	for(int i=0; i<9; i++){
		cout<<"�_�I ~ ��"<<i<<"�I: "; 
		cout << Distance[i]<<endl;
	}
	cout<<endl;
	system("pause");
	return 0;
}

