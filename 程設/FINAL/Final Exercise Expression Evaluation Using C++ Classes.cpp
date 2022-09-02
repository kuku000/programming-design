// Exercise 20.12 Solution: Ex20_12.cpp
// Infix to postfix conversion
#include <iostream> 
#include <cctype>
#include <cmath>
#include <cstring>
#include "Stack.h" 


using namespace std;


void convertToPostfix( char * const, char * const );  
bool isOperator( char );        
bool precedence( char, char );  
int evaluatePostfixExpression( char * const );  
int calculate( int opnd1, int opnd2, char oper );  
  

int pow( int , int );

int main()
{
   const int MAXSIZE = 100;
   char c;
   char inFix[ MAXSIZE ];
   char postFix[ MAXSIZE ];
   int pos = 0;
   int answer;
   int i = 0;
   
   cout << "Enter the infix expression.\n";

   
   while ( ( c = static_cast< char >( cin.get() ) ) != '\n' )
	{	
      if ( c != ' ' )
         inFix[ pos++ ] = c;
	}
	
   inFix[ pos ] = '\0';

   cout << "The original infix expression is:\n" << inFix << '\n';

    
   convertToPostfix( inFix, postFix );

   cout << "The expression in postfix notation is:\n" << postFix << endl;

   answer = evaluatePostfixExpression( postFix );
   cout << "The value of the expression is: " << answer << endl;	
   return 0;
}    

 
void convertToPostfix( char * const infix, char * const postfix )
{
   Stack< char > charStack;
   int infixCount;
   int postfixCount;
   bool higher;
   char popValue;
   char leftParen = '(';

   
   charStack.push( leftParen );
   charStack.printStack();
   strcat( infix, ")" );

   
   for ( infixCount = 0, postfixCount = 0; charStack.stackTop(); 
         infixCount++ ) 
   {
      if ( isdigit( infix[ infixCount ] ) )
         postfix[ postfixCount++ ] = infix[ infixCount ];
      else if ( infix[ infixCount ] == '(' ) 
      {
         charStack.push( leftParen );
         charStack.printStack();
      }  
      else if ( isOperator( infix[ infixCount ] ) ) 
      {
         higher = true; // used to store value of precedence test

         while ( higher ) 
         {
            if ( isOperator( charStack.stackTop() ) )
            {
               if ( precedence( charStack.stackTop(), 
                  infix[ infixCount ] ) ) 
               {
                  charStack.pop(postfix[ postfixCount++ ]);
                  charStack.printStack();
               }  
               else 
                  higher = false;
            }  
            else
               higher = false;
         }  
         charStack.push( infix[ infixCount ] );
         charStack.printStack();
      }  
      else if ( infix[ infixCount ] == ')' ) 
      {
         while (charStack.pop(popValue) && popValue!='(' )
		 {
			charStack.printStack();
            postfix[ postfixCount++ ] = popValue;
         } 

         charStack.printStack();
      }  
   } 

   postfix[ postfixCount ] = '\0';
} 

 
bool isOperator( char c )
{
   if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )
      return true;
   else
      return false;
}  

 ns
bool precedence( char operator1, char operator2 )
{
   if ( operator1 == '^' )
      return true;
   else if ( operator2 == '^' )
      return false;
   else if ( operator1 == '*' || operator1 == '/' )
      return true;
   else if ( operator1 == '+' || operator1 == '-' )
   {
      if ( operator2 == '*' || operator2 == '/' )
         return false;
      else
         return true;
   }  

   return false;
}    
int evaluatePostfixExpression( char * const expr )
{
   int i=0;
   int finalVal;
   Stack< int > intStack;
   char c;
   
  
	while ( expr[i]!='\0'){
		if ( !isOperator(expr[i]) ){
			int a=expr[i]-48;
			intStack.push(a);
			intStack.printStack();
		}
		else{
			int n1,n2,a;
			intStack.pop(n1);
			intStack.printStack();
			intStack.pop(n2);
			intStack.printStack();
			a=calculate(n2,n1,expr[i]);
			intStack.push(a);
			intStack.printStack();	
		}
		i++;
	}
	
   intStack.pop(finalVal);   
   return finalVal;
}  
int calculate( int op1, int op2, char oper )
{
   int answer;
   switch( oper ) 
   {
		case '+':
			return op1+op2;
		case '-':
			return op1-op2;
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;
		case '^':
			return answer=pow(op1,op2);
   }  

   return 0;
} 

int pow( int a, int b)
{
	int r=1;
	for(int i=0;i<b;i++)
		r=r*a;
	return r;
}
/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
