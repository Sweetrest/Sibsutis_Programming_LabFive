#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int size=10;
    float arr[size];
    for(int i = 0; i < size; ++i) { 
        scanf("%f ", &arr[i]);
    }
    int k =atoi(argv[2]);
    float x =atoi(argv[1]);
    for (int i=0;i<size;i++){
        if(i==k-1){
            arr[i]=x;
        }
        printf("%f ",arr[i]);
    }
    printf("\n");
return 0;
}