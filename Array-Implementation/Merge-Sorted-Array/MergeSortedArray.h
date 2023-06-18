#pragma once
#include <vector>
#include <iostream>
namespace msa
{

	template <typename T>
	void merge(T& result, const T& a, int sizeA, const T& b, int sizeB)
	{
		int k = 0, i = 0, j = 0;

		for (; i < sizeA && j < sizeB; )
		{
			if (a[i] <= b[j])
				result[k++] = a[i++];
			else
				result[k++] = b[j++];
		}

		while (i < sizeA)
			result[k++] = a[i++];

		while (j < sizeB)
			result[k++] = b[j++];
	}

	int* mergeSortedArray(int* a, int* b, int sizeA, int sizeB)
	{
		int* result = new int[sizeA + sizeB];

		merge(result, a, sizeA, b, sizeB);
		return result;
		
	}

	std::vector<int> mergeSortedArray(const std::vector<int>& a, const std::vector<int>& b)
	{
		std::vector<int> rst(a.size() + b.size() );
		merge(rst, a, a.size(), b, b.size());
		return rst;
	}

}