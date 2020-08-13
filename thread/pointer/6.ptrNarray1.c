#include <stdio.h>

int main(void)
{
	short arr[5] = {1, 2, 3, 4, 5};
	short *p;
	int i;

	p = &arr[0];
	printf("%d,%d\n", p[1], p[3]);

	p = &arr[2];
	printf("%d,%d\n", p[1], p[3]);//3, 5

#if 0
	for(i=0, p=arr; i<5; i++) {
		printf("%d,%d\n", arr[i], *(p+i));
		printf("%d,%d\n", *(arr+i), *(p+i));
	}
#endif
	for(i=0, p=arr; i<5; i++, p++) {
		printf("%d,%d\n", arr[i], *p);
	}
	for(i=0, p=arr; i<5; i++, arr++) {//unavailable
		printf("%d,%d\n", p[i], *arr);
	}
	return 0;
}
