#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct airline_ticket {
	char customer_name[10];
	int customer_id;
	int boarding_group;
	char airline_name[10];
	int gate;
	char destination[10];
} airline_ticket;

airline_ticket* make_tickets(int n) {
	airline_ticket *tix = (airline_ticket*)malloc(n * sizeof(airline_ticket));
	for (int i = 0; i < n; i++) {
		airline_ticket *t = &tix[i];
		scanf("%s %d %d %s %d %s",
			t->customer_name,
			&(t->customer_id),
			&(t->boarding_group),
			t->airline_name,
			&(t->gate),
			t->destination
			);
	}
	return tix;
}

void print_tickets(airline_ticket* tix, int n) {
	for (int i = 0; i < n; i++) {
		airline_ticket *t = &tix[i];
		printf("tix[%d]: %s %d %d %s %d %s\n", i,
			t->customer_name,
			(t->customer_id),
			(t->boarding_group),
			t->airline_name,
			(t->gate),
			t->destination
			);
	}
}
void filter_gate_airlines(airline_ticket* tix, int n, int gate, char *airline) {
		printf("Customers traveling by airline: %s on gate: %d\n", airline, gate);
	for (int i = 0; i < n; i++) {
		if (tix[i].gate ==  gate && strcmp(tix[i].airline_name, airline) == 0) {
			printf("%s\n",tix[i].customer_name);
		}
	}
}
char* search_id(airline_ticket* tix, int n, int customer_id) {
	for (int i = 0; i < n; i++) {
		if (tix[i].customer_id == customer_id) {
			return tix[i].customer_name;
		}
	}
	return NULL;
}


int cmp_by_name(const void *a, const void *b) {
	airline_ticket *t1 = (airline_ticket*)a;
	airline_ticket *t2 = (airline_ticket*)b;
	return strcmp(t1->customer_name, t2->customer_name);
}

void sort_by_name(airline_ticket* tix, int n) {
	return qsort(tix, n, sizeof(airline_ticket), cmp_by_name);
}

int main() {
	int num;
	printf("Enter number of tickets: ");
	scanf("%d", &num);
	airline_ticket *tix;
	printf("Enter tickets as customer_name customer_id boarding_group airline_name gate destination\nExample: John 1 1 United 1 SJC\n");
	tix = make_tickets(num);
	printf("Tickets entered\n");
	print_tickets(tix, num);

	// problem 3.1
	sort_by_name(tix, num);
	printf("Sorted tickets\n");
	print_tickets(tix, num);

	// problem 3.2
	int gate;
	char airline[10];
	printf("Enter gate and airline name to filter by: ");
	scanf("%d %s", &gate, airline);
	filter_gate_airlines(tix, num, gate, airline);

	// problem 3.3
	int customer_id;
	printf("Enter customer ID: ");
	scanf("%d", &customer_id);
	char *name = search_id(tix, num, customer_id);
	if (name != NULL) {
		printf("Found customer: %s\n", name);
	} else {
		printf("No customer found\n");
	}


	return 0;
}
