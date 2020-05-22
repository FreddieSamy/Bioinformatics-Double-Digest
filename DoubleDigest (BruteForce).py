AB=input("Enter A+B numbers separated by , :")
AB=AB.split(',')
for i in range(len(AB)):
    AB[i]=int(AB[i])
Sum=sum(AB)
if Sum%2!=0:
    print("invailed Multiset..sum of all numbers must be even")
else:
    Sum/=2
    import math
    import itertools
    print("possible Solutions:")
    for i in range(1,math.ceil(len(AB)/2)+1):
        c=itertools.combinations(AB,i)
        for j in c:
            temp=AB.copy()
            if sum(j)==Sum:
                [temp.remove(z) for z in j]
                print(j,temp)



    
