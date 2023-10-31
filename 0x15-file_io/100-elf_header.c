#include "main.h"

/**
 * print_elf_header_info - Print information from the ELF header.
 * @ehdr: Pointer to the ELF header structure.
 */
void print_elf_header_info(Elf64_Ehdr *ehdr)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", ehdr->e_ident[i]);
	}
	printf("\nClass:  %d-bit\n", ehdr->e_ident[EI_CLASS] == ELFCLASS64 ? 64 : 32);
	printf("Data: %s-endian\n", ehdr->e_ident[EI_DATA] ==
		ELFDATA2MSB ? "big" : "little");
	printf("Version: %d (current)\n", ehdr->e_ident[EI_VERSION]);
	printf("OS/ABI:  %d\n", ehdr->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", ehdr->e_ident[EI_ABIVERSION]);
	printf("Type:    %d\n", ehdr->e_type);
	printf("Entry point address: 0x%lx\n", (unsigned long)ehdr->e_entry);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr ehdr; /* ELF header structure */

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(98);
	}
	/* Read the ELF header */
	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
	{
		perror("Error");
		close(fd);
		exit(98);
	}
	/* Verify that it's an ELF file */
	if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}
	/* Print information from the ELF header */
	print_elf_header_info(&ehdr);

	close(fd);
	return (0);
}


