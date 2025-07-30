# Visualization_Of_Sorting

This repository contains a Python script that visualizes the step-by-step process of various sorting algorithms using `matplotlib`. The script dynamically generates bar charts to represent the state of the array at each step of the sorting process, creating a simple animation.

## Features
-   Visualize the sorting process for different algorithms.
-   Command-line interface to choose the algorithm.
-   Supports:
    -   Insertion Sort
    -   Merge Sort
    -   Radix Sort

## How It Works
The `visualize.py` script works in conjunction with pre-compiled executable files for each sorting algorithm (`insertion.exe`, `merge.exe`, `radix.exe`).

1.  When you run the script, it prompts you to select a sorting algorithm.
2.  Based on your choice, it executes the corresponding compiled program (e.g., `./insertion.exe`).
3.  The executable performs the sort and writes each step of the process to a `steps.csv` file. Each row in the CSV contains a title for the step and the state of the array.
4.  The Python script then reads `steps.csv` using `pandas`.
5.  It iterates through each step (row) and generates a `matplotlib` bar plot to display the array's state, pausing between plots to create a visual animation.

## Prerequisites
-   Python 3
-   `pandas`
-   `matplotlib`
-   Pre-compiled executables for the sorting algorithms (`insertion.exe`, `merge.exe`, `radix.exe`) must be present in the root directory of the repository. These executables are responsible for generating the `steps.csv` file.

## Installation

1.  **Clone the repository:**
    ```sh
    git clone https://github.com/Krushnakant-08/Visualization_Of_Sorting.git
    cd Visualization_Of_Sorting
    ```

2.  **Install the required Python packages:**
    ```sh
    pip install -r requirements.txt
    ```
    Alternatively, you can install them manually:
    ```sh
    pip install pandas matplotlib
    ```

## Usage

1.  Ensure the compiled executables for the sorting algorithms (`insertion.exe`, `merge.exe`, `radix.exe`) are in the same directory as `visualize.py`.

2.  Run the visualization script from your terminal:
    ```sh
    python visualize.py
    ```

3.  You will be prompted to choose an algorithm:
    ```
    💡 Choose a sorting algorithm to visualize:
    1. Insertion Sort
    2. Merge Sort
    3. Radix Sort
    4. Exit
    Enter option (1/2/3):
    ```

4.  Enter the number corresponding to the algorithm you wish to see. A `matplotlib` window will open and display the visualization.
