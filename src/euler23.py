"""
Euler 23
Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
"""
import timeit
start_time = timeit.default_timer()
import math

def divisors(n):
    yield 1
    largest = int(math.sqrt(n)) + 1
    for i in range(2, largest):
        if n % i == 0:
            yield i
            if i < n / i:
                yield n / i
            
def is_abundant(n):
    if sum(divisors(n)) > n:
        return True
    return False

abundants = set(n for n in xrange(12,29124) if is_abundant(n))
odd_abundants = sorted(set(n for n in abundants if n%2==1))

def is_abundant_sum(n):
    
    if n%2 == 1:
        for a in odd_abundants:
            if a >= n:
                return False
            x = n-a
            if x in abundants:
                return True
        return False
        
    else: 
        if n > 46:
            return True
        
        for a in abundants:
            if a >= n:
                return False
            x = n-a
            if x in abundants:
                return True
        return False

not_abundant_sums = [n for n in xrange(1,29124) if not is_abundant_sum(n)]

result = sum(not_abundant_sums)

print result

print "Time: " + str(timeit.default_timer() - start_time)