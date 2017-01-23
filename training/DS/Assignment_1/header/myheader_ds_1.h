#ifndef _MY_HEADER_DS_1
#define _MY_HEADER_DS_1

#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#define MAX 5 

extern int stack(void);
extern int queue(void);
extern int cir_queue(void);
extern int single_linked_list(void);
extern int double_linked_list(void);
extern int cir_single_linked_list(void);

int cir_isfull(void);                                                           
int cir_isempty(void);                                                          
void cir_enqueue(int);                                                          
void cir_display(void);                                                         
void cir_dequeue(void);                                                         
                                                                                
void my_enqueue(int);                                                           
void my_dequeue(void);                                                          
void my_display_queue(void); 

extern void my_push(int);                                                       
extern void my_pop(void);                                                       
extern void my_display(void); 

extern void cir_ins_beg(void);                                                              
extern void cir_ins_end (void);                                                             
extern void cir_ins_pos (int);                                                        
extern void cir_sll_display(void);                                                             
extern void cir_del_beg(void);
extern void cir_del_end(void);
extern void cir_del_pos (int);                                                             
extern int  cir_search (int);

extern void ins_end_d(int);
extern void ins_pos_d(int, int);
extern void ins_before_pos_d(int, int);
extern void ins_after_pos_d(int, int);
extern void ins_middle_d(int);
extern void ins_penultimate_d(int);
extern void display_d(void);
extern void ins_bef_num_d(int, int);                                                   
extern void ins_aft_num_d(int, int);
extern void del_pos_d(int);
extern int  search_d(int);

extern void ins_beg(int);
extern void ins_end (int);
extern void ins_pos (int, int);
extern void ins_before_pos (int, int);
extern void ins_after_pos (int, int);
extern void ins_middle (int);
extern void ins_penultimate (int);
extern void display(void);
extern void ins_bef_num (int, int);                                                   
extern void ins_aft_num (int, int);
extern void del_pos (int);
extern int  search (int);

#endif
