#include<bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration & Initialization
    multiset<int> ms1;                    // empty multiset of ints
    multiset<int> ms2 = {5, 1, 3, 5, 2};   // initializer list; duplicates accepted

    // 2. Inserting elements
    ms1.insert(10);
    ms1.insert(7);
    ms1.insert(10);  // duplicate
    cout << "Inserted values into ms1: 10, 7, 10\n";
    cout << "Number of 10s in ms1: " << ms1.count(10) << "\n";

    // 3. Checking size & emptiness
    cout << "ms1 has " << ms1.size() << " elements\n";
    cout << "ms2 is " << (ms2.empty() ? "empty" : "not empty") << "\n";

    // 4. Iteration (ascending order)
    cout << "Elements of ms1: ";
    for (int x : ms1)
        cout << x << ' ';
    cout << "\n";

    cout << "Elements of ms2: ";
    for (int x : ms2)
        cout << x << ' ';
    cout << "\n";

    // 5. Finding elements
    auto it_find = ms1.find(10);
    if (it_find != ms1.end())
        cout << "Found a 10 in ms1\n";
    else
        cout << "No 10 found in ms1\n";

    // 6. Counting elements (can be >1)
    cout << "Number of 10s in ms1: " << ms1.count(10) << "\n";
    cout << "Number of 5s in ms2: " << ms2.count(5) << "\n";

    // 7. Erasing elements
    // erase all 10s from ms1
    size_t removed = ms1.erase(10);
    cout << "Erased " << removed << " instances of 10 from ms1\n";
    cout << "ms1 now: ";
    for (int x : ms1) cout << x << ' ';
    cout << "\n";

    // erase a single 1 from ms2 using iterator
    auto it = ms2.find(1);
    if (it != ms2.end()) {
        ms2.erase(it);
        cout << "Erased one '1' from ms2\n";
    }
    cout << "ms2 now: ";
    for (int x : ms2) cout << x << ' ';
    cout << "\n";

    // 8. Range queries
    // upper_bound: first element > key
    auto ub = ms2.upper_bound(3);
    if (ub != ms2.end())
        cout << "In ms2, first element > 3 is " << *ub << "\n";

    // lower_bound: first element >= key
    auto lb = ms2.lower_bound(3);
    if (lb != ms2.end())
        cout << "In ms2, first element >= 3 is " << *lb << "\n";

    // 9. Clear all
    ms1.clear();
    cout << "After clear, ms1 size = " << ms1.size() << "\n";

    // 10. Custom comparator: descending order
    multiset<string, greater<string>> fruits = {"Apple", "Banana", "Cherry", "Banana"};
    cout << "Fruits in descending order:\n";
    for (const auto &f : fruits)
        cout << "  " << f << "\n";

    return 0;
}
