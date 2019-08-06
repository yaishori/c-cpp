int reverse(int n){
	
int remainder;
int reverseInt;
while( n != 0 ) {
remainder = n % 10;
reversedInt = reversedInt * 10 + remainder;
n=n/10;
}
return reversedInt;
}

int isPalindrome(int n){
int x;
int ans;
x = reverse(n);
ans = (n==x) ? 1 : 0;

return ans;

}


int main (){
	printf("enter number:");
	int n;
	scanf("%d, &n);
	int x = isPalindrome(n);
	printf("%d",x);
	return 0;
}

