class Solution
{
public:
    bool isPred(const string &a, const string &b)
    {
        int diff = 0;
        int ai = 0, bi = 0;
        while (ai < a.size() && bi < b.size())
        {
            if (a[ai] == b[bi])
                ai++;
            else
                diff++;
            bi++;
        }
        return diff == 1 || diff == 0;
    }
    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> count;
        map<int, vector<string>> group;
        int result = 0;

        for (const string &word : words)
            group[word.size()].push_back(word);

        for (auto it = group.begin(); it != group.end(); it++)
        {
            const vector<string> &curr = it->second;
            for (const string &word : curr)
            {
                int longest = 1;
                for (const string &subWord : group[it->first - 1])
                {
                    if (isPred(subWord, word))
                        longest = max(longest, count.find(subWord) != count.end() ? count[subWord] + 1 : 1);
                }
                count[word] = longest;
                result = max(longest, result);
            }
        }

        return result;
    }
};