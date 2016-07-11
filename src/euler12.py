"""
Euler 12
What is the value of the first triangle number to have over five hundred divisors?

A better implementation would add exponents of prime factors: http://mathschallenge.net/library/number/number_of_divisors
"""

import math
import time 
import numpy

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
        
def triangle_num_with_divisors(min_divisors):
    """
    1. Triangle numbers follow a sum of series pattern 
        nth triangle number = n * (n+1) / 2
    2. n and n+1 are coprimes so we can find divisors of both and multiply
    """
    
    n = 0 #nth triangle number
    total_divisors = 0
    while total_divisors<min_divisors:
        n = n+1
        if n%2==0:
            a=get_total_divisors(n/2)
            b=get_total_divisors(n+1)
            total_divisors = a*b
            
        elif (n+1)%2==0:
            a=get_total_divisors(n)
            b=get_total_divisors((n+1)/2)
            total_divisors = a*b
    
    result = n*(n+1)/2      
    return result


start_time = time.time()
print triangle_num_with_divisors(501)
print "Found result in " + str(time.time()-start_time) + " seconds"