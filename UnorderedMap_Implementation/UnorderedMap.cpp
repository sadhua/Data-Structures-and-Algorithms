#include "UnorderedMap.h"
#include <iostream>

template class dsa::MyUnorderedMap<int, int>;

namespace dsa
{
	template <class KeyType, class ValueType>
	MyUnorderedMap<KeyType, ValueType>::MyUnorderedMap(int size) :
		size_(size),
		data_(new std::unique_ptr< VectorPairKeyValue > [size] )
	{
		std::cout << "-- my_unordered_map constr ::" << size_ << std::endl;

	}

	template <class KeyType, class ValueType>
	void MyUnorderedMap<KeyType, ValueType>::set(const KeyType& key, const ValueType& value)
	{
		int index = hash(key);

		if (data_[index] == nullptr)
		{
			data_[index] = std::unique_ptr < VectorPairKeyValue >(new VectorPairKeyValue() );
		}

		data_[index]->push_back(std::make_pair(key, value));
	}

	template <class KeyType, class ValueType>
	bool MyUnorderedMap<KeyType, ValueType>::get(const KeyType& key, ValueType& valueRef) const
	{
		int index = hash(key);

		if (data_[index] == nullptr)
		{
			return false;
		}

		std::vector<PairKeyValueType>& dataVecAtKey = *(data_[index]);

		for (auto& itr : dataVecAtKey)
		{
			if (key == itr.first)
			{
				valueRef = itr.second;
				return true;
			}
		}	
		return false;
	}

	template <class KeyType, class ValueType>
	std::vector<KeyType> MyUnorderedMap<KeyType, ValueType>::keys() const
	{
		std::vector<KeyType> keys;
		for (int i = 0; i < size_; ++i)
		{
			if (data_[i] != nullptr)
			{
				auto& vecRef = *(data_[i]);
				for (auto& itr : vecRef)
				{
					keys.push_back(itr.first);
				}
			}
		}
		return keys;
	}

	template <class KeyType, class ValueType>
	std::vector<KeyType> MyUnorderedMap<KeyType, ValueType>::values() const
	{
		std::vector<KeyType> values;
		for (int i = 0; i < size_; ++i)
		{
			if (data_[i] != nullptr)
			{
				auto& vecRef = *(data_[i]);
				for (auto& itr : vecRef)
				{
					values.push_back(itr.second);
				}
			}
		}
		return values;
	}

	template <class KeyType, class ValueType>
	bool MyUnorderedMap<KeyType, ValueType>::find(const KeyType& key) const
	{
		int index = hash(key);

		if (data_[index] == nullptr)
		{
			return false;
		}

		std::vector<PairKeyValueType>& dataVecAtKey = *(data_[index]);

		for (auto& itr : dataVecAtKey)
		{
			if (key == itr.first)
			{
				return true;
			}
		}
		return false;
	}

	template <class KeyType, class ValueType>
	void MyUnorderedMap<KeyType, ValueType>::remove(const KeyType& key)
	{
		int index = hash(key);

		if (nullptr == data_[index])
		{
			return;
		}

		auto& vecRef = *(data_[index]);

		for (auto itr = vecRef.begin(); itr != vecRef.end(); ++itr)
		{
			if (itr->first == key)
			{
				vecRef.erase(itr);
				return;
			}
		}
	}

	template <class KeyType, class ValueType>
	void MyUnorderedMap<KeyType, ValueType>::print() const
	{
		std::cout << "----- MyUnorderedMap ------" << std::endl;

		for (int i = 0; i < size_; ++i)
		{
			if (data_[i] != nullptr)
			{
				auto& vecRef = *(data_[i]);
				for (auto& itr : vecRef)
				{
					std::cout << "--- (" << itr.first << ", " << itr.second << ")" << std::endl;
				}
			}
		}
	}

	template <class KeyType, class ValueType>
	int MyUnorderedMap<KeyType, ValueType>::hash(const KeyType& key) const
	{
		std::cout << "----hash ::" << key % size_ << std::endl;
		return key % size_;
	}


}