/*
Euler 2
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/


#include <stdio.h>
#include <time.h>

//    fib_n returns the nth number in the Fibonnaci seq via recursion
int fib_n(int n){ 
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return(fib_n(n - 1) + fib_n(n - 2));
}

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
//  Begin solution 
    
    int limit  = 4000000;
    int sum = 0;
    int n = 0;
    int fib = 0;
    
    // Every third term in the fibonnaci sequence is even
    // We'll increment n=0 by three in each step of the following loop
    // We'll generate fib_n(n), and add to sum unless fib_n(n)>limit
    
    while(1){
        
        n += 3;
        fib = fib_n(n);
        if(fib>limit){
            
            break;
        }
        else
         sum += fib_n(n);
    }
    
    printf("Result: %d\n", sum);
    
//    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}