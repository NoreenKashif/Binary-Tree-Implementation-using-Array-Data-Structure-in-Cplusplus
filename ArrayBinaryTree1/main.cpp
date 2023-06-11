#include<iostream>
#include<string>
#include"ABT.h"
using namespace std;
int main()
{
	ArrayBinaryTree<string> b(5);
	b.setRoot("A");
	b.setLeftChild("A", "B");
	b.setRightChild("A", "C");
	b.setRightChild("B","E");
	b.setLeftChild("B", "D");
	b.setRightChild("D", "H");
	//b.displayAncestors("H");
	cout << "\n";
	//b.remove("B");
	//b.displayAncestors("D");
	b.setLeftChild("E", "I");
	b.setRightChild("E", "J");
	b.setLeftChild("I", "K");
	b.setRightChild("C", "F");
	b.displayAncestors("K");
	b.heightOfTree();
	cout << "\n";
	b.inOrder();
	cout << "\nLEVEL ORDER IS:\n";
	b.levelOrder(0);
	cout << "\n";
	b.displayParenthesisizedView(0);
	//b.levelOrder();
	cout << "\n";
	b.dispalyDescendents("A");
	cout << "\n";
	//b.displayLevel(2);
	b.displayExplorerView(0);
	cout << "\n";
	cout<<b.findLevelOfNode("I");







}