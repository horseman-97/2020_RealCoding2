void func(int *p)
{
    int *q = p;
    *q = 100;
    q++;
    *q = 200;
}

int main()
{
    int a = 1;
    int b = 2;
    int *pa, *pb, pp;
	pa = &a; 
	pb = &b; 
	pp = (int) pa; 
	printf("%d %d\n", a, b);
    printf("%d %d\n", *pa, *pb);
	func(&b); 
	printf("%d %d\n", *pa, *pb);
	printf("%d %d %d\n", pa, pb, *(int *) pp);
	printf("%d %d\n", a, b);
	printf("%d, %d, %d, %d\n", a, &a, *(&a), *(int *)(int)(&a) );
}