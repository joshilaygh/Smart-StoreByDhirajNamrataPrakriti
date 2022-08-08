#include "purchaseProduct.c"
#include "purchaseReturnProduct.c"

int pMenu()
{
	while(1){
		system("cls");
		int opt;
		displayTitleHead();
		printf("\t\t\t**| PURCHASE OPTIONS |**\n\n");
		printf("\t\t1 - Purchase\n");
		printf("\t\t2 - Purchase Return\n");
		displayFooterMenu();
		
		opt= tolower(getch());
		
		switch(opt)
		{
			case 49: //ASCII value '1'
				purchaseProd();
				break;
					
			case 50: //ASCII value '2'
				purchaseReturnProd();
				break;
			
			case 27:// ASCII 'ESC'
				return;
				
			default:
				operateFooter(opt);
				break;
		}
	}
}
