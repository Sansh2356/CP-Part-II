import time
import matplotlib.pyplot as plt

def calculate_power(x, n):
    result = 1
    for _ in range(n):
        result *= x
    return result 

# Define inputs for 5 instances
inputs = [(2, 100), (3, 200), (4, 300), (5, 400), (6, 500)]

execution_times = []

# Calculate execution time for each input instance
for x, n in inputs:
    start_time = time.time()
    calculate_power(x, n)
    end_time = time.time()
    execution_times.append(end_time - start_time)

# Plotting the results
plt.figure(figsize=(8, 6))
plt.plot(range(1, 6), execution_times, marker='o', linestyle='-')
plt.title('Execution Time for Calculating Power of a Number')
plt.xlabel('Instance')
plt.ylabel('Execution Time (seconds)')
plt.xticks(range(1, 6))
plt.grid(True)
plt.show()
