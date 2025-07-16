#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>

int main() {
    // 1) Default max-heap of ints
    std::priority_queue<int> maxHeap;
    maxHeap.push(5);
    maxHeap.push(1);
    maxHeap.push(10);
    maxHeap.push(3);
    // Will print elements in descending order: 10, 5, 3, 1
    std::cout << "Default max-heap (int): ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << ' ';
        maxHeap.pop();
    }
    std::cout << "\n\n";

    // 2) Min-heap of ints using std::greater<>
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(10);
    minHeap.push(3);
    // Will print elements in ascending order: 1, 3, 5, 10
    std::cout << "Min-heap (int) with std::greater: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << ' ';
        minHeap.pop();
    }
    std::cout << "\n\n";

    // 3) Max-heap of pairs (sorts by first, then by second)
    std::priority_queue<std::pair<int, std::string>> pairHeap;
    pairHeap.push({2, "apple"});
    pairHeap.push({5, "banana"});
    pairHeap.push({5, "apricot"});
    pairHeap.push({1, "orange"});
    // Will print highest first; for ties, larger string: 
    // (5, "banana"), (5, "apricot"), (2, "apple"), (1, "orange")
    std::cout << "Max-heap of pair<int,string>: ";
    while (!pairHeap.empty()) {
        auto [num, fruit] = pairHeap.top();
        std::cout << '(' << num << ',' << fruit << ") ";
        pairHeap.pop();
    }
    std::cout << "\n\n";

    // 4) Min-heap of pairs using custom comparator
    auto cmp = [](const std::pair<int,std::string>& a, 
                  const std::pair<int,std::string>& b) {
        if (a.first != b.first)
            return a.first > b.first;            // smaller first => higher priority
        return a.second < b.second;              // for equal first, lexicographically larger => higher priority
    };
    std::priority_queue<
        std::pair<int,std::string>,
        std::vector<std::pair<int,std::string>>,
        decltype(cmp)
    > customHeap(cmp);

    customHeap.push({2, "apple"});
    customHeap.push({5, "banana"});
    customHeap.push({5, "apricot"});
    customHeap.push({1, "orange"});
    // Will print smallest first; for ties, lexicographically largest first:
    // (1, "orange"), (2, "apple"), (5, "banana"), (5, "apricot")
    std::cout << "Custom min-heap of pair<int,string>: ";
    while (!customHeap.empty()) {
        auto [num, fruit] = customHeap.top();
        std::cout << '(' << num << ',' << fruit << ") ";
        customHeap.pop();
    }
    std::cout << "\n\n";

    // 5) Priority queue of a user-defined struct with custom comparator
    struct Task {
        int priority;
        std::string description;
    };
    // Higher priority value => handled first
    struct TaskCompare {
        bool operator()(Task const& a, Task const& b) const {
            return a.priority < b.priority;
        }
    };
    std::priority_queue<Task, std::vector<Task>, TaskCompare> taskQueue;
    taskQueue.push({3, "Write report"});
    taskQueue.push({5, "Fix critical bug"});
    taskQueue.push({1, "Update docs"});
    taskQueue.push({4, "Deploy to prod"});
    // Will print by descending priority:
    // (5, Fix critical bug), (4, Deploy to prod), (3, Write report), (1, Update docs)
    std::cout << "Priority queue of Task struct: ";
    while (!taskQueue.empty()) {
        Task t = taskQueue.top();
        std::cout << '(' << t.priority << ',' << t.description << ") ";
        taskQueue.pop();
    }
    std::cout << "\n";

    return 0;
}
