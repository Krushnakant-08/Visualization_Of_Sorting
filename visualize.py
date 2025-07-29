import subprocess
import matplotlib.pyplot as plt
import pandas as pd
import os

file_path = 'steps.csv'
if os.path.exists(file_path):
    os.remove(file_path)
    open(file_path, 'w').close() 


print("💡 Choose a sorting algorithm to visualize:")
print("1. Insertion Sort")
print("2. Merge Sort")
print("3. Radix Sort")
print("4. Exit")

choice = input("Enter option (1/2/3): ")
if choice == '1':
    subprocess.run(["./insertion.exe"])
elif choice == '2':
    subprocess.run(["./merge.exe"])
elif choice == '3':
    subprocess.run(["./radix.exe"])
elif choice == '4':
    print("Exiting the program.")
    exit()
else:
    print("Invalid choice. Please select a valid option.")


df = pd.read_csv("steps.csv", header=None)
for index, row in df.iterrows():
    title = row[0]
    data = row[1:-1]
    plt.bar(range(len(data)), data)
    plt.title(title)
    if choice != '3':
        plt.pause(0.15)
    else:
        plt.pause(1.5)
    plt.clf()
