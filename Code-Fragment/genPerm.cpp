


// queue<T> q
// deque<T> s

template <typename T>
void genPerm(queue<T> &q, deque<T> &s){
	int size = q.size();
	if (q.empty()){
		// cout permutation in s
		// cout << s << endl;
		return;
	}
	for (int i = 0; i < size; i++){
		s.push_front(q.front());
		q.pop();
		genPerm(q, s);
		q.push(s.front());
		s.pop_front();
	}
}

/*
 * LC 46: Given a collection of distinct numbers, return all possible permutations.
 */
class Solution {
    vector<vector<int>> res;
    
    void genPerm(vector<int> pre, vector<int> v){
        if (v.size() == 0){
            res.push_back(pre);
            return;
        }
        int len = v.size();
        for (int i = 0; i < len; i++){
            int tmp = v[0];
            pre.push_back(tmp);
            v.erase(v.begin());
            genPerm(pre, v);
            pre.erase(pre.end() - 1);
            v.push_back(tmp);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return vector<vector<int>>();
        genPerm({}, nums);
        return res;
    }
};