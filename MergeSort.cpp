#include <iostream>
#include <vector>
#include <algorithm> // Chứa std::sort (thường là Introsort, tối ưu hơn Merge Sort thuần)
#include <iomanip>

using namespace std;

// Hàm này chứa logic Merge Sort (hoặc sort tổng quát)
void sort_full_stream(vector<int>& stream, int num) {
    // 1. Thêm số mới
    stream.push_back(num);
    
    // 2. Sắp xếp lại toàn bộ danh sách O(N log N)
    sort(stream.begin(), stream.end());
}

// Hàm tính và in trung vị (Tương tự như trên)
void find_and_print_median_merge_sort(const vector<int>& stream) {
    int N = stream.size();
    double median;

    // ... (logic tính trung vị tương tự)
    if (N % 2 != 0) {
        median = (double)stream[N / 2];
    } else {
        median = (double)(stream[N / 2 - 1] + stream[N / 2]) / 2.0;
    }

    cout << fixed << setprecision(1) << median << endl;
}

void solve_with_merge_sort(const vector<int>& input_array) {
    vector<int> current_stream;
    
    cout << "--- Trung vi cap nhat (Dung Merge Sort O(N log N)) ---" << endl;
    for (int num : input_array) {
        // Thêm và sắp xếp lại toàn bộ danh sách
        sort_full_stream(current_stream, num); 
        
        // Tim va in trung vi O(1)
        find_and_print_median_merge_sort(current_stream);
    }
}

// int main() {
//     vector<int> input_data = {1, 5, 2, 10, 3, 7, 4};
//     solve_with_merge_sort(input_data);
//     return 0;
// }