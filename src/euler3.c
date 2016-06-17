/*
 Euler 3
 What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <time.h>
#include <math.h>

int64_t largest_prime_factor(int64_t num){
    int64_t n = num;
    int64_t divisor=2;
    int64_t factor=0;
    int64_t remainder=1;
    
    while (1){
        factor = n/divisor;
        remainder = n%divisor;
        
        if(factor==1&remainder==0){
            return divisor;
        }
        
        else if(remainder>0){
            divisor++; // could be optimised – increment to next prime number
            
        }
        
        else if(remainder==0){
            n = factor;
        }
    }
    
    return 0;
}


int main(){
    clock_t begin, end;
    double time_spent;
    begin=clock();
//  Begin code
    
    int64_t num = 600851475143;
    printf("Result:%lld \n", largest_prime_factor(num));

    
//  End code
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}