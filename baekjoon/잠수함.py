import re
import sys

pattern = re.compile('(100+1+|01)+') 
   
s = input()
result = pattern.fullmatch(s)
        
if result == None:
    print('NOISE')
            
else:
    print('SUBMARINE')


