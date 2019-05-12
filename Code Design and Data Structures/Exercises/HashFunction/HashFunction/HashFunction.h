#pragma once
#include <iostream>

class HashFunction {

public:
	unsigned int BasicHash(unsigned char* a_hashData, unsigned int a_arraySize) {
		// initializes the hash sum to 0
		unsigned int m_hash = 0;

		// iterates through all array elements (letters)
		for (unsigned int i = 0; i < a_arraySize; i++)
		{
			// Adds each elements values to the hash sum as integers
			m_hash += a_hashData[i];
		}

		// returns the hash sum
		return m_hash;
	}

	unsigned int BKDRHash(unsigned char* a_hashData, unsigned int a_arraySize) {
		// initializes the hash sum to 0
		unsigned int m_hash = 0;

		// iterates through all array elements (letters)
		for (unsigned int i = 0; i < a_arraySize; i++)
		{
			// Adds each elements values to the hash sum as integers
			// after multiplying the hash by a pattern of numbers '1313'
			m_hash = (m_hash * 1313) + a_hashData[i];
		}

		// returns hash sum
		return (m_hash & 0x7FFFFFFF);
	}

	// Complex Hash Function
	unsigned int ELFHash(unsigned char* a_hashData, unsigned int a_arraySize) {
		unsigned int m_hash = 0, x = 0;
		for (unsigned int i = 0; i < a_arraySize; i++)
		{
			m_hash = (m_hash << 4) + a_hashData[i];
			if ((x = m_hash & 0xF0000000L) != 0) {
				m_hash ^= (x >> 24);
				m_hash &= ~x;
			}
		}

		return (m_hash & 0x7FFFFFFF);
	}
};