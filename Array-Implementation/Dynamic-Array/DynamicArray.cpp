#include "DynamicArray.h"
#include <iostream>

template class dsa::DynamicArray<int>;

namespace dsa {

	template < class T>
	DynamicArray<T>::DynamicArray(int capacity) 
   :capacity_(capacity),
		a_(new T[capacity])
	{
	}

	template <class T>
	void DynamicArray<T>::push_back(const T data)
	{
		if (size_ == capacity_)
		{
			increaseCapacity();
		}

		a_[size_++] = data;
	}

	template <class T>
	void DynamicArray<T>::pop() 
	{
		if (size_ == 0)
		{
			std::cout << " EMPTY array " << std::endl;
			return;
			
		}
		size_--;
	}

	template <class T>
	T DynamicArray<T>::get(int index)
	{
		if (index < 0 || index >= size_)
		{
			std::cout << "OUSIDE the range access" << std::endl;
			return T();
		}

		return a_[index];
	}

	template <class T>
	void DynamicArray<T>::insert(const T data, int position)
	{
		if (size_ == capacity_)
		{
			increaseCapacity();
		}

		if (position < 0 || position > size_)
		{
			std::cout << "OUTSIDE range insertion" << std::endl;
			return;
		}

		shiftRight(position);
		a_[position] = data ;
	}

	template<class T>
	void DynamicArray<T>::shiftRight(int index)
	{
		for (int i = size_; i > index; i--)
		{
			a_[i] = a_[i - 1];
		}
		size_++;
	}

	template <class T>
	void DynamicArray<T>::remove(const T data)
	{
		int position = find(data);
		if (position == -1) return;

		shiftLeft(position);
	}

	template <class T>
	void DynamicArray<T>::shiftLeft(int index)
	{
		for (int i = index; i < size_ - 1; ++i)
		{
			a_[i] = a_[i + 1];
		}

		size_--;
	}

	template <class T>
	int DynamicArray<T>::find(const T data)
	{
		for (int i = 0; i < size_; ++i)
		{
			if (a_[i] == data)
				return i;
		}

		return (-1);
	}

	template <class T>
	void DynamicArray<T>::print() const
	{
		std::cout << "\nSize_ ::" << size_ << " Capacity_ ::" << capacity_ << std::endl;
		for (int i = 0; i < size_; ++i)
		{
			std::cout << a_[i] << " ";
		}

		std::cout << "\n" << std::endl;
	}

	template <class T>
	void DynamicArray<T>::increaseCapacity()
	{
		int newCapacity = capacity_ * 2;

		T* tempPtr = new T[newCapacity];

		copyArr(tempPtr);

		a_.reset( tempPtr ) ;

		capacity_ = newCapacity;
	}

	template <class T>
	void DynamicArray<T>::copyArr(T * ptr)
	{
		for (int i = 0; i < size_; ++i)
		{
			ptr[i] = a_[i];
		}
	}

	template <class T>
	T DynamicArray<T>::operator[](int index)
	{
		return this->get(index);
	}
}//dsa
