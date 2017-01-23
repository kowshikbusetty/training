# include "../header/readelf.h"

/*
 *elf header function
 */

void elf_func (char * argv)
{
	FILE *fp = NULL; 
	short int i;

	struct Ehdr * hdr = (struct Ehdr*) malloc (sizeof (struct Ehdr)); 

	if (NULL == (fp = fopen (argv, "r"))) {                              
           perror ("file opening failed");                                     
           exit (1);                                                           
	}                                                                       
    if (0 == fread (hdr, sizeof (struct Ehdr), 1, fp)) {                  
         perror ("Error: test: Failed to read file's magic number");         
         exit (1);                                                           
    }  

	if(hdr -> e_ident[0] != 0x7f) {
		printf("Error: Not an ELF file - "
							"it has the wrong magic bytes at the start\n");
		exit(0);
	}

	printf("Magic:\t ");
	for (i = 0; i < IDENT; i++) {
		printf ("%.2x  ", hdr -> e_ident[i]);
	}
	
	printf ("\nClass:\t\t");

	switch(hdr -> e_ident[4]){
		case 0 :
			printf ("\t\t\t Invalid class");
				break;
		case 1 :
			printf ("\t\t\t ELF32 OBJECTS");
				break;
		case 2 :
			printf ("\t\t\t ELF64 OBJECTS");
				break;
	}

	printf ("\nData:\t\t\t");

	switch(hdr -> e_ident[5]){
		case 0 :
				printf ("\t\t Invalid class");
				break;
		case 1 :
				printf ("\t\t 2's compliment , little endian");
				break;
		case 2 :
				printf ("\t\t 2's compliment , big endian");
				break;
	}

	printf ("\nVersion:\t\t\t");

	(hdr -> e_ident[6]) ? printf ("\t 1 (current)") : 
										printf ("\t 0 (invalid)");

	printf ("\nOS/ABI:\t\t\t\t\t ");

	switch (hdr -> e_ident[7]){
		case 0 : 
				printf("same os ELFOSABI_SYSV");
				break;
		case 1 : 
				printf("UNIX Systme V ABI");
				break;
		case 2 : 
				printf("HP-UX ABI");
				break;
		case 3 : 
				printf("NetBSD ABI");
				break;
		case 4 : 
				printf("Linux ABI");
				break;
		case 5 : 
				printf("solaris ABI");
				break;
		case 6 : 
				printf("IRTX ABI");
				break;
		case 7 : 
				printf("FreeBSD ABI");
				break;
		case 8 : 
				printf("TRU64 UNIX ABI");
				break;
		case 9 : 
				printf("ARM architecture");
				break;
		case 10 : 
				printf("Stand-alone (embedded) ABI");
				break;
	}	

	printf ("\nABI Version: \t\t\t\t 0");

	printf ("\nType: \t\t\t\t\t ");

	switch(hdr -> e_type){
		case 0 : 
				printf ("No file type");
				break;
		case 1 : 
				printf ("Relocatable file");
				break;
		case 2 : 
				printf ("Executable file");
				break;
		case 3 : 
				printf ("Shared hdr file");
				break;
		case 4 : 
				printf ("Core file");
				break;
			
		case 0x00ff : 
				printf ("Processor-specific");
				break;
		case 0xffff : 
				printf ("Processor-specific");
				break;
	}

	printf("\nMachine:  \t\t\t\t ");
	switch(hdr -> e_machine) {

		case 0 : printf("No Machine\n");
				 break;
		case 1 : printf("AT&T WE 32100\n");
				 break;
		case 2 : printf("SPARC\n");
				 break;
		case 3 : printf("Intel 80386\n");
				 break;
		case 4 : printf("Motorola 68000\n");
				 break;
		case 5 : printf("Motorola 88000\n");
				 break;
		case 7 : printf("Intel 80860\n");
				 break;
		case 8 : printf("MIPS RS3000 Big-Endian\n");
				 break;
		case 10 : printf("MIPS RS4000 Big-Endian\n");
				  break;
	}

	printf("Version: \t\t\t\t 0x%x\n", (hdr -> e_version) ? 
											1 : printf("Invaid version\n"));

	printf("Entry Point Address:\t\t\t 0x%x\n", hdr -> e_entry);

	printf("Start of program headers:\t\t %x\n", hdr -> e_phoff);

	printf("Start of section headers:\t\t %d\n", hdr -> e_shoff);

	printf("Flags:\t\t\t\t\t 0x%x\n", hdr -> e_flags);

	printf("Size of this header:\t\t\t %d\n", hdr -> e_ehsize);

	printf("Size of program header:\t\t\t %x\n", hdr -> e_phentsize);

	printf("Number of program headers:\t\t %x\n", hdr -> e_phnum);

	printf("Size of section headers:\t\t %d\n", hdr -> e_shentsize);

	printf("Number of section headers:\t\t %d\n", hdr -> e_shnum);

	printf("Section header string table index:\t %d\n", hdr -> e_shstrndx);
	
	fclose(fp);
	return;
}

