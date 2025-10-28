#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int size=10;
    float arr[size];
    for(int i = 0; i < size; ++i) { 
        scanf("%f ", &arr[i]);
    }
    float sum=0;
    for (int i=0;i<size;i++){
        sum+=arr[i];
    }
    sum/=size;
    printf("%f",sum);
    printf("\n");
return 0;
}