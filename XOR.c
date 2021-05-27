#include "Includes.h"

int XOR(int Value)
{
	return Value ^ (~szKeyLen);
}

void SZXOR(char* buffer, size_t buffSize)
{
	size_t z = 0;
	for (size_t i = 0; i < buffSize; i++, z++)
	{
		if (buffer[i] == 0)
			continue;

		if (z >= szKeyLen)
			z = 0;

		if (buffer[i] == szKey[z] || buffer[i] == (szKey[z] ^ ~szKey[z]))
			buffer[i] = buffer[i] ^ (~szKey[z]);
		else
			buffer[i] ^= szKey[z];
	}
}
