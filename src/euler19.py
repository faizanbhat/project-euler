"""
Euler 19
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
"""

from itertools import compress
import timeit

def days_in_month(month, year):
    calendar = {1:31,3:31,4:30,5:31,6:30,7:31,8:31,9:30,10:31,11:30,12:31}
    if month == 2:
        if year%100 == 0:
            if year%400 == 0:
                return 29
            else:
                return 28
        else: 
            if year%4 == 0:
                return 29
            else:
                return 28
    else:
        return calendar[month];
        
def count_sundays():
    weekdays = ["Tue","Wed","Thu","Fri","Sat","Sun","Mon"]
    weekdays_sunday_mask = [False,False,False,False,False,True,False]
    all_days_masked = []
    for day in xrange(0,365*100+25):
        all_days_masked.append(weekdays_sunday_mask[day%7])      

    all_dates = []
    for year in xrange(1901,2001):
        for month in xrange (1,13):
            for i in xrange (1,days_in_month(month,year)+1):
                all_dates.append(i)
            

    only_sundays = list(compress(all_dates,all_days_masked))
    return only_sundays.count(1)
    
# Run
start_time = timeit.default_timer()
n = count_sundays()
print "Sundays in the last century: " + str(n)
print "Time: " + str(timeit.default_timer() - start_time)    
