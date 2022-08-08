#include "fileUpdate.c"
#include "checkOption.c"
#include "errorMessage.c"
#include "invMenu.c"
#include "purMenu.c"
#include "salesMenu.c"
#include "stockReportMenu.c"

void mMenu ()
{
	while(1){
		int opt;
		system("cls");
		displayTitleHead();
		printf("\t\t\t**| MAIN MENU |**\n\n");
		printf("\t\tI - Inventory\n");
		printf("\t\tP - Purchase\n");
		printf("\t\tS - Sales\n");
		printf("\t\tR - Stock Report\n");
		printf("\t\tX - Exit\n");
		
		printf("\n\n\t\tEnter your choice: ");
		
		opt= tolower(getch());
		
		operateFooter(opt);
	}
}
