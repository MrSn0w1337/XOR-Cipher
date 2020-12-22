#include "Includes.h"

int XOR(int Value)
{
	if (Value != szKeyLen)
		return Value ^ szKeyLen;
	else
		return Value ^ (szKeyLen + 1);
}

void SZXOR(char* buffer, int len, int szLen, BOOL Encrypt)
{
	if (Encrypt)
	{
		if (!szLen) return;
		memset(buffer + szLen, 0, len - szLen);
		buffer[szLen] = '\0';
	}
	
	if(!szKeyLen)
		szKeyLen = strlen(szKey)

	int z = 0;
	for (int i = 0; i < len; i++)
	{
		if (i >= szKeyLen)
			z = 0;
		else
			z = i;

		if (buffer[i] == szKey[i] || buffer[i] == (szKey[z] ^ ~szKey[z]))
		{
			if (buffer[i] == '\0') break;
			buffer[i] = buffer[i] ^ (~szKey[z]);
			continue;
		}

		if (buffer[i] == '\0') break;
		buffer[i] ^= szKey[z];
	}
}
