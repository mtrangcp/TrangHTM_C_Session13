#include <stdio.h>
#include <stdbool.h>

void cn1( int arr[], int *n ){
	printf("\nBan chon chuc nang 1!\n");
	do{
		printf("Nhap so phan tu(1-20): ");
		scanf("%d", n);
	}while( *n <1 || *n>20 );
	
	for ( int i =0; i< *n; i++){
		printf("Nhap ptu thu %d: ", i+1);
		scanf("%d", &arr[i] );
	}
}

void cn2( int arr[], int n ){
	printf("\nBan chon chuc nang 2: hien thi!\n");
	for ( int i =0; i< n; i++){
		printf("\t%d", arr[i] );
	}
}

void cn3( int arr[], int n ){
	printf("\nBan chon chuc nang 3: them 1 phan tu!\n");
	int index, num;
	
	printf("\nNhap vi tri muon them (1-%d): ",n+1 );
	scanf("%d", &index);
	while ( index > (n+1) || index < 1 ){
		printf("Vi tri khong hop le!");
		printf("\nNhap vi tri muon them (1-%d): ",n+1 );
		scanf("%d", &index);
	}
	
	printf("Nhap gia tri muon them: ");
	scanf("%d", &num);
	n +=1;
	
	for ( int i = n ; i> index-1; i--){
		arr[i] = arr[i-1];
	}
	arr[index-1] = num;
	
	printf("\nkq: ");
	for ( int i = 0; i< n; i++){
		printf("\t%d", arr[i]);
	}
}

void cn4( int arr[], int n ){
	printf("\nBan chon chuc nang 4: Sua 1 phan tu!\n");
	int index, num;
	
	printf("\nVi tri muon sua(1-%d): ", n);
	scanf("%d", &index);
	while ( index > n || index < 0){
		printf("Vi tri khong hop le!");
		printf("\nVi tri muon sua(1-%d): ", n);
		scanf("%d", &index);
	}
	
	printf("Gia tri muon sua: ");
	scanf("%d", &num);
	
	arr[index-1] = num;
	
	printf("\nPhan tu sau update: ");
	for ( int i = 0; i< n  ; i++){
		printf("\t%d", arr[i]);
	}
}

void cn5( int arr[], int n ){
	printf("\nBan chon chuc nang 5: Xoa 1 phan tu!\n");
	int index, num;
	
	printf("\nnhap vi tri muon xoa(1-%d): ", n );
	scanf("%d", &index);
	while ( index > n || index < 0){
		printf("Vi tri khong hop le!");
		printf("\nnhap vi tri phan tu muon xoa(1-%d): ", n );
		scanf("%d", &index);
	}
	
	for ( int i = index-1; i< n; i++){
		arr[i] = arr[i+1];
	}
	n -= 1;
	
	printf("\nkq: ");
	for ( int i = 0; i< n; i++){
		printf("\t%d", arr[i]);
	}
}

void cn6( int arr[], int n ){
	printf("\nBan chon chuc nang 6: sap xep!\n");
	char chose;
	
	printf("\na. Giam dan");
	printf("\nb. Tang dan");
	do{
		printf("\nMoi chon: ");
		scanf("%c", &chose);
	}while( chose!= 'a' && chose!= 'b' );
	
	switch(chose){
		case 'a':{
			printf("\nBan chon sap xep giam dan!");
			for ( int i =0; i<n ; i++){
				for ( int j =0; j< n-1-i; j++){
					if ( arr[j] < arr[j+1] ){
						int temp = arr[j] ;
						arr[j] = arr[j+1] ;
						arr[j+1] = temp ;
					}
				}
			}
			break;
		}
		case 'b':{
			printf("\nBan chon sap xep giam dan!");
			for ( int i =0; i<n ; i++){
				for ( int j =0; j< n-1-i; j++){
					if ( arr[j] > arr[j+1] ){
						int temp = arr[j] ;
						arr[j] = arr[j+1] ;
						arr[j+1] = temp ;
					}
				}
			}
			break;
		}
	}
	printf("\nKet qua: ");
	for ( int i =0; i< n; i++){
		printf("\t%d", arr[i] );
	}
}

