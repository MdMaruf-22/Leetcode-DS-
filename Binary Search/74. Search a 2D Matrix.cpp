#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int lo = 0, hi = n - 1, row = -1;

    // Find the row where the target might be present
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (mid < n && matrix[mid][0] <= target && matrix[mid][m - 1] >= target)
        {
            row = mid;
            break;
        }
        else if (mid < n && matrix[mid][0] > target)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (row == -1)
        return false;
    // Perform binary search in the identified row
    lo = 0, hi = m - 1; 
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (matrix[row][mid] == target)
        {
            return true;
        }
        else if (matrix[row][mid] < target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return false;
}

void solve()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    bool found = searchMatrix(matrix, target);

    if (found)
        cout << "true\n";
    else
        cout << "false\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
