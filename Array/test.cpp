#include <bits/stdc++.h> // Include necessary libraries
#define ll long long // Define alias for long long data type
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Optimize I/O operations
    cin.tie(NULL); // Disable synchronization with C I/O streams

    int q;
    cin >> q; // Input the number of queries

    unordered_map<int, int> mp; // Map to store frequencies of elements
    priority_queue<pair<int, int>> pq; // Priority queue to maintain elements with maximum frequency

    while (q--) { // Iterate through each query
        int n, x; 
        cin >> n; // Input the type of query

        if (n == 1) { // If it's a type 1 query
            cin >> x; // Input the element to be inserted
            mp[x]++; // Increment the frequency of the element in the map
            pq.push({mp[x], x}); // Push the element and its frequency to the priority queue
        } else { // If it's a type 2 query
            if (mp.empty()) { // If the map is empty
                cout << "empty\n"; // Print "empty" since there are no elements
            } else {
                while (!pq.empty() && mp[pq.top().second] != pq.top().first) {
                    pq.pop(); // Remove elements from the priority queue if their frequency doesn't match
                }

                if (!pq.empty()) { // If the priority queue is not empty
                    cout << pq.top().second << "\n"; // Print the element with the maximum frequency
                    mp[pq.top().second] = 0; // Reset the frequency of the element in the map
                    pq.pop(); // Remove the element from the priority queue
                } else { // If the priority queue is empty
                    cout << "empty\n"; // Print "empty" since there are no elements with non-zero frequency
                }
            }
        }
    }

    return 0;
}
