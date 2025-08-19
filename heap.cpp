#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm> // for std::swap

template <typename T>
class MaxHeap
{
private:
    std::vector<T> heap;

    void heapifyDown(int i)
    {
        int n = heap.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest])
            largest = left;
        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            std::swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heap[i] > heap[parent])
            {
                std::swap(heap[i], heap[parent]);
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

public:
    MaxHeap(const std::vector<T> &arr = {})
    {
        heap = arr;
        buildMaxHeap();
    }

    void buildMaxHeap()
    {
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            heapifyDown(i);
        }
    }

    void push(const T &val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
    }

    const T &top() const
    {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        return heap[0];
    }

    size_t size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }

    void printHeap() const
    {
        for (const T &val : heap)
            std::cout << val << " ";
        std::cout << "\n";
    }
};
