#include <stdio.h>
#include <stdlib.h>

int findUCLN( int a, int b){
	if ( a == 0 ) return b;
	if ( b == 0 ) return a;
	if ( a == b ) return a;
	if ( a == 0 && b == 0 ) return 0;
	
	int a1 = abs(a), b1 = abs(b);
	int uCLN = ( a1 > b1 )? b1 : a1 ;
	
	for ( int i = uCLN; i>0 ; i--){
		if ( a1%i == 0 && b1%i == 0){
			uCLN = i;
			break;
		}
	}
	return uCLN;
}

int main(){
	int a,b,c ;
	printf("Nhap 3 so nguyen: ");	
	scanf("%d %d %d", &a, &b, &c);
	
	int m = findUCLN(a, b);
	int uCLN = findUCLN(m, c);
	
	if ( uCLN == 0 ){
		printf("\n UCLN cua 3 so: k xac dinh");
	}else{
		printf("\n UCLN cua 3 so: %d", uCLN);
	}
	
	return 0;
}
