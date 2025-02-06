# Input dataset
data = [27, 15, 39, 2, 28, 70]
print("Initial data:", data)

# Selection sort implementation without a function
n = len(data)

# Traverse through all elements in the dataset
for i in range(n):
    # Find the minimum element in the unsorted portion of the list
    min_index = i
    for j in range(i + 1, n):
        if data[j] < data[min_index]:
            min_index = j
    
    # Swap the found minimum element with the first unsorted element
    data[i], data[min_index] = data[min_index], data[i]
    
    # Print the dataset after each iteration
    print(f"After pass {i+1}: {data}")
