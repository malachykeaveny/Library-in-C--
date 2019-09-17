/*
	Student Name: Malachy Keaveny
	Student Number: C16775539
*/

#define _CRT_SECURE_NO_WARNINGS
#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





//Stucture template for data part of a LinearNode
struct data {
	char bookID[15];
	char bookName[30];
	char bookAuthor[30];
	int pubYear;
	bool loaned;
	char cusName[15] = "";
	int timesLoaned;
	int outstandingFees = 0;
};

//Stucture template for one node
struct LinearNode {
	struct data *element;
	struct LinearNode *next;
};


// Function prototypes
void addNodes();  //adding nodes to end of the list
void takeOutNode(); // take out a book
void returnNode(); // return a book
void deleteNode(); // delete a specific book
void viewANode(); // view a book
void viewAllNodes(); // view all books
void extraFunction(); // take out a book and have it delivered to you
bool isEmpty();



// Global Variables
struct LinearNode *front = NULL;
struct LinearNode *last = NULL;

/**************MAIN FUNCTION*******************/
int main() {

	int userChoice;
	printf("\n----MENU----");
	printf("\n1. Add a new node to the list");
	printf("\n2. Allow customer to take out a book");
	printf("\n3. Allow customer to return a book");
	printf("\n4. Delete an old book from stock");
	printf("\n5. View all books");
	printf("\n6. View a specified book");
	printf("\n7. View details of most popular and least popular books");
	printf("\n8. Loan a book and have it sent to you by post (Postage charges will apply)");
	printf("\n9. Exit the system\n");


	do {
		printf("\nPlease input your choice: ");
		scanf("%d", &userChoice);
		switch (userChoice)
		{
		case 1:
			printf("\nYou've selected: 1. Add a new node to the list");
			printf("\n---------------");
			addNodes();
			break;
		case 2:
			printf("\nYou've selected 2: Take out a book");
			takeOutNode();
			break;
		case 3:
			printf("\nYou've selected 3: Return a book");
			returnNode();
			break;
		case 4:
			printf("\nYou've selected 4: Delete an old book from stock:");
			deleteNode();
			break;
		case 5:
			printf("\nYou've selected 5: View all books");
			viewAllNodes();
			break;
		case 6:
			printf("\nYou've selected 6: View a selected book");
			viewANode();
			break;
		case 7:
			printf("\nYou've selected 7:  View details of most popular and least popular books");
		case 8:
			printf("\n You've selected 8: Loan a book and have it sent to you by post (Postage charges will apply)");
			extraFunction();
			break;
		}
	} while (userChoice != 9);

	

	getchar();
	getchar();
}


void addNodes() {


	struct LinearNode *aNode;
	struct data *anElement;

	if (sizeof(struct data) <= 10) {
		printf("Sorry list is full");
	}
	else {
		//Create space for data part of node
		anElement = (struct data *)malloc(sizeof(struct data));

		if (anElement == NULL)
			printf("Error - no space for the new element\n");
		else
		{
			//Input value into the data part
			printf("\nEnter book ID: (Must be all numbers in format XXXX-XXXX");
			scanf("%s", &anElement->bookID);

			//make sure the 5th element is "-"
			for (int i = 0; i < sizeof(anElement->bookID); i += 1) {
				if (anElement->bookID[4] != '-') {
					printf("\nEnter book ID: (Must be all numbers in format XXXX-XXXX");
					scanf("%s", anElement->bookID);
				}
				else if (anElement->bookID[1]) {

				}

			}

			printf("\nEnter book name: ");
			getchar();
			// I looked online and this ("%[^\n]s") seemed to be the best way to take in a string with whitespace. The [^n] keeps reading in until the end of the line
			scanf("%[^\n]s", &anElement->bookName);
			printf("\nEnter book author: ");
			getchar();
			scanf("%[^\n]s", &anElement->bookAuthor);
			
			do {
				printf("\nEnter publication year: ");
				scanf("%d", &anElement->pubYear);
			} while (anElement->pubYear < 2008);
			anElement->loaned = false;
			anElement->cusName;
			anElement->timesLoaned = 0;
			anElement->outstandingFees;

			// create space for new node that will contain data
			aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

			if (aNode == NULL)
				printf("Error - no space for the new node\n");
			else { // add data part to the node
				aNode->element = anElement;
				aNode->next = NULL;

				//add node to end of the list
				if (isEmpty())
				{
					front = aNode;
					last = aNode;
				}
				else {
					last->next = aNode;
					last = aNode;

					} //end else
				} //end else
			}//end else
		}//end else 
	//end for
} //end addNodes


 

  /**********VIEW ALL THREE NODES IN THE LIST******************/
  // Each new node is added to the end of the list

