
struct ListElement
{
	int value ;
	ListElement* next ;
};
struct List
{
	ListElement* first ;
};

List* createList(int n) ;
bool listIsEmpty(List* list) ;
int elementsLeft(List* list) ;
void destroyList(List* list) ;
void printList(List* list) ;
void addToSList(List* list, int n) ;
void removeSList(List* list, int n) ;
void insertElement(ListElement* tmp , int n , ListElement* tmp2) ;