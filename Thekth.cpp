/*****
快排思想求k小问题
中间加入舍伍德算法避免最坏情形
****/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int first[maxn];
int jude(int arr[],int low,int hight){//
	int x = (rand() % (hight-low+1))+ low;
	//cout<<x<<endl;
	int temp = arr[x];
	arr[x]=arr[low];
	while(low<hight){
		while(arr[hight]>temp&&low<hight)hight--;
		arr[low]=arr[hight];
		while(arr[low]<=temp&&low<hight)low++;
		arr[hight]=arr[low];
	}
	arr[low] = temp;
	//cout<<x<<endl;
	return low;
}

int B_s(int arr[],int low,int hight,int k){	
	int t = jude(arr,low,hight);
	//cout<<"t = "<<t<<endl;
	if(k==t){return arr[t];}
	else if(k>t){
		return B_s(arr,t+1,hight,k);
	}
	else {
		return B_s(arr,low,t-1,k);
	}
	return -1;
}

int main(){
	/***********
	 5 2
	 1 2 3 4 5
	 5 3
	 4 2 3 5 4
	************/
	int n,k;
	srand((unsigned)time(NULL)); 
	while(cin>>n>>k){
		for(int i=1;i<=n;i++){
			scanf("%d",first+i);
		}
		int ans = B_s(first,1,n,k);
		cout<<ans<<endl;	
	}
	return 0;
}