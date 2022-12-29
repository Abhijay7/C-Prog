// Program for binary search
// Abhijay Rawat
// 20.11.2022

#include<stdio.h>

void main(){
	int arr[] = {1,11,23,45,56,67,78,90,100,120};
	int mid, high, low, num;
	low = 0;
	high = 9;

	printf("Enter an element to find in array:");
	scanf("%d", &num);

	mid = (low+high) / 2;
		
	while((arr[mid] != num) && (low <= high)){
		
		if(arr[mid] < num)
			low = mid + 1;

		else
			high = mid - 1;
		
		mid = (low+high)/2;

	}

	if(arr[mid] == num)
		printf("Your element is at %d position.\n", mid+1);

	else
		printf("-1 Element not in the list.\n");

}
