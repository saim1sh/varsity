#include<stdio.h>
int main()
{
	int X,Y;
	float snack;
	scanf("%d %d",&X,&Y);
	float arr[5]={4.00,4.50,5.00,2.00,1.50};
	snack=arr[X-1]*Y;
	printf("Total: R$ %.2f\n",snack);

	return 0;
}