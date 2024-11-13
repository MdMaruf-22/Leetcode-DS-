class Solution {
public:
    vector<int> construct_lps(vector<int> nums) {
        vector<int> lps(nums.size());
        int len = 0, i = 1;
        lps[0]=0;
        while (i < nums.size()) {
            if (nums[len] == nums[i]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        cout << "LPS Array: ";
        for (int val : lps) {
            cout << val << " ";
        }
        cout << endl;
        return lps;
    }

    int kmp(vector<int> &text, vector<int> &pat) {
        int M = pat.size();
        int N = text.size();
        vector<int> lps = construct_lps(pat);
        int i = 0, j = 0, ans = 0;
        while ((N - i) >= (M - j)) {
            if (pat[j] == text[i]) {
                j++;
                i++;
            }
            if (j == M) {
                ans++;
                j = lps[j - 1];
            } else if (i < N && pat[j] != text[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return ans;
    }

    int countMatchingSubarrays(vector<int> &v, vector<int> &p) {
        int n = v.size();
        int m = p.size();
        vector<int> t;
        for (int i = 0; i + 1 < n; i++) {
            if (v[i] > v[i + 1])
                t.push_back(-1);
            else if (v[i] == v[i + 1])
                t.push_back(0);
            else
                t.push_back(1);
        }
        int ans = kmp(t, p);
        return ans;
    }
};