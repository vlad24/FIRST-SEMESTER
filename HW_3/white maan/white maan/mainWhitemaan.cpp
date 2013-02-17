#include "listprep.h"
#include "iostream"
#include "listprep.h"

int main()
{	
	printf("Enter the number of people  ") ;
	int n = 24 ;
	scanf("%d",&n) ;
	printf("Enter the position  ");
	int pos = 24 ;
	scanf("%d" , &pos ) ;

	for(int k=2 ; k <= n ; k++)
	{
		List* l = createList(n) ;
		ListElement* temp = l->first ; 
		while(l->first != l->first->next)
		{
			temp = deleteNextElement(l,temp,k) ;
		}
		if (temp->value == pos)
			printf("%d ",k);
		delete l->first ;
		delete l ;
	}
	int y = 24 ;
	scanf("%d",&y);
}