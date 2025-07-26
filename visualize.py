import subprocess
import matplotlib.pyplot as plt
import pandas as pd
import os

file_path = 'steps.csv'
if os.path.exists(file_path):
    os.remove(file_path)
    open(file_path, 'w').close()  # Recreate an empty file

subprocess.run(["./a.exe"])


df = pd.read_csv("steps.csv", header=None)

for index, row in df.iterrows():
    title = row[0]
    data = row[1:-1]
    plt.bar(range(len(data)), data)
    plt.title(title)
    plt.pause(.01)
    plt.clf()
