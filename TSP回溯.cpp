#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100;
const int inf = 0x3fffffff;
int ans;
bool visit[maxn];
int disit[maxn][maxn];
vector<int> v[maxn];
int n,m;
int start;
int bestpath[maxn];
int path[maxn];
void TSPdfs(int cur,int c,int cnt){
	if(c>ans)return;
	if(cnt==n){
		//cout<<"ok"<<endl;
		if(ans>c+disit[cur][start]){
			ans = c+disit[cur][start];
			//cout<<ans<<endl;
			for(int i=1;i<=n;i++){
				bestpath[i]=path[i];
			}
				bestpath[n+1]=start;
		}
		
		return;
	}
	for(int i = 0;i<v[cur].size();i++){
		if(!visit[v[cur][i]]){
			visit[v[cur][i]] = true;
			path[cnt+1] = v[cur][i];
			cout<<"c="<<c<<endl;
			TSPdfs(v[cur][i],c+disit[cur][v[cur][i]],cnt+1);
			visit[v[cur][i]] =false;
		}
	}

}

int main(){
	int s,e,cost;
	memset(disit,0,sizeof(disit));
	memset(visit,0,sizeof(visit));
	cin>>n>>m;
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			disit[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>s>>e>>cost;
		v[s].push_back(e);
		v[e].push_back(s);
		disit[s][e]=cost;
		disit[e][s]=cost;
	}
	start = 1;
	visit[start]=true;
	ans = inf;
	path[1] = start;
	TSPdfs(start,0,1);
	cout<<ans<<endl;
	for(int i=1;i<=n+1;i++)cout<<bestpath[i]<<" ";
		cout<<endl;
	return 0;
}