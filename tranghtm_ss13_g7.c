#include <stdio.h>

void showArr( int a, int b){
	int arr[a][b];
	for ( int i =0; i<a; i++){
		for( int j =0; j<b; j++){
			printf("Nhap phan tu thu %d hang %d: ", j+1, i+1);
			scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}
	
	printf("\nKet qua: \n");
	for ( int i =0; i<a; i++){
		for( int j =0; j<b; j++){
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int row, col;
	printf("Nhap hang: ");
	scanf("%d", &row);
	
	printf("Nhap cot: ");
	scanf("%d", &col);
	
	if ( row < 0 || col < 0){
		return 1;
	}
	
	showArr(row, col);
	
	return 0;
}
