//Source code for Nqueens
//Cheryl Dsouza
//cvd3@pitt.edu




#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<process.h>

void display1(int n) ;
int arr[20];       //defined an N*N array of size 20
int counter;      //counter is defined to count the number of solution for the value of N
int main()
{
	int n;                           // defined for the vale of N
	void queenAlgo(int row, int n);
	printf("Enter value for N:  \n");  //Input from the user to get the vale of N
	scanf("%d",&n);
	queenAlgo(1,n);                                      
	getch();
	
	return 0;
 }

 

/*this function checks for available position  */
void queenAlgo(int row, int n)
{
	int col;                  //defined a variable col for the column in the matrix
	for(col=1;col<=n;col++)
	{
		if(position(row,col))
		{
			arr[row]=col;   //no problem with the position and hence place queen
			if(row==n)
				display1(n);    
			else      
                          //try queen with next position                
				queenAlgo(row+1,n);  //recursive function	
		}
	}
}


 
/*In this method looking for position.
if no conflict for the desired position it returns true(i.e 1) 
otherwise it returns false(0) */

int position(int row ,int col)
{
	int i;
	for(i=1;i<=row-1;i++)
	{
		
		if(arr[i]==col) //checking for column and diagonal 
			return 0;
		else
			if(abs(arr[i]-col)==abs(i-row)) // abs function return absolute value i.e. positive value
			return 0;
	}
	//Queen can be placed
	return 1;
}


//display1 the solution to n-Queen's problem
void display1(int n)
{
	int i,j;
	printf("\n\n SOLUTION %d:\n\n",++counter);

	
	for(i=1;i<=n;i++)         //number of solution found   
	{
		printf(" %d",i);
	}
	for(i=1;i<=n;i++)
	{
		printf("\n\n%d",i);
		for(j=1;j<=n;j++)        
		{
			if(arr[i]==j)
				printf(" Q");   //Queen is represented by ‘Q’ 
			else
				printf(" -");   //NO Queen is represented by ‘-‘ (backtracking method is used)
		}
	}
	
}