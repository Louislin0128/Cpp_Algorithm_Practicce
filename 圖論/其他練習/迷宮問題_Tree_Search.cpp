#include<iostream>
#include<queue>
#include<iomanip>
#include<vector>
#define Max 15 
using namespace std;
char g[Max][Max];			//迷宮矩陣 
char last[Max][Max];		//顯示最佳路徑之迷宮矩陣 
typedef pair<int, int> P;
int r=0,c=0;
int sx,sy; 		//起始位置 
int tx,ty; 		//目標位置 

int d[Max][Max];			//儲存起點到某一點的距離
int dx[4] = {1,0,-1,0};		//移動方向==> 下 右 上 左 
int dy[4] = {0,1,0,-1}; 
P pre[Max][Max];
void bfs(){
	
	queue<P> que;
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			d[i][j] = -1;				//初始化所有點的距離為-1 
		}
	}
	que.push(P(sx,sy));	
	d[sx][sy] = 0;						//從起點出發將距離設為0，並放入Queue的top 
	
	while (que.size()){ 				//題目保證有路到終點，所以不用擔心死迴圈
		P p = que.front(); 				//彈出top元素
		que.pop();			
		
		int i;
		for (i=0;i<4;i++){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];	//移動後的座標
			//判斷可移動且沒到過
			//之前到過的話不用考慮，因為距離在佇列中遞增，肯定不會獲得更好的解
			if (0 <= nx && nx < r && 0 <= ny && ny < c && g[nx][ny] != '#' && d[nx][ny] == -1){
				que.push(P(nx, ny));						//可以移動，則設定距離為之前加一，放入佇列
				d[nx][ny] = d[p.first][p.second] + 1;		//填入可移動的點(以數字顯示) 
				pre[nx][ny] = {p.first , p.second};
				if(nx==tx && ny==ty) break;
            }
		}
		if(i!=4) break;
	}
	int x=tx,y=ty;
    while(x!=sx || y!=sy){
    	//cout<<"( "<<x<<","<<y<<" )"<<endl; 	//路徑位址index顯示  ex：(9,7) 
        P t=pre[x][y];
        x=t.first;
        y=t.second;
        if(x!=sx || y!=sy)
        	last[x][y]='m';
    }
}
int main(){
	cout<<"please input how many rows：";
	cin>>r;
	cout<<"please input how many cols：";
	cin>>c;
	cout<<"please input initial graph："<<endl;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>g[i][j];
			last[i][j] = g[i][j];
			
			if(g[i][j] == 'S' || g[i][j] == 's'){
				sx=i; 
				sy=j;
			}
			if(g[i][j] == 'G' || g[i][j] == 'g'){
				tx=i;
				ty=j;
			}
		}
	}
	
	cout<<endl;
	bfs();
	
	cout<<"\nthe shortest path："<<endl;
	/*cout<<"以數字顯示："<<endl;				//由小到大 
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<setw(3)<<d[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"以m標示顯示："<<endl;*/				 
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<last[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
/*# S # # # # # # . #
. . . . . . # . . #
. # . # # . # # . #
. # . .  . . . . . .
# # . # # . # # # #
. . . . # . . . . #
. # # # # # # # . #
. . . . # . . . . .
. # # # # . # # # .
. . . . # . . . G #

. . . . S #
. # # # # #
. . . . # .
# # # . . #
. G . . . .
*/
