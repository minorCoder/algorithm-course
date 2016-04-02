#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int  maxn  = 101;
const int inf = 0xfffffff;
/*
Dijstra
*/
void coutPath(int parents[],int k){
	if(k!=parents[k])coutPath(parents,parents[k]);
	cout<<k<<" ";
}
void Dijstra(int c[][maxn],int n,int k){
	int d[maxn];
	int parents[maxn];
	bool visit[maxn];
	for(int i=1;i<=n;i++){
		d[i]=inf;
		visit[i]=false;
	}
	d[k]=0;
	visit[k]=true;
	parents[k]=k;
	for(int i=1;i<=n;i++){
		int num = k;
		int min = inf;
		bool flag = false;
		for(int j=1;j<=n;j++){
			if(!visit[j]&&d[j]<min){//找到目前k到节点最小值
				min=d[j];
				num = j;
				flag = true;
			}
		}
		visit[num]=true;//选中最小
		//if(!flag)break;  //标记 选完就退出
		for(int j=1;j<=n;j++){
			if(!visit[j]&&d[num]+c[num][j]<d[j]){
				d[j]=d[num]+c[num][j];
				parents[j]=num;
			}
		}


	}
	for(int i = 1;i<=n;i++)cout<<"k to "<<i<<" the shortest distance is: "<<d[i]<<" "<<endl;//输出重1到每个节点的最短路
		cout<<endl;
		cout<<"to x = 5 path is"<<endl;
		coutPath(parents,5);//打印最短路路径
		cout<<endl;

}
int main(){
	/* 创建以下的图
          2    3
      (1)--(2)--(3)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (4)-------(5)
            9          
 */
	int c[maxn][maxn]={//0 1 2 3 4 5 
				   {0,0, 0, 0, 0, 0},
				   {0,0, 2, inf, 6, inf},
                   {0,2, 0, 3, 8, 5},
                   {0,inf, 3, 0, inf, 7},
                   {0,6, 8, inf, 0, 9},
                   {0,inf, 5, 7, 9, 0}
				};

        Dijstra(c,5,1);
      
	return 0;
}	

