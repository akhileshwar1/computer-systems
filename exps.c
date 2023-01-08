#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void print_array(int arr[],int s){
    for(int i=0; i<s; i++){
        printf("%d", arr[i]);
    }
}

int *get_array_reverse(int arr[],int s){
    int* result = malloc(sizeof(int)*400);
    for(int i=s-1; i>=0; i--){
        printf("%d\n", arr[i]);
        result[(s-1)-(i)]= arr[i];
    }

    return result;
}

int binary_to_int(int* arr, int s){
    int result = 0;
    for(int i=0; i<s;i++){
       if(i == (s-1)){
        result = result - ((*arr) * (int)pow(2, i));
        }
        else{
        result = result + ((*arr) * (int)pow(2, i));
        }
        arr++;
    }
    return result;
}


//void print_bytes(int* p){
//} 


char* int_to_bytes(int n){
    char bytes[4];
    bytes[0] = (n >> 24) & 0xFF;
    printf("%x\n", bytes[0]);
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = (n >> 0) & 0xFF;

    char* p = bytes;
    return p;
}

int xor(int x, int y){
    int b_array[32];
    for(int i=32; i>0; i--){
        int b1 = (x >> i);
        int b2 = (y >> i);
        int res1 = b1 & 1;
        int res2 = b2 & 1;
        if(res1 == res2){
            b_array[32 - i] = 0;
        }
        else{
            b_array[32 - i] = 1;
        }
    }
    int final = binary_to_int(b_array,32);
    printf("the final is %d\n", final);
    return final;
}
        


int main(){
    int x = -2147483648;
    char* z= int_to_bytes(x);
    int y = 2147483647;
    int finallisima = xor(x, y);
    printf("the finallisima is %d\n", finallisima);
    int result[320];

    int res;
    int rem;
    int rem1;
    for (int i=0; i<320; i++){
        rem = x%2;
        rem1 = y%2;
        if(rem == rem1){
            res = 0;
        }
        else{
            res = 1;
        }

        result[i] = res;
        x = x/2;
        y = y/2;
    }

    int* reverse = get_array_reverse(result,320);
    int final = binary_to_int(reverse, 320);
    printf("the final is %d\n", final);
    return final;
}



