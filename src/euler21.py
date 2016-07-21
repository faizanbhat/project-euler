"""
Euler 21
Evaluate the sum of all the amicable numbers under 10000.
"""

import timeit
import math 

  
def sum_of_divisors(n):
  """
  Iterate through possible divisors from 2 to square root of n
  When a divisor is found, store both the divisor and the factor to the list
  """
  divisor_list = [1]
  
  for possible_divisor in xrange(1, int(math.sqrt(n))):
    mult_factor = n / possible_divisor
    remainder = n % possible_divisor
    if remainder == 0 and possible_divisor not in divisor_list:
      divisor_list.append(possible_divisor)
      if (mult_factor) not in divisor_list:
        divisor_list.append(mult_factor)   
         
  return sum(divisor_list)

def is_amicable(n):
  """
  Find pairs of numbers where sum of divisors of each number returns the other & sum of divisors isn't equal to the number itself e.g. 1
  """
  n_1 = sum_of_divisors(n)
  n_2 = sum_of_divisors(n_1)
  if n_2 == n and n_1 != n: 
    return True
  else:
    return False
  
def sum_amicable(limit):
  sum = 0
  for n in xrange(2,limit,1):
    if is_amicable(n):
      sum = sum + n
      
  return sum

start_time = timeit.default_timer()
print "Sum: " + str(sum_amicable(10000))
print "Time: " + str(timeit.default_timer() - start_time)
  
    