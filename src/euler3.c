/*
 Euler 3
 What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <time.h>
#include <math.h>
#define given_number 600851475143

long largest_prime_factor(long n){
    long divisor=2;
    long factor=0;
    long remainder=1;
    
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
    
    printf("Result:%ld \n", largest_prime_factor(given_number));

    
//  End code
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}