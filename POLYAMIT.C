#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct nodeType
{
  int coeff;
  int power;
  struct nodeType *next;
} node;

 void readPolynomial(node **);
  void printPolynomial(node *);
  void addPolynomial(node *, node *, node **);
  void addNode(node **, int, int);
  void deletePolynomial(node **);
void main()
{
  node *poly1, *poly2, *poly3;
  int choice, element, after, before;

   poly1 = poly2 =poly3 = NULL;
  clrscr();

  printf("\n Porgram to add two polynomials");
  printf("\n--------------------------------\n");

  printf("\nEnter first polynomial:");
  readPolynomial(&poly1);
  printf("\nEnter second polynomial:");
  readPolynomial(&poly2);

  addPolynomial(poly1, poly2, &poly3);

  printf("\n sum of polynomials\n");
  printPolynomial(poly1);
  printf("\n and \n");
  printPolynomial(poly2);
  printf("\n is \n");
  printPolynomial(poly3);
  getch();

  deletePolynomial(&poly1);
  deletePolynomial(&poly2);
  deletePolynomial(&poly3);
}

void addNode(node **ptr, int coef, int powe)
{
 node *tempPtr;

 tempPtr -> coeff = coef;
 tempPtr -> power = powe;

  if(*ptr == NULL)
  {
    tempPtr -> next = NULL;
    *ptr = tempPtr;
  }
  else
  {
    tempPtr -> next = *ptr;
  }
}

void readPolynomial(node **p)
{
  int coeficient, power;
  printf("\nEnter the term in the ascending order of power");
  while(1)
  {
    printf("\nEnter the degree of x:");
    scanf("%d",&power);
    printf("\nEnter its coeficient:");
    scanf("%f",&coeficient);

    addNode(p,coeficient,power);

    printf("\nAny more term (Y/N) ?");
    if(toupper(getch()) == 'Y')
    break;
  }
}

void printPolynomial(node *ptr)
{
  if(ptr != NULL)
  printf("%d x %d",ptr -> coeff, ptr -> power);

  for(ptr = ptr -> next; ptr != NULL; ptr = ptr ->next)
  {
    if(ptr -> coeff > 0)
    printf(" + ");
      if(ptr -> power == 0)
      printf("%d",ptr -> coeff);
	else if(ptr -> power == 1)
	printf("%dx",ptr -> coeff);
    else printf("%dx^%d", ptr -> coeff, ptr -> power);
  }
}

void addPolynomial(node* ptr1, node* ptr2, node** ptr3)
{
  int powe;
  float coef;

  while((ptr1 != NULL) && (ptr2 != NULL))
  {
    if(ptr1 -> power > ptr2 -> power)
    {
      coef = ptr1 -> coeff;
      powe =ptr1 -> power;
      ptr1 = ptr1 -> next;
    }
    else if(ptr1 -> power < ptr2 -> power)
    {
      coef = ptr2 -> coeff;
      powe =ptr2 -> power;
      ptr2 = ptr2 -> next;
    }
    else
    {
      coef = ptr1 -> coeff + ptr2 -> coeff;
      powe = ptr1 -> power;
      ptr1 = ptr1 -> next;
      ptr2 = ptr2 -> next;
    }
      if(coef != 0)
      addNode(ptr3, coef, powe);
  }

  if(ptr1 == NULL)
  {
    for(; ptr2 != NULL; ptr1 = ptr2 -> next)
    addNode(ptr3, ptr2 -> coeff, ptr2 -> power);
  }
  else if(ptr2 == NULL)
  {
    for(; ptr1 != NULL; ptr1 = ptr1 -> next)
    addNode(ptr3, ptr1 -> coeff, ptr1 -> power);
  }
}

void deletePolynomial(node **ptr)
{
  node *temp;
  while(*ptr != NULL)
  {
    temp = *ptr;
    *ptr = (*ptr) -> next;
    free(temp);
  }
}