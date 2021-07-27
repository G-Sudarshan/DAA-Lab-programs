# matrix operations

# declare multi-dimensional arrays
arr1 = np.arange(4).reshape(2, 2) 
arr2 = np.arange(4).reshape(2, 2)

# initialise arr1
print("Enter elements of arr1")
for i in range(0,2):
  for j in range(0,2):
    arr1[i][j] = int(input("Enter element arr1[{0}][{1}]: ".format(i,j)))

print("---------------------------------")

#initialse arr2
print("Enter elements of arr2")# matrix operations

# declare multi-dimensional arrays
arr1 = np.arange(4).reshape(2, 2) 
arr2 = np.arange(4).reshape(2, 2)

# initialise arr1
print("Enter elements of arr1")
for i in range(0,2):
  for j in range(0,2):
    arr1[i][j] = int(input("Enter element arr1[{0}][{1}]: ".format(i,j)))

print("---------------------------------")

#initialse arr2
print("Enter elements of arr2")
for i in range(0,2):
  for j in range(0,2):
    arr2[i][j] = int(input("Enter element arr2[{0}][{1}]: ".format(i,j)))

print("---------------------------------")

print('First array:') 
print(arr1)
  
print('\nSecond array:') 
print(arr2)
  
print("---------------------------------")  

print('\nAdding the two arrays:') 
print(np.add(arr1, arr2))
  
print('\nSubtracting the two arrays:') 
print(np.subtract(arr1, arr2))
  
print('\nMultiplying the two arrays:')
print(np.multiply(arr1, arr2))
  
print('\nDividing the two arrays:')
print(np.divide(arr1, arr2))

print("---------------------------------")
# row and column summation
print ("The column wise summation  : ")
print (np.sum(arr1,axis=0))
print ("The row wise summation: ")
print (np.sum(arr1,axis=1))
# using "T" to transpose the matrix
print ("Matrix transposition : ")
print (arr1.T)