/*
 *Section header implementation
 */

void sec_hdr_fun(char * argv)
{
	char *buff;
	int i;

	struct Ehdr *hdr = (struct Ehdr *) malloc (sizeof (struct Ehdr));
	struct sec_hdr *shdr = (struct sec_hdr *) malloc (sizeof (struct sec_hdr));

	FILE *fp, *strfp;

	if(NULL == (fp = fopen(argv, "rb"))) {
		perror("fopen failed\n");
		exit(1);
	}

	if(NULL == (strfp = fopen(argv, "rb"))) {
		perror("fopen failed\n");
		exit(1);
	}

	if(0 == (fread(hdr, sizeof(struct Ehdr), 1, fp))) {
		perror("fread failed\n");
		exit(1);
	}

	fseek(fp, hdr -> e_shoff, SEEK_SET);

	fseek(strfp, (hdr -> e_shoff) + (hdr -> e_shentsize) * (hdr -> e_shstrndx), SEEK_SET);
	fread(shdr, sizeof (struct sec_hdr), 1, strfp);

	if(NULL == (buff = (char *) malloc (shdr -> sh_size))){
			printf ("malloc for buffer failed.....\n");
			exit(1);
	}
	
	fseek(strfp, shdr -> sh_offset, SEEK_SET);
	fread(buff, shdr -> sh_size, 1, strfp);

	printf("\nSection Header:\n\n[Nr]  Name\t\tType\t\t  Addr\t");
	printf ("    Off\t   Size\t  ES\tFlag\tLk\tInf\tAl\n");

	for( i = 0; i < hdr -> e_shnum; i++) {

		fread(shdr, sizeof(struct sec_hdr), 1, fp); 

		printf("[%2d] ", i);
		printf(" %-14s", (buff + shdr -> sh_name));

		switch( shdr -> sh_type ) {

			case 0 :printf("\tNULL\t"); 
					break;
			case 1 :printf("\tPROGBITS");
					break;
			case 2 :
					printf("\tSYSTAB\t");
					break;
			case 3 :
					printf("\tSTRTAB\t");
					break;
			case 4 :
					printf("\tRELA\t");
					break;
			case 5 :	
					printf("\tHASH\t");
					break;
			case 6 :
					printf("\tDYNAMIC");
					break;
			case 7 :
					printf("\tNOTE\t");
					break;
			case 8 :
					printf("\tNOBITS\t");
					break;
			case 9 :
					printf("\tREL\t");
					break;
			case 10 :
					printf("\tSHLIB");
					break;
			case 11 :
					printf("\tDYNSYS");
					break;
			case 0x70000000 :
					printf("\tLOPROC");
					break;
			case 0x7fffffff :
					printf("\tHIPROC");
					break;
			case 0x80000000 :
					printf("\tLOUSER");
					break;
			case 0xffffffff :
					printf("\tHIUSER");
					break;
			default :
					break;
		}

		printf("\t%08x  ", shdr -> sh_addr);
		printf("%06x",shdr -> sh_offset);
		printf("  %06x",shdr -> sh_size); 
		printf("  %02d\t",shdr -> sh_entsize); 
		switch(shdr -> sh_flags) {
			case 0x1 : printf ("W\t");
					   break;

			case 0x2 : printf ("A\t");
					   break;

			case 0x4 : printf ("X\t");
					   break;
			
			default : printf ("\t");
		}
		printf("%2d\t",shdr -> sh_link); 
		printf("%2d\t", shdr -> sh_info); 
		printf("%2d\n", shdr -> sh_addralign);  
	}
}



