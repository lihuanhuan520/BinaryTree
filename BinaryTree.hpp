#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
typedef char DataType;

template <class T >
struct BinaryTreeNode
{
public:
	BinaryTreeNode(T value)
		:_value(value)
		, _right(NULL)
		, _left(NULL)
	{}
	T _value;
	BinaryTreeNode<T>* _right;
	BinaryTreeNode<T>* _left;

};

template <class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
private:
	BinaryTreeNode<T>* _root;
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(char* str)
	{
		_CreateTree(_root, str);
	}
	~BinaryTree()
	{}
	void PrevOrder()
	{
		cout << "前序遍历:	";
		_PrevOrder_R(_root);
		cout << endl;
	}
	void PrevOrder_NR()
	{
		stack<Node*> s;
		if (_root)
			s.push(_root);

		while (!s.empty())
		{
			Node* top = s.top();
			cout << top->_value << " ";
			s.pop();

			if (top->_right)
				s.push(top->_right);
			if (top->_left)
				s.push(top->_left);
		}
	}
	void Inorder_NR()
	{
		stack<Node*> s;
		Node* cur = _root;
		
		while (cur ||!s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top();
			cout << top->_value << " ";
			s.pop();

			if (top->_right)
			{
				cur = top->_right;
			}
		}
	}
	void Postorder_NR()
	{
		stack<Node*> s;
		Node* cur = _root;
		Node* prev = NULL;

		while (cur||!s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			Node* top = s.top();
			if (top->_right == NULL || top->_right == prev)
			{
			
				cout << top->_value << " ";
				s.pop();
				prev = top;	
			}
			else 
			{
				cur = top->_right;
			}
		}
	}
	void PostOrder()
	{
		cout << "后序遍历:	";
		_PostOrder_R(_root);
		cout << endl;
	}

	void InOrder()
	{
		cout << "中序遍历:	";
		_InOrder(_root);
		cout << endl;
	}
	void PrevOrder_NonR()
	{
		cout << "前序遍历：" << " ";
		_PrevOrder_NonR();
		cout << endl;
	}
	void Mirror()
	{
		_Mirror(_root);
		cout << endl;
	}
	int LeafSize()
	{
		return _LeafSize(_root);
	}
	int GetKSize(int k)
	{
		return _GetKSize(_root,k);
	}
	int Size()
	{
		return _Size(_root);
	}

	int Depth()
	{
		return _Depth(_root);
	}

	//二叉树的层序遍历
	void LeverOrder()
	{
		queue<Node*> q;
		if (_root == NULL)//没有节点
		{
			return;
		}
		else if (_root->_left == NULL && _root->_right == NULL)//一个节点
		{
			cout << _root->_value << " ";
			return;
		}
		else
		{
			Node* cur = _root;
			q.push(cur);
			while (!q.empty() && cur != NULL)
			{
				Node* front = q.front();
				cout << front->_value << " ";
				q.pop();
				if (front->_left != NULL)
					q.push(front->_left);
				if (front->_right != NULL)
					q.push(front->_right);
			}
			cout << endl;
		}
	}
protected:

	void _CreateTree(BinaryTreeNode<T>*& root, char* &str)//创建二叉树
	{
		if (*str != '\0' && *str != '#')
		{
			root = new BinaryTreeNode<T>(*str);
			_CreateTree(root->_left, ++str);
			if (*str == '\0')
			{
				return ;
			}
			_CreateTree(root->_right, ++str);
		}
	}
	
	void _PrevOrder_R(BinaryTreeNode<T>* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			cout << root->_value << " ";
			_PrevOrder_R(root->_left);
			_PrevOrder_R(root->_right);
		}
	}


	void _PostOrder_R(BinaryTreeNode<T>* root)//后序遍历 递归
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			_PostOrder_R(root->_left);
			_PostOrder_R(root->_right);
			cout << root->_value << " ";
		}
	}

	void _InOrder(BinaryTreeNode<T>* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			_InOrder(root->_left);
			cout << root->_value << " ";
			_InOrder(root->_right);
		}
	}

	void _InOrder_NonR(BinaryTreeNode<T>* root)//中序遍历 非递归
	{
		queue<BinaryTreeNode<T>*> q;
		if (root)
		{
			q.push(root);
		}
		while (!q.empty())
		{
			BinaryTreeNode<T>* front = q.front();
			cout << front->_value << " ";
			q.pop();
			if (front->_left != NULL)
			{
				_LevelOrder(front->_left);
			}
			if (front->_right != NULL)
			{
				_LevelOrder(front->_right);
			}
		}
	}


	void _PrevOrder_NonR()    // 二叉树前序遍历(非递归)
	{
		stack<Node*> s;
		if (_root)  //root 不为空 压栈
		{
			s.push(_root);
		}
		while (!s.empty())
		{
			Node* top = s.top();
			cout << top ->_value<< " ";
			s.pop();
			if (top->_right != NULL) //先压右 后压左
			{
				s.push(top->_right);
			}
			if (top->_left != NULL)
			{
				s.push(top->_left);
			}
		}
	}


	int _GetKSize(BinaryTreeNode<T>* root, int k)//求第K层节点数
	{
		if (root == NULL)
			return 0;
		else if (k == 1)
			return 1;
		else
			return _GetKSize(root->_left, k - 1) + _GetKSize(root->_right, k - 1);
	}
	int _LeafSize(BinaryTreeNode<T>* root)
	{
		if (root == NULL)
			return 0;
		else if (root->_left == NULL&&root->_right == NULL)
			return 1;
		else
			return _LeafSize(root->_left) + _LeafSize(root->_right);
	}
		int _Size(BinaryTreeNode<T>* root)
		{
			if (root == NULL)
			{
				return 0;
			}
			return 1 + _Size(root->_left) + _Size(root->_right);
		}


		int _Depth(BinaryTreeNode<T>* root)
		{
			int leftDepth;
			int rigthDepth;
			if (root == NULL)
			{
				return 0;
			}
			leftDepth = _Depth(root->_left);
			rigthDepth = _Depth(root->_right);
			return 1 + (leftDepth > rigthDepth ? leftDepth : rigthDepth);
		}

};