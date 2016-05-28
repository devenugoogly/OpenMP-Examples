#include<stdio.h>
int main(){
	int a[10000]={1},n=10000;
      	for ( int i=0; i< n; i++ ) {
       	printf("id: %d\n",i);
		if(i%2==0)
			a[i] = 1;
		else
			a[i] = 2;
      	}
   
	printf("After Diffusion\n");
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
