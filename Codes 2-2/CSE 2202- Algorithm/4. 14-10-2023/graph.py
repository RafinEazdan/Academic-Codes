import matplotlib.pyplot as plt

# Provided data
data_size = [1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000]
quick_sort_time = [145, 334, 664, 1359, 1954, 2309, 2628, 3379, 3.507]
merge_sort_time = [0, 0, 1, 1, 2, 2, 2, 2, 3]

# Plotting the data
plt.figure(figsize=(10, 5))
plt.plot(data_size, quick_sort_time, marker='o', label='Quick Sort')
plt.plot(data_size, merge_sort_time, marker='o', label='Merge Sort')

# Adding labels and title
plt.xlabel('Number of Data')
plt.ylabel('Time (miliseconds)')
plt.title('Comparison of Quick Sort and Merge Sort')
plt.legend()

# Display the graph
plt.show()
