/*
 Euler 10
 Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <time.h>

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
    //  Begin solution
    
    int n = 2000000;
    long long sum = 0;
    
    // Reusing prime sieve from problem 7
    
    int sieve[n];
    
    // Fill up list
    for (int i=0;i<n;i++){
        sieve[i] = i;
    }
   
    int sieve_index = 0;

    // Sieve the list for primes
    while (sieve_index<n){
        int current_observation = sieve[sieve_index];
        
        if (current_observation > 1){
            
            // If prime is found, add to sum and null all multiples
            sum = sum+current_observation;
            int factor = 2;
            
            while ((sieve_index*factor)<n){
                sieve[sieve_index*factor]=0;
                factor++;
            }
        }
        
        sieve_index++;
    }
    
    printf("Result: %lld\n",sum);
    
    //    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}