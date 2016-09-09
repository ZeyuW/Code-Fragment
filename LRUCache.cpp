// LRU Cache C++ implementation (STL) for https://leetcode.com/problems/lru-cache/

/*
 *  Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 *
 *  get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 *  set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 *
 */

// 1. Simple STL implementation: Doubly-linked list and unordered map
class LRUCache{
    int m_capacity;
    list<pair<int, int>> m_list;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
    
public:
    LRUCache(int capacity):m_capacity(capacity){}
    
    int get(int key) {
        auto iter = m_map.find(key);
        if (iter == m_map.end())
            return -1;
        m_list.splice(m_list.begin(), m_list, iter->second);
        return iter->second->second;
    }
    
    void set(int key, int value) {
        auto iter = m_map.find(key);
        if (iter != m_map.end()){
            m_list.splice(m_list.begin(), m_list, iter->second);
            iter->second->second = value;
            return;
        }
        if (m_map.size() == m_capacity){
            int back_key = m_list.back().first;
            m_list.pop_back();
            m_map.erase(back_key);
        }
        pair<int, int> tmp_pair(key, value);
        m_list.push_front(tmp_pair);
        m_map[key] = m_list.begin();
    }
};


// 2. With template
template <class KEY_T, class VAL_T>
class LRUCache{
    size_t m_capacity;
    list<pair<KEY_T, VAL_T>> m_list;
    unordered_map<KEY_T, list<pair<KEY_T, VAL_T>>::iterator> m_map;
    
public:
    LRUCache(size_t capacity):m_capacity(capacity){}
    
    VAL_T get(const KEY_T& key) {
        auto iter = m_map.find(key);
        if (iter == m_map.end())
            return -1;
        m_list.splice(m_list.begin(), m_list, iter->second);
        return iter->second->second;
    }
    
    void set(const KEY_T& key, const VAL_T& value) {
        auto iter = m_map.find(key);
        if (iter != m_map.end()){
            m_list.splice(m_list.begin(), m_list, iter->second);
            iter->second->second = value;
            return;
        }
        if (m_map.size() == m_capacity){
            KEY_T back_key = m_list.back().first;
            m_list.pop_back();
            m_map.erase(back_key);
        }
        pair<KEY_T, VAL_T> tmp_pair(key, value);
        m_list.push_front(tmp_pair);
        m_map[key] = m_list.begin();
    }
};