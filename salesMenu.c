#include "salesProduct.c"
#include "salesReturnProduct.c"

int sMenu()
{
	while(1){
		system("cls");
		int opt;
		displayTitleHead();
		printf("\t\t\t**| SALES OPTIONS |**\n\n");
		printf("\t\t1 - Sales\n");
		printf("\t\t2 - Sales Return\n");
		displayFooterMenu();
		
		opt= tolower(getch());
		
		switch(opt)
		{
			case 49: //ASCII value '1'
				salesProd();
				break;
					
			case 50: //ASCII value '2'
				salesReturnProd();
				break;
			
			case 27:// ASCII 'ESC'
				return;
				
			default:
				operateFooter(opt);
				break;
		}
	}
}
