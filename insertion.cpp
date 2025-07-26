#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
 int pass = 1;
void logState(const vector<int>& arr, int pass) {
    ofstream out("steps.csv", ios::app);
    out << "Pass " << pass << ",";
    for (int val : arr) out << val << ",";
    out << "\n";
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        logState(arr, pass++);

    }
}

int main() {
    vector<int> data ={97326, 85955, 26244, 63938, 1763, 78984, 37439, 71832, 44206, 96856, 
37992, 93464, 96043, 98392, 93730, 41178, 13691, 7417, 42771, 17091, 
40926, 31913, 13011, 61459, 31104, 22280, 86456, 85124, 38817, 87499, 
13675, 30883, 34598, 29948, 32484, 10681, 96844, 24855, 12152, 22302, 
92534, 80619, 29555, 30550, 60592, 88164, 11514, 64025, 76455, 17466,};

    insertionSort(data);

    cout << "Sorted array: ";
    for (int num : data)
        cout << num << " ";
    cout << endl;

    return 0;
}