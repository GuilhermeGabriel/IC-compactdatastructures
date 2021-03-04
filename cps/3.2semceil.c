#include <stdio.h>
#include <math.h>

int n=10,l=5,w=32;
unsigned int W[2];

int bitRead(unsigned int *W, int j){
	return (W[j/w]/(1<<w-(((j-1)%w)+1)))%2;
}

void bitSet(unsigned int *W, int j){
	if((W[j/w]/(1<<w-(((j-1)%w)+1))%2)==0)
		W[j/w]+=(1<<w-(((j-1)%w)+1));
}

void bitClear(int *W, int j){
	if((W[(j/w)]/(1<<w-(((j-1)%w)+1))%2)==1)
		W[(j/w)]-=(1<<w-(((j-1)%w)+1));
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