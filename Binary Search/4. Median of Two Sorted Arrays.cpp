#include <bits/stdc++.h>
using namespace std;

// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//     vector<int> vc;
//     int n = nums1.size();
//     int m = nums2.size();

//     int i = 0, j = 0;

//     while (i < n && j < m) {
//         if (nums1[i] < nums2[j]) {
//             vc.push_back(nums1[i++]);
//         } else {
//             vc.push_back(nums2[j++]);
//         }
//     }

//     while (i < n) vc.push_back(nums1[i++]);
//     while (j < m) vc.push_back(nums2[j++]);

//     int total = vc.size();
//     if (total % 2 == 1)
//         return vc[total / 2];
//     else
//         return (vc[total / 2 - 1] + vc[total / 2]) / 2.0;
// }

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vc;
    int n = nums1.size();
    int m = nums2.size();

    
}

int main() {
    int n, m;
    cin >> n;
    vector<int> nums1(n);
    for(int i = 0; i < n; i++) cin >> nums1[i];

    cin >> m;
    vector<int> nums2(m);
    for(int i = 0; i < m; i++) cin >> nums2[i];

    double ans = findMedianSortedArrays(nums1, nums2);
    cout << ans << endl;

    return 0;
}
