#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 100;
int c;//找要等于c的值
int rec[maxn];//记录路径
bool flag;
int n;
void dfs(int s[],int sum,int cnt){
	if(sum==c){//当sum等于目标c时就输出
		//flag = true;
		cout<<"yes"<<endl;
		for(int i=0;i<n;i++)cout<<rec[i]<<" ";
		cout<<endl;
		return ;
	}
	if(flag||sum>c||cnt>=n)return;//不满足条件就提前返回
	for(int i=0;i<=1;i++){
		rec[cnt]=i;//记录选或不选
		dfs(s,sum+s[cnt]*i,cnt+1);//选择搜索
		rec[cnt]=0;//回溯改值
	}
}
int main(){
	int s[] = {1,2,3,4,5,6,7,8,9,10};
	cin>>c;
	n =10;
	flag = false;
	dfs(s,0,0);
	return 0;
}