#pragma once
#include <unordered_map>
#include <list>

template<typename K, typename V>
class LRUCache {

private:

    size_t capacity;

    std::list<std::pair<K,V>> cache;

    std::unordered_map<K, typename std::list<std::pair<K,V>>::iterator> map;

public:

    LRUCache(size_t cap) : capacity(cap) {}

    V get(K key) {

        if (!map.count(key))
            throw std::runtime_error("Key not found");

        auto it = map[key];

        cache.splice(cache.begin(), cache, it);

        return it->second;
    }

    void put(K key, V value) {

        if (map.count(key)) {
            auto it = map[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }

        if (cache.size() == capacity) {

            auto last = cache.back();
            map.erase(last.first);
            cache.pop_back();
        }

        cache.emplace_front(key,value);
        map[key] = cache.begin();
    }
};