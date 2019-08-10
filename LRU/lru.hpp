#include <unordered_map>
//reference:https://blog.csdn.net/qq_38506897/article/details/81218683
template <typename K, typename V>
class ListNode {
public:
	K key;
	V value;
	ListNode<K,V>* prev;
	ListNode<K,V>* next;
	ListNode(K k, V v) {
		key = k;
		value = v;
		prev = next = nullptr;
	}
};
template <typename K,typename V>
class LRUCache {
public:
	LRUCache(int size) { capacity = size; head = tail = nullptr; }
	~LRUCache() {
		auto it = hash_mp.begin();
		while (it != hash_mp.end()) {
			delete it.second;
			it.second = nullptr;
			auto temp = it++;
			hash_mp.erase(temp);
		}
		delete head;
		head = nullptr;
		delete tail;
		tail = nullptr;
	}
	void remove(ListNode<K,V>* list_node) {
		list_node->next = head;
		list_node->prev = nullptr;
		if (head == nullptr) head = list_node;
		else {
			head->prev = list_node; list_node = head;
		}
		if (tail == nullptr) tail = head;
	}
	void setHead(ListNode<K,V>* list_node) {
		if(list_node->prev) list_node->prev->next = list_node->next;
		if(list_node->next) list_node->next->prev = list_node->prev;
		list_node->next = head;
		list_node->prev = nullptr;
		head = list_node;
		return;
	}


	void set(K k, V v) {
		auto it = hash_mp.find(k);
		if (it != hash_mp.end()) {
			ListNode<K,V>* list_node = it->second;
			list_node->value = v;
			remove(list_node);
			setHead(list_node);
		}
		else {
			ListNode<K,V>* list_node = new ListNode<K,V>(k, v);
			if (hash_mp.size() >= capacity) {
				auto it = hash_mp.find(tail->key);
				remove(tail);
				delete it->second;
				hash_mp.erase(it);
			}
			setHead(list_node);
			hash_mp[k] = list_node;
		}
		return;
	}
	 V get(K k) {
		auto it = hash_mp.find(k);
		if (it != hash_mp.end()) {
			ListNode<K,V>*  list_node = it->second;
			remove(list_node);
			setHead(list_node);
			return list_node->value;
		}
		else {
			return 1;//maybe is not approprate!!!
		}
	}

	int getSize() { return hash_mp.size(); }


private:
	int capacity;
	ListNode<K,V>* head;
	ListNode<K,V>* tail;
	std::unordered_map<K,ListNode<K,V>*> hash_mp;
};

/*test cases
#include <iostream>
#include "lru.hpp"
using namespace std;
int main(int argc, char** argv) {
		LRUCache<int,int>* lruCache = new LRUCache<int,int>(3);
		lruCache->set(1, 1);
		lruCache->set(2, 3);
		cout << lruCache->getSize() << endl;
		lruCache->set(3, 5);
		cout << lruCache->getSize() << endl;
		cout << lruCache->get(1) << endl;
		lruCache->set(6, 3);
		cout << lruCache->getSize() << endl;
		cout << lruCache->get(3) << endl;
		cout << lruCache->get(6) << endl;
		cout << lruCache->get(2) << endl;
		
		cin.get();
		return 0;
}
*/
