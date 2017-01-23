VPATH=source out 
app : main.o sort.o binary_search_tree.o bubble_sort.o merge_sort.o insertion_sort.o selection_sort.o quick_sort.o int_valid.o rb_tree.o
	#gcc -o ./out/app -Wall ./out/*.o
	./out/app

int_valid.o : 
	#gcc ./source/int_valid.c -Wall -c -o ./out/int_valid.o

merge_sort.o : 
	#gcc ./source/merge_sort.c -Wall -c -o ./out/merge_sort.o

bubble_sort.o : 
	#gcc ./source/bubble_sort.c -Wall -c -o ./out/bubble_sort.o

selection_sort.o : 
	#gcc ./source/selection_sort.c -Wall -c -o ./out/selection_sort.o

quick_sort.o : 
	#gcc ./source/quick_sort.c -Wall -c -o ./out/quick_sort.o

insertion_sort.o : 
	#gcc ./source/insertion_sort.c -Wall -c -o ./out/insertion_sort.o

main.o :  
	#gcc ./source/Assignment_2_1.c -Wall -c -o ./out/main.o

sort.o : 
	#gcc ./source/sort.c -Wall -c -o ./out/sort.o

binary_search_tree.o :
	#gcc ./source/binary_search_tree.c -Wall -c -o ./out/binary_search_tree.o

rb_tree.o :
	#gcc ./source/rb_tree.c -Wall -c -o ./out/rb_tree.o

