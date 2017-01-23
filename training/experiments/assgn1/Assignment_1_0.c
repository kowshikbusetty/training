//Assignment 1: Bit wise operators

#include <stdio.h>

extern void showbits (int);

int bit_swap (int, int, int);

void bit_copy (int, int, int, int, int);

int even_bit_toggle (int);
int odd_bit_toggle (int);

void count_bit_set (int);                                                       
void count_bit_clear (int);

#define bit_ts(num, pos) \
((num >> pos) & 1u) ? printf ("bit is already set \n") : (num |= (1u << pos));		 
					
int right_rotate_bits (int);
int left_rotate_bits (int);
int right_rotate_n_bits (int, int);
int left_rotate_n_bits (int, int);

int cnt_leading_cleared_bits (int);                                             
int cnt_leading_set_bits (int);                                                 
int cnt_trailing_cleared_bits (int);                                            
int cnt_trailing_set_bits (int);  

#define great for(i = 0; i < (sizeof(int) * 8); i++){\
					if(a >> i & 1){\
						l = i;\
						c1++;\
					}\
					if(b >> i & 1){\
						m = i;\
						c2++;\
					}\
				}                                                                               
                                                                                
#define clear_rightmost_set_bit if ( num != 0){\
								for (i = 0; i <= (sizeof(int) * 8 - 2); i++){\
										if (((num >> i) & 1u) == 0)\
											continue;\
										else\
											num ^= (1u << i);\
											break;\
								}\
								}                                               
                                                                                
                                                                                
#define clear_leftmost_set_bit if (num != 0){\
								  for (i = (sizeof(int) * 8 -2); i >= 0; i--){\
										if (((num >> i) & 1u) == 0)\
											continue;\
										else\
											num ^= 1u << i;\
											break;\
									}\
								}
                                                     
#define set_rightmost_cleared_bit for (i = 0; i <= (sizeof(int) * 8 - 1); i++){\
										if (((num >> i) & 1u) != 0)\
											continue;\
										else\
											num ^= 1u << i;\
											break;\
								   }                                         


#define set_leftmost_cleared_bit for (i = (sizeof(int) * 8 -2); i >= 0; i--){\
									if (((num >> i) & 1u) != 0)\
											continue;\
										else\
											num ^= 1u << i;\
											break;\
								}                                               
                                                                                
#define setbits_s_d for (i = (sizeof(int) * 8 -2); i > s; i--)\
						num &= (~(1u << i));\
					for (i = s; i >= d; i--)\
						num |= (1u << i);\
					for (i = d-1; i >= 0; i--)\
						num &= (~(1u << i));                                    
                                                                                
#define clearbits_s_d for (i = (sizeof(int) * 8 -2); i > s; i--)\
						num |= (1u << i);\
					  for (i = s; i >= d; i--)\
						num &= (~(1u << i));\
					  for (i = d-1; i >= 0; i--)\
						num |= (1u << i);                                       
                                                                                
#define togglebits_s_d  for (; s >= d; s--)\
							num ^= (1u << s);                                   
                                                

void setbits_copy (int, int, int, int);                                  

int invert (int x, int p, int n);                                                

#define getbits(x,p,n) for (i= p + n - 1; i >= p; i--)\
							printf ("%d", (x >> i) & 1);\
							printf("\n");                                       
                                        

unsigned int temp;
int num;
int s;
int d;
int n;	
int i;
int j;
int l;
int m;
int a;
int b;
int c;
int c1 = 0;                                                                 
int c2 = 0;  
int snum;
int dnum;
int pos;
int op;
int x;
int y;                                                                      
int p;                                                                      

#if 1

