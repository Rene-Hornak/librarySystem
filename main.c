// C program to create a library management system 
// to store, find books

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct libraryStructure {
	char book_name[20];
	char author[20];
	int pages;
	float price;
};

void waitForKey()
{
	printf("\n\nPress enter to continue.. \n");
	//fflush(stdin); // flush the input buffer, but not recommended
	while((getchar()) != '\n');
	getchar();
}

void clearScreen() 
{
	/* \033[H moves coursor top left, \033[J delete everything from the cursor forward */
	printf("\033[H\033[J");
}

int main() 
{
	// create a instance
	struct libraryStructure library[100];

	char author_name[30], book_name[30];

	int i, input, count;

	i = input = count = 0;

	// iterate the loop until (5 = exit)
	while(input != 5)
	{
		clearScreen();
		printf("\t\t\t=== WELCOME TO LIBRARY SYSTEM ===\n\n");
	
		printf(" 1. Add book information\n");
		printf(" 2. Display book information\n");
		printf(" 3. List all books of given author\n");	
		printf(" 4. List the count of books in the library\n");
		printf(" 5. Exit\n");

		printf("\n\nEnter one of the above: ");
		scanf("%d", &input);

			switch(input)
			{
				// add book information
				case 1:
					clearScreen();
					printf("Enter the book name: ");
					scanf("%s", library[i].book_name);

					printf("Enter the author name: ");
					scanf("%s", library[i].author);

					printf("Enter pages: ");
					scanf("%d", &library[i].pages);
		
					printf("Enter price: ");
					scanf("%f", &library[i].price);
					count++;

					waitForKey();

					break;

				// print book information
				case 2:
					clearScreen();
					printf("\t\t\t= Books Details =\n\n");
					
					for(i = 0; i < count; i++)
					{
						printf(" Book name: %s\n", 
							library[i].book_name);

						printf(" Author name: %s\n",
							library[i].author);
						printf(" Pages: %d\n",
							library[i].pages);

						printf(" Price: %f\n\n",
							library[i].price);
					}

					waitForKey();

					break;
				
				// find book by author
				case 3:
					clearScreen();
					
					printf("Enter the author name: ");
					scanf("%s", author_name);
					printf("\n");
					
					// comment
					for(i = 0; i < count; i++)
					{
						if(strcmp(author_name, library[i].author) == 0)
						{
							printf("Book Name: %s\n", library[i].book_name);
							printf("Author Name: %s\n", library[i].author);
							printf("Pages: %d\n", library[i].pages);
							printf("Price: %f\n\n", library[i].price);
						}
					}

					waitForKey();

					break;

				// print total number of books
				case 4:
					clearScreen();
					printf("No. of books in library: %d\n", count);
						
					waitForKey();

					break;

				case 5:
					exit(0);	
					break;
				
				default:
					exit(0);
					break;
			}
	}
					
	return 0;
}
