#include<iostream>
#include"ABT.h"
using namespace std;
//template <typename T>
//int ArrayBinaryTree<T>::printLevel(int i, int level)
//{
//	if (nodeStatus[i] != false)
//		return;
//	if (level < 0)
//		return;
//}
template <typename T>
int ArrayBinaryTree<T>::search(int i, T key)
{
	int status = -1;
	if (data[i] == key)
	{
		status = i;
	}
	if (status == -1 && (2 * i + 1) < arraySize && nodeStatus[2 * i + 1])
	{
		status = search(2 * i + 1, key);
	}
	if (status == -1 && (2 * i + 2) < arraySize && nodeStatus[2 * i + 2])                                                                                                                                   
	{
		status = search(2 * i + 2, key);
	}
	return status;
}
template <typename T>
ArrayBinaryTree<T>::ArrayBinaryTree(int h)
{
	if (h <= 0)
		return;
	maxHeight = h;

	arraySize = pow(2, maxHeight) - 1;
	nodeStatus = new bool[arraySize];
	data = new T[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		nodeStatus[i] = false;
	}

}
template <typename T>
void ArrayBinaryTree<T>::setRoot(T v)
{
	data[0] = v;
	nodeStatus[0] = true;
}
template <typename T>
T ArrayBinaryTree<T>::getParent(T node)
{
	int i = search(0, node);
	if (i == -1)
	{
		exit(0);
	}
	return data[(i - 1) / 2];
}
template <typename T>
void ArrayBinaryTree<T>::remove(T node)
{
	int i = search(0, node);
	if (i == -1)
		return;
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
	{
		remove(data[2 * i + 1]);

	}
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
	{
		remove(data[2 * i + 2]);
	}
	nodeStatus[i] = false;
}
template <typename T>
void ArrayBinaryTree<T>::heightOfTree()
{
	cout<<"\nHeight of tree is: "<< heightOfTree(0);
}

template <typename T>
int ArrayBinaryTree<T>::heightOfTree(int i)
{
	int l = 0, r = 0;
	int h = 1;
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
	{
		l = heightOfTree(2 * i + 1);
	}
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
	{
		r = heightOfTree(2 * i + 2);
	}
	if (l > r)
	{
		return h + l;
	}
		return h + r;
}
template <typename T>
void ArrayBinaryTree<T>::setLeftChild(T parent, T child)
{
	int x = search(0, parent);
	if (x == -1)
	{
		return;
	}
	data[2 * x + 1] = child;
	nodeStatus[2 * x + 1] = true;

}
template <typename T>
void ArrayBinaryTree<T>::setRightChild(T parent, T child)
{

	int x = search(0, parent);
	if (x == -1)
	{
		return;
	}
	data[2 * x + 2] = child;
	nodeStatus[2 * x + 2] = true;

}
template <typename T>
void ArrayBinaryTree<T>::preOrder(int i)//VLR
{
	if (i <= -1)
	{
		return;
	}
	cout << data[i];
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
	{

		preOrder(2 * i + 1);
	}
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
	{

		preOrder(2 * i + 2);
	}
}
template <typename T>
void ArrayBinaryTree<T>::postOrder(int i)//LRV
{

	if (i <= -1)
	{
		return;
	}
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
	{
		postOrder(2 * i + 2);
	}
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
	{

		postOrder(2 * i + 1);
	}
	cout << data[i];
}
template <typename T>
void ArrayBinaryTree<T>::displayAncestors(T node)
{

	int x = search(0, node);
	if (x == 0)
	{
		return;
	}
	
	displayAncestors(data[(x - 1) / 2]);
	cout << data[(x - 1) / 2] << " ";
	//x = (x - 1) / 2;
	


}
template <typename T>
void ArrayBinaryTree<T>::dispalyDescendents(T node)
{
	int i = search(0, node);
	/*if (i == 0)
	{
		return;
	}*/
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
	{
		cout << data[2 * i + 1];
		dispalyDescendents(data[2 * i + 1]);
	}
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
	{
		cout << data[2 * i + 2];
		dispalyDescendents(data[2 * i + 2]);
	}

}
template <typename T>
void ArrayBinaryTree<T>::levelOrder(int i)
{
	if (i <= -1)
	{
		return;
	}

	if (i >= arraySize)
	{
		return;
	}
	if (nodeStatus[i] == true && i<arraySize)
	{
		cout << data[i];
		
	}
	levelOrder(i + 1);
}
template <typename T>
void ArrayBinaryTree<T>::inOrder(int i)
{
	if (i <= -1)
	{
		return;
	}

	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
	{
		inOrder(2 * i + 1);
	}
	cout << data[i]<<" ";
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
	{
		inOrder(2 * i + 2);
	}
}
//template <typename T>
//void ArrayBinaryTree<T>::displayLevel(int levelNo)
//{
//	if (levelNo == 0)
//	{
//		cout << "\nIt's the Root Node: ";
//		cout << data[0];
//		return;
//	}
//	if (levelNo > 0 && levelNo < maxheight)
//	{
//
//	}
//	displayLevel(levelNo + 1);
//	
//}
template <typename T>
void ArrayBinaryTree<T>::displayParenthesisizedView(int i)
{
	
	if (nodeStatus[0] == false)
		return;
	cout << data[i];
	if (nodeStatus[2 * i + 1] && 2 * i + 1 < arraySize || nodeStatus[2 * i + 2] && 2 * i + 2 < arraySize)
	{
		cout << "(";
	}
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
	{

		displayParenthesisizedView(2 * i + 1);
	}
	if (nodeStatus[2 * i + 1] && 2 * i + 1 < arraySize || nodeStatus[2 * i + 2] && 2 * i + 2 < arraySize)
	{
		cout << ",";
	}
	
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
	{

		displayParenthesisizedView(2 * i + 2);
	}
	if ((2 * i + 1) < arraySize && (2 * i + 1) < arraySize || nodeStatus[2 * i + 2] && nodeStatus[2 * i + 1])
	{
		cout <<")";

	}
}
template <typename T>
void ArrayBinaryTree<T>::displayExplorerView(int i)
{
	
	if (i == 0 && nodeStatus[i] == false)
	{
		return;
	}
	cout << data[i] << "\n";
	if (2 * i + 1 < arraySize && nodeStatus[2 * i + 1])
	{
		cout << "\t";
		displayExplorerView(2 * i + 1);
	}
	if (2 * i + 2 < arraySize && nodeStatus[2 * i + 2])
	{
		cout << "\t";
		displayExplorerView(2 * i + 2);
	}
}
template <typename T>
int ArrayBinaryTree<T>::findLevelOfNode(T node)
{
	int i = search(0, node);
	if (i == -1)
		return -1;
	int level=heightOfTree(i);
	level = maxHeight-level+1;
	return level;
}