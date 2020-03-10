#pragma once
#include<iostream>
#include<vector>
using namespace std;

class bitmap
{
	vector<int> m_bit;
	size_t m_bitcount;//bitmap的总大小，相当于capacity
public:
	bitmap(size_t bite) :
		m_bit(bite / 32 + 1),
		m_bitcount(bite)
	{

	}

	//给某一位置一
	void set(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}
		//例：表示1,22,34
		//[0]：00000000 01000000 00000000 00000010
		//[1]：00000000 00000000 00000000 00000100
		//[2]：00000000 00000000 00000000 00000000
		//[3]：00000000 00000000 00000000 00000000
		size_t index = pos / 32;//表示下标
		size_t bits = pos % 32;//表示每组中的位置

		m_bit[index] |= 1u << bits;//置一
	}

	//给某一位置零
	void reset(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}

		size_t index = pos / 32;//表示下标
		size_t bits = pos % 32;//表示每组中的位置

		m_bit[index] &= ~(1u << bits);//置零
	}

	//判断某一位的结果是0或1
	bool get(size_t pos)
	{
		if (pos > m_bitcount)
		{
			return;
		}

		size_t index = pos / 32;//表示下标
		size_t bits = pos % 32;//表示每组中的位置

		return m_bit[index]  >> bits & 1;
	}

	//位图不支持扩容
	size_t size()
	{
		return m_bitcount;
	}

	//数位图中一共有多少个1
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
				char c = value;//char类型对value进行截断，相当于取8位
				count += pCount[c & 0x0f];//计算低4位中1的个数
				c >> 4;//右移4后，计算剩下4位中1的个数
				count += pCount[c & 0x0f];
			}
		}
	}
};