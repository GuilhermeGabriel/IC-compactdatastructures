#include <stdio.h>
#include <math.h>

#define Ceil(x,y) (x/y + (x%y!=0))

unsigned int n=10,l=5,w=32,W[2];

int pot(int b,int ex){
 return pow(b,ex);
}

int bitRead(unsigned int *W, int j){
	int r=((j-1)%w)+1;
	return (W[Ceil(j,w)]/pot(2,w-r))%2;
}

void bitSet(unsigned int *W, int j){
	int r=((j-1)%w)+1;
	if((W[Ceil(j,w)]/pot(2,w-r)%2)==0){
		W[Ceil(j,w)]+=pot(2,w-r);
	}
}

void bitClear(int *W, int j){
	int r=((j-1)%w)+1;
	if((W[Ceil(j,w)]/pot(2,w-r)%2)==1){
		W[Ceil(j,w)]-=pot(2,w-r);
	}
}

int main(){
	bitSet(W,1);
	for(int i=1;i<=64;i++)
		printf("%d", bitRead(W,i));
	
	printf("\n\n%u %u", W[0], W[1]);

	return 0;
}