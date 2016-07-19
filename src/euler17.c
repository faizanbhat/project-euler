/*
 Euler 17
 If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 */

#include <stdio.h>
#include <time.h>
#include <string.h>

const char *c_ones[20]={
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

const char *c_tens[10]={
    "",
    "",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

const char *c_hundreds[10]={
    "",
    "onehundred",
    "twohundred",
    "threehundred",
    "fourhundred",
    "fivehundred",
    "sixhundred",
    "sevenhundred",
    "eighthundred",
    "ninehundred"
};


short count_letters_for_number(short n){

    short count = 0;
    
    if (n==1000){
        return 11;
    }
    
    short ones = n % 10;
    short tens = (n %100) / 10;
    short hundreds = (n % 1000) / 100;
    
    short last_two_digits = (tens * 10) + ones;
    
    if (last_two_digits <20){
        
        count = count + (short)strlen(c_ones[last_two_digits]);
    }
    
    else if (last_two_digits >= 20){
        count = count + (short)strlen(c_tens[tens]);
        count = count + (short)strlen(c_ones[ones]);
    }
    
    if(n>=100){
        
        count = count + (short)strlen(c_hundreds[(hundreds)]);
        
        if (n % 100 != 0) {
            count = count + 3; // add 3 for 'and'
        }
        
    }
    
    return count;
}

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
    //  Begin solution
    short sum = 0;
    
    for (short i = 1; i<=1000; i+=1){
        
        sum = sum + count_letters_for_number(i);
    }
    
    printf("%d \n",sum);
    
    //    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}