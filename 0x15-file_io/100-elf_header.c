#include "main.h"

/**
 * _memcmp - compares the adress of two memory blocks
 * @s1: first memory block
 * @s2: second memory block
 * @n: size of memory blocks
 *
 * Return: d9fference between memory blocks else 0
 */

int _memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p1 = s1, *p2 = s2;
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (p1[i] != p2[i])
			return ((int)p1[i] - (int)p2[i]);
	}

	return (0);
}

/**
 * print_error - primts corressponding error message
 * @msg: message to print
 *
 * Return: Nothing
 */

void print_error(char *msg)
{
	    dprintf(STDERR_FILENO, "Error: %s\n", msg);
}

/**
 * print_elf_header - prints elf header properties
 * @header: elf header struct
 *
 * Return: Nothing
 */

void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("  Magic:\t");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:\t\t\t\t");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%s", "ELF32\n");
	else
		printf("%s", "ELF64\n");
	printf("  Data:\t\t\t\t");
	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("%s\n", "2's complement, big endian");
	else
		printf("%s\n", "2's complement, little endian");
	printf("  Version:\t\t\t\t%d ", header->e_ident[EI_VERSION]);
	if (header->e_ident[EI_VERSION] == EV_CURRENT)
		printf("%s\n", "current");
	else
		printf("%s\n", "invalid");

	printf("  OS/ABI:\t\t\t");
	if (header->e_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("%s\n", "UNIX - System V");
	else
		printf("%s\n", "Other");
	printf("  ABI Version:\t\t\t%d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:\t\t\t\t%d ", header->e_type);
	if (header->e_type == ET_EXEC)
		printf("%s\n", "EXEC (Executable file)");
	else if (header->e_type == ET_DYN)
		printf("%s\n", "DYN (Shared object file)");
	else
		printf("%s\n", "other");
	printf("  Entry point address:\t\t%lx\n", header->e_entry);
}

/**
 * main - main function
 * @argc: argument count
 * @argv: argument values
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	    int fd;
	    ssize_t bytes_read;
	    Elf64_Ehdr header;
	    Elf64_Ehdr buf[sizeof(header)];

	    if (argc != 2)
	    {
		    print_error("Usage: elf_header elf_filename");
		    exit(98);
	    }
	    fd = open(argv[1], O_RDONLY);
	    if (fd == -1)
	    {
		    print_error("Unable to open file");
		    exit(98);
	    }
	    bytes_read = read(fd, buf, sizeof(header));
	    if (bytes_read != sizeof(header))
	    {
		    print_error("Unable to read file");
		    exit(98);
	    }
	    if (_memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	    {
		    print_error("Not an ELF file");
		    exit(98);
	    }
	    print_elf_header(&header);
	    close(fd);
	    return (0);
}
