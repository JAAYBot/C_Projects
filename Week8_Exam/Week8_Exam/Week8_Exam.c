/*
John McCormack

MCT609

Week 8 Exam

December 12, 2016
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

//Structs
struct robots {

	int id_number;
	int type;
	char name[15];

};
struct jobs {
	
	int job_id;
	int robot_number;
	int robot_type;
	char job_name[15];
	int current_lsc;
	int end_lsc;
	int job_flag;
		
	struct time_stamp {

		int hour;
		int minute;
		int day;
		int month;
		int year;

	}t_stamp;

};

//Functions prototypes
void start_program();
void load_robot_data();
void load_jobs_data();
void view_robots_information();
void view_jobs_information();
void add_robot();
void add_job();
void save_robots();
void save_jobs();
void set_job_completed();
void sort_robots();
void sort_jobs_by_date();
void bubble_sort_robots(struct robots **temp_s, int array_size);
void bubble_sort_jobs(struct jobs **temp_s, int array_size);
void view_individual_job();
void view_jobs_by_robot();
void recently_completed_delivery();

//Global Variables
struct robots **robots_array;
struct jobs **jobs_array;
int robot_count;
int job_count;
char robot_db[] = "robots_database.txt";
char jobs_db[] = "jobs_database.txt";
char temp_db[] = "temp.txt";

//Main
void main(void) {

	start_program();

	free(robots_array);
	free(jobs_array);

	//getch();

}

//Function Implementation
void start_program() {

	robot_count = 0;
	job_count = 0;
	load_robot_data();
	load_jobs_data();
	int a;
	
	do {
		system("cls");
		printf("*********************************************************\n");
		printf("Welcome to the Hotel Automation Management System (HAMSA)\n");
		printf("*********************************************************\n");
		printf("\nPlease select an action by pressing its number\n\n");
		printf("1. Add a Robot\n"); //complete, but can add duplicate robots
		printf("2. Add a Job\n"); //complete but can add duplicate job ids
		printf("3. View all Robot Information\n"); //complete
		printf("4. View all Jobs\n"); //complete
		printf("5. Sort Robot information by type\n"); //complete
		printf("6. View Job information by date and time\n");
		printf("7. Sort Job information by date and time\n"); //completed
		printf("8. Set Job as completed\n"); //complete clean up maybe
		printf("9. View Job information by Robot\n");
		printf("10. View Recently Completed Deliveries\n");
		printf("11. Save and Exit\n"); //complete
		printf("12. Exit Without Saving\n\n"); //complete
		printf("*********************************************************\n\n");
		scanf("\n%d", &a);
		printf("\n");

		switch (a) {
		case 1:
			system("cls");
			printf("*********************************************************\n");
			printf("Add a Robot\n");
			printf("*********************************************************\n");
			add_robot();
			printf("\nA new Robot has been Added\n\n");
			printf("Changes will not be saved to database until instructed to do so\n");
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 2:
			system("cls");
			printf("*********************************************************\n");
			printf("Add a Job\n");
			printf("*********************************************************\n");
			add_job();
			printf("\nA new Job has been Added\n");
			printf("Changes will not be saved to database until instructed to do so\n\n");
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 3:
			system("cls");
			printf("*********************************************************\n");
			printf("View all Robot Information\n");
			printf("*********************************************************\n");
			view_robots_information();
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 4:
			system("cls");
			printf("*********************************************************\n");
			printf("View All Jobs\n");
			printf("*********************************************************\n");
			view_jobs_information();
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 5:
			system("cls");
			printf("*********************************************************\n");
			printf("Sort Robot information by type\n");
			printf("*********************************************************\n");
			sort_robots();
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 6:
			system("cls");
			printf("*********************************************************\n");
			printf("View Job information by date and time\n");
			printf("*********************************************************\n");
			view_individual_job();
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 7:
			system("cls");
			printf("*********************************************************\n");
			printf("Sort Job information by date and time\n");
			printf("*********************************************************\n");
			sort_jobs_by_date();
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 8:
			system("cls");
			printf("*********************************************************\n");
			printf("Set Job as completed\n");
			printf("*********************************************************\n");
			set_job_completed();
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 9:
			system("cls");
			printf("*********************************************************\n");
			printf("View Job information by Robot\n");
			printf("*********************************************************\n");
			view_jobs_by_robot();
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 10:
			system("cls");
			printf("*********************************************************\n");
			printf("View Recently Completed Deliveries\n");
			printf("*********************************************************\n");
			recently_completed_delivery();
			printf("\n*********************************************************\n");
			printf("\nPress Any Key to Continue\n");
			getch();
			break;
		case 11:
			system("cls");
			printf("*********************************************************\n");
			printf("Save and Exit\n");
			printf("*********************************************************\n");
			save_robots();
			save_jobs();
			printf("\n*********************************************************\n");
			printf("\nGoodBye...\n");
			getch();
			break;
		case 12:
			system("cls");
			printf("*********************************************************\n");
			printf("Exit Without Saving\n");
			printf("*********************************************************\n");
			printf("\nGoodBye...\n");
			getch();
			break;
		}
		if (a == 12) {
		a = 11;}
	
	} while (a != 11);

}

void load_robot_data() {
	
	int i = 0, t1, t2;
	char temp_s[14];
	
	FILE *fptr;

	if ((fptr = fopen(robot_db, "r")) == NULL) {
		printf("Error!!!\n");
		return 0;
	}
	else {

		robots_array = (struct robots **)malloc(sizeof(struct robots *));

		while (fscanf(fptr, "%d%d%s", &t1, &t2, &temp_s) != EOF) {

				robots_array = (struct robots **)realloc(robots_array, (sizeof(struct robots *)*(i+1)));
				robots_array[i] = (struct robots *)malloc(sizeof(struct robots));
				robots_array[i]->id_number = t1;
				robots_array[i]->type = t2;
				strcpy(robots_array[i]->name, temp_s);
				i++;
				++robot_count;
			}
	
	}

	fclose(fptr); //close
	
}

void load_jobs_data() {

	int i = 0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
	char temp_s[14];
	char c;

	FILE *fptr;

	if ((fptr = fopen(jobs_db, "r")) == NULL) {
		printf("Error!!!\n");
		return 0;
	}
	else {

		jobs_array = (struct jobs **)malloc(sizeof(struct jobs *));

		while (fscanf(fptr, "%d%d%s%d%d%d%d%c%d%d%c%d%c%d", &t1, &t2, &temp_s, &t3, &t4, &t5, &t6, &c, &t7, &t8, &c, &t9, &c, &t10) != EOF) {

			jobs_array = (struct jobs **)realloc(jobs_array, (sizeof(struct jobs *)*(i + 1)));
			jobs_array[i] = (struct jobs *)malloc(sizeof(struct jobs));
			jobs_array[i]->job_id = t1;
			jobs_array[i]->robot_number = t2;
			strcpy(jobs_array[i]->job_name, temp_s);
			jobs_array[i]->current_lsc = t3;
			jobs_array[i]->end_lsc = t4;
			jobs_array[i]->job_flag = t5;
			jobs_array[i]->t_stamp.hour = t6;
			jobs_array[i]->t_stamp.minute = t7;
			jobs_array[i]->t_stamp.day = t8;
			jobs_array[i]->t_stamp.month = t9;
			jobs_array[i]->t_stamp.year = t10;
			
			jobs_array[i]->robot_type = strcmp(temp_s, "cleaning") ? 20 : 10;

			i++;
			++job_count;

		}

	}

	fclose(fptr); //close 

}

void view_robots_information() {
	
	int i;

	printf("\nRobot Number\tType Code\tType Name\n\n");
	for (i = 0; i < robot_count; i++) {
		printf("%d\t\t%d\t\t%s\n", robots_array[i]->id_number, robots_array[i]->type, (*robots_array[i]).name);
	}

}

void view_jobs_information() {
	int i;
	printf("\nJob Id\tRobot Number\tJob Name\tCurrent LSC\tEnd LSC\tFlag\tCreated Timestamp\n\n");
	for (i = 0; i < job_count; i++) {
		printf("%d\t%d\t\t%s\t%d\t\t%d\t%d\t%d:%d %d/%d/%d\n",
			jobs_array[i]->job_id, jobs_array[i]->robot_number, jobs_array[i]->job_name,
			jobs_array[i]->current_lsc, jobs_array[i]->end_lsc, jobs_array[i]->job_flag,
			jobs_array[i]->t_stamp.hour, jobs_array[i]->t_stamp.minute, jobs_array[i]->t_stamp.day, jobs_array[i]->t_stamp.month, jobs_array[i]->t_stamp.year);
	}

}

void add_robot() {

	struct robots temp_struct;

	printf("Please Enter new Robot's Number:\n");
	scanf("\n%d", &temp_struct.id_number);
	int i;
	for (i = 0; i < robot_count; i++) {
		while (robots_array[i]->id_number == temp_struct.id_number) {
			printf("This Robot already Exists, please re-enter New Robot ID\n");
			scanf("\n%d", &temp_struct.id_number);
		}
	}


	printf("Please Enter new Robot's Type\n");
	printf("Enter 10  for 'Cleaner' or  Enter 20 for 'Courier'\n");
	scanf("\n%d", &temp_struct.type);

	if (temp_struct.type == 10) {
		strcpy(temp_struct.name, "Cleaner");
	}
	else if (temp_struct.type == 20) {
		strcpy(temp_struct.name, "Courier");
	}
	
	robots_array = (struct robots **)realloc(robots_array, ((sizeof(struct robots *))*(robot_count+1)));
	robots_array[robot_count] = (struct robots *)malloc(sizeof(struct robots));
	
	strcpy(robots_array[robot_count]->name, temp_struct.name);
	robots_array[robot_count]->id_number = temp_struct.id_number;
	robots_array[robot_count]->type = temp_struct.type;
	
	++robot_count;

}

void add_job() {

	struct jobs temp_struct;
	int i;

	printf("\nPlease Enter New Job ID:\n");
	scanf("\n%d", &temp_struct.job_id);
	for (i = 0; i < job_count; i++) {
		while(jobs_array[i]->job_id == temp_struct.job_id) {
			printf("This Job ID already Exists, please re-enter Job ID\n");
			scanf("\n%d", &temp_struct.job_id);
		}
	}

	printf("Please Enter Type of Job\n");
	printf("Enter 10 for 'cleaning' type or  20 for 'delivery' type\n");
	scanf("\n%d", &temp_struct.robot_type);
	if (temp_struct.robot_type == 10) {
		strcpy(temp_struct.job_name, "cleaning");
	}
	else {
		strcpy(temp_struct.job_name, "delivery");
	}
	printf("Please Enter Start Location of job from location 1 - 5 :\n");
	scanf("\n%d", &temp_struct.current_lsc);
	printf("Please Enter End Location of job from location 1 - 5 :\n");
	scanf("\n%d", &temp_struct.end_lsc);

	printf("Status of Job set to incomplete\n");
	temp_struct.job_flag = 0;
	
	printf("Please Enter Robot to assigned from list\n");

	for (i = 0; i < robot_count; i++) {
		if (robots_array[i]->type == temp_struct.robot_type) {
			printf("Robot: %d\n", robots_array[i]->id_number);
		}
	}

	scanf("\n%d", &temp_struct.robot_number);
		
	time_t curtime;
	struct tm *loctime;
	
	curtime = time(NULL);
	
	loctime = localtime(&curtime);
			
	jobs_array = (struct jobs **)realloc(jobs_array, ((sizeof(struct jobs *))*(job_count + 1)));
	jobs_array[job_count] = (struct jobs *)malloc(sizeof(struct jobs));

	jobs_array[job_count]->job_id = temp_struct.job_id;
	jobs_array[job_count]->robot_number = temp_struct.robot_number;
	strcpy(jobs_array[job_count]->job_name, temp_struct.job_name);
	jobs_array[job_count]->current_lsc = temp_struct.current_lsc;
	jobs_array[job_count]->end_lsc = temp_struct.end_lsc;
	jobs_array[job_count]->job_flag = temp_struct.job_flag;
	jobs_array[job_count]->robot_type = temp_struct.robot_type;

	jobs_array[job_count]->t_stamp.hour = loctime->tm_hour;
	jobs_array[job_count]->t_stamp.minute = loctime->tm_min;
	jobs_array[job_count]->t_stamp.day = loctime->tm_mday;
	jobs_array[job_count]->t_stamp.month = loctime->tm_mon+1;
	jobs_array[job_count]->t_stamp.year = loctime->tm_year+1900;
	

	++job_count;

}

void save_robots() {

	FILE *ftptemp = fopen(temp_db, "w");
	int i;
	for (i = 0; i < robot_count; i++) {
	
		fprintf(ftptemp, "%d\t%d\t%s\n", robots_array[i]->id_number, (*robots_array[i]).type, robots_array[i]->name);

	}

	fclose(ftptemp);
	remove(robot_db);
	rename(temp_db, robot_db);


}

void save_jobs() {

	FILE *ftptemp = fopen(temp_db, "w");
	int i;
	for (i = 0; i < job_count; i++) {

		fprintf(ftptemp, "%d\t%d\t%s\t%d\t%d\t%d\t%d:%d %d/%d/%d\n",
			jobs_array[i]->job_id, jobs_array[i]->robot_number, jobs_array[i]->job_name,
			jobs_array[i]->current_lsc, jobs_array[i]->end_lsc, jobs_array[i]->job_flag,
			jobs_array[i]->t_stamp.hour, jobs_array[i]->t_stamp.minute, jobs_array[i]->t_stamp.day, jobs_array[i]->t_stamp.month, jobs_array[i]->t_stamp.year);

	}

	fclose(ftptemp);
	remove(jobs_db);
	rename(temp_db, jobs_db);

}

void set_job_completed(){

	int i, j =0;
	char c = 'y';
	printf("\nJobs List:\n");
	view_jobs_information();
	printf("\nSelect Job mark as complete\n");

			
		printf("\nEnter Job Number\n");
		scanf("\n%d", &i);

		while (jobs_array[j]->job_id != i) {
			if (j == job_count - 1) {
				++j;
				break;
		}
			j++;

		}
		if (j == job_count) {
			printf("Job Id does not exist\n");
		}
		else {
			jobs_array[j]->job_flag = 1;
			printf("Marked as complete\n");
		}

}

void sort_robots() {

	int i;
	struct robots **temp_s = (struct robots **)malloc(sizeof(struct robots *)*robot_count);

	for (i = 0; i < robot_count; i++) {

		temp_s[i] = (struct robots *)malloc(sizeof(struct robots));
						
		temp_s[i]->id_number = robots_array[i]->id_number;
		temp_s[i]->type = robots_array[i]->type;
		strcpy(temp_s[i]->name, robots_array[i]->name);
	}
	
	bubble_sort_robots(temp_s, robot_count);
	
	printf("\nGenerating report called Sorted_Robots_Report.txt\n");

	FILE *ftptemp = fopen("Sorted_Robots_Report.txt", "w");
	
	fprintf(ftptemp, "Sorted Robots Report\n\n");
	fprintf(ftptemp, "Id Number\tType Code\tType Name\n\n");
	
	for (i = 0; i < robot_count; i++) {
			
		fprintf(ftptemp, "%d\t\t%d\t\t%s\n", temp_s[i]->id_number, temp_s[i]->type, temp_s[i]->name);

	}

	fclose(ftptemp);
		
}

void bubble_sort_robots(struct robots **temp_s, int array_size) {

	int counter;

	for (counter = 0; counter < array_size - 1; counter++) {

		int counter_2;

		for (counter_2 = 0; counter_2 < (array_size - 1 - counter); counter_2++) {
			
			if (temp_s[counter_2]->type > temp_s[counter_2 + 1]->type) {

				struct robots *temp = temp_s[counter_2];

				temp_s[counter_2] = temp_s[counter_2+1];
				temp_s[counter_2 + 1] = temp;
				
			}
			
		}

	}

}

void bubble_sort_jobs(struct jobs **temp_s, int array_size) {

	int counter;

	for (counter = 0; counter < array_size - 1; counter++) {

		int counter_2;

		for (counter_2 = 0; counter_2 < (array_size - 1 - counter); counter_2++) {

			if (temp_s[counter_2]->t_stamp.year > temp_s[counter_2 + 1]->t_stamp.year) {

				struct jobs *temp = temp_s[counter_2];

				temp_s[counter_2] = temp_s[counter_2 + 1];
				temp_s[counter_2 + 1] = temp;
			
			}

			if (temp_s[counter_2]->t_stamp.year == temp_s[counter_2 + 1]->t_stamp.year && temp_s[counter_2]->t_stamp.month > temp_s[counter_2 + 1]->t_stamp.month) {

				struct jobs *temp = temp_s[counter_2];

				temp_s[counter_2] = temp_s[counter_2 + 1];
				temp_s[counter_2 + 1] = temp;

			}

			if (temp_s[counter_2]->t_stamp.year == temp_s[counter_2 + 1]->t_stamp.year && temp_s[counter_2]->t_stamp.month == temp_s[counter_2 + 1]->t_stamp.month && temp_s[counter_2]->t_stamp.day > temp_s[counter_2 + 1]->t_stamp.day) {

				struct jobs *temp = temp_s[counter_2];

				temp_s[counter_2] = temp_s[counter_2 + 1];
				temp_s[counter_2 + 1] = temp;

			}

			if (temp_s[counter_2]->t_stamp.year == temp_s[counter_2 + 1]->t_stamp.year && temp_s[counter_2]->t_stamp.month == temp_s[counter_2 + 1]->t_stamp.month && temp_s[counter_2]->t_stamp.day == temp_s[counter_2 + 1]->t_stamp.day && temp_s[counter_2]->t_stamp.hour > temp_s[counter_2 + 1]->t_stamp.hour) {

				struct jobs *temp = temp_s[counter_2];

				temp_s[counter_2] = temp_s[counter_2 + 1];
				temp_s[counter_2 + 1] = temp;

			}

			if (temp_s[counter_2]->t_stamp.year == temp_s[counter_2 + 1]->t_stamp.year && temp_s[counter_2]->t_stamp.month == temp_s[counter_2 + 1]->t_stamp.month && temp_s[counter_2]->t_stamp.day == temp_s[counter_2 + 1]->t_stamp.day && temp_s[counter_2]->t_stamp.hour == temp_s[counter_2 + 1]->t_stamp.hour && temp_s[counter_2]->t_stamp.minute > temp_s[counter_2 + 1]->t_stamp.minute) {

				struct jobs *temp = temp_s[counter_2];

				temp_s[counter_2] = temp_s[counter_2 + 1];
				temp_s[counter_2 + 1] = temp;

			}

		}

	}





}

void view_individual_job() {

	int i, j = 0;

	printf("\nSelect a Job to View by entering the job's ID Number\n");
	scanf("\n%d", &i);

	while (jobs_array[j]->job_id != i) {
			j++;
		}

	printf("\nJob Id\tJob Type\tDate Created\t\tCurrent Status\tAssigned Robot\tCurrent Sector Location\n\n");
	
	printf("%d\t%s\t%d:%d %d/%d/%d\t%s\t%d\t\t%d\n",
			jobs_array[j]->job_id, jobs_array[j]->job_name, 
			jobs_array[j]->t_stamp.hour, jobs_array[j]->t_stamp.minute, 
			jobs_array[j]->t_stamp.day,	jobs_array[j]->t_stamp.month, jobs_array[j]->t_stamp.year,
			jobs_array[j]->job_flag == 1 ? "Completed" : "Outstanding",
			jobs_array[j]->robot_number,
			jobs_array[j]->current_lsc);

}

void sort_jobs_by_date() {

	int i;
	struct jobs **temp_s = (struct jobs **)malloc(sizeof(struct jobs *)*job_count);

	for (i = 0; i < job_count; i++) {

		temp_s[i] = (struct jobs *)malloc(sizeof(struct jobs));

		temp_s[i]->job_id = jobs_array[i]->job_id;
		temp_s[i]->robot_number = jobs_array[i]->robot_number;
		strcpy(temp_s[i]->job_name, jobs_array[i]->job_name);
		temp_s[i]->current_lsc = jobs_array[i]->current_lsc;
		temp_s[i]->end_lsc = jobs_array[i]->end_lsc;
		temp_s[i]->job_flag = jobs_array[i]->job_flag;
		temp_s[i]->t_stamp.hour = jobs_array[i]->t_stamp.hour;
		temp_s[i]->t_stamp.minute = jobs_array[i]->t_stamp.minute;
		temp_s[i]->t_stamp.day = jobs_array[i]->t_stamp.day;
		temp_s[i]->t_stamp.month = jobs_array[i]->t_stamp.month;
		temp_s[i]->t_stamp.year = jobs_array[i]->t_stamp.year;

	}
		
	bubble_sort_jobs(temp_s, job_count);
	
	printf("\nGenerating report called Sorted_Jobs_Report.txt\n");

	FILE *ftptemp = fopen("Sorted_Jobs_Report.txt", "w");

	fprintf(ftptemp, "Sorted Jobs Report\n");
	fprintf(ftptemp, "\nJob Id\tRobot Number\tJob Name\tCurrent LSC\tEnd LSC\tFlag\tCreated Timestamp\n\n");

	for (i = 0; i < job_count; i++) {
		fprintf(ftptemp, "%d\t%d\t\t%s\t%d\t\t%d\t%d\t%d:%d %d/%d/%d\n",
			temp_s[i]->job_id, temp_s[i]->robot_number, temp_s[i]->job_name,
			temp_s[i]->current_lsc, temp_s[i]->end_lsc, temp_s[i]->job_flag,
			temp_s[i]->t_stamp.hour, temp_s[i]->t_stamp.minute, temp_s[i]->t_stamp.day, temp_s[i]->t_stamp.month, temp_s[i]->t_stamp.year);
	}
	
	fclose(ftptemp);

}

void view_jobs_by_robot() {
	int i, j;
	int robots[20] = { 0 };
	
	for (i = 0; i < job_count; i++) {
		++robots[(jobs_array[i]->robot_number)];
	}

	printf("\nRobot Number\tNumber of Jobs Currently Assigned\tJobs Assigned\n\n");

	for (i = 1; i < 20; i++) {
		if (robots[i] != 0) {
		printf("%d\t\t%d\t\t\t\t\t", i, robots[i]);
		
		for (j = 0; j < job_count; j++) {
			if (jobs_array[j]->robot_number == i) {
				printf("%d ", jobs_array[j]->job_id);
			}
					
		}
		printf("\n");
		
		
		
		}
	}


}

void recently_completed_delivery() {

	int i, j = 0;

	time_t curtime;
	struct tm *loctime;

	curtime = time(NULL);

	loctime = localtime(&curtime);

	printf("\nDeliveries completed less than 3 hours ago\n");
	printf("\nJob Id\tRobot Number\tJob Name\tCurrent LSC\tEnd LSC\tFlag\tCreated Timestamp\n\n");
		
	for (i = 0; i < job_count; ++i) {
		if (jobs_array[i]->robot_type == 20 && jobs_array[i]->job_flag == 1  && (loctime->tm_hour - jobs_array[i]->t_stamp.hour) <= 3) {

			printf("%d\t%d\t\t%s\t%d\t\t%d\t%d\t%d:%d %d/%d/%d\n",
				jobs_array[i]->job_id, jobs_array[i]->robot_number, jobs_array[i]->job_name,
				jobs_array[i]->current_lsc, jobs_array[i]->end_lsc, jobs_array[i]->job_flag,
				jobs_array[i]->t_stamp.hour, jobs_array[i]->t_stamp.minute, 
				jobs_array[i]->t_stamp.day, jobs_array[i]->t_stamp.month, jobs_array[i]->t_stamp.year);
	
		}
	}

}

