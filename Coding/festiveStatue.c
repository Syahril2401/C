#include <stdio.h>

int main() {
	char a[100];
	char b[100];
	char c[100];
	char d[100];
	char e[100];
	
	scanf("%s", &a);
	scanf("%s", &b);
	scanf("%s", &c);
	scanf("%s", &d);
	scanf("%s", &e);
	
    printf("%10s|%s\n", a, a);
    printf("%10s|%s\n", b, b);
    printf("%10s|%s\n", c, c);
    printf("%10s|%s\n", d, d);
    printf("%10s|%s\n", e, e);

    return 0;
}

