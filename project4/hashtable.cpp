#include "hashtable.h"
#include <functional>

HashTable::HashTable(size_t bucketCount) : buckets_(bucketCount ? bucketCount : 1), size_(0) {}

bool HashTable::insert(const std::string& key, const ItemHandle& value) {
    size_t index = indexFor(key);
    auto& bucket = buckets_[index];

    for (auto& pair : bucket) {
        if (pair.first == key) {
            pair.second = value;
            return false;
        }
    }

    bucket.emplace_back(key, value);
    ++size_;
    return true;
}

ItemHandle* HashTable::find(const std::string& key) {
    size_t index = indexFor(key);
    auto& bucket = buckets_[index];
    for (auto& pair : bucket) {
        if (pair.first == key) {
            return &pair.second;
        }
    }
    return nullptr;
}

const ItemHandle* HashTable::find(const std::string& key) const {
    size_t index = indexFor(key);
    const auto& bucket = buckets_[index];
    for (const auto& pair : bucket) {
        if (pair.first == key) {
            return &pair.second;
        }
    }
    return nullptr;
}

bool HashTable::erase(const std::string& key) {
    size_t index = indexFor(key);
    auto& bucket = buckets_[index];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            bucket.erase(it);
            --size_;
            return true;
        }
    }
    return false;
}
