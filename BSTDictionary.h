#pragma once

#include "Dictionary.h"
#include "BSTree.h"
#include "LinkedList.h"
#include "Pair.h"
#include <stdexcept>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename K, typename V>

class BSTDictionary : public Dictionary<K, V> {

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

	void setValue(K key, V value) override {
		
		if (!tree->contains(Pair<K, V>(key))) {

			throw runtime_error("Key not found");
		}

		tree->remove(Pair<K, V>(key));

		tree->insert(Pair<K, V>(key, value));
	}

	bool contains(K key) override {

		return tree->contains(Pair<K, V>(key));
	}

	bool isEmpty() override {

		return tree->isEmpty();
	}

	void clear() override {

		tree->clear();
	}	

	List<K>* getKeys() override {

		List<Pair<K, V>>* pairs = tree->getElements();

		List<K>* keys = new LinkedList<K>();

		pairs->goToStart();

		while (!pairs->atEnd()) {

			keys->append(pairs->getElement().key);

			pairs->next();
		}

		delete pairs;

		return keys;
	}

	List<V>* getValues() override {

		List<Pair<K, V>>* pairs = tree->getElements();

		List<V>* values = new LinkedList<V>();

		pairs->goToStart();

		while (!pairs->atEnd()) {

			values->append(pairs->getElement().value);

			pairs->next();
		}

		delete pairs;

		return values;
	}

	int getSize() override {

		return tree->getSize();
	}

	void print() override {

		List<Pair<K, V>>* pairs = tree->getElements();

		pairs->goToStart();

		cout << "{ ";

		bool first = true;

		while (!pairs->atEnd()) {

			if (!first) {

				cout << ", ";
			}

			Pair<K, V> pair = pairs->getElement();

			cout << pair.key << ": " << pair.value;

			first = false;

			pairs->next();
		}

		cout << " }" << endl;

		delete pairs;
	}

	void update(Dictionary<K, V>* D) override {

		List<K>* keys = D->getKeys();

		keys->goToStart();

		while (!keys->atEnd()) {

			K key = keys->getElement();

			V value = D->getValue(key);

			if (contains(key) {

				setValue(key, value);
			}
			else {

				insert(key, value);
			}

			keys->next();
		}

		delete keys;
	}

	void zip(List<K>* keys, List<V>* values) override {
		
		keys->goToStart();

		values->goToStart();

		while (!keys->atEnd() && !values->atEnd()) {

			K key = keys->getElement();

			V value = values->getElement();

			if (contains(key)) {

				setValue(key, value);
			}

			else {

				insert(key, value);
			}

			keys->next();

			values->next();
		}
	}
};