int main (void)
{
	int choice;

	printf ("enter the choice that what function you need to execute : \n ");

	printf ("1.swaping 2b in same num  2.swaping 2b in 2no \n");
    printf (" 3.bit copy 4.toggle 5.position set 6.right rotate one time\n");
    printf ("left rotate one time , lef & right for n times\n");
	printf ("7. count the number of bits set and number of bits cleared \n");
	printf ("8. count leading 0's & 1's, tailing 0's & 1's \n ");
	printf ("9.macros for the basic operations on bitwise operators \n");
	printf ("10.function setbits (x,p,n,y) \n");
	printf ("11. function invert (x,p,n) \n");
	printf ("12. macro getbits (x,p,n) \n");

	scanf ("%d", &choice);
	printf ("\n");
	switch (choice){	//select which program has to execute

	case 1 : /*experiment 1 : Given 2 bit positions d and s in a number n,
										 swap the bit values between s and d.*/
		
			printf ("enter the number : \t");
			scanf ("%d", &n);

			printf ("I am considering source position from lsb... \n");
			printf ("enter source and destination positions : \t");
			scanf ("%d%d", &s, &d);

			printf ("bits before swapping : \t");

			showbits (n);	           	 // displays binary form of a decimal 

			m = bit_swap (n, s, d);
	
			printf ("after swaping the number is : %d \n", m);
			printf ("bits after swappting : \t");

			showbits (m);				 // displays binary form of a decimal  

			break;


	case 2 :	

			/*experiment 2 : swap bit values between 2 numbers 
													for given positions*/
			printf ("I am considering source position from msb \n");


			printf ("enter snum : \n");
			scanf ("%d", &snum);

			showbits (snum);			// displays binary form of a decimal

			printf ("enter dnum : \n");
			scanf ("%d", &dnum);

			showbits (dnum); 			 // displays binary form of a decimal

			printf (" enter s position & d position : \n");
			scanf ("%d%d", &s, &d);

			if(((snum >> s) & 1u) != ((dnum >> d) & 1u)){	
				snum ^= 1u << s;
				dnum ^= 1u << d;	
			}

			printf ("after swapping the bit,the snum is : \t");
			
			showbits (snum);			 // displays binary form of a decimal

			printf ("after swapping the bit,the dnum is : \t");

			showbits (dnum);			 // displays binary form of a decimal

			break;


	case 3 :
			//experiment 3 : implementation of bit_copy function
			printf ("I am considering source position from msb \n");

			printf ("enter snum : \n");
			scanf ("%d", &snum);

			showbits (snum);			 // displays binary form of a decimal
			
			printf ("enter dnum : \n");
			scanf ("%d", &dnum);

			showbits (dnum);			 // displays binary form of a decimal
				
			printf (" enter s position & d position : \n");
			scanf ("%d%d", &s, &d);
			
			printf ("enter no. of bits to copy: \n ");
			scanf ("%d", &n);
				
			bit_copy (snum, dnum, n, s, d);
			
			break;


	case 4 :
			//experiment 4 : even and odd bit toggle functions implementations
			printf ("I am considering source position from msb \n");

			printf ("enter the number: \n");
			scanf ("%d", &num);
			showbits (num);				// displays binary form of a decimal
			
			printf (" Enter the option 1)even bit toggle \n"
											"2) odd bit toggle : \t");
			scanf ("%d", &op);

			switch (op){	//to select whether even or odd bit to toggle
		 
			case 1 : num = even_bit_toggle (num);
					 showbits(num);		 // displays binary form of a decimal
					 break;	

			case 2 : num = odd_bit_toggle (num);
					 showbits(num);	 	 // displays binary form of a decimal
					 break;

			default : printf ("enter correct option.. \n");

			}	

			break;


	case 5 :
			/*experiment 5 : To check whether a particular position 
													in a num is set or not*/
			printf ("I am considering source position from msb \n");

			printf ("enter the number : \n");
			scanf ("%d", &num);
			
			printf ("enter the position : \n");
			scanf ("%d", &pos);

			showbits (num);				 // displays binary form of a decimal

			bit_ts(num, pos) 

			showbits (num);				 // displays binary form of a decimal

			break;


	case 6 :			
			/*experiment 6 : implementing functionsfor right rotate,
			 left rotate,left rotate for n bits and right rotate for n bits */
			printf ("I am considering source position from msb \n");
			
			printf ("enter number= \t");
			scanf ("%d", &num);

			printf ("before shifting: \n");
			showbits (num);               // displays binary form of a decimal 

			printf ("enter option: \n");
			printf ("1)left rotate, 2)right rotate, \n");
			printf ("3)left rotate with n bits, \n"
										 "4)right rotate with n bits \n");
			scanf ("%d", &op);

			switch (op){	//to select type of rotation

			case 1:
					num = left_rotate_bits (( unsigned ) num);

					printf ("number after left rotate: %d \n",num);
					showbits (num);       // displays binary form of a decimal 
					break;
			case 2:
					num = right_rotate_bits (( unsigned ) num);  

					printf ("number after right rotate: %d \n",num);
					showbits (num);      // displays binary form of a decimal 		
					break;

			case 3:
					printf ("enter no. of shifts= \t");
					scanf ("%d", &n);

					num = left_rotate_n_bits (( unsigned ) num, n);

					printf ("number left rotate: %d \n",num);
					showbits (num);      // displays binary form of a decimal 
					break;
			case 4:
					printf ("enter no. of shifts= \t");
					scanf ("%d", &n);
					
					num = right_rotate_n_bits (( unsigned ) num, n);  

					printf ("number after right rotate: %d \n",num);
					showbits (num);       // displays binary form of a decimal 		
					break;

			default: 
					printf ("enter correct option... \n ");

		
			}
		break;


	case 7 :/*experiment 7 : functions which will count the number of bits set
			 and number of bits cleared in the given number num respectively*/
			 printf ("I am considering source position from msb \n");
			
			 printf("enter the number: \n");                                             
			 scanf("%d", &n);                                                            
																						
			 showbits (n);                // displays binary form of a decimal    
																						
			 count_bit_set (n);                                                          
			 count_bit_clear (n);                                                        
			 break;					 


	case 8 :/*experiment 8 : functions which counts the no. of leading 0's, 
			leading 1's, tailing 0's, tailing 1's */ 
			
			 printf ("enter the number:");                                               
			 scanf ("%d", &num);                                                         
			 showbits (num);              // displays binary form of a decimal     

			 b = cnt_leading_set_bits (num);                                             
			 printf ("no. of leading ones is: %d \n",b);                                 
																						
			 b = cnt_leading_cleared_bits (num);                                         
			 printf ("no. of leading zeros is: %d \n",b);                                
																						
			 b = cnt_trailing_cleared_bits (num);                                        
			 printf ("no. of tailing zeros is: %d \n",b);                                
																						
			 b = cnt_trailing_set_bits (num);                                            
			 printf ("no. of tailing ones is: %d \n",b); 																		 

			 break;


	case 9 : /*experiment 9 : macros for some basic operations on 
													bitwise operators*/
			 printf ("I am considering source position from msb \n");

			 printf ("\n");
			 printf ("enter the option : \n");                                           
			 printf ("1.To find MAX and MIN \n");                                        
			 printf ("2.To clear right most set bit in a number \n");                    
			 printf ("3.To clear left most set bit in a number \n");                     
			 printf ("4.To set right most cleared bit in a number \n");                  
			 printf ("5.To set left most cleared bit in a number \n");                   
			 printf ("6.set bits from bit ‘s’ to bit ‘d’ \n");         
			 printf ("7.clear bits from bit ‘s’ to bit ‘d, \n");       
			 printf ("8.toggle bits from bit ‘s’ to bit ‘d’ \n");      
																						
			 scanf ("%d", &op);    

    		 switch (op){	//To do the which basic operation in 9th program                                                                 
																							
				case 1 :                                                                    
						printf ("enter the no.s... \n");                                     
						scanf ("%d %d", &a, &b);                                            
																							
						great                                                               
																							
						if(l == m)                                                          
							if(c1 > c2)                                                     
								printf ("%d is max, %d is min \n", a, b);           
							else                                                            
								printf ("%d is max, %d is min \n", b, a);           
																							
						else if(l > m)                                                      
								printf ("%d is max, %d is min \n", a, b);           
							else                                                            
								printf ("%d is max, %d is min \n", b, a);           
						break;                                                              
																							
				case 2 : printf ("Enter the num : \t");                                     
						 scanf ("%d", &num);                                                
						 showbits(num);                                                     
																							
						 clear_rightmost_set_bit                                            
																							
						 showbits(num);  // displays binary form of a decimal                                                      
																							
						 break;            
			    
				case 3 : printf ("Enter the num : \t");                                     
						 scanf ("%d", &num);                                                
						 showbits(num);                                                     
																							
						 clear_leftmost_set_bit                                             
																							
						 showbits(num);   // displays binary form of a decimal                                                    
																							
						 break;                                                             
																							
				case 4 : printf ("Enter the num : \t");                                     
						 scanf ("%d", &num);                                                
						 showbits(num);                                                     
																							
						 set_rightmost_cleared_bit                                          
																							
						 showbits(num);  // displays binary form of a decimal                                                     
																							
						 break;                                                             
																							
				case 5 : printf ("Enter the num : \t");                                     
						 scanf ("%d", &num);                                                
						 showbits(num);                                                     
																							
						 set_leftmost_cleared_bit                                           
																							
						 showbits(num);  // displays binary form of a decimal                                                     
																							
						 break;                  

			    case 6 : printf ("Enter the num : \t");                                     
						 scanf ("%d", &num);                                                
						 showbits(num);   // displays binary form of a decimal                                                    
																							
						 printf ("considering source position from msb \n");
						 
						 printf ("enter the position s : \t");                              
						 scanf ("%d", &s);                                                  
																							
						 printf ("enter the position d : \t");                              
						 scanf ("%d", &d);                                                  
																							
						 setbits_s_d                                                       
																							
						 showbits(num);   // displays binary form of a decimal                                                     
																							
						 break;                                                             
																							
				case 7 : printf ("Enter the num : \t");                                     
						 scanf ("%d", &num);                                                
						 showbits(num);   // displays binary form of a decimal                                                     
																							
						 printf ("considering source position from msb \n");
						
						 printf ("enter the position s : \t");                              
						 scanf ("%d", &s);                                                  
																							
						 printf ("enter the position d : \t");                              
						 scanf ("%d", &d);                                                  
																							
						 clearbits_s_d                                                      
																							
						 showbits(num);  // displays binary form of a decimal                                                    
																							
						 break;                       

				 case 8 : printf ("Enter the num : \t");                                     
						 scanf ("%d", &num);                                                
						 showbits(num);   // displays binary form of a decimal   
                                                   
						 printf ("considering source position from msb \n");
						 printf ("enter the position s : \t");                              
						 scanf ("%d", &s);                                                  
																							
						 printf ("enter the position d : \t");                              
						 scanf ("%d", &d);                                                  
																							
						 togglebits_s_d                                                     
																							
						 showbits(num);  // displays binary form of a decimal                                                    
																							
						 break;                                                             
																							
		   		 default : printf ("enter correct option \n");                               

				 }         

				break;																							

	case 10 : /*experiment 10 : a function setbits (x,p,n,y) that returns x 
				with the ‘n’ bits that begin at position p set to the
				right most n bits of y, leaving the other bits unchanged.*/

			  printf ("enter x value : \t");                                              
			  scanf ("%d", &x);                                                            
																						
			  showbits (x);               // displays binary form of a decimal      
																						
			  printf ("enter y value : \t");                                              
			  scanf ("%d", &y);                                                            
																						
			  showbits (y);               // displays binary form of a decimal      
																						
			  printf (" enter  position : \n");                                           
			  scanf ("%d", &p);                                                           
																						
			  printf ("enter no. of bits to copy: \n ");                                  
			  scanf ("%d", &n);                                                           
																						
			  setbits_copy (x, p, n, y);                                                  
			
			  break;                                

	case 11 : /*experiment 11 : function invert (x,p,n) that returns x 
				with n bits that begin at position p inverted, leaving
				others unchanged.*/

			  printf ("enter the number: \t");                                            
			  scanf ("%d", &x);                                                           
																						
			  showbits (x);               // displays binary form of a decimal         
																						
			  printf ("considering source position from msb \n");
		      printf ("enter source position: \t");                                       
			  scanf ("%d", &p);                                                           
			  printf ("enter no. of bits : \t");                                          
			  scanf ("%d", &n);                                                           
																						
			  x = invert (x, p, n);                                                       
																						
			  showbits (x);               // displays binary form of a decimal         
			  
			  break;                    


	case 12 : /* experiment 12 : a macro getbits (x,p,n) that retuns 
				(left adjusted) n-bit field of x that begins at position p*/

			  printf ("enter the number: \t");                                            
			  scanf ("%d", &x);                                                           
																						
			  showbits (x);              // displays binary form of a decimal         
																						
			  printf ("enter source position: \t");                                       
			  scanf ("%d", &p);                                                           
			  printf ("enter no. of bits : \t");                                          
			  scanf ("%d", &n);                                                           
																						
			  getbits(x, p, n)      

			  break;

	default : printf ("enter correct optionto select program \n");
	
	}
	return 0;
}
#endif


