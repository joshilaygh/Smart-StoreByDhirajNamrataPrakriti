void getProdDetail() {
	FILE *fp=fopen("inventory.dat", "a");
	//int x; //for float validation
	char code[15];
	struct product pd,*p;
	p=&pd;
	if(fp==NULL){
		displayAddProdHead();
		printf("\nFile doesn't exist or Can't open file.");
	}
	else{
		do{
			addProduct:
    		displayAddProdHead();
    		fflush(stdin);
			printf("\tEnter Product Detials:\n");
			printf("\tCode: ");
	    	gets(code);
	    	if(!strlen(code)){
	    		goto addProduct;
			}
	    	if(doCodeExist(code, p)){
	    		printf("\n\tCode already Exist or Invalid Code.\n");
	    		sleep(2);
			}
		}while(doCodeExist(code, p));
		
		strcpy(p->code, code);
	    printf("\tName: ");
	    gets(p->name);
		p->qty= 0;
	    printf("\tCost Price: ");
	    scanf("%f", &p->cp);
	    
	    do{
	    	printf("\tSell Price: ");
	    	scanf("%f", &p->sp);
		    /*x= scanf("%f", &p->sp);
		    if (!x){ //Check if entered data is number or not
		    	printf("\tInvalid Input!\n");
		    	goto addProduct;
			}
		    else */if(isSPValid(p)){
		    	fwrite(p, sizeof(struct product), 1, fp);
			}
			else{
				printf("\n\tInvalid Sell Price!\n\n");
			}
		}while(!(isSPValid(p)));
		displayAddProdHead();
		printf("\n\tFile Added Successfully.");
		sleep(2);
	}
	fclose(fp);
}
