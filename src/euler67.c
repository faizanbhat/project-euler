/*
 Euler 67
 Max Path Sum 2: Find the maximum total from top to bottom of the triangle
 https://projecteuler.net/problem=67
 */

#include <stdio.h>
#include <time.h>

/*
 
 Store numbers (i.e. elements) in a plain array indexed as such:
   0
  1 2
 3 4 5
 
 0 = Row 1, Col 1
 1 = Row 2, Col 1
 and so on..
 */

// Return total number of elements in n rows
int elements_in_rows(int n){
    int sum = 0;
    for (int i=1;i<=n;i++)
        sum = sum + i;
    return sum;
}

// Return row of element at index
int row_for_index(int index){
    int n = index+1;
    if (n==0) return 0;
    int rows = 1;
    for (int i = 1; 1==1; i+=rows){
        if (n <= i) return rows;
        else rows++;
    }
    return 0;
}

// Return column of element at index
int col_for_index(int index){
    int n = index+1;
    int rows = 1;
    for (int i = 1; 1==1; i+=rows){
        if (n <=i) break;
        else rows ++;
    }
    int col = index + 1 - elements_in_rows(rows-1);
    return col;
}

// Return index for element at row, col
int index_for_row_col(int row, int col) {
    int total = elements_in_rows(row-1);
    return total + col - 1;
}

// Return index of left child
int l_child_index(int index){
    int r = row_for_index(index);
    int c = col_for_index(index);
    return index_for_row_col(r+1, c);
}

// Return index of right child
int r_child_index(int index){
    int r = row_for_index(index);
    int c = col_for_index(index);
    return index_for_row_col(r+1, c+1);
}

int max_path_sum(int values[], int size){
    int last_row = row_for_index(size-1);
    for (int row = last_row - 1; row > 0; row--){ // Loop through rows, starting with last but one
        int first_col_index = index_for_row_col(row, 1);
        int last_col_index = first_col_index + row - 1;
        for (int i = first_col_index; i <= last_col_index; i++) { // Loop through cols in row
            // For each element, get left and right child, and add max of children to value of element
            int c_1 = l_child_index(i), c_2 = r_child_index(i);
            if (values[c_1] > values[c_2])
                values[i] += values[c_1];       
            else values[i] += values[c_2];
        }
    }
    return values[0];
}


int main(){
    clock_t begin, end;
    double time_spent;
    begin = clock();
    //  Begin solution
    
    FILE *file;
    file = fopen("./data/p067_triangle.txt", "r");
    
    int values[5050];
    int i=0;
    int num;
    
    while(fscanf(file, "%d", &num) > 0) {
        values[i] = num;
        i++;
    }
    
    fclose(file);
    
    int size = sizeof(values)/sizeof(values[0]);
    int result = max_path_sum(values, size);
    
    printf("Result: %d \n", result);
    
    //    End solution
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Found result in %f time\n", time_spent);
    return 0;
}