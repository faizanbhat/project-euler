/*
 Euler 14
Which starting number, under one million, produces the longest Collatz sequence?
 */

#include <stdio.h>
#include <time.h>

#define max_num 999999

// Store the sequence length for numbers between 1-maxn
int results[max_num];

void insert_result(long num, int sequence_length){
    if (num < max_num)
    	results[num-1] = sequence_length;
}

int get_result(long num){
    if (num < max_num)
			return results[num-1];
    else return 0;
}

// Calculate next number in collatz sequence
long next_in_collatz_sequence(long n){
       if (n%2 == 0)
				 return n/2;
			 return (long)((3*n)+1);
}


int sequence_length_for_num(long num){
    
    if (num==1){ // Base case
        return 1; 
    }
    
		int stored_count  = get_result(num); // use previously stored sequence lengths
    if (stored_count>0)
        return stored_count;

    long next = next_in_collatz_sequence(num); 
    int result = sequence_length_for_num(next)+1; // recursively find sequence length
    
    insert_result(num, result);     // Save sequence length before returning
		
    return result;
}

int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
    //  Begin solution
    
    int greatest_count=0;
    long result= 1;
    
    for (int i=1;i<=max_num;i++){
        
            int c = sequence_length_for_num(i); 
        
            if (c>greatest_count){
                greatest_count=c;
                result=i;
            }
    }

    printf("Number: %ld, Sequence length: %d\n",result, greatest_count);
    
		//    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}