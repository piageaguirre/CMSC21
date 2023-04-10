// Maria Pilar Isabel S. Aguirre
// Activity 7
// CMSC 21 Machine Problems 1
#include <stdio.h>

#define ROWS 9
#define COLS 9
#define INT_MAX 2147483647

int main(void){
	char letters[COLS]={'a','b','c','d','e','f','g','h','i'};
	char LETTERS[COLS]={'A','B','C','D','E','F','G','H','I'};
	int road_networks[ROWS][COLS]={
	    {1, 1, 0, 0, 0, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0},
		{1, 0, 1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 1, 1}};
		
	printf("Adjacency Matrix\n\n");
	for(int i =-1;i<COLS;i++){
		if(i==2||i==3){
			printf("[%c]   ",letters[i]);
		}
		else{printf(" %-5c",letters[i]);}
		
		for(int j =0;j<COLS;j++){
		if(i==-1){
			if(j==2||j==3){
				printf("[%c]  ",letters[j]);
			}
			else{printf("%-5c",letters[j]);}
			continue;}
		
	
			printf("%-5d",road_networks[i][j]);
		}
		printf("\n");
	}
	int point;
	while(1){
	printf("\nWhich point are you located? (0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H, 8 - I)\n\n");
	scanf("%d",&point);
    if (point == 2 || point == 3) {
        printf("\npoint: %c is a charging station\n", LETTERS[point]);
		break;
	}	
	int visited[COLS]={[0 ... 8] = 0};
	int distance[COLS]={[0 ... 8] = INT_MAX};
	
	distance[point]=0;
	
	// Dijkstra's Algorithm
	for(int i =0; i<ROWS;i++){
		int min=INT_MAX;
		int curr;
		
		// Min Distance Function integrated into the main loop
		for(int j=0;j<COLS;j++){
			if(visited[j]==0 && distance[j]<=min){
				min = distance[j], curr=j;
			}
		}
		
		visited[curr]=1;
		
		for(int adj=0;adj<COLS;adj++){
			if(	visited[adj]==0
				&& road_networks[curr][adj]==1
				&& distance[curr]!= INT_MAX
				&& distance[curr]+road_networks[curr][adj] < distance[adj]){
				distance[adj] = distance[curr]+road_networks[curr][adj];
			}

		}
	} 
	if(distance[2] == INT_MAX && distance[3] == INT_MAX){
		printf("At point: %c\n",LETTERS[point]);
		printf("No charging stations nearby.\n");
		break;
	}
	else{
		printf("At point: %c\n",LETTERS[point]);
		printf("point: %c arrived to charging station.\n",LETTERS[2+(distance[2]>distance[3])]);
		break;
	}}

	
}