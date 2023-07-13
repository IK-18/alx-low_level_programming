#include "main.h"

/**
 * _printMagicClass - Prints the magic numbers and class of an ELF header.
 * @e_id: A pointer to an array containing the ELF magic numbers.
 *
 * Return: Nothing
 */

void _printMagicClass(unsigned char *e_id)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_id[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
	printf("  Class:                             ");
	switch (e_id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * _printDataVersion - Prints the data and version of an ELF header.
 * @e_id: A pointer to an array containing the ELF class.
 *
 * Return: Nothng
 */

void _printDataVersion(unsigned char *e_id)
{
	printf("  Data:                              ");

	switch (e_id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
	printf("  Version:                           %d",
		   e_id[EI_VERSION]);

	switch (e_id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * _printOSABI - Prints the OS/ABI and ABI of an ELF header.
 * @e_id: A pointer to an array containing the ELF version.
 *
 * Return: Nothing
 */

void _printOSABI(unsigned char *e_id)
{
	printf("  OS/ABI:                            ");
	switch (e_id[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_OSABI]);
	}
	printf("  ABI Version:                       %d\n",
		   e_id[EI_ABIVERSION]);
}

/**
 * _printTypeEntry - Prints the type and entry point of an ELF header.
 * @e_t: The ELF type.
 * @e_entry: The ELF entry.
 * @e_id: A pointer to an array containing the ELF class.
 *
 * Return: Nothing
 */

void _printTypeEntry(uint e_t, unsigned long int e_entry, unsigned char *e_id)
{
	if (e_id[EI_DATA] == ELFDATA2MSB)
		e_t >>= 8;
	printf("  Type:                              ");
	switch (e_t)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_t);
	}
	printf("  Entry point address:               ");
	if (e_id[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (uint)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, s, i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	s = read(fd, header, sizeof(Elf64_Ehdr));
	if (s == -1)
	{
		free(header);
		close(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	for (i = 0; i < 4; i++)
	{
		if (e_id[i] != 127 && e_id[i] != 'E' && e_id[i] != 'L' && e_id[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
	printf("ELF Header:\n");
	_printMagicClass(header->e_id);
	_printDataVersion(header->e_id);
	_printOSABI(header->e_id);
	_printTypeEntry(header->e_t, header->e_entry, header->e_id);
	free(header);
	close(fd);
	return (0);
}

