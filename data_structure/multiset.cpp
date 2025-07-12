#include<bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration & Initialization
    multiset<int> ms1;                    // empty multiset of ints
    // ms1: {}

    multiset<int> ms2 = {5, 1, 3, 5, 2};   // initializer list; duplicates accepted
    // ms2: {1, 2, 3, 5, 5}

    // 2. Inserting elements
    ms1.insert(10);
    // ms1: {10}
    ms1.insert(7);
    // ms1: {7, 10}
    ms1.insert(10);  // duplicate
    // ms1: {7, 10, 10}
    cout << "Inserted values into ms1: 10, 7, 10" << endl;
    // prints: Inserted values into ms1: 10, 7, 10

    // 3. Checking size & emptiness
    cout << "ms1 has " << ms1.size() << " elements" << endl;
    // prints: ms1 has 3 elements
    cout << "ms2 is " << (ms2.empty() ? "empty" : "not empty") << endl;
    // prints: ms2 is not empty

    // 4. Iteration (ascending order)
    cout << "Elements of ms1: ";
    for (int x : ms1)
        cout << x << ' ';
    cout << endl;
    // prints: Elements of ms1: 7 10 10

    cout << "Elements of ms2: ";
    for (int x : ms2)
        cout << x << ' ';
    cout << endl;
    // prints: Elements of ms2: 1 2 3 5 5

    // 5. Finding elements
    auto it_find = ms1.find(10);
    if (it_find != ms1.end())
        cout << "Found a 10 in ms1" << endl;
    else
        cout << "No 10 found in ms1" << endl;
    // prints: Found a 10 in ms1

    // 6. Counting elements (can be >1)
    cout << "Number of 10s in ms1: " << ms1.count(10) << endl;
    // prints: Number of 10s in ms1: 2
    cout << "Number of 5s in ms2: " << ms2.count(5) << endl;
    // prints: Number of 5s in ms2: 2

    // 7. Erasing elements
    size_t removed = ms1.erase(10);
    // removed = 2, ms1: {7}
    cout << "Erased " << removed << " instances of 10 from ms1" << endl;
    // prints: Erased 2 instances of 10 from ms1
    cout << "ms1 now: ";
    for (int x : ms1) cout << x << ' ';
    cout << endl;
    // prints: ms1 now: 7

    // erase a single 1 from ms2 using iterator
    auto it = ms2.find(1);
    if (it != ms2.end()) {
        ms2.erase(it);
        // ms2: {2, 3, 5, 5}
        cout << "Erased one '1' from ms2" << endl;
        // prints: Erased one '1' from ms2
    }
    cout << "ms2 now: ";
    for (int x : ms2) cout << x << ' ';
    cout << endl;
    // prints: ms2 now: 2 3 5 5

    // 8. Range queries
    auto ub = ms2.upper_bound(3);
    if (ub != ms2.end())
        cout << "In ms2, first element > 3 is " << *ub << endl;
    // prints: In ms2, first element > 3 is 5

    auto lb = ms2.lower_bound(3);
    if (lb != ms2.end())
        cout << "In ms2, first element >= 3 is " << *lb << endl;
    // prints: In ms2, first element >= 3 is 3

    // 9. Clear all
    ms1.clear();
    cout << "After clear, ms1 size = " << ms1.size() << endl;
    // prints: After clear, ms1 size = 0

    // 10. Custom comparator: descending order
    multiset<string, greater<string>> fruits = {"Apple", "Banana", "Cherry", "Banana"};
    cout << "Fruits in descending order:" << endl;
    for (const auto &f : fruits)
        cout << "  " << f << endl;
    // prints:
    // Fruits in descending order:
    //   Cherry
    //   Banana
    //   Banana
    //   Apple

    return 0;
}
