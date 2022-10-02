#include<iostream>
#include<queue>
#include<iomanip>
#include<vector>
#define Max 15 
using namespace std;
char g[Max][Max];			//�g�c�x�} 
char last[Max][Max];		//��̨ܳθ��|���g�c�x�} 
typedef pair<int, int> P;
int r=0,c=0;
int sx,sy; 		//�_�l��m 
int tx,ty; 		//�ؼЦ�m 

int d[Max][Max];			//�x�s�_�I��Y�@�I���Z��
int dx[4] = {1,0,-1,0};		//���ʤ�V==> �U �k �W �� 
int dy[4] = {0,1,0,-1}; 
P pre[Max][Max];
void bfs(){
	
	queue<P> que;
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			d[i][j] = -1;				//��l�ƩҦ��I���Z����-1 
		}
	}
	que.push(P(sx,sy));	
	d[sx][sy] = 0;						//�q�_�I�X�o�N�Z���]��0�A�é�JQueue��top 
	
	while (que.size()){ 				//�D�ثO�Ҧ�������I�A�ҥH���ξ�ߦ��j��
		P p = que.front(); 				//�u�Xtop����
		que.pop();			
		
		int i;
		for (i=0;i<4;i++){
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];	//���ʫ᪺�y��
			//�P�_�i���ʥB�S��L
			//���e��L���ܤ��ΦҼ{�A�]���Z���b��C�����W�A�֩w���|��o��n����
			if (0 <= nx && nx < r && 0 <= ny && ny < c && g[nx][ny] != '#' && d[nx][ny] == -1){
				que.push(P(nx, ny));						//�i�H���ʡA�h�]�w�Z�������e�[�@�A��J��C
				d[nx][ny] = d[p.first][p.second] + 1;		//��J�i���ʪ��I(�H�Ʀr���) 
				pre[nx][ny] = {p.first , p.second};
				if(nx==tx && ny==ty) break;
            }
		}
		if(i!=4) break;
	}
	int x=tx,y=ty;
    while(x!=sx || y!=sy){
    	//cout<<"( "<<x<<","<<y<<" )"<<endl; 	//���|��}index���  ex�G(9,7) 
        P t=pre[x][y];
        x=t.first;
        y=t.second;
        if(x!=sx || y!=sy)
        	last[x][y]='m';
    }
}
int main(){
	cout<<"please input how many rows�G";
	cin>>r;
	cout<<"please input how many cols�G";
	cin>>c;
	cout<<"please input initial graph�G"<<endl;
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
	
	cout<<"\nthe shortest path�G"<<endl;
	/*cout<<"�H�Ʀr��ܡG"<<endl;				//�Ѥp��j 
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<setw(3)<<d[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"�Hm�Х���ܡG"<<endl;*/				 
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
