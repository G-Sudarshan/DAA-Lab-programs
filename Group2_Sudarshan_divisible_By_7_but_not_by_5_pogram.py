# write  a progrm to find such a number which are divisible by 7 but not 5 between 2000 to 3200

for i in range(2000, 3200):
  if(i%7==0 and i%5!=0):
    print(i)
