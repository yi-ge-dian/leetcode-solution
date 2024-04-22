/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
  int capacity_;
  list<pair<int, int>> cache_;
  unordered_map<int, list<pair<int, int>>::iterator> k2it;

public:
  LRUCache(int capacity) { this->capacity_ = capacity; }

  int get(int key) {
    if (!k2it.count(key)) {
      return -1;
    }

    auto node = *k2it[key];
    cache_.erase(k2it[key]);
    cache_.push_front(node);
    k2it[key] = cache_.begin();
    return node.second;
  }

  void put(int key, int value) {
    // 如果有
    if (k2it.count(key)) {
      cache_.erase(k2it[key]);
      cache_.push_front(make_pair(key, value));
      k2it[key] = cache_.begin();
    } else {
      // 是否满了
      if (k2it.size() == capacity_) {
        auto tailKey = cache_.back().first;
        cache_.erase(k2it[tailKey]);
        k2it.erase(tailKey);
        cache_.push_front(make_pair(key, value));
        k2it[key] = cache_.begin();
      } else {
        cache_.push_front(make_pair(key, value));
        k2it[key] = cache_.begin();
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
