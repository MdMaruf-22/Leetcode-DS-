#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
    // Function to get all the processes that will be killed if process "kill" is terminated.
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // Create a graph that represents the parent-child relationship between processes.
        unordered_map<int, vector<int>> processGraph;
        int numOfProcesses = pid.size();
        for (int i = 0; i < numOfProcesses; ++i) {
            processGraph[ppid[i]].push_back(pid[i]);
        }
        // List that will hold all the processes to kill.
        vector<int> processesToKill;
        dfs(kill, processGraph, processesToKill); // Call DFS function

        return processesToKill;
    }
private:
    void dfs(int currentProcess, unordered_map<int, vector<int>>& processGraph, vector<int>& processesToKill) {
        processesToKill.push_back(currentProcess); // Add current process to the list of processes to kill
        for (int childProcess : processGraph[currentProcess]) {
            dfs(childProcess, processGraph, processesToKill); // Recur for all child processes
        }
    }
};