int bit_swap (int n, int s, int d)
{	
	if (((n >> d) & 1u) != ((n >> s) & 1u)){
		n ^= 1u << s;
		n ^= 1u << d;
	}
	
	return n;
}

void bit_copy (int snum, int dnum, int n, int s, int d)
{
	for (i = s, j = d; i >= s-n+1; i--,j--){
		if ((snum >> i & 1u) != (dnum >> j & 1u)){
			dnum ^= 1u << j;
		}
	}

	printf ("after copying the bits dnum is : %d \n", dnum);	
	showbits (dnum); 					 // displays binary form of a decimal
}

int even_bit_toggle (int num)
{
	int key = 1u;
	while(key){
		num ^= key;
		key <<= 2;
	}
    return num;
}

int odd_bit_toggle (int num)
{
	int key = 2u;

	while(key){
		num ^= key;
		key <<= 2;
	}

    return num;
}

int right_rotate_bits (int num)
{
    num = ((unsigned)num >> 1u) | ((unsigned)num << (sizeof(int) * 8 - 1));      
/*	temp = num & 1u;
	temp <<= (sizeof(int) * 8 - 1);
	num = (unsigned)num >> 1;
	num |= temp;*/
	
	return num;
}

int left_rotate_bits (int num)
{
	num = ((unsigned)num << 1u) | ((unsigned)num >> (sizeof(int) * 8 - 1));  
	/*temp = (num >> (sizeof(int) * 8 - 1) & 1u);
	num = (unsigned)num << 1;
	num |= temp;*/

	return num;
}

