#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
const int maxn = 10010;
using namespace std;
struct E{
	int u,v,w;
};
E e[maxn];
bool cmp(E e1,E e2){
	return e1.w<e2.w;
}
int f[maxn];
int Find(int x){
	if(x!=f[x])f[x] = Find(f[x]);
	return f[x];
}
void Inint(int n,int m){
	for(int i=1;i<=n;i++){
		f[i] = i;
	}
}
int kruskal(int n,int m){
	int t = 0;
	int ans = 0;
	int i;
	for(i=1;i<=m;i++){
		int x = Find(e[i].u);
		int y = Find(e[i].v);
		if(x!=y){
			f[y]=x;
			t++;
			cout<<"每次选的边为:"<<e[i].u<<" "<<e[i].v<<endl;
			ans+=e[i].w;
			if(t==n-1)break;
		}
	}
	if(i>m)return -1;
	else return ans;
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
 /*
5 7
1 2 2
1 4 6
2 3 3
2 4 8
2 5 5
3 5 7
4 5 9
 */
	int m,n;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	Inint(n,m);
	sort(e+1,e+1+m,cmp);
	int ans = kruskal(n,m);
	printf("最小权值和是:%d",ans);
	return 0;
}