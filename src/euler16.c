/*
 Euler 16
 What is the sum of the digits of the number 21000?
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Python solution: sum(int(x) for x in str(pow(2,1000)))
// Runs faster than this C implementation

#define n 330

void multiply_by_2(char* s) {
    int carry = 0;
    for (int i=n-1; i>=0; i--){
        int digit = s[i] - '0';
        int product = digit*2 + carry;
        int new_digit = product%10;
        carry = product/10;
        s[i] = new_digit + '0';
    }
}

int sum_digits(char* s){
    
    int sum = 0;
    for (int i=0; i<n; i++){
        sum = sum+(s[i]-'0');
    }
    
    return sum;
}


int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
    //  Begin solution

    char *prod = malloc( sizeof(char) * ( n + 1 ) );
    
    for (int i = 0; i < n; i++)
        prod[i] = '0';
    
    prod[n-1] =  '2';
    
    for(int i = 0;i < 999; i++){
        multiply_by_2(prod);
    }
    
    int result = sum_digits(prod);
    
    printf("%d\n",result);

    free(prod);

    //    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}