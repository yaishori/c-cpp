int isAsc(int n){
int x=1;
remainder1=n%10;
n=n/10;
	while(n!=0){
	remainder2=n%10;
		if(remainder2 >= remainder1){
		x=0;
		break;
		}
	remainder1=remainder2;
	n=n/10;
		if(n<10){
			if(n >= remainder1){
			x=0;
			break;
			}
			
		}
	
	}
return x;
}


int main (){
	printf("enter number:");
	int n;
	scanf("%d, &n);
	int x = isAsc(n);
	printf("%d",x);
	return 0;
}

