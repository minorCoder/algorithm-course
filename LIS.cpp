#include <iostream>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;
const int inf = 0x7fffffff;
const int minx = INT_MIN;
void find(int list[],int k,int a[]){//find the LIS path
	if(k==list[k]){
		cout<<"xuhao"<<k<<"the number = "<<a[k]<<endl;
		return;
	}
	else find(list,list[k],a);
	cout<<"xuhao"<<k<<"the number = "<<a[k]<<endl;
}
int LIS(int a[],int n){
	int list[n+1];
	int dp[n+1];
	for(int i=1;i<=n;i++)list[i]=i;
	for(int i=1;i<=n;i++){dp[i]=1;}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j]){
				if(dp[j]+1>dp[i]){
					dp[i]=dp[j]+1;
					list[i]=j;
				}
			}
			else {
				if(dp[j]>dp[i]){dp[i]=dp[j];list[i]=j;}
			}

		}
	}
	int ans = minx;
	int k = 0;
	for(int i=1;i<=n;i++){
		if(ans<dp[i]){
			ans = dp[i];
			k=i;
		}
	}
	find(list,k,a);
	return ans;
}
int main(){
	int a[]={
		inf,10,22,9,33,21,50,41,60,80
	};//一个序列求最长递增子序列

	int ans = LIS(a,9);
	cout<<ans<<endl;

	return 0;
}