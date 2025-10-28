#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int size=10;
    float arr[size];
    for(int i = 0; i < size; ++i) { 
        scanf("%f ", &arr[i]);
    }
    int k =atoi(argv[1]);
    for (int i=1;i<=size;i++){
        printf("%f ",arr[(i+size-1-k)%size]);
    }
    printf("\n");
return 0;
}