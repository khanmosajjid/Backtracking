#include<bits/stdc++.h>
using namespace std;



bool isSafe(int board[][10],int i,int j,int n){
	//you can check for the column
	// j is the column;
	for(int row=0;row<i;row++){
		if(board[row][j]==1){
			return false;
		}
	}
	//you can check for left diagonal row;
	int x=i;
	int y=j;
	while(x>=0&&y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	//check for the right diagonal;
	 x=i;
	 y=j;
	while(x>=0&&y<n){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}
     
     //agar kahi se bhi false return nhi ho ra it means we have corect position;
	return true;

}
// n is total number of rows;
//i is the current row;
bool solveNQueen(int board[][10],int i,int n){
	//base case
	if(i==n){
		//you have successfully placed queens in n rows from 0...n-1;
		//print the board;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]==1){
					cout<<" Q ";
				}
				else
					cout<<" x ";
			}
			cout<<""<<endl;
		}
		cout<<""<<endl;
		return false;
	}
	//Recursive call;
	// in recursion we assume that our subboard is solve by recursion and we placed queen in current row;
	//call on the remaining part;

	for(int j=0;j<n;j++){
		// we have to check that we can place queen in i,j position or not;
		//assumint that i,j is right position of queen;
		if(isSafe(board,i,j,n)){
			board[i][j]=1;
	
	      bool nextQueenRakhPaaRhe=solveNQueen(board,i+1,n);

	      if(nextQueenRakhPaaRhe){
		     return true;
	     }
	     //if we come here means i,j is not correct position;
	     board[i][j]=0; //backtrack kr liya hmne;
  }

 }
 //it means hmne cuurent row me saare positon try kiya aur queen nhi rakh paaye;
 return false;
} 


int main(){
	int n;
	//n is total number of rows
	cin>>n;
	int board[10][10]={0};
	solveNQueen(board,0,n);

}
