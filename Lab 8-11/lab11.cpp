// lab11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "lab11.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	BinarySearchTree<int> tree{ 8,3,1,6,4,7,15,11,9,10,12,16 };
	cout << tree << endl;
	tree.remove(8);
    cout << tree << endl;
	BinarySearchTree<int> tree1{ 8,10,3,14,6,1,7,13,4 };

	BinarySearchTree<int> tree2{ 8,10,3,14,6,1,7,13,4 };

	if (tree1 == tree2) cout << "TRUE" << endl;

	else cout << "FALSE" << endl;

	tree1.insert(5);

	if (tree1 == tree2) cout << "TRUE" << endl;

	else cout << "FALSE" << endl;

	BinarySearchTree<int> tree4;

	cin >> tree4;//не работает правильно считывание (не определяет конец считывания);

	ofstream out("C:/Users/User/Documents/Tree.txt");

	out << tree4;

	out.close();

	system("PAUSE");
    return 0;
}

