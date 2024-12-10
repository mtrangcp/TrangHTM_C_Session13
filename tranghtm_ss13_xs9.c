#include <stdio.h>

void cn1( int arr[20][20], int row, int col ){
	printf("\nBan chon chuc nang 1!\n");
	for ( int i =0; i< row; i++){
		for ( int j =0; j<col; j++){
			printf("Nhap ptu thu %d hang %d: ", j+1, i+1);
			scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}
}

void cn2( int arr[20][20], int row, int col ){
	printf("\nBan chon chuc nang 2!\n");
	printf("\nHien thi phan tu theo ma tran: \n");
	for ( int i =0; i< row; i++){
		for ( int j =0; j<col; j++){
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}
}

void cn3( int arr[20][20], int row, int col ){
	printf("\nBan chon chuc nang 3!\n");
	printf("\nHien thi phan tu o goc theo ma tran: \n");
	for ( int i =0; i< row; i++){
		for ( int j =0; j<col; j++){
			if (( i ==0 || i == row-1) && ( j ==0 || j == col-1)){
				printf("\t%d", arr[i][j]);
			}else{
				printf("\t0");
			}
		}
		printf("\n");
	}
}

void cn4( int arr[20][20], int row, int col ){
	printf("\nBan chon chuc nang 4!\n");
	printf("\nHien thi phan tu o bien theo ma tran: \n");
	for ( int i =0; i< row; i++){
		for ( int j =0; j<col; j++){
			if ( i ==0 || i == row-1 || j ==0 || j == col-1){
				printf("\t%d", arr[i][j]);
			}else{
				printf("\t0");
			}
		}
		printf("\n");
	}
}

void cn5( int arr[20][20], int row, int col ){
	printf("\nBan chon chuc nang 5!\n");
	if ( row == col ){
		printf("\nHien thi duong cheo chinh, cheo phu theo ma tran: \n");
		for ( int i =0; i< row; i++){
			for ( int j =0; j<col; j++){
				if ( i==j || ( i+j == col-1) ){
					printf("\t%d", arr[i][j]);
				}else{
					printf("\t0");
				}
			}
			printf("\n");
		}
	}else{
		printf("\nChi ma tran vuong moi co cheo chinh, cheo phu! \nVui long tao mang co hang va cot bang nhau!");
	}
}

int checkNT( int n ){
	if ( n < 2) return -1;
	for( int i = 2; i<n ; i++){
		if ( n%i == 0) return -1;
	}
	return 1;
}
void cn6( int arr[20][20], int row, int col ){
	printf("\nBan chon chuc nang 6!\n");
	printf("\nHien thi ptu la so nguyen to theo ma tran: \n");
	for ( int i =0; i< row; i++){
		for ( int j =0; j<col; j++){
			if (checkNT(arr[i][j]) == 1){
				printf("\t%d", arr[i][j]);
			}else{
				printf("\t0");
			}
		}
		printf("\n");
	}
}

int main(){
	int arr[20][20];
	int n, m, choice, check = -1;
	
	do{
		printf("Nhap hang(1-20): ");
		scanf("%d", &n);
	}while( n <1 || n>20 );
	do{
		printf("Nhap cot(1-20): ");
		scanf("%d", &m);
	}while( m <1 || m>20 );
	
	printf("\nBan da nhap %d hang, %d cot!", n,m);
	
	do{
		printf("\n\n------------Menu------------------");
		printf("\n1. Nhap gia tri cac phan tu cho mang ");
		printf("\n2. In gia tri phan tu theo ma tran ");
		printf("\n3. In ra phan tu o goc theo ma tran");
		printf("\n4. In phan tu nam tren duong bien theo ma tran");
		printf("\n5. In phan tu nam tren duong cheo chinh & phu theo ma tran");
		printf("\n6. In phan tu la so nguyen to theo ma tran");
		printf("\n7. Thoat");
		printf("\n Lua chon cua ban: ");
		scanf("%d", &choice);
		
		switch( choice){
			case 1:{
				check = 1;
				cn1(arr, n, m);
				break;
			}
			case 2:{
				if ( check == 1){
					cn2(arr, n, m);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 3:{
				if ( check == 1){
					cn3(arr, n, m);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 4:{
				if ( check == 1){
					cn4(arr, n, m);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 5:{
				if ( check == 1){
					cn5(arr, n, m);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 6:{
				if ( check == 1){
					cn6(arr, n, m);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 7:{
				printf("\nBan chon thoat!");
				break;
			}
			default:{
				printf("\nVui long nhap dung lua chon(1-7)!");
				break;
			}
		}
		
	}while( choice != 7 );
	
	return 0;
}
