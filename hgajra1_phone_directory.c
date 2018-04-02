#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

struct telephoneBook      //declaring structure
{
	char fname[20];
	char lname[20];
	char tno[20];
};
struct telephoneBook arr[10];
int flag2=0;

struct telephoneBook putInStruct (char* str)
{
	struct telephoneBook result;
	int flag = 0;
	char *token = strtok(str, " ,");
	
	while( token != NULL )
	{
		if (0 == flag)
			strcpy(result.fname, token);
		else if (1 == flag)
			strcpy(result.lname, token);
		else
			strcpy(result.tno,token);
		
		flag++;
		flag2++;
		token = strtok( NULL, " ," );
	}
	return result;
}



void print(struct telephoneBook* arr, int size) //print to test
{ int i;
	for ( i = 0; i < size; i++)
	{
		
		//printf("%s %s %s\n", arr[i].fname, arr[i].lname, arr[i].tno);
		
	}
	
	int j;
	
	int n=sizeof(arr);
	for (i = 0; i < n-1; i++){
		printf("----------");
		for (j = i+1; j < n ; j++) {
			//	printf("inside loop %s %s \n",arr[i].lname,arr[j].lname);
			
		}
	}
	
}


void sort_contact(){   //sort
	//	printf("insort");
	int firstIndex =0;
	int lastIndex  = ((flag2-1)/3)-1;
	//	printf("flag2 is %d ",flag2);
	quick_sort(arr,firstIndex,lastIndex);
}


void search(char search_fname[],char search_lname[]){ //search 
	
	int loc= binarySearch(search_fname, search_lname);
	
	if(loc >0){
		printf("  Name Found at location %d \n",loc);
		//printf("%s %s, %s ",arr[loc].fname,arr[loc].lname,arr[loc].tno );
	}else{
		printf("\n Not Found the name ");
	}
}

int binarySearch(char search_fname[],char search_lname[]){  //Binary Search algo
	
	int  first, last, middle, n, search;
	
	
	first = 0;
	int len = ((flag2-1)/3);
	last = len;
	middle = (first+last)/2;
	
	while (first <= last) {
		if (strcmp(arr[middle].fname ,search_fname)<0)
			first = middle + 1;
		else if (strcmp(arr[middle].fname ,search_fname)==0) {
			
			if (strcmp(arr[middle].lname,search_lname)==0){
				printf("%s %s, %s \n",arr[middle].fname,arr[middle].lname,arr[middle].tno );
				return (middle+1);
				//printf("Name found at location %d",middle+1);
				
			}
			
			
			break;
		}
		else
			last = middle - 1;
		
		middle = (first + last)/2;
	}
	if (first > last){
		
		printf(" %s %s is not present \n", search_fname,search_lname);
		
		return 0;
	}
	return 0;
}



void swap(struct telephoneBook *a, struct telephoneBook *b)//swapping
{
	struct telephoneBook temp;
	strcpy(temp.fname,a->fname);
	strcpy(temp.lname,a->lname);
	strcpy(temp.tno,a->tno);
	strcpy(a->fname, b->fname);
	strcpy(a->lname, b->lname);
	strcpy(a->tno,b->tno);
	strcpy(b->fname ,temp.fname);
	strcpy(b->lname ,temp.lname);
	strcpy(b->tno ,temp.tno);
}
int partion(struct telephoneBook arr[], int p, int r)//partition
{
	
	int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
	
	struct telephoneBook *pivot;
	
	int i = p - 1;
	
	int j;
	
	pivot = &arr[pivotIndex];
	
	swap(&arr[pivotIndex], &arr[r]);
	
	for (j = p; j < r; j++)
	{
		if (strcmp(arr[j].fname, pivot->fname)<0)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		else if(strcmp(arr[j].fname , pivot->fname)==0)
		
		{
			if(strcmp(arr[j].lname,pivot->lname)<0)
			{
				
				i++;
				swap(&arr[i], &arr[j]);
			}
			else if (strcmp(arr[j].lname,pivot->lname)==0)
			{
				if (strcmp(arr[j].tno,pivot->tno)<0)
				{
					i++;
					swap(&arr[i], &arr[j]);
				}
			}
		}
		
		
	}
	swap(&arr[i+1], &arr[r]);
	return i + 1;
}

void display_names()//displaying the names
{int i ;
	int lenf =((flag2-1)/3);
	for (i=0;i<lenf;i++){
		
		printf("\n  %s  %s,  %s", arr[i].fname,arr[i].lname,arr[i].tno);
	}
}

void quick_sort(struct telephoneBook arr[], int p, int q) //quick sort
{
	
	int j;
	if (p < q)
	{
		j = partion(arr, p, q);
		quick_sort(arr, p, j-1);
		quick_sort(arr, j+1, q);
	}
	
}

void insert (char fnme[],char lnme[], char tn[]) //insert
{
	int i=0;
	int len = ((flag2-1)/3);
	int index = len-1;
	
	strcpy(arr[index+1].fname,fnme);
	strcpy(arr[index+1].lname,lnme);
	strcpy(arr[index+1].tno,tn);
	len++;
	
	flag2 =flag2+3;
	sort_contact();
	display_names();
	
}
void delete(char fnme[],char lnme[]){  //delete
	int del_loc =	binarySearch(fnme,lnme);
	int len =((flag2-1)/3);
	int i=0;
	int del_next =del_loc+1;
	if (del_loc > 0 ){
		
		
		for (i=del_loc-1;i<len-1;i++){
			
			strcpy(arr[i].fname,arr[i+1].fname);
			strcpy(arr[i].lname,arr[i+1].lname);
			strcpy(arr[i].tno,arr[i+1].tno);
		}
		len --;
		
		for (i=0;i<len;i++){
			printf("\n %s %s %s  ",arr[i].fname,arr[i].lname,arr[i].tno);
			
		}
		
	}
	else{
		printf(" Name not found ");
	}
	
}

int main(int argc , char *argv[])
{
	
	char fileName[50];
	
//	printf("Enter the name of the file ");
//	scanf("%s",fileName);
	FILE* file = fopen(argv[1], "r");
	if (!file)
		return -1;
	
	char buffer[BUFFER_SIZE];
	int flag = 0;
	while (fgets(buffer, BUFFER_SIZE, file))
	{
		arr[flag] = putInStruct(buffer);
		flag++;
	}
	
	int len = ((flag2-1)/3);
	print(arr, len);
	while(1){
		
		int choice;
		
		printf("\n Enter your choice ");
		printf("\n 1. sort_contact  ");
		printf("\n 2. search ");
		printf("\n 3.delete ");
		printf("\n 4.insert \n");
		scanf("%d",&choice);
		
		char fnme[50];
		char lnme[50];
		char tn[25];
		
		switch(choice) {
			
			case 1  :
			sort_contact();
			display_names();
			break; /* optional */
			
			case 2:
			
			printf("Enter the first name and last name : ");
			scanf("%s %s",fnme,lnme);
			
			search(fnme,lnme);
			break;
			
			
			case 3:
			printf("Enter the first name and last name : ");
			scanf("%s %s",fnme,lnme);
			delete(fnme,lnme);
			break;
			
			case 4:
			printf("Enter the first-name and last-name and Number ");
			scanf("%s %s %s",fnme,lnme,tn);
			insert(fnme,lnme,tn);
			break;
			
			default : /* Optional */
			exit(1);
		}
	}
	return 0;
}
