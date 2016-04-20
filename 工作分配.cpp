/*
类似tsp
*/
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const int maxn = 100;
int best;
int c[maxn][maxn];
int bestp[maxn],person[maxn];//记录最优路径
int n;
bool visit[maxn];
void work(int cnt,int cost){
	if(cnt == n){
		if(best>cost){
			best = cost;
			for(int i=0;i<n;i++)bestp[i]=person[i];//更新路径
		}
		return;
	}
	if(cost>best)return;
	for(int i=0;i<n;i++){
		if(!visit[i]){
			visit[i]=true;//标记任务分配过
			person[cnt]=i;
			work(cnt+1,cost+c[cnt][i]);
			visit[i]=false;//回溯改值
		}
	}
}
int main(){
	memset(visit,0,sizeof(visit));
	best = inf;
/*
5
50 43 1 58 60 
87 22 5 62 71 
62 98 97 27 38 
56 57 96 73 71 
92 36 43 27 95
*/
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)cin>>c[i][j];
	work(0,0);
	cout<<best<<endl;
	for(int i=0;i<n;i++)cout<<"第 "<<i+1<<"个工作分配给:"<<bestp[i+1]<<"个人"<<endl;//打印最优路径
	cout<<endl;
	return 0;
}