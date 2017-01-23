#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IDENT 16
#define MAX 4096

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
}*hdr;

struct p_hdr{
	unsigned int p_type;
	unsigned int p_offset;
	unsigned int p_vaddr;
	unsigned int p_paddr;
	unsigned int p_filesz;
	unsigned int p_memsz;
	unsigned int p_flags;
	unsigned int p_align;
}*phdr;

int main (int argc, char* argv[])
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	short int i;
//	char buf[MAX];
	char *c = (char*) malloc(MAX);

	 hdr = (struct Ehdr*) malloc (sizeof(struct Ehdr));	

	if (argc < 3){
		printf ("No files are passed \n");
	}

	if (NULL == (fp1 = fopen (argv[1], "rb"))) {                              
           perror ("file opening failed");                                     
           exit (1);                                                           
	}         
	if (NULL == (fp2 = fopen (argv[2], "wb"))) {                              
           perror ("file opening failed");                                     
           exit (1);                                                           
	}        

	 phdr = (struct p_hdr*) malloc (sizeof(struct p_hdr)); 

	if ((hdr -> e_phnum)  == 0) {                                               
        printf("There are no program headers in this file\n");                  
        return;                                                                 
    }      

	fseek(fp1, (hdr -> e_phoff) + (hdr -> e_phentsize) * 2, SEEK_SET); 

	memcpy(c, phdr -> p_vaddr, MAX);

	fwrite(c, MAX, 1, fp2);	

	return 0;
}

