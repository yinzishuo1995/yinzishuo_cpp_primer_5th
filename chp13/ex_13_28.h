#pragma once

#include <string>

class TreeNode {
public:
	TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode& rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
	TreeNode& operator=(const TreeNode&);
	~TreeNode();
private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
	BinStrTree() : root(new TreeNode()) {}
	BinStrTree(const BinStrTree &rhs) : root(new TreeNode(*rhs.root)) {}
	BinStrTree& operator=(const BinStrTree&);
	~BinStrTree() { delete root; }

private:
	TreeNode *root;
};