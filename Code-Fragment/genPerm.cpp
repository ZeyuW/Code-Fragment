


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
