#ifndef ARRAYBINARYTREE_H
#define ARRAYBINARYTREE_H
template<typename T>
class ArrayBinaryTree
{
	T* data;
	int maxHeight;
	bool* nodeStatus;
	int arraySize;
	int search(int i, T key);
	int heightOfTree(int i);
	int printLevel(int i, int level);
	
public:
	
	ArrayBinaryTree(int h);
	void setRoot(T v);
	void setLeftChild(T parent, T child);
	void setRightChild(T parent, T child);
	T getParent(T node);
	void remove(T node);
	void displayAncestors(T node);
	void dispalyDescendents(T node);
	void heightOfTree();
	void preOrder(int i=0);
	void postOrder(int i=0);
	void levelOrder(int i=0);
	void inOrder(int i=0);
	//void displayLevel(int levelNo);
	void displayParenthesisizedView(int i);
	void displayExplorerView(int i=0);
	int findLevelOfNode(T node);
	




};
#endif
