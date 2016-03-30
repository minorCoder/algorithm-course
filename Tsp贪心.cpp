#include <cstdio>
#include <iostream>
#include <algorithm>
const int maxn = 101;
const int inf = 0x3fffffff;
using namespace std;

int TSP(int c[][maxn],int n){
	bool visit[maxn];
	int path[maxn][maxn];
	int ans = inf;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)visit[j]=false;
		int p = i;
		path[i][1]=p;
		visit[p] = true;
		int cost = 0;
		int r = 1;
		for(int k = 2;k<=n;k++){
			int min = inf;
			for(int t = 1;t<=n;t++){
				if(!visit[t]&&min>c[p][t]){
					min = c[p][t];
					r=t;
				}
			}
				visit[r]=true;
				cost+=c[p][r];
				path[i][k]=r;
				p = r;
		}

		for(int u=1;u<=n;u++)cout<<path[i][u]<<" ";
		cout<<endl;
		cost +=c[p][i];
		cout<<cost<<endl;
		if(cost<ans)ans = cost;
	}
	
	return ans;
}

//Tsp贪心近优解
int main(){
	int c[maxn][maxn]={//0 1 2 3 4 5 
				   {0,0, 0, 0, 0, 0},
				   {0,0, 2, inf, 6, inf},
                   {0,2, 0, 3, 8, 5},
                   {0,inf, 3, 0, inf, 7},
                   {0,6, 8, inf, 0, 9},
                   {0,inf, 5, 7, 9, 0}
};
 /* 创建以下的图
          2    3
      (1)--(2)--(3)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (4)-------(5)
            9          
 */
     int ans = TSP(c,5);
     cout<<ans<<endl;
	return 0;
}