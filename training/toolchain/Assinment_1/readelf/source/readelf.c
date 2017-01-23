# include "../header/readelf.h"

int main (int argc, char* argv[])
{
	short int i;

	if (argc < 2){
		printf ("No files are passed \n");
	}

	for (i = 1; i < argc; i++) {
		printf ("FILE: \t %s\n", argv[i]);
		elf_func (argv[i]);
		sec_hdr_fun(argv[i]);
		program_header(argv[i]);
	}	

	return 0;
}
