#include<bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration & Initialization
    set<int> s1;                    // empty set of ints
    set<int> s2 = {5, 1, 3, 5, 2};  // initializer list; duplicate ‘5’ ignored

    // 2. Inserting elements
    auto result = s1.insert(10);   // returns pair<iterator,bool>
    if (result.second)
        cout << "Inserted 10 into s1\n";
    else
        cout << "10 was already in s1\n";

    s1.insert(7);
    s1.insert(3);

    // 3. Checking size & emptiness
    cout << "s1 has " << s1.size() << " elements\n";
    cout << "s2 is " << (s2.empty() ? "empty" : "not empty") << "\n";

    // 4. Iteration (ascending order)
    cout << "Elements of s1: ";
    for (int x : s1)
        cout << x << ' ';
    cout << "\n";

    // 5. Finding elements
    if (s1.find(7) != s1.end())
        cout << "7 found in s1\n";
    else
        cout << "7 not found in s1\n";

    // 6. Counting elements (0 or 1)
    cout << "Number of 10s in s1: " << s1.count(10) << "\n";

    // 7. Erasing elements
    s1.erase(3);                   // erase by key
    cout << "After erasing 3, s1: ";
    for (int x : s1) cout << x << ' ';
    cout << "\n";

    // erase by iterator
    auto it = s1.find(7);
    if (it != s1.end()) {
        s1.erase(it);
        cout << "Erased one element via iterator\n";
    }

    // 8. Range queries
    // upper_bound: first element > key
    auto ub = s2.upper_bound(3);
    if (ub != s2.end())
        cout << "In s2, first element > 3 is " << *ub << "\n";

    // lower_bound: first element >= key
    auto lb = s2.lower_bound(3);
    if (lb != s2.end())
        cout << "In s2, first element >= 3 is " << *lb << "\n";

    // 9. Clear all
    s1.clear();
    cout << "After clear, s1 size = " << s1.size() << "\n";

    // 10. Custom comparator: descending order
    set<string, greater<string>> names = {"Alice", "Bob", "Charlie", "Bob"};
    cout << "Names in descending order:\n";
    for (auto &name : names)
        cout << "  " << name << "\n";

    return 0;
}