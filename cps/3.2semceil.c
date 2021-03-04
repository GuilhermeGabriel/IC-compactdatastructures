#include <stdio.h>
#include <math.h>

unsigned int n=10,l=5,w=32,W[2];

int pot(int b,int ex){
 return pow(b,ex);
}

int bitRead(unsigned int *W, int j){
	int r=((j-1)%w)+1;
	return (W[j/w]/pot(2,w-r))%2;
}

void bitSet(unsigned int *W, int j){
	int r=((j-1)%w)+1;
	if((W[j/w]/pot(2,w-r)%2)==0){
		W[j/w]+=pot(2,w-r);
	}
}

void bitClear(int *W, int j){
	int r=((j-1)%w)+1;
	if((W[(j/w)]/pot(2,w-r)%2)==1){
		W[(j/w)]-=pot(2,w-r);
	}
}

int main(){
  for (int bit =0; bit < 64; bit++) {
    bitSet(W,bit);
    for(int i=0;i<32;i++)
      printf("%d", bitRead(W,i));
    for(int i=32;i<64;i++)
      printf("%d", bitRead(W,i));
    printf("\n");                                                                                                                                 
  }

  printf("\n\n %u %u", W[0], W[1]);
  
  return 0;
}