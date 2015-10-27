#include <stdio.h>

int num[1001];
int divide(int [] ,int , int);
int merge(int [], int, int, int);

int main(){
	int numOfNums,i;
	scanf("%d",&numOfNums);
	for(i=0;i<numOfNums;i++)
		scanf("%d",&num[i]);
	printf("%d\n", divide(num, 0, numOfNums-1));
	return 0;
}


int divide(int arr[],int low, int high){
	int mid=(low+high)/2, invcount=0;
	
	if(low<high){
		invcount=divide(arr, low, mid);
		invcount+=divide(arr,mid+1,high);
		invcount+=merge(arr,low,mid,high);
	}
	
	return invcount;
}

int merge(int arr2[],int low, int high, int max){
	int temp[1001]={0};
	int low1=low, high1=high, low2=high+1, high2=max;
	int i=low,j, invcount=0;

	while(low1<=high1 && low2<=max){
		
		if(arr2[low1]<=arr2[low2]){
			temp[i]=arr2[low1];
			low1++;
		}

		else{
			temp[i]=arr2[low2];
			low2++;
			invcount += high1-low1+1;
		}

		
		i++;
	}

	while(low1<=high1){
		temp[i]=arr2[low1];
		low1++;
		i++;
	}

	while(low2<=max){
		temp[i]=arr2[low2];
		low2++;
		i++;
	}

	for(j=low;j<=max;j++){
		arr2[j]=temp[j];
	}
	return invcount;
}