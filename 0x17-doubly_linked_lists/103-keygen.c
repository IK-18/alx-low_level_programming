#include "lists.h"
#define KEY_LEN 16

/**
 * main - main function that generates key from username
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on succes, 1 otherwise
 */

int main(int argc, char **argv)
{
	char *user, *key;
	char *keygen = "abcdefghijklmnoprstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int len, i, index;

	if (argc != 2)
	{
		printf("Usage: ./keygen5 username\n");
		return (1);
	}
	char *user = argv[1];
	len = strlen(user);
	key = malloc((len + 1) * sizeof(char));
	for (i = 0; i < KEY_LEN; i++)
	{
		key[i] = keygen[(int)user[index] % (sizeof(keygen) - 1)];
		index++;
		if (index >= len)
			index = 0;
	}
	key[KEY_LEN] = '\0';
	printf("%s\n", key);
}