void viewANode() {
	char abookID[15];
	printf("\nEnter ID of book:");
	scanf("%s", &abookID);

	struct LinearNode *current, *previous;
	bool notFound = true;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = previous = front;

		while (notFound && current != NULL) {
			if (strcmp(current->element->bookID, abookID) == 0)
				notFound = false;
			else {
				previous = current;
				current = current->next;
			}//end else
		} //end while

		if (notFound) {
			printf("\nError - there is not such node with value %s\n", abookID);
		}
		else {
			printf("Book ID: %s\n", current->element->bookID);
			printf("Book name: %s\n", current->element->bookName);
			printf("Book author: %s\n", current->element->bookAuthor);
			printf("Publication year: %d\n", current->element->pubYear);

			if (current->element->loaned == true) {
				printf("Book loaned: Yes\n");
				printf("Customer name: %s\n", current->element->cusName);
				printf("What fees must be paid when this book is returned? : %d", current->element->outstandingFees);
			}
			else
				printf("Book loaned: No\n");


		}
	}//end else
}

void viewAllNodes() {
	struct LinearNode *current;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = front;
		while (current != NULL) {
			printf("Book ID: %s\n", current->element->bookID);
			printf("Book name: %s\n", current->element->bookName);
			printf("Book author: %s\n", current->element->bookAuthor);
			printf("Publication year: %d\n", current->element->pubYear);

			if (current->element->loaned == true) {
				printf("Book loaned: Yes\n");
				printf("Customer name: %s\n", current->element->cusName);
				printf("What fees must be paid when this book is returned? : %d", current->element->outstandingFees);
			}
			else
				printf("Book loaned: No\n");

			


			
			current = current->next;
		} //end while
	}//end else
	
} //end viewAllNodes
 

void deleteNode() {
	printf("\nEnter ID of book:");
	char abookID[15];
	scanf("%s", &abookID);
	struct LinearNode *current, *previous;
	bool notFound = true;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = previous = front;

		while (notFound && current != NULL) {
			if (strcmp(current->element->bookID, abookID) == 0)
				notFound = false;
			else {
				previous = current;
				current = current->next;
			}//end else
		} //end while

		if (notFound)
			printf("Error - there is not such node with value %s\n", abookID);
		else {

			if (current->element->pubYear > 2010)
				printf("Error - Cannot delete books newer than 2010!");

			else {
				if (current == front) { //delete front node
					front = front->next;
					free(current);
				} //end else
				else if (current == last) {//delete last node
					free(current);
					previous->next = NULL;
					last = previous;
				}
				else {//delete node in middle of list
					previous->next = current->next;
					free(current);
				} //end else
				printf("Node with value %s has been deleted\n", abookID);

			} //end else
		}//end else
	}//end else
}// end deleteNode

void takeOutNode() {
	char abookID[15];
	printf("\nEnter ID of book:");
	scanf("%s", &abookID);

	struct LinearNode *current, *previous;
	bool notFound = true;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = previous = front;

		while (notFound && current != NULL) {
			if (strcmp(current->element->bookID, abookID) == 0)
				notFound = false;
			else {
				previous = current;
				current = current->next;
			}//end else
		} //end while

		if (notFound) {
			printf("\nError - there is not such node with value %s\n", abookID);
		}
		else {
			if (current->element->loaned == true) {
				printf("\nSorry! Book has already been loaned out");
			}
			else {
				printf("\nBook is available for loan!");
				printf("\nEnter your name:");
				getchar();
				scanf("%[^\n]s", current->element->cusName);
				current->element->loaned = true;
				current->element->timesLoaned += 1;
			}
		}
	}//end else
}

