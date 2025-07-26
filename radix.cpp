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
  vector<int> arr = {
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
    radixSort(arr);
    return 0;
}
