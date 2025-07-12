#include<bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration & Initialization
    multimap<int, string> mm1;  // empty multimap
    // mm1: {}

    multimap<int, string> mm2 = {
        {1, "one"}, {2, "two"}, {1, "uno"}, {3, "three"}, {2, "dos"}
    };
    // mm2: [(1, "one"), (1, "uno"), (2, "two"), (2, "dos"), (3, "three")]

    // 2. Inserting elements
    mm1.insert({1, "one"});
    // mm1: [(1, "one")]
    mm1.insert(make_pair(2, "two"));
    // mm1: [(1, "one"), (2, "two")]
    mm1.insert({1, "ein"});  // duplicate key
    // mm1: [(1, "one"), (1, "ein"), (2, "two")]
    cout << "Inserted entries into mm1: (1, one), (2, two), (1, ein)" << endl;
    // prints: Inserted entries into mm1: (1, one), (2, two), (1, ein)

    // 3. Checking size & emptiness
    cout << "mm1 has " << mm1.size() << " elements" << endl;
    // prints: mm1 has 3 elements
    cout << "mm2 is " << (mm2.empty() ? "empty" : "not empty") << endl;
    // prints: mm2 is not empty

    // 4. Iteration (ascending key order)
    cout << "Elements of mm1:" << endl;
    for (auto &p : mm1)
        cout << "  [" << p.first << "] = " << p.second << endl;
    // prints:
    // Elements of mm1:
    //   [1] = one
    //   [1] = ein
    //   [2] = two

    // 5. Finding elements
    auto it_find = mm1.find(1);
    if (it_find != mm1.end())
        cout << "Found key=1, value=" << it_find->second << endl;
    else
        cout << "Key=1 not found in mm1" << endl;
    // prints: Found key=1, value=one (first match)

    // 6. Counting elements (number of entries with key)
    cout << "Number of entries with key=1 in mm1: " << mm1.count(1) << endl;
    // prints: Number of entries with key=1 in mm1: 2

    // 7. Range queries with equal_range
    auto range = mm2.equal_range(2);
    cout << "Entries in mm2 with key=2:" << endl;
    for (auto it = range.first; it != range.second; ++it)
        cout << "  [" << it->first << "] => " << it->second << endl;
    // prints:
    // Entries in mm2 with key=2:
    //   [2] => two
    //   [2] => dos

    // 8. Erasing elements
    size_t erased_all = mm1.erase(1);
    // erased_all = 2, mm1: [(2, "two")]
    cout << "Erased " << erased_all << " entries with key=1 from mm1" << endl;
    // prints: Erased 2 entries with key=1 from mm1
    cout << "mm1 now has " << mm1.size() << " elements" << endl;
    // prints: mm1 now has 1 elements

    // erase a single element via iterator from mm2
    auto it = mm2.find(3);
    if (it != mm2.end()) {
        mm2.erase(it);
        // mm2: [(1, "one"), (1, "uno"), (2, "two"), (2, "dos")]
        cout << "Erased one entry with key=3 from mm2" << endl;
        // prints: Erased one entry with key=3 from mm2
    }

    // 9. Using lower_bound and upper_bound
    auto lb = mm2.lower_bound(2);
    auto ub = mm2.upper_bound(2);
    cout << "Lower bound for key=2: " << lb->second << endl;
    // prints: Lower bound for key=2: two
    cout << "Upper bound for key=2: " << ub->second << endl;
    // prints: Upper bound for key=2: three (first key >2)

    // 10. Clear all
    mm1.clear();
    cout << "After clear, mm1 size = " << mm1.size() << endl;
    // prints: After clear, mm1 size = 0

    // 11. Custom comparator: descending key order
    multimap<int, string, greater<int>> scores = {
        {10, "Alice"}, {20, "Bob"}, {10, "Charlie"}
    };
    cout << "Scores in descending key order:" << endl;
    for (auto &p : scores)
        cout << "  [" << p.first << "] = " << p.second << endl;
    // prints:
    // Scores in descending key order:
    //   [20] = Bob
    //   [10] = Alice
    //   [10] = Charlie

    return 0;
}