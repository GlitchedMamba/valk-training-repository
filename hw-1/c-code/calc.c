#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int n;
	char op[10];
	int val;
	int i;
	int x = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", op);
		scanf("%d", &val);
		if (strcmp(op, "+") == 0)
			x += val;
		else if (strcmp(op, "-") == 0)
			x -= val;
		else if (strcmp(op, "*") == 0)
			x *= val;
		else if (strcmp(op, "/") == 0)
			x /= val;
		else if (strcmp(op, "**") == 0)
			 x = pow(x, val);
	}
	printf("%d\n", x);
}

