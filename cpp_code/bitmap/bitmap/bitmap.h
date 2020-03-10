#pragma once
#include<iostream>
#include<vector>
using namespace std;

class bitmap
{
	vector<int> m_bit;
	size_t m_bitcount;//bitmap���ܴ�С���൱��capacity
public:
	bitmap(size_t bite) :
		m_bit(bite / 32 + 1),
		m_bitcount(bite)
	{

	}

	//��ĳһλ��һ
	void set(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}
		//������ʾ1,22,34
		//[0]��00000000 01000000 00000000 00000010
		//[1]��00000000 00000000 00000000 00000100
		//[2]��00000000 00000000 00000000 00000000
		//[3]��00000000 00000000 00000000 00000000
		size_t index = pos / 32;//��ʾ�±�
		size_t bits = pos % 32;//��ʾÿ���е�λ��

		m_bit[index] |= 1u << bits;//��һ
	}

	//��ĳһλ����
	void reset(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}

		size_t index = pos / 32;//��ʾ�±�
		size_t bits = pos % 32;//��ʾÿ���е�λ��

		m_bit[index] &= ~(1u << bits);//����
	}

	//�ж�ĳһλ�Ľ����0��1
	bool get(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}

		size_t index = pos / 32;//��ʾ�±�
		size_t bits = pos % 32;//��ʾÿ���е�λ��

		return m_bit[index]  >> bits & 1;
	}

	//λͼ��֧������
	size_t size()
	{
		return m_bitcount;
	}

	//��λͼ��һ���ж��ٸ�1
	size_t count()
	{
		const char *pCount = "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4";
											// 0  1  2 3 4 5  6  7 8 9 a  b  c d e f

		size_t size = m_bit.size();
		size_t count = 0;
		size_t i;
		for (i = 0; i < size; i++)
		{
			int value = m_bit[i];
			for (int j = 0; j < sizeof(m_bit[0]); j++, value >>= 8)
			{
				char c = value;//char���Ͷ�value���нضϣ��൱��ȡ8λ
				count += pCount[c & 0x0f];//�����4λ��1�ĸ���
				c >> 4;//����4�󣬼���ʣ��4λ��1�ĸ���
				count += pCount[c & 0x0f];
			}
		}
	}
};