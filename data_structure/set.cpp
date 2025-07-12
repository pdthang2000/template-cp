#include<bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration & Initialization
    set<int> s1;                    // empty set of ints
    // s1: {}

    set<int> s2 = {5, 1, 3, 5, 2};  // initializer list; duplicate ‘5’ ignored
    // s2: {1, 2, 3, 5}

    // 2. Inserting elements
    auto result = s1.insert(10);   // returns pair<iterator,bool>
    // s1.insert(10) -> result.second = true; s1: {10}
    if (result.second)
        cout << "Inserted 10 into s1" << endl;
    // prints: Inserted 10 into s1
    else
        cout << "10 was already in s1" << endl;

    s1.insert(7);
    // s1: {7, 10}
    s1.insert(3);
    // s1: {3, 7, 10}

    // 3. Checking size & emptiness
    cout << "s1 has " << s1.size() << " elements" << endl;
    // prints: s1 has 3 elements
    cout << "s2 is " << (s2.empty() ? "empty" : "not empty") << endl;
    // prints: s2 is not empty

    // 4. Iteration (ascending order)
    cout << "Elements of s1: ";
    for (int x : s1)
        cout << x << ' ';
    cout << endl;
    // prints: Elements of s1: 3 7 10 

    // 5. Finding elements
    if (s1.find(7) != s1.end())
        cout << "7 found in s1" << endl;
    else
        cout << "7 not found in s1" << endl;
    // prints: 7 found in s1

    // 6. Counting elements (0 or 1)
    cout << "Number of 10s in s1: " << s1.count(10) << endl;
    // prints: Number of 10s in s1: 1

    // 7. Erasing elements
    s1.erase(3);                   // erase by key
    // s1: {7, 10}
    cout << "After erasing 3, s1: ";
    for (int x : s1) cout << x << ' ';
    cout << endl;
    // prints: After erasing 3, s1: 7 10 

    // erase by iterator
    auto it = s1.find(7);
    if (it != s1.end()) {
        s1.erase(it);
        // s1: {10}
        cout << "Erased one element via iterator" << endl;
        // prints: Erased one element via iterator
    }

    // 8. Range queries
    // upper_bound: first element > key
    auto ub = s2.upper_bound(3);
    if (ub != s2.end())
        cout << "In s2, first element > 3 is " << *ub << endl;
    // prints: In s2, first element > 3 is 5

    // lower_bound: first element >= key
    auto lb = s2.lower_bound(3);
    if (lb != s2.end())
        cout << "In s2, first element >= 3 is " << *lb << endl;
    // prints: In s2, first element >= 3 is 3

    // 9. Clear all
    s1.clear();
    cout << "After clear, s1 size = " << s1.size() << endl;
    // prints: After clear, s1 size = 0

    // 10. Custom comparator: descending order
    set<string, greater<string>> names = {"Alice", "Bob", "Charlie", "Bob"};
    cout << "Names in descending order:" << endl;
    for (auto &name : names)
        cout << "  " << name << endl;
    // prints:
    // Names in descending order:
    //   Charlie
    //   Bob
    //   Alice

    return 0;
}
