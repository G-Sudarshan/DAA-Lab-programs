# perform operations on one dimensional array using numpy
import numpy as np

# declare array
arr1 = np.arange(5)
arr2 = np.arange(5)

# initialize arr1
print("Enter elements  of first array: ")
for i in range(0, 5):
  arr1[i] = int(input("Enter element {0} of arr1: ".format(i)))


# initialize arr2
print("Enter elements of Second array: ")
for i in range(0, 5):
  arr2[i] = int(input("Enter element {0} of arr2: ".format(i)))


print("First array: ")
print(arr1)

print("Second array: ")
print(arr2)

print("------------------------------------")

print('\nAdding the two arrays:') 
print(np.add(arr1, arr2))
  
print('\nSubtracting the two arrays:') 
print(np.subtract(arr1, arr2))
  
print('\nMultiplying the two arrays:')
print(np.multiply(arr1, arr2))
  
print('\nDividing the two arrays:')
print(np.divide(arr1, arr2))
