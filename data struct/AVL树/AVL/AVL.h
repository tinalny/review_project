#pragma once
#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
	int m_bf;
	T m_data;
	TreeNode<T> * m_left;
	TreeNode<T> * m_right;
	TreeNode<T> * m_parent;
public:
	TreeNode(const T & val = T()) :
		m_bf(0),
		m_data(val),
		m_left(nullptr),
		m_right(nullptr),
		m_parent(nullptr)
	{

	}

	template <class T>
	friend class AVLTree;
};


template<class T>
class AVLTree
{
	TreeNode<T> * m_root;

	//*************************************左单旋**********************************************
	void Lround(TreeNode<T> * pre)
	{
		TreeNode<T> * parent = pre->m_parent;
		TreeNode<T> * cur = pre->m_right;

		//若进行左单旋，可能需要对三个结点进行调整
		cur->m_parent = parent;
		if (parent)//若需要旋转的该结点有父结点
		{
			if (parent->m_left == pre)
			{
				parent->m_left = cur;
			}
			else
			{
				parent->m_right = cur;
			}
		}
		else//若该结点没有父结点，则该结点就是根结点
		{
			m_root = cur;
		}

		//该结点的左孩子会成为原来父结点的右孩子
		pre->m_right = cur->m_left;
		if (cur->m_left)//若该结点原来的左孩子存在，则它的父亲结点会变成pre
		{
			cur->m_left->m_parent = pre;
		}

		cur->m_left = pre;//该结点之前的父结点将会变为该结点的左孩子
		pre->m_parent = cur;//该结点变为原来父亲结点的父结点

		cur->m_bf = pre->m_bf = 0;
	}

	//*************************************右单旋**********************************************
	void Rround(TreeNode<T> * pre)
	{
		TreeNode<T> * parent = pre->m_parent;
		TreeNode<T> * cur = pre->m_left;

		cur->m_parent = parent;

		if (parent)
		{
			if (parent->m_left == pre)
			{
				parent->m_left = cur;
			}
			else
			{
				parent->m_right = cur;
			}
		}
		else
		{
			m_root = cur;
		}

		pre->m_left = cur->m_right;
		if (cur->m_right)
		{
			cur->m_right->m_parent = pre;
		}

		cur->m_right = pre;
		pre->m_parent = cur;

		cur->m_bf = pre->m_bf = 0;
	}

	//*************************************左右单旋**********************************************
	void LRround(TreeNode<T> * pre)
	{
		TreeNode<T> * left = pre->m_left;
		TreeNode<T> * newroot = left->m_right;

		int flag = newroot->m_bf;

		Lround(pre->m_left);
		Rround(pre);

		if (flag == -1)
		{
			pre->m_bf = 1;
		}
		else
		{
			left->m_bf = -1;
		}
	}

	//*************************************右左单旋**********************************************
	void RLround(TreeNode<T> * pre)
	{
		TreeNode<T> * right = pre->m_right;
		TreeNode<T> * newroot = right->m_left;

		//旋转之前，保存newroot的平衡因子，旋转完成之后，需要根据该平衡因子来调整其他节点的平衡因子
		int flag = newroot->m_bf;

		Rround(pre->m_right);//先进行右单旋
		Lround(pre);//再进行左单旋

					//判断右左单旋后flag的结果
		if (flag == -1)//当新结点的平衡因子为-1的情况是：在该结点的左孩子插入一个结点，经过右左单旋有的结果
		{
			right->m_bf = 1;
		}
		else//当新结点的平衡因子为 1 的情况是：在该结点的右孩子插入一个结点，经过右左单旋有的结果
		{
			pre->m_bf = -1;
		}
	}

public:
	AVLTree() :
		m_root(nullptr)
	{

	}

	//**************************AVL树的插入**********************************
	bool insert(const &T val)
	{

		if (m_root == nullptr)
		{
			m_root = new TreeNode<T>(val);
			return true;
		}

		TreeNode<T> * cur = m_root;
		TreeNode<T> *pre = nullptr;

		while (cur)
		{
			if (val < cur->m_data)
			{
				pre = cur;
				cur = cur->m_left;
			}
			else if (val > cur->m_data)
			{
				pre = cur;
				cur = cur->m_right;
			}
			else
			{
				return false;
			}
		}
		cur = new TreeNode<T>(val);
		if (val < pre->m_data)
		{
			pre->m_left = cur;
		}
		else
		{
			pre->m_right = cur;
		}

		cur->m_parent = pre;

		while (pre)
		{
			if (pre->m_left == cur)
			{
				pre->m_bf--;
			}
			else
			{
				pre->m_bf++;
			}

			if (pre->m_bf == 0)
			{
				break;
			}
			else if (pre->m_bf == 1 || pre->m_bf == -1)
			{
				cur = pre;
				pre = pre->m_parent;
			}
			else
			{
				//插入新结点会导致原来的二叉树不平衡，可以总结为以下四种情况进行调整，使二叉树重新平衡
				if (pre->m_bf == 2)
				{
					if (cur->m_bf == 1)//“右右”
					{
						Lround(pre);
					}
					else//“右左”
					{
						RLround(pre);
					}
				}
				else
				{
					if (cur->m_bf == 1)//“左右”
					{
						LRround(pre);
					}
					else//“左左”
					{
						Rround(pre);
					}
				}
				break;
			}
		}
		return true;
	}

	//**************************AVL树的删除**********************************
	bool erase(const T &val)
	{
		if (m_root == nullptr)
		{
			m_root = new TreeNode<T>(val);
			return true;
		}

		TreeNode<T> * cur = m_root;
		TreeNode<T> *pre = nullptr;

		while (cur)
		{
			if (val < cur->m_data)
			{
				pre = cur;
				cur = cur->m_left;
			}
			else if (val > cur->m_data)
			{
				pre = cur;
				cur = cur->m_right;
			}
			else
			{
				break;
			}
		}

		if (cur == nullptr)
		{
			return false;
		}

		if (cur->m_left && cur->m_right)
		{
			TreeNode<T> * cur2 = cur->m_left;

			if (cur2->m_right)
			{
				for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);

				pre2->m_right = cur2->m_left;
				cur2->m_left = cur->m_left;
			}

			cur2->m_right = cur->m_right;

			if (cur->m_data < pre->m_data)
			{
				pre->m_left = cur2;
			}
			else
			{
				pre->m_right = cur2;
			}
			delete cur;
		}
		else if (cur->m_left)
		{
			if (cur->m_data < pre->m_data)
			{
				pre->m_left = cur->m_left;
			}
			else
			{
				pre->m_right = cur->m_left;
			}
			delete cur;
		}
		else
		{
			if (cur->m_data < pre->m_data)
			{
				pre->m_left = cur->m_right;
			}
			else
			{
				pre->m_right = cur->m_right;
			}
			delete cur;
		}
	}
};
