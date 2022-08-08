#include "addProduct.c"
#include "editProduct.c"
#include "displayProduct.c"
#include "deleteProduct.c"
#include "searchProduct.c"

int iMenu()
{
	system("cls");
	int opt;
	displayTitleHead();
	printf("\t\t\t**| INVENTORY OPTIONS |**\n\n");
	printf("\t\tA - Add\n");
	printf("\t\tE - Edit\n");
	printf("\t\tD - Delete\n");
	printf("\t\tV - View\n");
	printf("\t\tH - Search\n");
	displayFooterMenu();
	
	opt= tolower(getch());
	
	switch(opt)
	{
		case 97:// ASCII 'a'
			getProdDetail();
			break;		
		case 101:// ASCII 'e'
			editProdDetail();
			break;
		
		case 100:// ASCII 'd'
			deleteProd();
			break;
			
		case 118:// ASCII 'v'
			displayProd();
			break;
			
		case 104:// ASCII 'h'
			searchProd();
			break;
		
		case 27:// ASCII 'ESC'
			return;
			
		default:
			operateFooter(opt);
			break;
	}
	iMenu();
}
