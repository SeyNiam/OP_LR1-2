#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#endif

#include <stdio.h>
#include <math.h>

#define N 4000 //defining a constant for maximum amount of elements

int main() {
	float a[N] = {0}; // array of elements
	int n; //the amount of elements to count
	int i = 0; //counter
	float sum = 0; //sum of elements
	float denominator = 1; //the denominator of a fraction
	int endFlag = 1; //a flag that stops the application

	do{ //a global cycle that prevents the program from endting without the user's desire
		printf("Please input the amount of elements.\n");
		scanf("%d", &n); //input of the amount of elements

		if (n > N) { //checking that the number entered by the user does not exceed the maximum allowed
			printf("The amount of elements must be equal to or less than %d. Please try again.\n\n", N);
			endFlag = 1;
		}
		else{
			if(n < 0) { //checking that the number entered by the user is not negative
				printf("The amount of elements should positive. Please try again.\n\n");
				endFlag = 1;
			}
			else{
				if (n != 0) { //if the amount of elements is not 0, then counting
					a[i] = 1; //setting the first element as 1
					sum = a[i]; //setting the sum as the value of the first element

					for (i = 1; i < n; i++) {
						denominator = denominator * 2; //multiplying the denominator by two
						a[i] = pow((-1),i) * ((i + 1) / (denominator));
						sum += a[i]; //adding the value of the new element to the sum
					}
				}				

				printf("\tThe result is: %f\n\n", sum); //output of the result
				sum = 0;

				printf("\nPlease choose from the following:\n\t1 - Count again.\n\t2 - Exit.\n"); //suggesting to user to run program again or exit.
				scanf("%d", &endFlag);
				switch (endFlag) {
				case 1: endFlag = 1; break;
				case 2: endFlag = 0; break;
				default: printf("Incorrect answer. The program will be closed."); endFlag = 0; break;
				}
			}
		}
	} 	while (endFlag); //if flag is 0, then exiting out of cycle 
	return 0;
}