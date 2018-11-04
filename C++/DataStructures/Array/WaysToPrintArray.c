/* Print array in all posible ways
 * Example:
 * 	Input:
 * 		[1, 2, 3]
 * 	Output:
 * 		(123)
 * 		(1)(23)
 * 		(1)(2)(3)
 * 		(12)(3)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Print array chunk */
void print_chunk(int *a, int size) {
	int i = 0;

	/* Print chunk */
	printf("(");
	for(i = 0; i < size; i++) {
		printf("%d", a[i]);
	}
	printf(") ");
}

/* Print array in all possible ways */
void print_array(int *a, int index, int len) {
	int i = 0;

	/* Validate input */
	if(!a) {
		return;
	}

	if(len < 1) {
		return;
	}

	print_chunk(a, len);

	/* Partition array */
	for(i = index; i < len; i++) {
		print_array(a, index+1, i);
		print_array(a+i, index+1, len-i);
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	printf("Ways to print array\n");

	/* Input array */
	int a[3] = {1,2,3};

	/* Array length */
	int len = 3;

	/* Print array chunk */
	print_chunk(a, len);
	printf("\n");

	print_array(a, 0, len);

	return 0;
}
