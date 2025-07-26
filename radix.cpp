#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

void logState(const vector<int>& arr, int pass) {
    ofstream out("steps.csv", ios::app);
    out << "Pass " << pass << ",";
    for (int val : arr) out << val << ",";
    out << "\n";
}

int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr)
        if (num > maxVal) maxVal = num;
    return maxVal;
}

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; ++i)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal / exp > 0; exp *= 10){ 
        countingSort(arr, exp);
        logState(arr, (int)log10((float) exp)+1);
    }

}

int main() {
    vector<int> arr = {97326, 85955, 26244, 63938, 1763, 78984, 37439, 71832, 44206, 96856, 
37992, 93464, 96043, 98392, 93730, 41178, 13691, 7417, 42771, 17091, 
40926, 31913, 13011, 61459, 31104, 22280, 86456, 85124, 38817, 87499, 
13675, 30883, 34598, 29948, 32484, 10681, 96844, 24855, 12152, 22302, 
92534, 80619, 29555, 30550, 60592, 88164, 11514, 64025, 76455, 17466,};
    radixSort(arr);
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
