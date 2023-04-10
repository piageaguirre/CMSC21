#include <stdio.h>

int main(void){
	int days,weekStart;
	printf("Enter the number of days in month: ");
	scanf("%d",&days);
	printf("Enter the starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d",&weekStart);
	
	int count = 8-weekStart;
	
	for(int x=1;x<=days;x++){
		while(weekStart>1){
			printf("   ");
			weekStart-=1;
		}
		if(count==0){
			printf("\n");
			count=7;
		}
		if(x<10){
			printf("  %d",x);
		}
		else{
			printf(" %d",x);
		}
		count-=1;
	}
	
	return 0;
	
	
}