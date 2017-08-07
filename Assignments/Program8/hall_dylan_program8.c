/*
 Dylan Hall
 Program 7
 11/23/16
 */

#include <stdio.h>
#include <string.h>

int menu(int, char[], char[], char[], char[]);
void format_name(char[], char[], char[]);
void paragraph(char *);
char toUpper(char[]);
void clear(char[], int);
int checkempty(char[]);
void format_para(int num_letters, char drama[]);

int main(void) {
	int num_letters;
	char fname[50] = "\0", lname[50] = "\0", intro[200] = "Drama Written by";

	printf("Please enter the length of your paragraph in characters: ");
	scanf("%d", &num_letters);
	while (num_letters > 1001 || num_letters < 100) {
		printf(
				"Invalid size. \nPlease enter the length of your paragraph in characters: ");
		scanf("%d", &num_letters);
	}
	char drama[num_letters];
	clear(drama, sizeof(drama));
	menu(num_letters, fname, lname, drama, intro);
	return 0;
}

int menu(int num_letters, char fname[], char lname[], char drama[],
		char intro[]) {
	char ch, in, temp[num_letters];
	int i, j;
	while (1) {
		printf("\n\n\n   Menu Display             \n");
		printf("|-------------|------------------|\n");
		printf("|    Input    |     Function     |\n");
		printf("|-------------|------------------|\n");
		printf("|   C or c    |   Clear Arrays   |\n");
		printf("|   N or n    |    Name Input    |\n");
		printf("|   F or f    |   Set Uppercase  |\n");
		printf("|   P or p    |   New Paragraph  |\n");
		printf("|   R or r    | Format Paragraph |\n");
		printf("|   D or d    |     Display      |\n");
		printf("|--------------------------------|\n");

		printf("Please choose which option to perform: ");
		scanf(" %c", &ch);
		tolower(ch);

		switch (ch) {
		case 'c':
			printf("\nYou chose to clear the arrays of their information.\n");
			clear(fname, strlen(fname));
			clear(lname, strlen(lname));
			clear(drama, strlen(drama));
			clear(intro, strlen(intro));
			strcpy(intro, "Drama Written by");
			printf("Info cleared.\n\n");
			break;

		case 'n':
			printf("\nYou chose to input a first and last name.\n\n");
			printf("Please enter your first name: ");
			scanf("%s", fname);
			printf("Please enter your last name: ");
			scanf("%s", lname);
			break;

		case 'f':
			if (checkempty(fname) == 1)
				break;
			format_name(fname, lname, intro);
			break;

		case 'p':
			clear(drama, strlen(drama));
			printf(
					"\nYou chose to write a paragraph. Press enter when finished\n\n");
			scanf("%c", &in);
			gets(drama);
			break;

		case 'r':
			if (checkempty(drama) == 1)
				break;
			format_para(num_letters, drama);
			break;

		case 'd':
			if (checkempty(drama) == 1)
				break;
			printf("You chose to display your drama.\n\n%s\n", intro);
			paragraph(drama);

			break;

		case 'x':
			printf("You chose to exit the program.");
			return 0;

		default:
			printf("Invalid choice.");
			break;
		}
	}
}

//Display Function
void paragraph(char *cat) {
	printf("\n\n%s\n", cat);
}

//To Upper Case Function
char toUpper(char a[]) {
	if (a[0] >= 'a' && a[0] <= 'z')
		a[0] = a[0] - 32;
	return a[0];
}

void clear(char a[], int size) {
	int i;
	for (i = 0; i < size; i++)
		a[i] = '\0';
}

int checkempty(char a[]) {
	if (a[0] == '\0') {
		printf("This information is empty. Can not modify.\n\n\n");
		return 1;
	} else
		return 0;
}

void format_name(char fname[], char lname[], char intro[]) {
	printf("\nYou chose to make the first letter of each name uppercase.\n");
	toUpper(fname);
	toUpper(lname);
	strcat(intro, " ");
	strcat(intro, fname);
	strcat(intro, " ");
	strcat(intro, lname);
	strcat(intro, ".");
	printf("Names properly formatted.\n\n\n");
}

void format_para(int num_letters, char drama[]) {
	int i, j;
	char temp[num_letters];
	clear(temp, strlen(temp));
	printf("You chose to format your paragraph.\n\n");
	for (i = 0; i < num_letters; i++) {
		temp[i] = drama[i];
		if (drama[i] == '.') {
			if (drama[i + 1] == ' ' && drama[i + 2] >= 'a'
					&& drama[i + 2] <= 'z') {
				drama[i + 2] = drama[i + 2] - 32;
			}
			i++;
			temp[i] = '\n';
		}
	}
	clear(drama, strlen(drama));
	strcat(drama, temp);

	if (drama[0] >= 'a' && drama[0] <= 'z')
		drama[0] = drama[0] - 32;

	printf("Paragraph successfully formatted.\n\n");
}
