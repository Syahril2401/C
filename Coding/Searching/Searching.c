#include <stdio.h>
#include <string.h>

typedef struct {
	long nim;
	char name[100]; 	
} Student;

Student* binarySearch(Student* profile, int data, long id){
	int left = 0; 
	int right = data - 1;
	
	while (left <= right){
		int mid = left + (right - left)/2;
		long midnim = profile[mid].nim;
		
		if (midnim > id){
			right =  mid - 1;
		}
		
		else if(midnim < id){
			left = mid + 1;
		}
		else {
			return profile + mid;
		}
	}
	
	return -1;
}

int main (){
	FILE *fileInput;
	fileInput = fopen("testdata.in", "r");
	
	if (fileInput == NULL){
			
	}
	
	int data;
	fscanf(fileInput, "%d", &data);
	Student profile[data];
	
	for(int i = 0; i < data; i++){
		fscanf(fileInput, "%ld %s", &profile[i].nim, &profile[i].name);
	}
	
	int test;
	fscanf(fileInput, "%d", &test);
	
	
	for(int j = 0; j < test; j++){
		long nim;
		fscanf(fileInput, "%ld", &nim);
	
	Student* studentName = binarySearch(profile, data, nim);

		if(studentName == -1){
			printf("Case #%d: N/A\n", j + 1);
		}
		else {
			printf("Case #%d: %s\n", j + 1, studentName->name);
		}
	}
	
	fclose(fileInput);
	
	return 0;
}
