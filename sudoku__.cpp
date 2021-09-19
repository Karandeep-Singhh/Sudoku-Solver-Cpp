#include<iostream>

using namespace std;

#define N 9
int grid[N][N] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};



void print_board(){

	for(int i = 0 ; i<N ; i++){
		if(i % 3 == 0 && i != 0){
			cout<<"------------------------------"<<endl;
		}
		for(int j = 0 ; j<N ; j++){
			if(j % 3 == 0 && j != 0)
				cout<<" | ";
			if(j==8)
				cout<<grid[i][j]<<endl;
			else
				cout<<" "<<grid[i][j]<<" ";
		}
	}
}

bool find_empty(int &row, int &col){
	for(row = 0 ; row<N ; row++)
		for(col = 0 ; col<N ; col++)
			if(grid[row][col] == 0)
				return true;
	return false;
}

bool in_row(int row, int num){

	for(int i = 0 ; i < N ; i++)
		if(grid[row][i] == num)
			return true;
	return false;

}

bool in_col(int col, int num){

	for(int i = 0 ; i<N ; i++)
		if(grid[i][col] == num)
			return true;

	return false;

}

bool in_box(int r, int c, int num){

	int x = r - r%3;
	int y = c - c%3;

	for(int i = 0 ; i<3 ; i++)
		for(int j = 0 ; j<3 ; j++)
			if(grid[i+x][j+y] == num)
				return true;

	return false;

}
bool is_valid(int row, int col, int num){

	if(!in_row(row,num) && !in_col(col,num) && !in_box(row,col,num))
		return true;

	return false;
}

bool solution(){

	int row,col;

	if(!find_empty(row,col))
		return true;

	for(int i = 1; i<10 ; i++)
		if(is_valid(row,col,i)){
			grid[row][col] = i;

			if(solution())
				return true;

			grid[row][col] = 0;
		}

	return false;

}
int main(){
	print_board();
	
	if(solution()==true){
		cout<<endl<<"---------------solved----------------"<<endl;
		print_board();
	}
	else{
		cout<<"\nno solution"<<endl;
	}
}