bool checkTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) return false;
    }
    return true;
}

bool checkGiamDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) return false;
    }
    return true;
}

int checkSX( int arr[], int n ){
	if ( checkGiamDan(arr,n)){
		return 1;
	}else if ( checkTangDan(arr, n)){
		return 2;
	}else{
		return 0;
	}
}
void cn7( int arr[], int n ){
	printf("\nBan chon chuc nang 7: Tim kiem !\n");
	int  num;
	char chose;
	
	printf("\na. Tim kiem tuyen tinh ");
	printf("\nb. Tim kiem nhi phan ");
	do{
		printf("\nMoi chon: ");
		scanf("%c", &chose);
	}while( chose!= 'a' && chose!= 'b' );
	
	printf("\nNhap so muon tim: ");
	scanf("%d", &num);
	
	switch(chose){
		case 'a':{
			printf("\nTim kiem tuyen tinh");
			printf("\nPhan tu can tim o vi tri: ");
			for ( int i =0; i<n ; i++){
				if ( arr[i] == num ){
					printf("\t%d ", i+1);
				}
			}
			break;
		}
		case 'b':{
			printf("\nTim kiem nhi phan");
			int start = 0, mid, end = n, count = 0;
			
			if ( checkSX(arr, n) == 1 ){
				while( start <= end){
					mid = ( start + end)/2 ;
					if ( arr[mid] == num){
						printf("\nVi tri phan tu muon tim: %d", mid+1);
						count++;
						break;
						
					}else if ( arr[mid] > num){
						start = mid+1;
					}else{
						end = mid -1;
					}
				}
				if ( count == 0 ) printf("\nKhong tim thay vi tri cua phan tu can tim!");
				
			}else if (checkSX(arr, n) == 2 ){
				while( start <= end){
					mid = ( start + end)/2 ;
					if ( arr[mid] == num){
						printf("\nVi tri phan tu muon tim: %d", mid+1);
						count++;
						break;
						
					}else if ( arr[mid] > num){
						end = mid -1;
					}else{
						start = mid+1;
					}
				}
				if ( count == 0 ) printf("\nKhong tim thay vi tri cua phan tu can tim!");
				
			}else{
				printf("\nMang chua duoc sap xep, k dung duoc sap xep nhi phan!");
			}
			break;
		}
	}
}

int main(){
	int arr[100];
	int n = 0, choice, check = -1;
	
	do{
		printf("\n\n------------Menu------------------");
		printf("\n1. Nhap so luong va gia tri cac phan tu ");
		printf("\n2. In gia tri phan tu ");
		printf("\n3. Them 1 phan tu vao vi tri chi dinh ");
		printf("\n4. Sua 1 phan tu vao vi tri chi dinh ");
		printf("\n5. Xoa 1 phan tu vao vi tri chi dinh ");
		printf("\n6. Sap xep ");
		printf("\n7. Tim kiem  ");
		printf("\n8. Thoat");
		printf("\n Lua chon cua ban: ");
		scanf("%d", &choice);
		fflush(stdin);
		
		switch( choice){
			case 1:{
				check = 1;
				cn1( arr, &n);
				break;
			}
			case 2:{
				if ( check == 1){
					cn2(arr, n);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 3:{
				if ( check == 1){
					cn3(arr, n);
					n++;
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 4:{
				if ( check == 1){
					cn4(arr, n);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 5:{
				if ( check == 1){
					cn5(arr, n);
					n--;
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 6:{
				if ( check == 1){
					cn6(arr, n);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 7:{
				if ( check == 1){
					cn7(arr, n);
				}else{
					printf("\nMang dang rong! Vui long chon cn1!");
				}
				break;
			}
			case 8:{
				printf("\nBan chon thoat!");
				break;
			}
			default:{
				printf("\nVui long nhap dung lua chon(1-8)!");
				break;
			}
		}
	}while( choice != 8 );
	
	return 0;
}
