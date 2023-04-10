#include <stdio.h>

int main() {
    int n;
    int initial=1;
    scanf("%d",&n);
	printf("n      2 to the n\n---   ---------------\n");
    for(int i=0;i<=n;i++){

        printf("%-8d %d\n",i,initial);
        initial = initial*2;
    }
	return 0;
}