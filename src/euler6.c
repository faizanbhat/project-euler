/*
Euler 6
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <stdio.h>
#include <time.h>
#define first_n 100
int sum_of_squares(int nums){
    
    return (nums*(nums+1)*(2*nums+1))/6;
}

int sum_squared(int nums){
    
    return ((nums*(nums+1))/2) * ((nums*(nums+1))/2);
}

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
//  Begin solution  
    
    printf("%d\n",sum_squared(first_n)-sum_of_squares(first_n));
    
//  End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}