/*
Euler X
Question
*/

#include <stdio.h>
#include <time.h>

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
//  Begin solution 



//    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}