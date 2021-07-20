# program to take 3 no. as input and print max from them

a = int(input("Enter a : "))
b = int(input("Enter b : "))
c = int(input("Enter c : "))

if (a > b) and (a > c):
  print("a is largest")  
elif (b >= a) and (b >= c):
  print("b is largest")  
else:
  print("c is largest")
