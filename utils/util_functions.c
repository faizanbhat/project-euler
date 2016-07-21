int sum_digits(char* s){ 
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum = sum + (s[i] - '0');
  }
  return sum;
}

void multiply_strnum_by(char* s, int factor) {
  int carry = 0;
  for (int i = n-1; i >= 0; i--){
    int digit = s[i] - '0';
    int product = (digit * factor) + carry;
    int new_digit = product%10;
    carry = product / 10;
    s[i] = new_digit + '0';
  }
}

// Implementation from https://en.wikipedia.org/wiki/Binomial_coefficient
long binomial(int n, int k){
  if (k < 0 || k > n) 
    return 0;
  if (k == 0 || k == n) 
    return 1;
  long res = 1;
  if (k>(n-k))
    k = n - k;
  for (int i = 1; i <= k; i++) {
    res = res * (n + 1 - i);
    res /= (i);
  }
  return res;
}

int is_pythagorean_triplet(int a, int b, int c){
  int lhs = a*a + b*b;
  int rhs = c*c;
  if (lhs == rhs){
    return 1;
  }
  return 0;    
}

int get_sieve_size(n_primes){
  // max sieve size should be n*log(n). x2 for buffer. 
  return (2 * n_primes * (int)log(n_primes));
}

int sum_of_squares(int nums){
  return (nums*(nums+1) * (2*nums+1)) / 6;
}

int sum_squared(int nums){
  return ((nums*(nums+1)) / 2) * ((nums*(nums+1)) / 2);
}

int is_palindrome_num(int num){
  int reverse = 0;
  while (num > 0) {
    reverse = reverse * 10;
    reverse = reverse + (num%10);
    num = num/10;
  }
  if (reverse == num_org){
    return 1;
  }
  else return 0; 
}

long largest_prime_factor(long n){
  long divisor = 2;
  long factor = 0;
  long remainder = 1;
    
  while (1){
    factor = n / divisor;
    remainder = n % divisor;
        
    if(factor==1 && remainder==0){
      return divisor;
    }
        
    else if(remainder>0){
      divisor++; // could be optimised – increment to next prime number
            
    }
        
    else if(remainder==0){
      n = factor;
    }
  }
    
  return 0;
}

//    fib_n returns the nth number in the Fibonnaci seq via recursion
int fib_n(int n){ 
  if (n == 0) return 0;
  else if (n == 1) return 1;
  else return(fib_n(n - 1) + fib_n(n - 2));
}

int sum_of_multiples_of_num_below_ceil(num, ceiling){
  // LM = largest multiple LM of num below ceiling 
  int LM = floor((ceiling - 1) / num);
    
  // Using sum series 1+2+3+4...+LM = LM(LM+1)/2
  int sum = num * (LM * (LM+1) / 2);
    
  return sum;
}
