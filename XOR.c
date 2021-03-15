#include "Includes.h"

int XOR(int Value)
{
	if (Value != szKeyLen)
		return Value ^ szKeyLen;
	else if (Value != 1337)
		return Value ^ 1337;
	else
		return Value ^ (szKeyLen + 1);
}

void SZXOR(char* buffer, int buffSize)
{
	int len = strlen(buffer);

	if (buffSize)
	{
		memset(buffer + len, 0, buffSize - len);
		buffer[len] = '\0';
	}

	int z = 0;
	for (int i = 0; i < len; i++, z++)
	{
		if (z >= szKeyLen)
			z = 0;

		if (buffer[i] == szKey[z] || buffer[i] == (szKey[z] ^ ~szKey[z]))
		{
			if (buffer[i] == '\0') break;
			buffer[i] = buffer[i] ^ (~szKey[z]);
			continue;
		}

		if (buffer[i] == '\0') break;
		buffer[i] ^= szKey[z];
	}
}
