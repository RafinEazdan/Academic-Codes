import matplotlib.pyplot as plt

# Provided data
data_size = [1000, 2500, 5000, 7500, 10000, 12500, 15000, 17500, 20000]
bruteForce_time = [0.001, 0.001, 0.001, 0.001, 0.002, 0.001, 0.001, 0.001, 0.001]
Divide_and_Conquer_time = [0, 0, 0, 0, 0.001, 0, 0, 0, 0]

# Plotting the data
plt.figure(figsize=(10, 5))
plt.plot(data_size, bruteForce_time, marker='o', label='Brute Force Method')
plt.plot(data_size, Divide_and_Conquer_time, marker='o', label='Divide and Conquer')

# Adding labels and title
plt.xlabel('Number of Data')
plt.ylabel('Time (seconds)')
plt.title('Comparison Brute Force Method of  and Divide and Conquer')
plt.legend()

# Display the graph
plt.show()
