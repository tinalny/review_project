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

	//*************************************����**********************************************
	void Lround(TreeNode<T> * pre)
	{
		TreeNode<T> * parent = pre->m_parent;
		TreeNode<T> * cur = pre->m_right;

		//������������������Ҫ�����������е���
		cur->m_parent = parent;
		if (parent)//����Ҫ��ת�ĸý���и����
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
		else//���ý��û�и���㣬��ý����Ǹ����
		{
			m_root = cur;
		}

		//�ý������ӻ��Ϊԭ���������Һ���
		pre->m_right = cur->m_left;
		if (cur->m_left)//���ý��ԭ�������Ӵ��ڣ������ĸ��׽�����pre
		{
			cur->m_left->m_parent = pre;
		}

		cur->m_left = pre;//�ý��֮ǰ�ĸ���㽫���Ϊ�ý�������
		pre->m_parent = cur;//�ý���Ϊԭ�����׽��ĸ����

		cur->m_bf = pre->m_bf = 0;
	}

	//*************************************�ҵ���**********************************************
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

	//*************************************���ҵ���**********************************************
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

	//*************************************������**********************************************
	void RLround(TreeNode<T> * pre)
	{
		TreeNode<T> * right = pre->m_right;
		TreeNode<T> * newroot = right->m_left;

		//��ת֮ǰ������newroot��ƽ�����ӣ���ת���֮����Ҫ���ݸ�ƽ�����������������ڵ��ƽ������
		int flag = newroot->m_bf;

		Rround(pre->m_right);//�Ƚ����ҵ���
		Lround(pre);//�ٽ�������

					//�ж���������flag�Ľ��
		if (flag == -1)//���½���ƽ������Ϊ-1������ǣ��ڸý������Ӳ���һ����㣬�����������еĽ��
		{
			right->m_bf = 1;
		}
		else//���½���ƽ������Ϊ 1 ������ǣ��ڸý����Һ��Ӳ���һ����㣬�����������еĽ��
		{
			pre->m_bf = -1;
		}
	}

public:
	AVLTree() :
		m_root(nullptr)
	{

	}

	//**************************AVL���Ĳ���**********************************
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
				//�����½��ᵼ��ԭ���Ķ�������ƽ�⣬�����ܽ�Ϊ��������������е�����ʹ����������ƽ��
				if (pre->m_bf == 2)
				{
					if (cur->m_bf == 1)//�����ҡ�
					{
						Lround(pre);
					}
					else//������
					{
						RLround(pre);
					}
				}
				else
				{
					if (cur->m_bf == 1)//�����ҡ�
					{
						LRround(pre);
					}
					else//������
					{
						Rround(pre);
					}
				}
				break;
			}
		}
		return true;
	}

	//**************************AVL����ɾ��**********************************
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
