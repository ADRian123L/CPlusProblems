#include <stdio.h>


int main(void) {
	
	int day_1 = 0, month_1=0, year_1=0,
	    day_2=0, month_2=0, year_2=0;

	printf("Enter the first date (mm/dd/yyyy): ");	
	scanf("%d/%d/%d", &month_1, &day_1, &year_1);
	printf("Enter the second date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month_2, &day_2, &year_2);
	
	printf("%s", (year_1 > year_2 || month_1 > month_2 || day_1 > day_2) ? ("First"): ("Second"));


return 0;

}
