/******************
Name: Dvir Agassi
ID: 215786328
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
	int is_true = 1;
	while(is_true) { // while true - do it
		// print the menu
		printf("Choose an Option:\n\t1. Happy Face\n\t2. Balanced Number\
			\n\t3. Generous Number\n\t4. Circle Of Joy\n\t5. Happy Numbers\
			\n\t6. Festival Of Laughter\n\t7. Exit\n");
		// get user choice
		int choice;
		scanf("%d", &choice);

		switch (choice) {
			// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
			/* Example:
			* n = 3:
			* 0   0
			*   o
			* \___/
			*/
			case 1:
				char eyes, nose, mouth, space = ' ';
				int face_size;
				printf("Enter symbols for the eyes, nose, and mouth:\n");
				scanf(" %c %c %c", &eyes, &nose, &mouth);
				printf("Enter face size:\n");
				scanf("%d", &face_size);
				while(!(face_size > 0 && face_size % 2 == 1)) {
					printf("The face's size must be an odd and positive number, please try again:\n");
					scanf("%d", &face_size);		
				}
				printf("%c", eyes); // print 1st eye
				for (int i = 0; i < face_size; i++) { // print the spaces between eyes
					printf("%c", space);
				}
				printf("%c\n", eyes); // print 2nd eye
				for (int i = 0; i < (face_size + 1) / 2; i++) { // print the spaces before nose
					printf("%c", space);
				}
				printf("%c\n", nose); // print the nose
				printf("\\");
				for (int i = 0; i < face_size; i++) { // print the mouth
					printf("%c", mouth);
				}
				printf("/\n");
				break;
			// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
			// and the sum of all digits to the right of the middle digit(s) are equal
			/* Examples:
			Balanced: 1533, 450810, 99
			Not blanced: 1552, 34
			Please notice: the number has to be bigger than 0.
			*/
			case 2:
				int number;
				printf("Enter a number:\n");
				scanf("%d", &number);				
				while(number <= 0) { // check if the num the user gave is ok
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);		
				}
				int check_num = number;
				int digits = 0, right_sum = 0, left_sum = 0;
				while (check_num > 0) { // count amount of digits in the number
					check_num /= 10;
					digits++;
				}
				if (digits % 2 == 0) { // if num has even amount of digits
					for (int i = 0; i < digits / 2; i++) { // add to the right sum all the right half
						right_sum += number % 10;
						number /= 10;
					}
					while (number > 0) { // add the rest to left half
						left_sum += number % 10;
						number /= 10;
					}
				} else {
					for (int i = 0; i < (digits-1) / 2; i++) { // add until the middle digit
						right_sum += number % 10;
						number /= 10;
					}
					number /= 10; // delete the middle digit
					while (number > 0) { // add the rest
						left_sum += number % 10;
						number /= 10;
					}
				}
				if (left_sum == right_sum) // check if the sums are equal
					printf("This number is balanced and brings harmony!\n");
				else
					printf("This number isn't balanced and destroys harmony.\n");
				break;
			// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
			/* Examples:
			Abudant: 12, 20, 24
			Not Abudant: 3, 7, 10
			Please notice: the number has to be bigger than 0.
			*/
			case 3:
				number;
				printf("Enter a number:\n");
				scanf("%d", &number);				
				while(number <= 0) { // check if the num the user gave is ok
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);		
				}
				int sum = 0;
				for (int i = 1; i < number; i++) {
					if (number % i == 0) { // check number number and if modulo num = 0, add to the sum
						sum += i;
					}
				}
				if (sum > number) { // if the sum of the divisors is bigger than the num
					printf("This number is generous!\n");
				} else {
					printf("This number does not share.\n");
				}
				break;
			// Case 4: determine wether a number is a prime.
			/* Examples:
			This one brings joy: 3, 5, 11
			This one does not bring joy: 15, 8, 99
			Please notice: the number has to be bigger than 0.
			*/
			case 4:
				number;
				printf("Enter a number:\n");
				scanf("%d", &number);				
				while(number <= 0) { // check if the num the user gave is ok
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);		
				}
				int is_prime = 1;
				for (int i = 2; i < number; i++) { // check if the num is prime
					if (number % i == 0) {	
						is_prime = 0;
						break;
					}
					// if you checked all the nums and got till here the num is prime
					if (i == number) {
						int reverse_num = 0;
						while (number > 0) {
							reverse_num *= 10 + (number % 10);
							number /= 10;
						}
						for (int i = 1; i < reverse_num; i++) { // check if the reverse_num is prime
							if (number % i == 0) {	
								is_prime = 0;
								break;
							}
						}
					}
				}
				if (is_prime)
					printf("This number completes the circle of joy!\n");
				else
					printf("The circle remains incomplete.\n");
				break;
			// Happy numbers: Print all the happy numbers between 1 to the given number.
			// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
			/* Examples:
			Happy :) : 7, 10
			Not Happy :( : 5, 9
			Please notice: the number has to be bigger than 0.
			*/
			case 5:
				number;
				printf("Enter a number:\n");
				scanf("%d", &number);				
				while(number <= 0) { // check if the num the user gave is ok
					printf("Only positive number is allowed, please try again:\n");
					scanf("%d", &number);		
				}
				for (int i = 1; i <= number; i++) {
					int new_num = i;
					while (sum != 1) {
						sum = 0;
						while (new_num > 0) {							
							int last_digit = new_num % 10;
							sum += last_digit * last_digit;
							new_num /= 10;
						}
					}
				}
				break;
			case 6:
				int smile, cheer, festival;
				printf("Enter a smile and cheer number:\n");
				int input = scanf("%d%d", &smile, &cheer);				
				while(smile <= 0 || cheer <= 0) { // check if the input the user gave is ok
					printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
					scanf("%d%d", &smile, &cheer);		
				}
				printf("Enter maximum number for the festival:\n");
				scanf("%d", &festival);				
				while(festival <= 0) { // check if the input the user gave is ok
					printf("Only positive maximum number is allowed, please try again:\n");
					scanf("%d", &festival);		
				}
				for (int i = 0; i <= festival; i++) {
					if (i % smile == 0 && i % cheer == 0) {
						printf("Festival!\n");
						continue;
					}
					if (i % smile == 0) {
						printf("Smile!\n");
						continue;
					}
					if (i % cheer == 0) {
						printf("Cheer!\n");
						continue;
					}
					printf("%d\n", i);
				}
				break;
			case 7:
				printf("Thank you for your journey through Numeria!\n");
				is_true = 0; // make the while loop stop
				break;
			default:
				printf("This option is not available, please try again.\n");
		}
	}
	
    

	

	

	
    

	

	// Festival of Laughter: Prints all the numbers between 1 the given number:
	// and replace with "Smile!" every number that divided by the given smile number
	// and replace with "Cheer!" every number that divided by the given cheer number
	// and replace with "Festival!" every number that divided by both of them
	/* Example:
	6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
	*/
	return 0;
}
