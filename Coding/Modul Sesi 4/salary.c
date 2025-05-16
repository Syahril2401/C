#include <stdio.h>

int main () {
	double sales;
	double salary;
	const double baseSalary = 200.0;
	const double commission = 0.09;
	
	while (1) {
		printf("Enter sakes in dollars (-1 to end): ");
		scanf("%lf", &sales);
		
		if(sales == -1) {
			break;
		}
		salary = baseSalary + (commission * sales);
		printf("Salary is : $%.2lf\n", salary);
	}
	return 0;
}
