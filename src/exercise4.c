#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int size=10;
    float arr[size];
    for(int i = 0; i < size; ++i) { 
        scanf("%f ", &arr[i]);
    }
    int k =atoi(argv[2]);
    float x =strtod(argv[1],NULL);
    for (int i=0;i<size;i++){
        if(i==k){
            arr[i]=x;
        }
        printf("%g ",arr[i]);
    }
    printf("\n");
return 0;
}