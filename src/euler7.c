/*
Euler 7
What is the 10001st prime number?
*/

// Solution: Sieve of Eratosthenes –– https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <stdio.h>
#include <time.h>
#include <math.h>
#define n 10001

int get_sieve_size(n_primes){
    
    // max sieve size should be n*log(n). x2 for buffer. 
    return (2*n_primes*(int)log(n_primes));
}

int main(){
    
    clock_t begin, end;
    double time_spent;
    begin = clock();
//  Begin solution
            
    // Create sieve and fill it up
    int sieve_size = get_sieve_size(n);
    int sieve[sieve_size];
    
    for (int i=0;i<sieve_size;i++){
        sieve[i] = i; // start with zero, so that sieve index matches sieve value
    }
    
    // Create prime number storage
    int primes[n];

    // Sieve – keep going until you find the prime you want or hit sieve limit
    int prime_count = 0;
    int sieve_index = 0;

    while (prime_count<n & sieve_index<sieve_size){ 
        int current_observation = sieve[sieve_index];
        
        if (current_observation > 1){
            primes[prime_count] = current_observation;
            prime_count++;
            int factor = 2;
            
            while ((sieve_index*factor)<sieve_size){
                sieve[sieve_index*factor]=0;
                factor++;
            }
        }
        sieve_index++;
    }
    
    printf("Result: %d\n",primes[n-1]);
    
//    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;    
}