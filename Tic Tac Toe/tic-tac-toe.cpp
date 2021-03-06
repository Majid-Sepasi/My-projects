// Author : Majid Sepasi

#include<iostream>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define N 4 // If you're gonna change the dimensions of table, just change this

#define white 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7)
#define blue 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3)
#define red 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12)
#define green 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2)
#define purple 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5)
using namespace std;
void showMatrix(string [][N] );
bool check_horizontal(string [][N], int);
bool check_vertical(string [][N], int );
bool check_main_diameter(string [][N], int, int);
bool check_sub_diameter(string [][N], int ,int );
bool is_repetitive(string [], int , string);
int min(int , int );


int main(){
	string mat[N][N];
	int num = 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			mat[i][j] = to_string(num);
			num++;
		}
	}
	
	bool player1 = true;
	int k = 0;
	string rep[N * N];
	showMatrix(mat);
	while(k != N * N)
	{
		cout << endl;
		cout << "Turn : ";
		player1 ? blue : purple;
		cout << (player1 ? "Player 1" : "Player 2") << endl;
		white;
		cout << "Enter a number : ";
		if(player1)
			blue;
		else
			purple;
		int op;
		cin >> op;
		while(op < 0 || op > N * N){
			red;
			cout << "This number is out of range ... try again : ";
			if(player1)
				blue;
			else
				purple;
			cin >> op;
		}
		while(is_repetitive(rep, k, to_string(op))){
			red;
			cout << "This number has already been selected ... try again : ";
			if(player1)
				blue;
			else
				purple;
			cin >> op;
		}
		white;
		int r = (op % N == 0 ? op / N - 1 : op / N );
		int c = (op % N == 0 ? N - 1 : op % N - 1);
		rep[k++] = mat[r][c];
		if(player1)
		{
			mat[r][c] = 'X';
		}
		else
		{
			mat[r][c] = 'O';
		}
		showMatrix(mat);
		
		if(check_horizontal(mat, r) || check_vertical(mat, c) || check_main_diameter(mat, r, c) || check_sub_diameter(mat, r, c)){
			green;
			cout << "Player" << (player1 ? 1 : 2) << " won !!";
			white;
			getch();
			return 0;
		}
		
		player1 = !player1;
	}
	showMatrix(mat);
	cout << "result :";
	red;
	cout << " equal !!";
	white;
	getch();
	return 0;
		
}

void showMatrix(string mat[][N]){
	system("cls");
	cout << endl;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
		{
			if(mat[i][j] == "X")
				blue;
			else if (mat[i][j] == "O")
				purple;	
			cout  <<  mat[i][j] << string(3 - mat[i][j].size(), ' ');
			white;
		}
		cout << endl;
	}
}

bool check_horizontal(string mat[][N], int row)
{
	int continuous = 1;
	for(int col = 0; col < N - 1; col++){
		if(mat[row][col] == mat[row][col + 1])
		{
			continuous++;
			if(continuous == 3)
				return true;
		}
		else{
			continuous = 1;
		}
	}
	return false;
}
bool check_vertical(string mat[][N], int col )
{
	int continuous = 1;
	for(int row = 0; row < N - 1; row++){
		if(mat[row][col] == mat[row + 1][col])
		{
			continuous++;
			if(continuous == 3)
				return true;
		}
		else
			continuous = 1;
	}
	return false;
}
bool check_main_diameter(string mat[][N], int row, int col)
{
	int r = row - min(row, col);
	int c = col - min(row ,col);
	
	int continuous = 1;
	while(r + 1 < N && c + 1 < N){
		if(mat[r][c] == mat[r + 1][c + 1])
		{
			continuous++;
			if(continuous == 3)
				return true;
		}
		else{
			continuous = 1;
		}
		r ++;
		c ++;
	}
	return false;
}
bool check_sub_diameter(string mat[][N] ,int row, int col )
{
	while(row > 0 && col < N - 1){
		row--;
		col++;
	}
	int continuous = 1;
	while(col - 1 >= 0 && row + 1 < N){
		
		if(mat[row][col] == mat[row + 1][col - 1])
		{
			continuous++;
			if(continuous == 3)
				return true;
		}
		else{
			continuous = 1;
		}
		row ++;
		col --;
	}
	return false;	
}

bool is_repetitive(string s[], int n, string x)
{
	for(int i = 0; i < n; i++)
		if(s[i] == x)
			return true;
	return false;
}

int min(int a, int b){
	return (a <= b ? a : b);
}

