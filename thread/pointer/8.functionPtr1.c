#include <stdio.h>

int add(int d1, int d2) {
	return d1+d2;
}
int sub(int d1, int d2) {
	return d1-d2;
}
int mul(int d1, int d2) {
	return d1*d2;
}
int div(int d1, int d2) {
	if(d2) return d1/d2;
	else { printf("Zero Dived Error!!\n"); return 0; }
}

int main(void)
{
	int no, rst;
	int (*fp) (int, int);//[type] (pointer variable) [type(s)]
	
	while(1) {
		do {
			printf("\nSelect(1.add, 2.sub, 3.mul, 4.div, 0.quit) => ");
			scanf("%d", &no);
		} while(no<0 || no>4);
		/*no function pointer
		switch(no)
		{
			case 1: rst = add(10, 20);
			break;
		}
		*/
		//function pointer case
		switch(no)
		{
			case 1: fp = &add;//fp = add also available
			break;
			case 2: fp = &sub;
			break;
			case 3: fp = &mul;
			break;
			case 4: fp = &add;
			break;
			case 0: return 0;//quit
		}

		rst = fp(10, 20);
		printf("rst => %d\n", rst);

	}

	return 0;
}
