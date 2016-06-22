#include<iostream>
#include"BinaryTree.hpp"
using namespace std;


void Test1()
{
	char str[] = "123##4##56";
	BinaryTree<char> gl(str);
	
	gl.PrevOrder();
	gl.InOrder();
	gl.PostOrder();
	cout << gl.Size() << endl;
	cout << gl.Depth() << endl;
}

void Test2()
{
	char str1[] = "123##4##56";
	BinaryTree<char> g(str1);
	g.PrevOrder_NonR();
	//g.PrevOrder_NR();
	//g.Inorder_NR();
	//cout << endl;
	//g.Postorder_NR();
	//g.LevelOrder_NonR();

	//cout << g.LeafSize() << endl;
	//cout << g.GetKSize(3) << endl;
	//g.PrevOrder();
	g.LeverOrder();
	
}
int main()
{
	Test1();
	Test2();
	return 0;
}