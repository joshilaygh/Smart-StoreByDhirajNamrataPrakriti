#include <stdio.h>
#include "structProduct.c"
void main(){
	int code;
	struct product *p, pd;
	p=&pd;
	FILE *purchase= fopen("purchase.dat", "r");
	if(purchase==NULL){
		printf("\nFile doesn't exist or Can't open file.");
	}
	else{
		while (fread(p, sizeof(struct product), 1, purchase)){
			code= atoi(p->code);
			printf("\n\t| %d= %-5s| %-40s| %-9d| %-11.2f| %-11.2f|   %02d/%02d/%02d  |", code, p->code, p->name, p->qty, p->cp, p->sp, p->d, p->m, p->y);
		}
	}
	fclose(purchase);
}
