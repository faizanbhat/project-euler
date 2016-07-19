/*
Euler 1
Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>
#include <time.h>
#include <math.h>
#define maxn 1000 

int brute_force(n){ 
    int sum=0;
    for (int i=3;i<n;i++){
        if (i%3==0||i%5==0){
            sum = sum+i;
        }
    }
    return sum;
}

int sum_of_multiples_of_num_below_ceil(num, ceiling){
    // LM = largest multiple LM of num below ceiling 
    int LM = floor((ceiling-1)/num);
    
    // Using sum series 1+2+3+4...+LM = LM(LM+1)/2
    int sum = num * (LM*(LM+1)/2);
    
    return sum;
}

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
//  Begin solution 
    
    //  Add sum of multiples of 3, 5, and subtract multiples of 15 due to double counting
    int sum = sum_of_multiples_of_num_below_ceil(3, maxn) + sum_of_multiples_of_num_below_ceil(5, maxn) - sum_of_multiples_of_num_below_ceil(15, maxn);
    
    printf("Result: %d\n", sum);
    
//    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}