int right_rotate_n_bits (int num, int n)
{	

   num = ((unsigned)num >> n) | ((unsigned)num << (sizeof(int) * 8 - n));      
	
	return num;
}

int left_rotate_n_bits (int num, int n)
{

	num = ((unsigned)num << n) | ((unsigned)num >> (sizeof(int) * 8 - n));  

	return num;
}

void count_bit_set (int n)                                                      
{                                                                               
    int s = 0;                                                                  
                                                                                
    while (n != 0){                                                             
        if (( n & (1u << (sizeof(int) * 8 -1))) != 0 )                            
            s++;                                                                
        n = (unsigned)n << 1;                                                             
    }                                                                           
                                                                                
    printf ("number of ones-%d \n", s);                                         
                                                                                
}                                                                               
                                                                                
void count_bit_clear (int n)                                                    
{                                                                               
    int c = 0;                                                                  
    int i;                                                                                                                        
                                                                                
    for (i = 0; i <= (sizeof(int) * 8 - 1); i++){                                
       if (((n >> i) & 1u) == 0)                                                              
            c++;                                                                
    }                                                                           
                                                                                
    printf ("number of zeros-%d \n", c);                                        
                                                                                
}                                                                               
            
int cnt_leading_cleared_bits (int num)                                          
{                                                                               
                                                                                
    int c = 0;                                                                  
    int i;                                                                      
                                                                                
    for (i = (sizeof(int) * 8 -1); i >= 0; i--){                                
        if (((num >> i) & 1u) == 0)                                                              
            c++;                                                                
        else                                                                    
            break;                                                              
    }                                                                           
                                                                                
    return c;                                                                   
                                                                                
}                                                                               
                                                                                
