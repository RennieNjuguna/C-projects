#include <iostream>
using namespace std;
#include <conio.h>

class sayMatrixType											//Creating class sayMatrixType
{
	public:
		long m[5][5];
		int row;int col;
		void getdata();
		int operator==(sayMatrixType);
		sayMatrixType operator*(sayMatrixType);
		sayMatrixType operator-(sayMatrixType);
		sayMatrixType operator+(sayMatrixType);
		friend ostream & operator << (ostream &,sayMatrixType &);
};

int sayMatrixType::operator==(sayMatrixType cm)				//Operator Overload Function 
{
	if(row==cm.row && col==cm.col)
	{
		return 1;
	}
	return 0;
 }
 
 void sayMatrixType::getdata()							//Declaing getdata() function to input matrix data
 {
 	cout<<"How many rows?\n";
 	cin>>row;
 	cout<<"How many columns?\n";
 	cin>>col;
 	cout<<"Insert Matrix Elements\n";
 	for(int i=0;i<row;i++)
 	{
 		for(int j=0;j<col;j++)
 		{
 			cin>>m[i][j];								//Storing input data in array
		 }
	 }	
 }
 
  sayMatrixType sayMatrixType::operator*(sayMatrixType mp)  //Overloading the * operator
{
	sayMatrixType temp;
	for(int i=0;i<row;i++)
 	{
 		for(int j=0;j<col;j++)
		 {
 			temp.m[i][j]=m[i][j]*mp.m[i][j];
		 }
		 temp.row;
		 temp.col;
	}
	return temp;	
}

 sayMatrixType sayMatrixType::operator+(sayMatrixType am)  //Overloading the + operator
{
	sayMatrixType temp;
	for(int i=0;i<row;i++)
 	{
 		for(int j=0;j<col;j++)
		 {
 			temp.m[i][j]=m[i][j]+am.m[i][j];
		 }
		 temp.row;
		 temp.col;
	}
	return temp;	
}
 sayMatrixType sayMatrixType::operator-(sayMatrixType sm)  //Overloading the - operator
{
	sayMatrixType temp;
	for(int i=0;i<row;i++)
 	{
 		for(int j=0;j<col;j++)
		 {
 			temp.m[i][j]=m[i][j]-sm.m[i][j];
		 }
		 temp.row;
		 temp.col;
	}
	return temp;	
}

ostream & operator <<(ostream &fout, sayMatrixType &d)  //Overloading the << operator
{
	for(int i=0;i<d.col;i++)
 	{
 		for(int j=0;j<d.col;j++)
 		{
 			fout<<d.m[i][j];
 			cout<<" ";
 		}
 		cout<<endl;
	}
	return fout;
}

main()      							
{
	sayMatrixType m1,m2,m3,m4,m5;						//Creating Objects of class sayMatrixType
	
	m1.getdata();						
	m2.getdata();
	if(m1==m2)
	{
		m3=m1+m2;
		m4=m1-m2;
		m5=m1*m2;
		cout<<"Result of Multiplication is:\n";
		cout<<"The result is\n";
		cout<<m5;
		cout<<"Result of Addition is:\n";
		cout<<"The result is\n";
		cout<<m3;
		cout<<"Result of Subtraction is:\n";
		cout<<"The result is\n";
		cout<<m4;								
	}
	else
	{
		cout<<"Rows and Column size is not the same\n";
	}
}

