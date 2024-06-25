#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void ingreso(int *,int );
void proceso(int *,int);
void impresion(int *,int);
typedef int entero;
int main()
{
	int t;
	int *ptr=new entero[10];
	std::cout<<"Ingrese el tamaño "<<std::endl;
	std::cin>>t;
	ingreso(ptr,t);
	impresion(ptr,t);
	proceso(ptr,t);
	impresion(ptr,t);
}
void ingreso(int *p,int t){
	int i;
	for(i=0;i<t;i++){
		scanf("%d",*(&p)+i);
	}
}
void impresion(int *p,int t){
	int i;
	printf("{ ");
	for(i=0;i<t;i++){
		printf("%d ",*(&(*p)));
		*(p++);
	}
	printf(" }");
}
void proceso(int *p,int t){
		int i,e;
		printf("\nIngrese el escalar ");
		scanf("%d",&e);
		for(i=0;i<t;i++){
			*p=(*(&(*p)))*e;
			*(p++);
		}
}
