# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <../Header/elf_header.h>

void print_program_header(char *file)
{
	int i;
	FILE *fp;
	FILE *f1, *f2;
	char *c = (char *) malloc (4096);
	f1 = fopen("abc.txt", "w");
	f2 = fopen("pqr.txt", "w");
	if(NULL == (fp = fopen(file, "rb"))) {
		perror("fopen failed\n");
		exit(1);
	}

	if ((hdr -> e_phnum)  == 0) {
		printf("There are no program headers in this file\n");
		return;
	}

	phdr = (struct program_header*) malloc (sizeof(struct program_header));

	fseek(fp, hdr -> e_phoff, SEEK_SET);

	printf("program header offset%x\n", hdr -> e_phoff);
	printf("\nProgram Headers\n");
	printf("Type\t\tOffset\t\tVirtAddr\t\tPhysAddr\t\tFileSiz\t\tMemSiz\t\ttAlign\n");
	for(i = 0; i < hdr -> e_phnum; i++) {

		fread(phdr, sizeof (struct program_header), 1, fp);
		//		printf("%d\t", phdr -> p_type);
		switch(phdr -> p_type) {
			case 0 : printf("NULL");
					 break;
			case 1 : printf("LOAD");
					 if((phdr -> p_vaddr % 4096) == 0) {
						 memcpy(c, phdr -> p_vaddr, 4096);
							 fprintf(f1, c);
					 } else {
						memcpy(c, (phdr -> p_vaddr - (phdr -> p_vaddr % 4096)), 4096);
						fprintf(f2, c);
					 }
					 break;
			case 2 : printf("DYNAMIC");
					 break;
			case 3 : printf("INTERP");
					 break;
			case 4 : printf("NOTE");
					 break;
			case 5 : printf("SHLIB");
					 break;
			case 6 : printf("PHDR");
					 break;
			case 0x70000000 : printf("LOPROC");
							  break;
			case 0x7fffffff : printf("HIPROC");
							  break;
			default : 
							  break;
		}
		printf("\t\t");
		printf("%6x\t\t",phdr -> p_offset);
		printf("%8x\t\t", phdr -> p_vaddr);
		printf("%8x\t\t", phdr -> p_paddr);
		printf("%5x\t\t", phdr -> p_filesz);
		printf("%5x\t\t", phdr -> p_memsz);
		printf("%4x\n", phdr -> p_align);
	}
}
