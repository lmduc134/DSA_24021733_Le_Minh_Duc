#include <iostream>
using namespace std;
class Node // tạo lớp node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
class LinkedList // tạo linkedlist
{
private:
    Node *head; // tạo head

public:
    LinkedList() // khởi tạo linkedlist
    {
        head = nullptr;
    }
    int get(int pos) // truy cập O(N)
    {
        if (pos <= 0) return -1;
        Node *temp = head;
        int index = 1;
        while (temp != nullptr && index < pos)
        {
            temp = temp->next;
            index++;
        }
        if (temp == nullptr){
              return -1;
        }
            return temp->data;
        // Nếu không tìm thấy vị trí, trả về giá trị mặc định (ví dụ -1)
      
    }
    void add_front(int value) // thêm phần tử đầu O(1)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void add_back(int value) // thêm phần tử cuối (O(N))
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void Insert(int value, int pos) // thêm vào vị trí bất kì (O(N))
    {
        Node *newNode = new Node(value);
    if (pos <= 0 || head == nullptr){
        newNode->next = head;
        head = newNode;
        return;
    }
        Node *temp = head;
        for (int i = 1; i < pos && temp->next != nullptr; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void del_front() // xóa phần tử đầu (O(1))
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    void del_back() // xóa phần tử cuối (O(N))
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    void del_pos(int pos) // xóa phần tử ở vị trí bất kì (O(N))
    {
        if (head == nullptr)
            return;
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            if (temp->next == nullptr)
                return; // Vị trí không hợp lệ
            temp = temp->next;
        }
        if (temp->next == nullptr)
            return; // Vị trí không hợp lệ
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    void traverse_forward() // duyệt xuôi (O(N))
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void traverse_backward(Node *temp)//Duyệt ngược; O(N)
    {
        if (temp == nullptr) return;
        traverse_backward(temp->next);
        cout << temp->data << " ";
    }
    void print_reverse() {
        traverse_backward(head);
        cout << endl;
    }
};
struct heapNode {
    int* arr;// Con trỏ tới mảng động chứa các phần tử Heap
    int capacity; // Kích thước tối đa của mảng
    int size;     // Số lượng phần tử hiện tại trong Heap
};
class MinHeap {
private:
    heapNode* heap;
    void heapifyUp(int index) {
        if (index && heap->arr[(index - 1) / 2] > heap->arr[index]) {
            swap(heap->arr[index], heap->arr[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap->size && heap->arr[left] < heap->arr[smallest])
            smallest = left;
        if (right < heap->size && heap->arr[right] < heap->arr[smallest])
            smallest = right;
        if (smallest != index) {
            swap(heap->arr[index], heap->arr[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    MinHeap(int capacity) {
        heap = new heapNode();
        heap->capacity = capacity;
        heap->size = 0;
        heap->arr = new int[capacity];
    }
    ~MinHeap() {
        delete[] heap->arr;
        delete heap;
    }
    void insert(int key) {
        if (heap->size == heap->capacity) {
            cout << "Heap overflow\n";
            return;
        }
        heap->arr[heap->size] = key;
        heapifyUp(heap->size);
        heap->size++;
    }
    void deleteMin() {
        if (heap->size <= 0) {
            cout << "Heap underflow\n";
            return;
        }
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapifyDown(0);
    }
    int getMin() {
        if (heap->size <= 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap->arr[0];
    }
    void display() {
        for (int i = 0; i < heap->size; i++) {
            cout << heap->arr[i] << " ";
        }
        cout << endl;
    }
};

class MaxHeap {
private:
    heapNode* heap;
    void heapifyUp(int index) {
        if (index && heap->arr[(index - 1) / 2] < heap->arr[index]) {
            swap(heap->arr[index], heap->arr[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap->size && heap->arr[left] > heap->arr[largest])
            largest = left;
        if (right < heap->size && heap->arr[right] > heap->arr[largest])
            largest = right;
        if (largest != index) {
            swap(heap->arr[index], heap->arr[largest]);
            heapifyDown(largest);
        }
    }
public:
    MaxHeap(int capacity) {
        heap = new heapNode();
        heap->capacity = capacity;
        heap->size = 0;
        heap->arr = new int[capacity];
    }
    ~MaxHeap() {
        delete[] heap->arr;
        delete heap;
    }
    void insert(int key) {
        if (heap->size == heap->capacity) {
            cout << "Heap overflow\n";
            return;
        }
        heap->arr[heap->size] = key;
        heapifyUp(heap->size);
        heap->size++;
    }
    void deleteMax() {
        if (heap->size <= 0) {
            cout << "Heap underflow\n";
            return;
        }
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapifyDown(0);
    }
    int getMax() {
        if (heap->size <= 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap->arr[0];
    }
    void display() {
        for (int i = 0; i < heap->size; i++) {
            cout << heap->arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    MinHeap minHeap(10);
    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(6);
    minHeap.insert(5);
    minHeap.insert(2);
    minHeap.insert(4);

    cout << "Min Heap elements: ";
    minHeap.display();

    cout << "Minimum element: " << minHeap.getMin() << endl;

    minHeap.deleteMin();
    cout << "After deleting minimum element, Min Heap elements: ";
    minHeap.display();
    
    MaxHeap maxHeap(10);
    maxHeap.insert(3);
    maxHeap.insert(1);  
    maxHeap.insert(6);
    maxHeap.insert(5);
    maxHeap.insert(2);
    maxHeap.insert(4);
    cout << "Max Heap elements: ";
    maxHeap.display();
    cout << "Maximum element: " << maxHeap.getMax() << endl;
    maxHeap.deleteMax();
    cout << "After deleting maximum element, Max Heap elements: ";
    maxHeap.display();
    return 0;

}