/*
Euler 5
Find the smallest positive number that is evenly divisible by all of the numbers from 1 to 20
*/

#include <stdio.h>
#include <time.h>

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
//  Begin solution 
    
    /* 
    Lets say that our num is X
    1. X is a multiple of all prime numbers between 1 to 20, therefore we only need to test multiples of the product of all primes between 1 to 20.
    2. We can ignore testing divisiblity by numbers below 11 as they are all factors of numbers between 11 to 20
    */
    
    int base = 19*17*13*7*5*3*2;
    int num = base;
    int multiply_by = 1;
    int count = 0;
    
    while (1){
        
        count = count+1;
        if (num%11==0 & num%12==0 & num%13==0 & num%14==0 & num%15==0 & num%16==0 & num%17==0 & num%18==0 & num%19==0 & num%20==0){
            break;
        }
        else{
            multiply_by++;
            num=base*multiply_by;
        }
    }
    
    printf("Result: %d\n",num);
    printf("Took %d iterations\n",count);
    
//    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}