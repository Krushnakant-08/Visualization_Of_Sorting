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
    vector<int> data = {
    82317, 45162, 92684, 13579, 59034, 74310, 63825, 10984, 39275, 81652,
    78013, 20938, 57493, 68425, 94716, 23564, 18907, 75491, 32048, 91835,
    49623, 23017, 81456, 60584, 70126, 55849, 38014, 69713, 80015, 21639,
    47120, 96304, 31342, 84069, 23450, 98312, 16490, 44783, 38562, 56823,
    62197, 45710, 91265, 70213, 83497, 61435, 74162, 38510, 49012, 23984,
    72308, 15902, 69273, 59813, 73196, 34129, 96502, 41235, 80124, 27963,
    56347, 97013, 36284, 48920, 35829, 24571, 63491, 51092, 91620, 37049,
    49175, 62983, 78520, 47210, 87349, 28763, 79513, 62739, 58102, 46590,
    53124, 34197, 59310, 78124, 32845, 93871, 40512, 51730, 20931, 67420,
    82359, 36948, 24186, 59841, 47031, 28417, 83591, 63420, 29375, 81246
};
    insertionSort(data);
    return 0;
}