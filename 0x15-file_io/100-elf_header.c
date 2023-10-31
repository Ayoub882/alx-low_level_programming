#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include "main.h"

/**
 * checkElfMagic - Checks if the file has a valid ELF magic number.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, it exits with code 98.
 */
void checkElfMagic(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != ELFMAG[index])
		{
			fprintf(stderr, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printElfMagic - Prints the ELF magic numbers.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void printElfMagic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * printElfClass - Prints the class of the ELF file.
 * @e_ident: A pointer to an array containing the ELF class.
 *
 * Description: The class can be ELF32, ELF64, or none.
 */
void printElfClass(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * printElfData - Prints the data encoding of the ELF file.
 * @e_ident: A pointer to an array containing the data encoding.
 *
 * Description: It can be 2's complement, little endian, big endian, or none.
 */
void printElfData(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
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
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * printElfVersion - Prints the ELF version.
 * @e_ident: A pointer to an array containing the ELF version.
 *
 * Description: It can be invalid or current.
 */
void printElfVersion(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf(" (invalid)\n");
			break;
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * printElfOsAbi - Prints the Operating System/ABI of the ELF file.
 * @e_ident: A pointer to an array containing the OS/ABI.
 *
 * Description: It can be various UNIX systems, ARM, or a standalone app.
 */
void printElfOsAbi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
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
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
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
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printElfType - Prints the type of the ELF file.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 *
 * Description: It can be None, Relocatable, Executable, Shared, or Core.
 */
void printElfType(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type = ((e_type << 8) & 0xFF00FF00) | ((e_type >> 8) & 0xFF00FF);
	printf("  Type:                              ");
	switch (e_type)
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
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * printElfEntryPoint - Prints the entry point of the ELF file.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 *
 * Description: Prints the entry point address in hexadecimal format.
 */
void printElfEntryPoint(Elf64_Addr e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * closeFile - Closes the file descriptor.
 * @fileDescriptor: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed, it exits with code 98.
 */
void closeFile(int fileDescriptor)
{
	if (close(fileDescriptor) == -1)
	{
		fprintf(stderr, "Error: Can't close file descriptor %d\n", fileDescriptor);
		exit(98);
	}
}

/**
 * main - Displays information about the ELF header of a given ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Description: If the file is not an ELF File or
 * the function fails, it exits with code 98.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
		exit(1);
	}

	int fileDescriptor, bytesRead;
	Elf64_Ehdr *header;

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeFile(fileDescriptor);
		fprintf(stderr, "Error: Can't allocate memory for header\n");
		exit(98);
	}

	bytesRead = read(fileDescriptor, header, sizeof(Elf64_Ehdr));
	if (bytesRead == -1)
	{
		free(header);
		closeFile(fileDescriptor);
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	checkElfMagic(header->e_ident);
	printf("ELF Header:\n");
	printElfMagic(header->e_ident);
	printElfClass(header->e_ident);
	printElfData(header->e_ident);
	printElfVersion(header->e_ident);
	printElfOsAbi(header->e_ident);
	printElfType(header->e_type, header->e_ident);
	printElfEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeFile(fileDescriptor);

	return (0);
}

