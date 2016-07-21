def get_sieved_primes(limit):
  sieve = range(0, limit)  
  for x in sieve:
    if x>1:
      factor = 2
      while (x * factor) < limit:
        sieve[x*factor] = 0
        factor = factor + 1
        
  return [x for x in sieve if x>1]

def get_prime_factors(n, prime_list):
    subset_primes = prime_list[0: 2*n*int(math.log(n)+2)]
    return [x for x in subset_primes if n % x ==0 ]
    
    
saved_divisors = {}
def get_total_divisors(number):
    """
    1. Save previously counted results in a dictionary 
    2. Total divisors of a given number equals 2 times the number of divisors of its square root
    """
    if number <= 2:
        return number
    try:
        d = saved_divisors[number]
        return d
    except:
        a = math.sqrt(number)
        array = list(range(1,int(a)))
        div = filter(lambda x: number%x == 0, array)
        total_divisors = len(div) * 2
        saved_divisors[number]=total_divisors
        return total_divisors