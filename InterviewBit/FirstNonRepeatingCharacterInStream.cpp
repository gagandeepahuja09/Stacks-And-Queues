string Solution::solve(string A) {
    queue<char> q;
    map<char, int> mp;
    string ret = "";
    for(int i = 0; i < A.size(); i++) {
        q.push(A[i]);
        mp[A[i]]++;
        while(q.size() && mp[q.front()] > 1) {
            q.pop();
        }
        if(q.size())
            ret += q.front();
        else
            ret += '#';
    }
    return ret;
}

