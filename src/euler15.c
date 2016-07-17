/*
 Euler 15
How many lattice paths are there through a 20x20 grid
 */

#include <stdio.h>
#include <time.h>


// Implementation from https://en.wikipedia.org/wiki/Binomial_coefficient
long binomial(int n, int k){
    
    if (k < 0 || k > n)
        return 0;
    
    if (k == 0 || k == n)
        return 1;
        
    long res = 1;
    
    if (k>(n-k))
        k = n-k;
    
    for (int i = 1; i <= k; i++) {
        res = res * (n + 1 - i);
        res /= (i);
    }
    
    return res;
}

int main(){
    
    clock_t begin, end;
    double time_spent;
    begin = clock();
    //  Begin solution
    
    int total_steps = 40;
    int down_steps = 20;
    
    // We need to take 20 steps down and 20 steps right - i.e. 40 total steps
    // Use binomial coefficients to find how many ways there are to pick 20 down steps in 40 total steps
    
    long result = binomial(total_steps, down_steps);
    
//    long result = factorial(total_steps)/(factorial(down_steps))*factorial(total_steps - down_steps);
    
    printf("%ld \n", result);
   
    //    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}