#include <stdio.h>
#pragma pack(1) 

extern void showbits (int);

int head_struct(void)			
{

	struct {							 //header-1 in Assignment-5 
		unsigned int GFC : 4;
		unsigned int vpi : 8;		
		unsigned int VCI : 16;
		unsigned int     : 1;
		unsigned int PTI : 1;
		unsigned int     : 1;
		unsigned int CLP : 1;

		unsigned char HEC;
		
	}struct1;

	struct{								 //header-2 in Assignment-5 
		unsigned int sourceport : 16;
		unsigned int destinationport : 16;
		unsigned int sequencenumber;
		unsigned int acknowledgementnumber;
		unsigned int headerlength : 4;
		unsigned int reserved : 6;
		unsigned int codebits : 6;
		unsigned int window : 16;
		unsigned int checksum : 16;
		unsigned int urgent : 16;
		unsigned int options;
		unsigned int data;
	}struct2;

	struct {						 //header-3 in Assignment-5 
		unsigned int version : 4;
		unsigned int headerlength : 4;
		unsigned int servicetype : 8;
		unsigned int totallength : 16;
		unsigned int identification : 16;
		unsigned int flags : 4;
		unsigned int fragmentationoffset : 12;
		unsigned int ttl : 8;
		unsigned int protocol : 8;
		unsigned int headerchecksum : 16;
		unsigned int sourceIPaddress;
		unsigned int destinationIPaddress;
		unsigned int options : 24;
		unsigned int padding : 8;
	}struct3;

	printf ("size of the struct1 structure is : %d \n", sizeof(struct1));
	printf ("size of the struct2 structure is : %d \n", sizeof(struct2));
	printf ("size of the struct3 structure is : %d \n", sizeof(struct3));

	return 0;
}


int union_assign(void)
{
	union sample{
		int a:5;
		int b:10;
		int c:5;
		int d:21;
		int e;
	};

	union sample sam;

	printf ("size = %d \n", sizeof(sam));
	printf ("address of members : %p \n", &sam.e);

	printf ("enter the value of e : \n");	//assigning the value
	scanf ("%d", &sam.e);
	showbits (sam.e);
											//printing values of members
	printf ("value at a : %d \n",sam.a);
	printf ("value at b : %d \n",sam.b);
	printf ("value at c : %d \n",sam.c);
	printf ("value at d : %d \n",sam.d);
	printf ("value at e : %d \n",sam.e);

	return 0;
}
//experiment 3 : to find endianness of a machine

void endian(void)
{
	union{
		int x;
		char c[2];
	}var;

	var.x = 1;			//intializing the value

	if (var.c[0] == 1)		// used for diagnostic purpose
		printf ("Little Endian \n");
	else
		printf ("Big Endian \n");
}

int main (void)
{
	int option;

	printf ("1.creting the structures for headers & finding sizes \n");
	printf ("2.assigning a value for one variable and printing the values \n");
	printf ("3.to check little endian (or) big endian \n");

	do{		//repeating the loop untill the user want to come out of execution

		printf ("\nenter the option to select the program & 0 for exit: \n");
		scanf ("%d", &option);

		switch(option){		//to select the program

		case 0 : 			//to come out of the program
				break;
		case 1 :
				head_struct();//to create hearders and to calculate their sizes 
				break;
		case 2 : 
				union_assign();//assigning a value to 1 member and printing other members values
				break;
		case 3 :
				endian();//to find endianess of machine
				break;
		default :
				printf ("enter the correct option \n");
				break;
		}

	}while(option != 0);

	return 0;
}
