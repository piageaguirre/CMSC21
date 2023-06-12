#include <stdio.h>
#include <math.h>
// creating the structure
struct line{
	struct point{
		float x;
		float y;
	}point1,point2;
	
	float *midpoint;
	float slope;
	float distance;
};


// initializing the functions to be used
float solveSlope(struct line line1);
float *solveMidpoint(struct line line1);
float solveDistance(struct line line1);
void getSlopeInterceptForm(struct line line1);


int main(void){
	struct line line1;
	printf("Enter x and y for point1: ");
	scanf("%f",&line1.point1.x);
	scanf("%f",&line1.point1.y);
	
	printf("Enter x and y for point2: ");
	scanf("%f",&line1.point2.x);
	scanf("%f",&line1.point2.y);
	
	line1.slope = solveSlope(line1);
	
	printf("\nSlope: %.6f", line1.slope);
	printf("\nMidpoint: %.6f, %.6f",*solveMidpoint(line1),*(solveMidpoint(line1)+1));
	printf("\nDistance between 2 points: %.6f", solveDistance(line1));
	getSlopeInterceptForm(line1);
}

// solving for slope
float solveSlope(struct line line1){
	float slope = line1.point1.y-line1.point2.y/line1.point1.x-line1.point2.y;
	
	return slope;
}

// solving for midpoint and assigning it  to an array
float *solveMidpoint(struct line line1){
	static float midpoint[2];
	midpoint[0] = (line1.point1.x+line1.point2.x)/2;
	midpoint[1] = (line1.point1.y+line1.point2.y)/2;
	return midpoint;

}

//solving for distance
float solveDistance(struct line line1){
	float distance = sqrt(pow(line1.point1.x-line1.point2.x,2)+pow(line1.point1.y-line1.point2.y,2));
	return distance;
}


// solving for m and b then printing slope intercept form
void getSlopeInterceptForm(struct line line1){
	float m = line1.slope;
	float b = (m*(-line1.point1.x))+line1.point1.y;
	printf("\ny= %.6fx + (%.6f)",m,b);
	
}
