# find factorial of given no

def fact(num):
  if(num==0):
    return 1
  else:
    return num*fact(num-1)


a = int(input("Enter number: "))
res = fact(a);
print("Factorial of {0} is {1}".format(a, res))
