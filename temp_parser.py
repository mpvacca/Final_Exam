import sys
import time
import os


line_count = 0
temps = sys.argv[1]
HT = int(sys.argv[2])
temps_found = 1
Avg = 0
fp = open(temps,'r')
data = fp.readlines()
for line in data:
  str1 = ''.join(data)
  temp = int(str1)
  if temp < HT:
    Avg = temp + Avg
    temps_found +=1
fp.close()
print('\t\t\t\tCPE 422/522 Final Exam')
print 'File name of sensor temperatures: ', temps
print 'Number of temperatures below', HT,'degrees C: ', temps_found
Avg = round(Avg/temps_found,3)
print 'Average Temperature: ', Avg
