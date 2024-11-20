#include <stdio.h>
#include <stdlib.h>

void insert_sort(int* arr, int n) {
	int temp, j;
	for (int i = 1; i < n; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp;j--) 
			arr[j + 1] = arr[j]; 		
		arr[j + 1] = temp;
	}
}

int main() {
	int arr[5], sum=0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	insert_sort(arr, 5);
	printf("%d\n%d", sum / 5, arr[2]);
	return 0;
}