#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int size=10;
    float arr[size];
    for(int i = 0; i < size; ++i) { 
        scanf("%f ", &arr[i]);
    }
    for (int i=size-1;i>=0;i--){
        printf("%f ",arr[i]);
    }
    printf("\n");
return 0;
}