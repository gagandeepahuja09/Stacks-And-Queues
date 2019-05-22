/* Given an integer A. 
Find and Return first positive A integers in ascending order containing only
digits 1, 2 and 3.
*/
vector<int> Solution::solve(int A) {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    vector<int> res;
    while(!q.empty() && A--) {
        int f = q.front();
        q.pop();
        res.push_back(f);
        q.push(f * 10 + 1);
        q.push(f * 10 + 2);
        q.push(f * 10 + 3);
    }
    return res;
}