void returnNode() {
	char abookID[15];
	printf("\nEnter ID of book:");
	scanf("%s", &abookID);

	struct LinearNode *current, *previous;
	bool notFound = true;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = previous = front;

		while (notFound && current != NULL) {
			if (strcmp(current->element->bookID, abookID) == 0)
				notFound = false;
			else {
				previous = current;
				current = current->next;
			}//end else
		} //end while

		if (notFound) {
			printf("\nError - there is not such node with value %s\n", abookID);
		}
		else {
			if (current->element->loaned == false) {
				printf("\nSorry! Book cannot be returned as it hasn't been loaned out. ");
			}
			else {
				// if customer has oustanding fees on their account from book delivery, they will be prompted to pay now.
				do {
					char payFees[5];
					strcpy(payFees, "");
					printf("\nYou have outstanding fees of €%d on your account from book delivery costs. Can you pay these fees now? (yes/no)", current->element->outstandingFees);
					scanf("%s", payFees);
					if (strcmp(payFees, "Yes") == 0 || strcmp(payFees, "yes") == 0) {
						current->element->outstandingFees = 0;
						printf("\nThanks for paying your account fees.");
					}
					else if (strcmp(payFees, "No") == 0 || strcmp(payFees, "no") == 0)
						printf("\nYou have chosen not to pay your account fees now. You will receive a letter with the bill.");
						current->element->outstandingFees = 0;

				} while (current->element->outstandingFees > 0);
				
				strcpy(current->element->cusName, ""); 
				current->element->loaned = false;			
			}
		}
	}//end else
}

void extraFunction() {
	int dublinDistrict = 0;
	char abookID[15];
	printf("\nEnter ID of book:");
	scanf("%s", &abookID);

	struct LinearNode *current, *previous;
	bool notFound = true;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = previous = front;

		while (notFound && current != NULL) {
			if (strcmp(current->element->bookID, abookID) == 0)
				notFound = false;
			else {
				previous = current;
				current = current->next;
			}//end else
		} //end while

		if (notFound) {
			printf("\nError - there is not such node with value %s\n", abookID);
		}
		else {
			if (current->element->loaned == true) {
				printf("\nSorry! Book has already been loaned out");
			}
			else {
				printf("\nBook is available for loan!");

				do {
					printf("\nWhich district in Dublin are you living in? (Enter a number between 1-24)");
					
					scanf("%d", &dublinDistrict);
				} while (dublinDistrict < 1 || dublinDistrict >24);

				if (dublinDistrict >= 1 && dublinDistrict <= 6) {
					printf("Your postage cost will be €3. This will be added to your library account fees");
					printf("\nEnter your name:");
					scanf("%s", current->element->cusName);
					current->element->loaned = true;
					current->element->timesLoaned += 1;
					current->element->outstandingFees += 3;
					printf("\nBook has been loaned and will be delivered in 3-5 working days!");
				}
				else if (dublinDistrict >= 7 && dublinDistrict <= 12) {
					printf("Your postage cost will be €4. This fee must be paid when the book is returned.");
					printf("\nEnter your name:");
					scanf("%s", current->element->cusName);
					current->element->loaned = true;
					current->element->timesLoaned += 1;
					current->element->outstandingFees += 4;
					printf("\nBook has been loaned and will be delivered in 3-5 working days!");
				}
				else if (dublinDistrict >= 13 && dublinDistrict <= 18) {
					printf("Your postage cost will be €5. This fee must be paid when the book is returned.");
					printf("\nEnter your name:");
					scanf("%s", current->element->cusName);
					current->element->loaned = true;
					current->element->timesLoaned += 1;
					current->element->outstandingFees += 5;
					printf("\nBook has been loaned and will be delivered in 3-5 working days!");
				}
				else if (dublinDistrict >= 19 && dublinDistrict <= 24) {
					printf("Your postage cost will be €6. This fee must be paid when the book is returned.");
					printf("\nEnter your name:");
					scanf("%s", current->element->cusName);
					current->element->loaned = true;
					current->element->timesLoaned += 1;
					current->element->outstandingFees += 6;
					printf("\nBook has been loaned and will be delivered in 3-5 working days!");
				}
			}
		}
	}//end else
}

bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}
