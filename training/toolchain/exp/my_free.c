/*int main(void)
{
	void *p = NULL;
//	int *p = NULL;
//	int *r = NULL;
	int i;

	p = (int *)malloc(5 * sizeof(int));
	printf ("P = %p \n", p);

	for(i = 0; i<5; i++){
		*(int *)(p + i) = i + 10;
//		p[i] = i + 10;
	}

	printf("printing contents of p: \n");

	for(i = 0; i<5; i++)
		printf ("p[%d] = %d\n", i, *(int *)(p + i));

	free(p);

	p = (int *)malloc(5 * sizeof(int));
	printf ("p = %p \n", p);

	printf("printing contents of p: \n");

	for(i = 0; i<5; i++)
		printf ("p[%d] = %d\n", i, p[i]);

	p = my_free(p);

	p = (int *)malloc(5 * sizeof(int));
	printf ("p = %p \n", p);

	printf("printing contents of p after my_free: \n");

	for(i = 0; i<5; i++)
		printf ("p[%d] = %d\n", i, *(int *)(p + i));

	return 0;
}
*/
