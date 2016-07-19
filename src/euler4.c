/*
Euler 4
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
#include <time.h>

typedef int bool;

bool is_palindrome(int num_org);

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
//  Begin solution 
        
    int prod;
    int result=0;

    for (int i=999;i>99;i--){
        for (int j=999;j>99;j--){
            prod = i*j;
            if(is_palindrome(prod)){
                if(prod>result) result = prod;
            }
        }
        
    }
    
    printf("Result: %d\n", result);
    
//    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}

int is_palindrome(int num_org){
    
    int num = num_org;
    
    int reverse = 0;
    
    while (num>0) {
        reverse = reverse*10;
        reverse = reverse + (num%10);
        num = num/10;
    }
    
    if (reverse==num_org){
        return 1;
    }
    
    else return 0;
    
}