int cnt_leading_set_bits (int num)                                              
{                                                                               
    c = 0;                                                                      
                                                                                
    for (i = (sizeof(int) * 8 - 1); i >=0; i--){                                
        if (((num >> i) & 1u) == 1)                                                              
            c++;                                                                
        else                                                                    
            break;                                                              
    }                                                                           
                                                                                
    return c;                                                                   
}                                                                               
      

int cnt_trailing_cleared_bits (int num)                                         
{                                                                               
    c = 0;                                                                      
                                                                                
    for (i = 0; i <= (sizeof(int) * 8 - 1); i++){                                
        if (((num >> i) & 1u) == 0)                                                              
            c++;                                                                
        else                                                                    
            break;                                                              
    }                                                                           
                                                                                
    return c;                                                                   
}                                                                               
                                                                                
int cnt_trailing_set_bits (int num)                                             
{                                                                               
    c = 0;                                                                       
                                                                                
    for (i = 0; i <= (sizeof(int) * 8 - 1); i++){                                
        if (((num >> i) & 1u) == 1)                                                              
            c++;                                                                
        else                                                                    
            break;                                                              
    }                                                                           
                                                                                
    return c;                                                                   
}                


void setbits_copy (int x, int p, int n, int y)                                  
{     
	for (i = p; i >= p-n+1; i--){                                              
        if((y >> i & 1u) != (x >> i & 1u))                                                            
            x ^= (1u << i);                                                                                                
    }                                                                           
                                                                                
    printf ("after copying the bits x is : %d \n", x);                          
                                                                                
    showbits (x);                     // displays binary form of a decimal      
                                                                                
}   

int invert (int x, int p, int n)                                                
{                    
	int i;
                                                                                                                               
     for (i = p; i >= p - n + 1; i--)                                                
        x ^= (1u << i);                                                         
                                                                                
    return x;                                                                   
}    

