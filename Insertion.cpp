#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Hàm chèn số mới vào đúng vị trí trong danh sách đã sắp xếp
void insertion_sort(vector<int>& stream, int num) {
    // 1. Thêm số mới vào cuối
    stream.push_back(num);
    
    // 2. Chèn ngược (Insertion Sort)
    int i = stream.size() - 1;
    while (i > 0 && stream[i] < stream[i - 1]) {
        swap(stream[i], stream[i - 1]);
        i--;
    }
}

// Hàm tính và in trung vị
void find_and_print_median(const vector<int>& stream) {
    int N = stream.size();
    double median;

    if (N % 2 != 0) {
        // Trường hợp lẻ: Trung vị là phần tử ở giữa
        median = (double)stream[N / 2];
    } else {
        // Trường hợp chẵn: Trung bình của hai phần tử giữa
        int mid1 = stream[N / 2 - 1];
        int mid2 = stream[N / 2];
        median = (double)(mid1 + mid2) / 2.0;
    }

    cout << fixed << setprecision(1) << median << endl;
}

void solve_with_insertion_sort(const vector<int>& input_array) {
    vector<int> current_stream;
    
    cout << "--- Trung vi cap nhat (Dung Insertion Sort) ---" << endl;
    for (int num : input_array) {
        // Cap nhat danh sach va duy tri thu tu sap xep O(N)
        insertion_sort(current_stream, num); 
        
        // Tim va in trung vi O(1)
        find_and_print_median(current_stream);
    }
}

// int main() {
//     vector<int> input_data = {1, 5, 2, 10, 3, 7, 4};
//     solve_with_insertion_sort(input_data);
//     return 0;
// }