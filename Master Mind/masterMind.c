// Author : Majid Sepasi
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define white 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7)
#define green 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10)
#define red 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12)
#define firouze SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11)

void showResult(char goal[], char t[]);
int main()
{
	srand(time(NULL));
	char goal[4];
	
	// first digit must not be zero !!
	int rnd = rand() % 10;
	
	while(rnd == 0){
		rnd = rand() % 10;
	}
		
	goal[0] = rnd + '0';
	for(int i = 1 ; i < 4; i++){
		rnd = rand() % 10;
		goal[i] = rnd + '0';
	}
	
//	printf("goal : %s\n", goal);
	
	int win = 0;
	char chance[4];
	for(int i = 0; i < 10; i++){
		
		printf("Enter your number : ");
		firouze;
		gets(chance);
		white;
		if(strcmp(chance, goal) == 0){
			win = 1;
			break;
		}
		if(strlen(chance) != 4){
			red;
			printf("chance missed !! the length of number must be 4 character !!\n");
			white;
		}
		else{
			showResult(goal, chance);
		}
	}
	
	if(win){
		printf("\nCorrect number but incorrect place : %d\n", 0);
		printf("Both a correct number and correct place : %d\n\n", 4);
		green;
		printf("You Win ^_*");
		white;
	}
	else{
		red;
		printf("You lost ^_^");
	}
	white;
	printf("\n");
	getch();
			
}
void showResult(char goal[], char t[])
{
	int correctOrder = 0;
	int correctUnOrder = 0;
	for(int i = 0; i < 4; i++){
		if(goal[i] == t[i]){
			t[i] = '*';
			correctOrder++;
		}
	}
	
	for(int i = 0; i < 4; i++){
		if(t[i] != '*'){
			for(int k = 0; k < 4; k++){
				if(goal[i] == t[k]){
					t[k] = '*';
					correctUnOrder++;
				}
			}
		}
	}
	
	printf("\nCorrect number but incorrect place : %d\n", correctUnOrder);
	printf("Both a correct number and correct place : %d\n\n", correctOrder);
	white;
	
}
