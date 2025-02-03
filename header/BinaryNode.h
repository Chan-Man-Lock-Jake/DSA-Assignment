#pragma once

// typedef std::string ItemType;
typedef int ItemType;
template <typename T>
struct BinaryNode
{
	ItemType key;		// node key
	T value;			// node data
	int height;			// node height
	BinaryNode* left;	// pointer pointing to left subtree
	BinaryNode* right;	// pointer pointing to right subtree

	BinaryNode(ItemType input_key, T input_value) {
		key = input_key;
		value = input_value;
		height = 1;
		left = nullptr;
		right = nullptr;
	}
};
