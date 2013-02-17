#include "stacks2.h"
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;

bool isCircle(char c)
{
     return ((c == '(') || (c == ')')) ; 
}
bool isSquare(char c)
{
      return (c == '[') || (c == ']') ;
}
bool isFigure(char c)
{
     return (c == '{') || (c == '}') ;
}

int main()
{
    Stack* stackmain = createStack() ;
   
    char string[100] = {} ;
	cout << "Enter the string \n" ;
    cin >> string ;
    int i = 0 ;
    int length = 0 ;
    while(string[i] != '\0')
    {
               length++ ;
               i++;
    }
    bool bad = false ;
    for(i = 0 ; i < length ; i++)
    {
                  
             if (isCircle(string[i]))
             {
                if (string[i] == '(')
                   push(stackmain , string[i]);
                if (string[i] == ')')
                   if (pop(stackmain) != '(')
                      bad = true ;
             }
              if (isSquare(string[i]))
             {
                if (string[i] == '[')
                   push(stackmain , string[i]);
                if (string[i] == ']')
                   if (pop(stackmain) != '[')
                      bad = true ;
             }
              if (isFigure(string[i]))
             {
                if (string[i] == '{')
                   push(stackmain , string[i]);
                if (string[i] == '}')
                   if (pop(stackmain) != '{')
                      bad = true ;
             }
        if(bad) break ;
          
    }
    if(!(isEmpty(stackmain)))
       bad = true ;
    if(bad)
       printf("disbalance");
    else
       printf("balance");
    int u = 24 ;
	cin >> u ;
}