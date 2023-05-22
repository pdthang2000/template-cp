// C++ program to illustrate the use
// of ropes using Rope header file
#include <ext/rope>
#include <iostream>

// SGI extension
using namespace __gnu_cxx;
using namespace std;

// push_back(): This function is used to input a character at the end of the rope. Time Complexity: O(log N).
// pop_back(): Introduced from C++11(for strings), this function is used to delete the last character from the rope. Time Complexity: O(log N).
// insert(int x, crope r1): Inserts the contents of r1 before the xth element. Time Complexity: For Best Case: O(log N) and For Worst Case: O(N).
// erase(int x, int l): Erases l elements, starting with the xth element. Time Complexity: O(log N).
// substr(int x, int l): Returns a new rope whose elements are the l characters starting at the position x. Time Complexity: O(log N).
// replace(int x, int l, crope r1): Replaces the l elements beginning with the xth element with the elements in r1. Time Complexity: O(log N).
// concatenate(+): concatenate two ropes using the ‘+’ symbol. Time Complexity: O(1).

// Driver Code
int main()
{
	// rope<char> r = "abcdef"
	crope r = "geeksforgeeks";

	cout << "Initial rope: " << r << endl;

	// 'g' is added at the
	// end of the rope
	r.push_back('g');
	r.push_back('f');
	r.push_back('g');

	cout << "Rope after pushing f: " << r << endl;

	for (int i = 0; i < r.size(); i += 2) {
		cout << r[i];
	}
	cout << endl;

	int pos = 2;

	// gfg will be inserted
	// before position 2
	r.insert(pos - 1, "gfg");

	cout << "Rope after inserting gfg at position 2: " << r << endl;

	// gfg will be deleted
	r.erase(pos - 1, 3);

	cout << "Rope after removing gfg inserted just before: " << r << endl;

	// Replace "ee" with "00"
	r.replace(pos - 1, 2, "00");

	cout << "Rope after replacing " << "characters: " << r << endl;

	// Slice the rope
	crope r1 = r.substr(pos - 1, 2);

	cout << "Subrope at position 2: " << r << endl;

	// Removes the last element
	r.pop_back();
	r.pop_back();
	r.pop_back();

	cout << "Final rope after popping" << " out 3 elements: " << r << '\n';

    cout << r.size() << endl;
    cout << r.max_size() << endl;

	return 0;
}
