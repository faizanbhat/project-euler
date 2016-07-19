/*
 Euler 9
 There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
 */

#include <stdio.h>
#include <time.h>

int is_pythagorean_triplet(int a, int b, int c){
    int lhs = a*a+b*b;
    int rhs = c*c;
    if (lhs==rhs){
        return 1;
    }
    return 0;    
}

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
    //  Begin solution
    
    short a,b,c;
    int result=0;
    
    // Loop through possible values of a, starting from 1 and ending at 1000
    for (a=1;a<=1000;a++){
        
        // Loop through possible values of b, starting from a and ending at 1000-a
        for (b=a+1;b<=1000-a;b++){
            
            // Third number has to be 1000-(first number + second number), hence we can avoid looping through possible values of c
            c = 1000-(a+b);
            
            // c should always be greater than both a and b. Use a condition to break for negative values of c
            if (c<b){
                break;
            }
            
            if (is_pythagorean_triplet(a, b, c)){
                result = a*b*c;
                goto print_result;
            }
        }
    }
    
    print_result:
    printf("Result: %d\n",result);
    
    //    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}