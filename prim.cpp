#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1010;//点的个数
const int inf = 0x7fffffff;//设置最大值
int closest[maxn];//记录离s最近的点
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

int s[maxn];//判断顶点是否在s里面
int lowest[maxn];//每次到s的最小距离
void prim(int n){
	memset(s,0,sizeof(s));
	for(int i=2;i<=n;i++){
		lowest[i]= c[1][i];
		closest[i]=1;
	}
	s[1]=1;
	int k;
	for(int i=2;i<=n;i++){
		int min = inf;
		for(int j=2;j<=n;j++){
			if(lowest[j]<min&&!s[j]){//找离s最近的点把s加进来
				min = lowest[j];
				k = j;
			}
		}
			cout<<k<<" "<<closest[k]<<" "<<lowest[k]<<endl;
			s[k]=1;
			for(int t = 2;t<=n;t++){//更新每个点到s的距离的最小值
				if(lowest[t]>c[k][t]&&!s[t]){
					lowest[t] = c[k][t];
					closest[t] = k;
				}
			}
	}

}

int main(){
		prim(5);
	return 0;
}