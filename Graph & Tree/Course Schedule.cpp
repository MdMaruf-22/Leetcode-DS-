class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);
        for(auto x:prerequisites){
            graph[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) q.push(i);
        }
        int vis=0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            vis++;
            for (int neighbor : graph[course]) {
                if (--inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return vis==numCourses;
    }
};