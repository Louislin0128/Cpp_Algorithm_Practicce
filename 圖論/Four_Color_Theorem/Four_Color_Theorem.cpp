#include<bits/stdc++.h>
using namespace std;
#define N 10 				//頂點個數，可以修改。 
int Map[N][N]={0};			//資料，存放各個頂點之間的關係，用相鄰矩陣表示。
vector<int> has(N);			//指定顏色，用一維陣列存。 
vector<int> temp(N);
int tot=0;
void init(){
	for(int i=0;i<N;i++){
		temp[i]=0;
		for(int j=0;j<N;j++){
			cin>>Map[i][j];
		}
	}
	cout<<endl;
}
bool check(int level,int color){		//check whether can be assigned color 
	for(int i=0;i<level;i++){
		if(Map[level][i]==1 && has[i]==color){
			return 0;
		}
	}
	return 1;
}
int dfs(int v){			//v代表頂點 ，用dfs搜尋 
	if(v>N){
		int num=0;
		for(int j=0;j<N;j++)				//紀錄是否有一樣的顏色指定存在，如果計算的個數與頂點個數不一樣，那就輸出ans 
			if(has[j] == temp[j]) 
				num++;
		if(num!=N){
			for(int j=0;j<N;j++){
				cout<<has[j]<<" ";
				temp[j]=has[j];
			}
			tot++;
			cout<<endl;
			//exit(0);						//如果覺得解太多，只要一個就好，只要再把這行註解掉就好 
		}
	}else{
		for(int color=1;color<=4;color++){			//顏色{R,G,B,Y}，分別用數字 1~4 代替，最大上限可以調大調小。		 
			has[v]=color;						//例如：co<=3，就代表只有3種顏色可以指定 
			if(check(v,color)){
				dfs(v+1);
			}
		}
	}
}
int main(){
	init();		//初始化，把資料填入 
	dfs(0);		//起點從0開始走 
	cout<<"全部的解有: "<<tot<<"種\n"; 
	return 0;
}
