#pragma once

#include "Dictionary.h"
#include "BSTree.h"
#include "LinkedList.h"
#include "Pair.h"
#include <stdexcept>

using std::runtime_error;

template <typename K, typename V>

class BSTDictionary {

private:
	BSTree<Pair<K, V>>* tree;

public:

	BSTDictionary() {

		tree = new BSTree<Pair<K, V>>();
	}
	~BSTDictionary() {

		delete tree;
	}
	void insert(K key, V value) override {

		tree->insert(Pair<K, V>(key, value));
	}
	V remove(K key) override {
		try {

			Pair<K, V> removed = tree->remove(Pair<K, V>(key));

			return removed.value;
		}
		catch (runtime_error& e) {

			throw runtime_error("Key not found");
		}
	}

	V getValue(K key) override {
		try {

			Pair<K, V> found = tree->find(Pair<K, V>(key));

			return found.value;
		}
		catch (runtime_error& e) {

			throw runtime_error("Key not found");
		}
	}

	List<Pair<K, V>>* getElements() {
		return tree->getElements();
	}
};

