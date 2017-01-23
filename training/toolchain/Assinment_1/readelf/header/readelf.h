# ifndef _ELF_H
# define _ELF_H

# include <stdio.h>
# include <stdlib.h>
# define IDENT 16
struct Ehdr {
	unsigned char e_ident[IDENT];
	unsigned short int e_type;
	unsigned short int e_machine;
	unsigned int e_version;
	unsigned int e_entry;
	unsigned int e_phoff;
	unsigned int e_shoff;
	unsigned int e_flags; 
	unsigned short int e_ehsize;
	unsigned short int e_phentsize;
	unsigned short int e_phnum;
	unsigned short int e_shentsize;
	unsigned short int e_shnum;
	unsigned short int e_shstrndx;
};
void elf_func(char *); 

struct sec_hdr{
	unsigned int sh_name;
	unsigned int sh_type;
	unsigned int sh_flags;
	unsigned int sh_addr;
	unsigned int sh_offset;
	unsigned int sh_size;
	unsigned int sh_link;
	unsigned int sh_info;
	unsigned int sh_addralign;
	unsigned int sh_entsize;
};

void sec_hdr_fun(char *);

struct program_header {
    unsigned int p_type;
    unsigned int p_offset;
    unsigned int p_vaddr;
    unsigned int p_paddr;
    unsigned int p_filesz;
    unsigned int p_memsz;
    unsigned int p_flags;
    unsigned int p_align;
}*phdr;

void print_program_header(char *);

#endif
