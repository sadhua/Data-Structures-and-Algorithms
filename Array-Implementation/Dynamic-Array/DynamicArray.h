#pragma once
#include <memory>

namespace dsa {
	template < class T>
	class DynamicArray
	{
	private :
		int capacity_ = 0;
		int size_ = 0;

		std::unique_ptr<T[]> a_;

	public :
		
		DynamicArray(int capacity);

		void push_back(const T data);

		void pop();

		T get(int index);

		void insert(const T data, int position);

		void remove(const T data);

		int find(const T data);

		void print() const;

		T operator[](int index);

	private:

		void shiftLeft(int index);

		void shiftRight(int index);

		void increaseCapacity();

		void copyArr(T* ptr);
	};
}//dsa

