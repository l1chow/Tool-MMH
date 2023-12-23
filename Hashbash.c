#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 150 // M

typedef struct person{
  	char firstName[15];
  	char lastName[15];
  	char gender[7];
  	char edu[40];
  	int age, exp;
  	struct person *next;
}person;

// khao bao bang hash
person *hash_table[TABLE_SIZE];

// ham bam su dung FirstName and LastName lam khoa
unsigned int hash_func(char fname[], char lname[]){
 	char name[35] = {0};
  	strcat(name, fname);
  	strcat(name, lname);
  	int namelen = strlen(name);
 	unsigned int sum = 0;
 	for(int i = 0; i < namelen; i++)
 		sum += name[i];
 	return sum % TABLE_SIZE;
}

// khoi tao bang hash
void init_hash_table(){
  	for(int i = 0; i < TABLE_SIZE; i++){
  		hash_table[i] = NULL;
 	}
}

//search a person by firstname and lastname
person *search(char fname[], char lname[]){
	int index = hash_func(fname, lname);
	person *tmp = hash_table[index];
	while(tmp != NULL && strcmp(tmp->firstName, fname) != 0 && strcmp(tmp->lastName, lname) != 0)
    	tmp = tmp->next;
    if(tmp == NULL) return NULL;
	else return tmp;
}

//delete data in hash table
person *delete(char fname[], char lname[]){
	int index = hash_func(fname, lname);
	person *tmp = hash_table[index];
  // su dung con tro prev de tim node o trc node can xoa
	person *prev = NULL;
	while(tmp != NULL && strcmp(tmp->firstName, fname) != 0 && strcmp(tmp->lastName, lname) != 0){
		prev = tmp;
		tmp = tmp->next;
	}
	if(tmp == NULL)
    	return 0;
	if(prev == NULL)
    // deleting the head
    	hash_table[index] = tmp->next;
	else
    	prev->next = tmp->next;
	return tmp;
}

// insert tu file
void insertFromFile(char fname[], char *lname, char *gender, int age, char *edu, int exp){
  	person *result = malloc(sizeof(person));
  	strcpy(result->firstName, fname);
  	strcpy(result->lastName, lname);
  	strcpy(result->gender, gender);
  	strcpy(result->edu, edu);
  	result->age = age;
  	result->exp = exp;
  	result->next = NULL;
  	int index = hash_func(fname, lname);
  	if(hash_table[index] == NULL)
    	hash_table[index] = result;
  //collision
  	else
  	{
    //add the node at the end of hash_table[index].
    	person *temp = hash_table[index];
    while(temp->next)
        temp = temp->next;
    temp->next = result;
  }
}

// in bang
void print_table(){
  	for(int i = 0; i < TABLE_SIZE; i++){
    	if(hash_table[i] == NULL){
      		printf("\t%i\t---\n", i);
    	}else{
      		printf("\n\t%i\t", i);
      		person *tmp = hash_table[i];
      	while(tmp != NULL){
        	printf("%s-%s-%s-%d-%s-%d\n", tmp->firstName, tmp->lastName, tmp->gender, tmp->age, tmp->edu, tmp->exp);
        	tmp = tmp->next;
      	}
      	printf("\n");
    }
  }
}

// doc file(
void readFile(){
  	FILE *fp = fopen("C:\\Users\\PC\\OneDrive\\Desktop\\C\\C.txt", "r");
  	if(!fp){
    	printf("Can't open the file data.csv");
    	exit(1);
  	}
  	int dataLine = 0;
  	for(char c = getc(fp); c != EOF; c = getc(fp)){
    	if(c == '\n')
      		dataLine++;
  	}
  	person tmp[dataLine+1];

  	char buf[200];
  	int i = 0;
  	char* delimiter = ",";
  	rewind(fp);

  	while(fgets(buf, 200, (FILE*)fp) != NULL){
    	strcpy(tmp[i].firstName, strtok(buf, delimiter));
    	strcpy(tmp[i].lastName, strtok(NULL, delimiter));
    	strcpy(tmp[i].gender, strtok(NULL, delimiter));
    	tmp[i].age = atoi(strtok(NULL, delimiter));
    	strcpy(tmp[i].edu, strtok(NULL, delimiter));
    	tmp[i].exp = atoi(strtok(NULL, delimiter));
    	i++;
  	}
  	fclose(fp);
  // array tmp -> hashtable
  	for(int i = 0; i <dataLine; i++){
    	insertFromFile(tmp[i].firstName, tmp[i].lastName, tmp[i].gender, tmp[i].age, tmp[i].edu, tmp[i].exp);
  	}
}

void menu(){
	printf("\n-----------------------------");
	printf("\n1. Read file.");
	printf("\n2. Print table.");
	printf("\n3. Search.");
	printf("\n4. Delete.");
	printf("\n5. End.");
	printf("\n-----------------------------");
	printf("\nChoose: ");
}

int main(){
	init_hash_table();
	int number;
	while(1){
		menu();
		scanf("%d", &number);
		switch(number){
			case 1:
				system("cls");
				readFile();
				printf("Read file success!");
				break;
			case 2:
				system("cls");
				print_table();
				break;
			case 3:
				system("cls");
				char firstN[15], lastN[15];
				printf("First name: ");
				fflush(stdin);
				gets(firstN);
				
				printf("Last name: ");
				fflush(stdin);
				gets(lastN);
				int i = hash_func(firstN, lastN);
				person *tmp = search(firstN, lastN);
				if(tmp == NULL) printf("Not found!");
				else printf(" %d, %s-%s-%s-%d-%s-%d", i, tmp->firstName, tmp->lastName, tmp->gender, tmp->age, tmp->edu, tmp->exp);
				break;
			case 4:
				system("cls");
				char firstN1[15], lastN1[15];
				printf("First name: ");
				fflush(stdin);
				gets(firstN1);
				
				printf("Last name: ");
				fflush(stdin);
				gets(lastN1);
				person *tmp1 = delete(firstN1, lastN1);
				if(tmp1 == NULL) printf("Not found!");
				else printf("Found %s %s.\n", tmp1->firstName, tmp1->lastName);
				break;
			case 5:
				exit(0);
		}
	}
  	return 0;
}
