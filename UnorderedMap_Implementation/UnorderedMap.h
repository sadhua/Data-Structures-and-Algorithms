#pragma once
#include <memory>
#include <vector>

namespace dsa
{
	template <class KeyType, class ValueType>
	class MyUnorderedMap
	{
	public:

		MyUnorderedMap(int size);

		void set(const KeyType& key, const ValueType& value);

		bool get(const KeyType& key, ValueType& valueRef) const;

		std::vector<KeyType> keys() const;

		std::vector<KeyType> values() const;

		bool find(const KeyType& key) const;

		void remove(const KeyType& key);

		void print() const;

	private:

		int hash(const KeyType& key) const;

		int size_;

		typedef std::pair<KeyType, ValueType> PairKeyValueType;
		typedef std::vector< PairKeyValueType> VectorPairKeyValue;
		std::unique_ptr < std::unique_ptr< VectorPairKeyValue >[] > data_; /// data_ -> [unique_ptr, unique_ptr, unique_ptr ...]
																	       /// each unique_ptr -> std::vector(key1, value1), (Key2, value2), (...,...))

	};


}//dsa
