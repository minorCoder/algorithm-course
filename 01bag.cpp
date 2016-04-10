#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
const int maxn = 101;
const int inf = 0x7fffffff;
using namespace std;
int bag0_1(int C,int D,int w[],int b[],int v[],int n){
	int dp[n+1][C+1][D+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=C;j++){
			for(int k=1;k<=D;k++){
				if(j>=w[i]&&k>=b[i]){
					if(dp[i-1][j][k]<dp[i-1][j-w[i]][k-b[i]]+v[i]){
						dp[i][j][k] = dp[i-1][j-w[i]][k-b[i]]+v[i];
					}
					else 
						dp[i][j][k]=dp[i-1][j][k];
				}
				else 
					dp[i][j][k]=dp[i-1][j][k];
			}
		}

	}
	int ans = 0;
	for(int i=n;i>=1;i--){
		if(dp[i][C][D]>dp[i-1][C][D]){
			cout<<"select: "<<i<<endl;
			C-=w[i];
			D-=b[i];
			ans+=v[i];
		}
	}

	return ans;
}
int main(){
	int w[] = {inf,3,4,6,1,2};
	int b[] = {inf,2,1,4,1,4};
	int v[] = {inf,6,5,7,3,8};
	int ans = bag0_1(8,7,w,b,v,5);
	cout<<ans<<endl;
	return 0;
}