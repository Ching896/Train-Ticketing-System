#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <Windows.h>
#define MAX_TRAIN 6
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)
#pragma warning(disable:6262)
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

//Staff Information Module Structure
struct Department {
	char position[50];
	char department[50];
};

typedef struct {
	char staffID[7];
	char ic[15];
	char name[50];
	char email[50];
	struct Department currentDepartment[1000];
	char phoneNo[13];
}Staff;

typedef struct {
	char staffID[7];
	char password[50];
	char name[50];
}Admin;

//Member Information Module Structure
typedef struct {
	char name[50];
	char ic[15];
	char contactno[13];
	char gender;
}MemberDetail;

struct Member {
	char memberid[6];
	char email[30];
	char password[30];
	MemberDetail detail;
};

//Train Scheduling Module Structure
typedef struct {
	char origin[40];
	char destination[40];
	char trainId[8];
	int departureHrs, departureMin;
	int arrivalHrs, arrivalMin;
	int durationHrs, durationMin;
}TrainSchedule;

//Ticket Booking Module Structure
typedef struct {
	int day;
	int month;
	int year;
}Date;

struct bookingDetail {
	char bookingid[6];
	char memberid[6];
	char name[40];
	char ic[15];
	char email[30];
	int qtyadult;
	int qtychild;
	char typeseat;
	int seat;
	int availableSeat;
	TrainSchedule scheduleBook;
	Date departuredate;
};

struct PaymentDetail {
	char bookingid[6];
	double amount;
	char accountno[20];
	Date pdate;
	int hrs;
	int min;
};

Admin detail[100];
Staff info[1000];
TrainSchedule schedule;

//Menu
void trainlogo();
void systemlogo();
void memberlogo();
void stafflogo();
int systemMainMenu();

//Back Menu
void backMenu();

//Staff and Member Share Function
int readMember(struct Member member[], int* lastindex);
int checkEmailFormat(char* email);
void checkPhoneNoFormat(char* phoneNo, int* validPhone);
void checkICFormat(char* ic, int* validIC);

//Member and Ticket Booking Share Function
void readBookingRecord(struct bookingDetail booking[], int* totalBook);

//Staff Module Function
int staffArray();
int adminArray();
void capital_StaffID_First_Two_characters(char staffID[7]);
void checkStaffIDUnique(char staffID[7], int* unique);
void checkStaffIDValid(char staffID[7], int* valid);
void findFunction(char staffID[7], int* selectedStaff, char* decision1, char* decision2);
char repeat();
void displayData(int count);
void inputStaffData(char name[50], char gmail[50], char department[50], char position[50], char phoneNo[13]);
int selectMenu(int currentAdmin);
int loginFunction(int* match);
void staffMainMenu();
char doubleConfirm();

void addFunction();
void searchFunction();
void modifyFunction();
void displayStaffFunction();
void deleteFunction();
void adminChangePassword(int currentAdmin);


//Member Module Function
int memberMainMenu();
int addMember(struct Member member[]);
int displayNewMember(char* name, char* email, char* password, char* ic, char* phNo, char gender);
void modifyMemberFile(struct Member member[], int lastindex);
int loginMember(struct Member member[], int* memberLogin);
int compareEmailPw(struct Member member[], char* email, char* pw);
int resetPwMember(struct Member member[], int* pw);
//member menu
int memberMenu(struct Member member[], int current);
int searchBookingDetail(struct Member member[], int current);
int displayBookingHistory(struct Member member[], int current);
//member account details menu
int memberAccDetailMenu(struct Member member[], int current);
void displayMemberDetail(struct Member member[], int current);
void modifyMemberDetail(struct Member member[], int current);
void getMemberEmail(char* email, int lastindex);
void compareEmail(struct Member member[], char* email, int* cmpEmail, int* sameIndex);
void getMemberIC(char* ic, int lastindex);
void compareIC(struct Member member[], char* ic, int* cmpIC, int* sameIndex);
void deleteMember(struct Member member[], int current);


//Train Scheduling Module Function
void calculateDuration(int departureHrs, int departureMin, int arrivalHrs, int arrivalMin, int* durationHrs, int* durationMin);
int validateTime(int hrs, int min);
//for staff
int trainMainStaff();
void displaySchedule(int who);
void addSchedule();
void modifySchedule();
void deleteSchedule();
//for member
int trainMainMember();
void viewDetails();
void searchSchedule();

//Train module and Booking module share function
void displayclassP();
void displayclassG();
void displayclassS();

//Booking Module
int bookingMenu(struct Member member[], int current);
void searchSelection(struct Member member[], int current);
void addBooking(struct Member member[], int current, TrainSchedule tempBook, struct bookingDetail bd);
void seatSelection(char typeseat, int qtyadult, int qtychild, int* totalqty);
void payment(char* bookingid, double amount);
void randomId(char* bookingID);
void displayNewBooking(struct bookingDetail currentBook, int totalqty);
void readBookingRecord(struct bookingDetail booking[], int* totalBooking);
void modifyBookingRecord(struct Member member[], int current);
void cancelBooking(struct Member member[], int current);
//booking report function staff
void dailysaleReport();
void readpayment(struct PaymentDetail payment[], int* totalRecord);
void todayReport();
void otherReport();

int seatchoose(struct bookingDetail tempBooking, TrainSchedule tempBook);
double calPayment(char typeseat, int qtyadult, int qtychild);
int inCurrentBooking(int seatNumber, int currentSeats[]);
int isValidName(const char* str);
int isValidNum(const char* str);
int isAlpha(char c);
int isDigit(char ch);


void main() {
	systemMainMenu();
	system("pause");
}

void trainlogo() {
	int i, j;
	//Blue Color 
	printf("\033[0;34m");
	for (i = 0; i < 30; ++i) { //Move the train for 30 times
		system("cls");
		// Print the train
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("___________   _______________________________________^__\n");
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf(" ___   ___ |||  ___   ___   ___    ___ ___  |   __  ,----\\\n");
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("|   | |   |||| |   | |   | |   |  |   |   | |  |  | |_____\\\n");
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("|___| |___|||| |___| |___| |___|  | O | O | |  |  |        \\\n");
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("           |||                    |___|___| |  |__|         )\n");
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("___________|||______________________________|______________/\n");
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("           |||                                        /--------\n");
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		printf("-----------'''---------------------------------------'\n");
		printf("\n");
		Sleep(50); 
	}
	printf("%s", RESET);
	printf("\n");
	printf("\t\t\t\t  _  __  __  __   ____                    _       _ \n");
	Sleep(70);
	printf("\t\t\t\t | |/ / |  \\/  | |  _ \\    __ _   _ __   (_)   __| |\n");
	Sleep(80);
	printf("\t\t\t\t | ' /  | |\\/| | | |_) |  / _` | | '_ \\  | |  / _` |\n");
	Sleep(70);
	printf("\t\t\t\t | . \\  | |  | | |  _ <  | (_| | | |_) | | | | (_| |\n");
	Sleep(70);
	printf("\t\t\t\t |_|\\_\\ |_|  |_| |_| \\_\\  \\__,_| | .__/  |_|  \\__,_|\n");
	Sleep(70);
	printf("\t\t\t\t                                 |_|                 \n");
	Sleep(70);

	printf("\n\n\n\t\t\t\t\t\tWELCOME TO KMRapid!!!!\n\n");
	Sleep(3000);

}

void systemlogo() {
	
	printf("\033[0;34m");//Blue Color
	printf("___________   _______________________________________^__");
	printf("\n ___   ___ |||  ___   ___   ___    ___ ___  |   __  ,----\\");
	printf("\n|   | |   |||| |   | |   | |   |  |   |   | |  |  | |_____\\");
	printf("\n|___| |___|||| |___| |___| |___|  | O | O | |  |  |        \\");
	printf("\n           |||                    |___|___| |  |__|         )");
	printf("\n___________|||______________________________|______________/");
	printf("\n           |||                                        /--------");
	printf("\n-----------'''---------------------------------------'");
	printf("\n\n");
	printf("%s", RESET);//RESET color

	printf("  _  __  __  __   ____                    _       _ \n");
	printf(" | |/ / |  \\/  | |  _ \\    __ _   _ __   (_)   __| |\n");
	printf(" | ' /  | |\\/| | | |_) |  / _` | | '_ \\  | |  / _` |\n");
	printf(" | . \\  | |  | | |  _ <  | (_| | | |_) | | | | (_| |\n");
	printf(" |_|\\_\\ |_|  |_| |_| \\_\\  \\__,_| | .__/  |_|  \\__,_|\n");
	printf("                                 |_|                 \n");

	printf("\nKMRapid  Main Menu\n");
}

void stafflogo() {
	printf("  _  __  __  __   ____      ____    _              __    __ \n");
	printf(" | |/ / |  \\/  | |  _ \\    / ___|  | |_    __ _   / _|  / _|\n");
	printf(" | ' /  | |\\/| | | |_) |   \\___ \\  | __|  / _` | | |_  | |_ \n");
	printf(" | . \\  | |  | | |  _ <     ___) | | |_  | (_| | |  _| |  _|\n");
	printf(" |_|\\_\\ |_|  |_| |_| \\_\\   |____/   \\__|  \\__,_| |_|   |_|  \n\n");
}

void memberlogo() {
	system("cls");
	printf("  _  __  __  __   ____      __  __                   _                 \n");
	printf(" | |/ / |  \\/  | |  _ \\    |  \\/  |  ___  _ __ ___  | |__    ___  _ __ \n");
	printf(" | ' /  | |\\/| | | |_) |   | |\\/| | / _ \\| '_ ` _ \\ | '_ \\  / _ \\| '__|\n");
	printf(" | . \\  | |  | | |  _ <    | |  | ||  __/| | | | | || |_) ||  __/| |   \n");
	printf(" |_|\\_\\ |_|  |_| |_| \\_\\   |_|  |_| \\___||_| |_| |_||_.__/  \\___||_|   \n\n\n");
}

int systemMainMenu() {
	int choice;
		trainlogo();
	do {
		system("cls");
		systemlogo();
		printf("\n1. Staff");
		printf("\n2. Member");
		printf("\n3. Exit");
		printf("\n\nEnter Choice > ");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			system("cls");
			staffMainMenu();
			break;
		case 2:
			memberMainMenu();
			break;
		case 3:
			exit(0);
			break;
		default:
			rewind(stdin);
			break;
		}
	} while (choice != 3);
}

//Staff Module
//Function to read staffs' file 
int staffArray() {
	FILE* staff = fopen("staff.txt", "r");

	if (staff == NULL) {
		printf("CANNOT OPEN!!");
		exit(-1);
	}

	//Read text file into structure
	int i = 0;
	while (fscanf(staff, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", info[i].staffID, info[i].name,
		info[i].email, info[i].ic, info[i].currentDepartment[i].department, info[i].currentDepartment[i].position, info[i].phoneNo) != EOF) {
		i++;
	}
	fclose(staff);

	return i;
}

//Function to read admins' file 
int adminArray() {
	FILE* admin = fopen("administrator.txt", "r");

	if (admin == NULL) {
		printf("CANNOT OPEN!!");
		exit(-1);
	}

	//Read text file into structure
	int i = 0;
	while (fscanf(admin, "%[^|]|%[^|]|%[^\n]\n", detail[i].staffID, detail[i].password, detail[i].name) != EOF) {
		i++;
	}
	fclose(admin);

	return i;
}

//Function to capitalize the first two character of staffID
void capital_StaffID_First_Two_characters(char staffID[7]) {
	staffID[0] = toupper(staffID[0]);
	staffID[1] = toupper(staffID[1]);
}

//Function to check the staffID exists in text file or not
void checkStaffIDUnique(char staffID[7], int* unique) {
	int totalStaff = staffArray();
	int found = 0;
	int a = 0;
	int isUnique = 1;

	//Loop to compare data enter by user and text file 
	while (a < totalStaff) {
		if (strcmp(staffID, info[a].staffID) == 0) {
			found = 1;
			break;
		}
		a++;
	}
	if (found) {
		isUnique = 0;
		printf("The staffID is exists. Please enter a new staffID!!!\n");
	}
	*unique = isUnique;
}

//Function to check the staffID format
void checkStaffIDValid(char staffID[7], int* valid) {
	int totalStaff = staffArray();
	int isValid = 1;

	// Check if the staff ID starts with "ST" or "st"
	if (staffID[0] == 'S' && staffID[1] == 'T') {

		// Check if the remaining characters are digits and the length is within the allowed range
		int length = strlen(staffID);
		if (length == 6) {
			for (int i = 2; i < length; i++) {
				if (!isdigit(staffID[i])) {
					// Non-digit character found, invalid
					isValid = 0;
					break;
				}
			}
		}
		else {
			isValid = 0;
		}
	}
	else {
		isValid = 0;
	}
	*valid = isValid;
}

//Function to find the match data of staff from text file 
void findFunction(char staffID[7], int* selectedStaff, char* decision1, char* decision2) {
	int totalStaff = staffArray();
	int found = 0;
	int a = 0;

	capital_StaffID_First_Two_characters(staffID);

	//Loop to compare data enter by user and text file 
	while (a < totalStaff) {
		if (strcmp(staffID, info[a].staffID) == 0) {
			found = 1;
			break;
		}
		a++;
	}
	*decision1 = ' ';
	*decision2 = ' ';

	if (found) {
		printf("\n%-10s %-15s %-20s %-15s  %-30s%-20s %-15s", "StaffID", "Name", "Email", "IC", "Department", "Position", "Phone Number");
		printf("\n----------------------------------------------------------------------------------------------------------------------------------\n");
		displayData(a);
		printf("\n\n");
		do {
			*decision1 = doubleConfirm();
			printf("\n");
			if (*decision1 == 'N') {
				*decision2 = repeat();
				if (decision2 == 'Y') {
					system("cls");
					stafflogo();
				}
			}
			*selectedStaff = a;
		} while (*decision1 != 'N' && *decision1 != 'Y');
	}

	else {
		printf("\nNo data found!\n\n");
		*decision2 = repeat();
		if (*decision2 == 'N') {
			printf("\n");
			backMenu();
		}
	}
}

//Function ask user want do again or not
char repeat() {
	char decision;
	do {
		printf("Do you want to enter again? (Y/N) > ");
		rewind(stdin);
		scanf("%c", &decision);
		decision = toupper(decision);
	} while (decision != 'N' && decision != 'Y');
	return decision;
}

//Function print data from array
void displayData(int count) {
	printf("%-10s", info[count].staffID);
	printf(" %-15s", info[count].name);
	printf(" %-20s", info[count].email);
	printf(" %-15s", info[count].ic);
	printf("  %-30s", info[count].currentDepartment[count].department);
	printf("%-20s", info[count].currentDepartment[count].position);
	printf(" %-15s", info[count].phoneNo);
}

//Prompt user input and validate
void inputStaffData(char name[50], char email[50], char department[50], char position[50], char phoneNo[13]) {
	int validEmail;
	int validPhNo;

	printf("%-12s : ", "Name");
	rewind(stdin);
	scanf("%[^\n]", name);

	do {
		printf("%-12s : ", "Email");
		rewind(stdin);
		scanf("%[^\n]", email);
		validEmail = checkEmailFormat(email);

		if (validEmail != 1) {
			printf("Please enter correct email!!\n");
		}
	} while (validEmail != 1);

	printf("%-12s : ", "Department");
	rewind(stdin);
	scanf("%[^\n]", department);

	printf("%-12s : ", "Position");
	rewind(stdin);
	scanf("%[^\n]", position);

	do {
		printf("%-12s : ", "Phone number");
		rewind(stdin);
		scanf("%[^\n]", phoneNo);
		checkPhoneNoFormat(phoneNo, &validPhNo);
		if (validPhNo != 1) {
			printf("Invalid Contact Number!\n");
			printf("Contact Number format > 0XX-XXXXXXX\n");
		}
	} while (validPhNo != 1);
}

//Double confirm input staff data
char doubleConfirm() {
	char sure;
	do {
		printf("Are you sure all correct? (Y/N) > ");
		rewind(stdin);
		scanf("%c", &sure);
		sure = toupper(sure);
	} while (sure != 'N' && sure != 'Y');
	return sure;
}

//Function to add new data of staff to text file
void addFunction() {
	FILE* staff;
	char condition, decision = ' ';
	char staffID[7];
	char staffIDValid[7] = " ";
	int valid;
	int unique = 0;
	int validIC;

	system("cls");
	stafflogo();
	printf("\nAdd New Staff\n\n");


	do {
		int success = 0;
		int totalStaff = staffArray();
		int count = totalStaff++;

		//Open file for adding new staff data
		if ((staff = fopen("staff.txt", "a")) == NULL) {
			printf("CANNOT OPEN!!");
			exit(-1);
		}

		//Loop to ensure staff ID format is correct and does not exists in text file
		do {
			do {
				printf("%-12s : ", "Staff ID");
				rewind(stdin);
				scanf("%[^\n]", staffID);
				capital_StaffID_First_Two_characters(staffID);
				checkStaffIDValid(staffID, &valid);
				if (valid == 1) {
					strcpy(staffIDValid, staffID);
					checkStaffIDUnique(staffIDValid, &unique);
					break;
				}
				else {
					system("cls");
					stafflogo();
					printf("\nAdd New Staff \n");
					printf("\nInvalid staffID format. Please enter a correct staffID format!!\n");
				}

			} while (valid == 0);

			if (unique == 1) {
				strcpy(info[count].staffID, staffIDValid);
				break;
			}
		} while (unique == 0);

		//Loop to ensure ic format is correct
		do {
			printf("%-12s : ", "IC");
			rewind(stdin);
			scanf("%[^\n]", info[count].ic);
			checkICFormat(info[count].ic, &validIC);
			if (validIC != 1) {
				printf("Invalid IC Number!\n");
				printf("IC Number format > XXXXXX-XX-XXXX\n");
			}
		} while (validIC != 1);

		inputStaffData(info[count].name, info[count].email, info[count].currentDepartment[count].department,
			info[count].currentDepartment[count].position, info[count].phoneNo);

		printf("\n");
		condition = doubleConfirm();

		if (condition == 'N') {
			printf("\n");
			decision = repeat();
		}

		else {
			//write data into text file
			fprintf(staff, "%s|%s|%s|%s|%s|%s|%s\n", info[count].staffID, info[count].name, info[count].email, info[count].ic,
				info[count].currentDepartment[count].department, info[count].currentDepartment[count].position, info[count].phoneNo);
			printf("\n%sCongratulation!Your record have been added successfully%s\n\n", GREEN, RESET);
			decision = repeat();
			if (decision == 'Y') {
				system("cls");
				stafflogo();
				printf("\nAdd New Staff\n\n");
			}
		}
		fclose(staff);
	} while (toupper(decision) == 'Y');
}

//Function to search the wanted data of staff form text file
void searchFunction() {
	int totalStaff = staffArray();
	char staffIDToSearch[7];
	char decision;
	int valid;

	system("cls");
	stafflogo();
	printf("\nSearch Staff\n");

	do {
		int a = 0;
		int found = 0;
		decision = ' ';

		//let user enter staff data that she/he ewant to search
		do {
			printf("\nEnter staff ID to search       > ");
			rewind(stdin);
			scanf("%[^\n]", staffIDToSearch);
			capital_StaffID_First_Two_characters(staffIDToSearch);
			checkStaffIDValid(staffIDToSearch, &valid);
			if (valid == 1) {
				break;
			}
			else {
				system("cls");
				stafflogo();
				printf("\nSearch Staff \n");
				printf("\nInvalid staffID format. Please enter a correct staffID format!!\n");
			}
		} while (valid == 0);

		capital_StaffID_First_Two_characters(staffIDToSearch);

		//compare with data from text file
		do {
			if (strcmp(staffIDToSearch, info[a].staffID) == 0) {
				printf("\n%-10s %-15s %-20s %-15s  %-30s%-20s %-15s", "StaffID", "Name", "Email", "IC", "Department", "Position", "Phone Number");
				printf("\n----------------------------------------------------------------------------------------------------------------------------------\n");
				displayData(a);
				printf("\n\n");
				found = 1;
				break;
			}
			a++;
		} while (a < totalStaff);

		if (!found) {
			printf("\nNo data found!\n\n");
		}
		decision = repeat();
		if (decision == 'Y') {
			system("cls");
			stafflogo();
			printf("\nSearch Staff \n");
		}
	} while (decision == 'Y');
}

//Function to modify data of staff which already exists in text file
void modifyFunction() {
	FILE* originalFile;
	FILE* newFile;
	char staffIDKeyIn[7];
	int staffModify;
	char choice1, choice2, choice3;
	char decision;
	system("cls");
	stafflogo();
	do {
		originalFile = fopen("staff.txt", "r");
		newFile = fopen("staff_temp.txt", "w");
		if (originalFile == NULL || newFile == NULL) {
			printf("CANNOT OPEN!!");
			exit(-1);
		}

		//save data into originalFile
		int i = 0;
		while (fscanf(originalFile, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", info[i].staffID, info[i].name, info[i].email, info[i].ic,
			info[i].currentDepartment[i].department, info[i].currentDepartment[i].position, info[i].phoneNo) != EOF) {
			i++;
		}
		fclose(originalFile);

		int count = 0;
		decision = ' ';

		do {
			choice2 = ' ';
			printf("\nEnter staff ID to modify: ");
			rewind(stdin);
			scanf("%s", &staffIDKeyIn);
			findFunction(staffIDKeyIn, &staffModify, &choice1, &choice2);
			if (choice1 == 'Y') {
				break;
			}
		} while (choice2 == 'Y');

		//save new data for the staff
		if (choice1 == 'Y') {
			inputStaffData(info[staffModify].name, info[staffModify].email, info[staffModify].currentDepartment[staffModify].department,
				info[staffModify].currentDepartment[staffModify].position, info[staffModify].phoneNo);

			printf("\n");
			choice3 = doubleConfirm();
			printf("\n");

			if (choice3 == 'N') {
				decision = repeat();
				system("cls");
				stafflogo();
			}
			else {
				do {
					//printf whole new structure into newFile  
					fprintf(newFile, "%s|%s|%s|%s|%s|%s|%s\n", info[count].staffID, info[count].name, info[count].email, info[count].ic,
						info[count].currentDepartment[count].department, info[count].currentDepartment[count].position, info[count].phoneNo);
					count++;
				} while (count < i);
				printf("\n%sStaff data modify successfully.%s\n\n", GREEN, RESET);
				fclose(newFile);
				remove("staff.txt");
				rename("staff_temp.txt", "staff.txt");
				decision = repeat();
				if (decision == 'Y') {
					system("cls");
					stafflogo();
				}
			}
		}
		else {
			fclose(newFile);
			remove("staff_temp.txt");
		}

	} while (decision == 'Y');
	fclose(newFile);
	system("cls");
	stafflogo();
}

//Function to display the wanted data of staff form text file
void displayStaffFunction() {
	int totalStaff = staffArray();
	int i;
	system("cls");
	stafflogo();
	printf("\n\nAll Staff of KMRapid\n");
	printf("\n%-10s %-15s %-20s %-15s  %-30s%-20s %-15s", "StaffID", "Name", "Email", "IC", "Department", "Position", "Phone Number");
	printf("\n----------------------------------------------------------------------------------------------------------------------------------");
	for (i = 0; i < totalStaff; i++) {
		printf("\n");
		displayData(i);
	}
	printf("\n\n\nSuccess display %d staff information\n\n", i);
	backMenu();
}

//Function to delete data of staff which already exists in text file
void deleteFunction() {
	FILE* originalFile;
	FILE* newFile;

	char staffIDKeyIn[7];
	char decision1, decision2, decision3;
	int staffDelete;

	system("cls");
	stafflogo();
	printf("\nDelete Staff\n");
	do {
		decision3 = ' ';
		int count = 0;
		originalFile = fopen("staff.txt", "r");
		newFile = fopen("staff_temp.txt", "w");

		if (originalFile == NULL || newFile == NULL) {
			printf("CANNOT OPEN!!");
			exit(-1);
		}

		//Loop if want to enter again
		int i = 0;
		while (fscanf(originalFile, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", info[i].staffID, info[i].name, info[i].email, info[i].ic,
			info[i].currentDepartment[i].department, info[i].currentDepartment[i].position, info[i].phoneNo) != EOF) {
			i++;
		}
		fclose(originalFile);

		do {
			decision2 = ' ';
			printf("\nEnter staff ID to delete : ");
			rewind(stdin);
			scanf("%s", &staffIDKeyIn);
			findFunction(staffIDKeyIn, &staffDelete, &decision1, &decision2);
			//For condition that the staff data is expected
			if (decision1 == 'Y') {
				break;
			}
		} while (decision2 == 'Y');

		//For condition that the staff data is expected
		if (decision1 == 'Y') {
			for (int count = 0; count <= i - 1; count++) {
				if (count == staffDelete) {
					continue;
				}
				fprintf(newFile, "%s|%s|%s|%s|%s|%s|%s\n", info[count].staffID, info[count].name, info[count].email, info[count].ic,
					info[count].currentDepartment[count].department, info[count].currentDepartment[count].position, info[count].phoneNo);
			}

			printf("%sStaff data delete successfully.%s\n\n", GREEN, RESET);
			fclose(newFile);
			remove("staff.txt");
			rename("staff_temp.txt", "staff.txt");
			decision3 = repeat();
		}

		//For condition data display not expected and dont want to enter data again
		else {
			fclose(newFile);
			remove("staff_temp.txt");
		}

		if (decision3 == 'Y') {
			system("cls");
			stafflogo();
			printf("\nDelete Staff\n");
		}

	} while (decision3 == 'Y');
	fclose(newFile);
}

//Function for staff to login before make any action
int loginFunction(int* match) {
	int totalAdmin = adminArray();
	char staffID[7];
	char password[50];
	char login;
	int currentAdmin;
	int valid;
	int isMatch;
	int found;

	do {
		stafflogo();
		printf("\nStaff Login\n");
		currentAdmin = 0;
		isMatch = 0;
		login = ' ';
		found = 0;
		do {
			printf("\nEnter [%s0%s] to back to menu", RED, RESET);
			printf("\nPlease enter your staffID : ");
			rewind(stdin);
			scanf("%[^\n]", staffID);

			if (strcmp(staffID, "0") == 0) {
				system("cls");
				return;
			}

			capital_StaffID_First_Two_characters(staffID);
			checkStaffIDValid(staffID, &valid);
			if (valid == 1) {
				break;
			}
			else {
				system("cls");
				stafflogo();
				printf("\nStaff Login\n");
				printf("\nInvalid staffID format. Please enter a correct staffID format!!\n");
			}
		} while (valid == 0);

		capital_StaffID_First_Two_characters(staffID);

		printf("Please enter you password : ");
		rewind(stdin);
		scanf("%s", &password);

		//For login success condition
		for (int b = 0; b <= totalAdmin; b++) {
			if (strcmp(staffID, detail[b].staffID) == 0) {
				found = 1;
				if (strcmp(password, detail[b].password) == 0) {
					isMatch = 1;
					currentAdmin = b;
					break;
				}
			}
		}

		//For login failed condition
		if (!isMatch || !found) {
			printf("Sorry your ID or PASSWORD is incorrect!!\n");
			do {
				printf("\nDo you want to login again? (Y/N) > ");
				rewind(stdin);
				scanf(" %c", &login);
				login = toupper(login);
				printf("\n");
			} while (login != 'Y' && login != 'N');
		}
		if (login == 'Y') {
			system("cls");
		}
	} while (login == 'Y');
	*match = isMatch;
	return currentAdmin;
}

//Function for admin to her/his change password
void adminChangePassword(int currentAdmin) {
	FILE* originalFile = fopen("administrator.txt", "r");
	FILE* newFile = fopen("administrator_temp.txt", "w");
	if (originalFile == NULL || newFile == NULL) {
		printf("CANNOT OPEN!!");
		exit(-1);
	}
	int i = 0;
	while (fscanf(originalFile, "%[^|]|%[^|]|%[^\n]\n", detail[i].staffID, detail[i].password, detail[i].name) != EOF) {
		i++;
	}
	fclose(originalFile);

	char sure1, sure2;
	int total = 0;

	system("cls");
	stafflogo();
	printf("\nChange Admin Password\n");

	do {
		sure2 = ' ';
		sure1 = ' ';
		printf("\nPlease enter the new password that you want to change : ");
		rewind(stdin);
		scanf("%s", &detail[currentAdmin].password);

		do {
			printf("\nAre you sure this %s%s%s is the new password that you would like to change? (Y/N) > ", RED, detail[currentAdmin].password, RESET);
			rewind(stdin);
			scanf("%c", &sure1);
			sure1 = toupper(sure1);
		} while (sure1 != 'N' && sure1 != 'Y');

		//For user confirm to change password condition
		if (sure1 == 'Y') {
			do {
				fprintf(newFile, "%s|%s|%s\n", detail[total].staffID, detail[total].password, detail[total].name);
				total++;
			} while (total < i);

			fclose(newFile);
			remove("administrator.txt");
			rename("administrator_temp.txt", "administrator.txt");
			printf("\n%sAdmin password modify successfully.%s\n", GREEN, RESET);
		}

		//If not confirm ask user want to change again or not
		else {
			printf("\n");
			sure2 = repeat();
		}
		if (sure2 == 'Y') {
			system("cls");
			stafflogo();
			printf("\nChange Admin Password\n");
		}
	} while (sure2 == 'Y');
	fclose(newFile);

	printf("\n");
	backMenu();
}

//Function get menu option
int selectMenu(int currentAdmin) {
	int option = 0;
	int validInput;
	int totalAdmin = adminArray();

	system("cls");
	stafflogo();
	printf("\nLogin successfully!! Welcome back %s!!\n", detail[currentAdmin].name);


	printf("\n1. Add Staff Info\n");
	printf("2. Search Staff Info\n");
	printf("3. Modify Staff Info\n");
	printf("4. Delete Staff Info\n");
	printf("5. Display Staff Info\n");
	printf("6. Change Password\n");
	printf("7. Train Schedule\n");
	printf("8. Generate Daily Sales Report\n");
	printf("0. Log out\n");


	do {
		printf("\nWhich function you want to use > ");
		validInput = scanf("%d", &option) == 1;
		if (!validInput) {
			printf("Please enter a number!\n");
			while (getchar() != '\n');
		}
	} while (!validInput);

	return option;
}

//Function call function after get menu option
void staffMainMenu() {
	int match;
	int currentAdmin = loginFunction(&match);
	int option;

	do {
		//If login in success then can do action
		if (match == 1) {
			option = selectMenu(currentAdmin);
			switch (option) {
			case 0:
				break;
			case 1:
				addFunction();
				break;
			case 2:
				searchFunction();
				break;
			case 3:
				modifyFunction();
				break;
			case 4:
				deleteFunction();
				break;
			case 5:
				displayStaffFunction();
				break;
			case 6:
				adminChangePassword(currentAdmin);
				break;
			case 7:
				trainMainStaff();
				break;
			case 8:
				dailysaleReport();
				break;
			default:
				system("cls");
				printf("Please enter a valid option!!\n");
				break;
			}
		}
		else {
			break;
		}
	} while (option != 0);
}

//Time Schedule Module of Staff
//menu for staff
int trainMainStaff() {
	int option;
	int staff = 1;
	system("cls");
	do {
		stafflogo();
		printf("\nKMR Train Schedule\n");
		printf("\n1.Display Daily Schedule\n");
		printf("2.Add New Schedule\n");
		printf("3.Modify Existing Schedule (Update)\n");
		printf("4.Delete Schedule\n");
		printf("0.Back\n");

		printf("\nEnter your option > ");
		scanf("%d", &option);

		switch (option) {
		case 0:
			system("cls");
			stafflogo();
			return;
			break;
		case 1:
			displaySchedule(staff);
			break;
		case 2:
			system("cls");
			addSchedule();
			break;
		case 3:
			system("cls");
			modifySchedule();
			break;
		case 4:
			system("cls");
			deleteSchedule();
			break;
		default:
			rewind(stdin);
			system("cls");
			break;
		}
	} while (option != 0);
	return 0;
}

//calculate duration for route
void calculateDuration(int departureHrs, int departureMin, int arrivalHrs, int arrivalMin, int* durationHrs, int* durationMin) {
	int depMin = departureHrs * 60 + departureMin;
	int arrMin = arrivalHrs * 60 + arrivalMin;
	int durationTotalMin = arrMin - depMin;

	if (durationTotalMin < 0) {
		durationTotalMin += 24 * 60;
	}
	*durationHrs = durationTotalMin / 60;
	*durationMin = durationTotalMin % 60;
}

//validation for departure time and arrival time
int validateTime(int hrs, int min) {
	if (hrs < 0 || hrs > 23 || min < 0 || min > 59) {
		printf("Invalid Time! Please re-enter the time!!! \n");
		return 0;
	}
	return 1;
}

//display whole daily schedule for staff and member
void displaySchedule(int who) {

	FILE* sd = fopen("train_schedule.dat", "rb");
	if (sd == NULL) {
		printf("Error: Unable to open the file!!!\n");
		exit(-1);
	}
	// who == 1 == Staff 
	// who == 2 == Member
	if (who == 1) {
		system("cls");
		stafflogo();
	}
	else {
		memberlogo();
	}

	printf("\n\n%-15s %-15s %-10s %-15s%-15s%-10s\n", "Origin", "Destination", "Train ID", "Departure", "Arrival", "Duration");
	printf("--------------------------------------------------------------------------------------------\n");

	while (fread(&schedule, sizeof(TrainSchedule), 1, sd) == 1) {
		printf("%-15s %-15s   %-10s %02d:%02d\t   %02d:%02d\t%d hours %d minutes\n",
			schedule.origin, schedule.destination, schedule.trainId, schedule.departureHrs,
			schedule.departureMin, schedule.arrivalHrs, schedule.arrivalMin,
			schedule.durationHrs, schedule.durationMin);
	}
	printf("\n\nWhole schedule is shown!!!\n\n");
	fclose(sd);
	backMenu();
	// who == 1 == Staff 
	// who == 2 == Member
	if (who == 2) {
		memberlogo();
	}
}

void backMenu() {
	char back;
	do {
		printf("Back to Menu (Y) > ");
		rewind(stdin);
		scanf("%c", &back);
	} while (toupper(back) != 'Y');
	system("cls");
}

//append more route
void addSchedule() {
	FILE* sd = fopen("train_schedule.dat", "ab");
	if (sd == NULL) {
		printf("Error: Unable to open the file!!!\n");
		exit(-1);
	}

	stafflogo();
	printf("\nAdd Train Schedule\n\n");

	char option;
	do {
		printf("Add new schedule (Y/N): ");
		rewind(stdin);
		scanf(" %c", &option);
		printf("\n");
		option = toupper(option);
		if (option == 'Y') {
			printf("Origin: ");
			rewind(stdin);
			scanf("%[^\n]", schedule.origin);

			printf("Destination: ");
			rewind(stdin);
			scanf("%[^\n]", schedule.destination);

			printf("Train ID: ");
			rewind(stdin);
			scanf("%[^\n]", schedule.trainId);

			// Departure Time Input & Validation Loop
			do {
				printf("Departure Time (HH:MM): ");
				scanf("%d:%d", &schedule.departureHrs, &schedule.departureMin);
			} while (!validateTime(schedule.departureHrs, schedule.departureMin));

			// Arrival Time Input & Validation Loop
			do {
				printf("Arrival Time (HH:MM): ");
				scanf("%d:%d", &schedule.arrivalHrs, &schedule.arrivalMin);
			} while (!validateTime(schedule.arrivalHrs, schedule.arrivalMin));

			int durationHrs, durationMin;
			calculateDuration(schedule.departureHrs, schedule.departureMin, schedule.arrivalHrs, schedule.arrivalMin, &durationHrs, &durationMin);
			schedule.durationHrs = durationHrs;
			schedule.durationMin = durationMin;
			fwrite(&schedule, sizeof(TrainSchedule), 1, sd);
			printf("\n%sSchedule added successfully!%s\n\n", GREEN, RESET);
		}
	} while (option == 'Y');
	fclose(sd);
	backMenu();
}

//modify schedule (update new time or route)
void modifySchedule() {
	char choice;
	stafflogo();
	printf("\nModify Train Schedule\n\n");
	do {
		TrainSchedule timetable[50];
		char inputTrainId[8];
		int count = 0, found = -1;

		FILE* target;
		target = fopen("train_schedule.dat", "rb");
		if (target == NULL) {
			printf("Error: Unable to open the file for modifying!!!\n");
			exit(-1);
		}
		while (fread(&timetable[count], sizeof(TrainSchedule), 1, target)) {
			count++;
		}
		fclose(target);

		printf("Enter Train ID: ");
		rewind(stdin);
		scanf("%[^\n]", inputTrainId);

		for (int i = 0; i < count; i++) {
			if (strcmp(inputTrainId, timetable[i].trainId) == 0) {
				printf("\n\n%-15s %-15s %-10s %-15s%-15s%-10s\n", "Origin", "Destination", "Train ID", "Departure", "Arrival", "Duration");
				printf("--------------------------------------------------------------------------------------------\n");
				printf("%-15s %-15s   %-10s %02d:%02d\t   %02d:%02d\t%d hours %d minutes\n",
					timetable[i].origin, timetable[i].destination, timetable[i].trainId, timetable[i].departureHrs,
					timetable[i].departureMin, timetable[i].arrivalHrs, timetable[i].arrivalMin,
					timetable[i].durationHrs, timetable[i].durationMin);
				found = i;
				break;
			}
		}
		if (found == -1) {
			printf("\nTrain ID not found!\n");
		}
		else {
			int option;
			printf("\nWhat do you want to modify?\n");
			printf("1.Origin\n");
			printf("2.Destination\n");
			printf("3.Departure Time\n");
			printf("4.Arrival Time\n");
			printf("Enter your option: \n\n");
			scanf("%d", &option);

			switch (option) {
			case 1:
				printf("Enter new Origin: ");
				rewind(stdin);
				scanf("%[^\n]", timetable[found].origin);
				break;
			case 2:
				printf("Enter new Destination: ");
				rewind(stdin);
				scanf("%[^\n]", timetable[found].destination);
				break;
			case 3:
				do {
					printf("Enter new Departure Time (HH:MM): ");
					scanf("%d:%d", &timetable[found].departureHrs, &timetable[found].departureMin);
				} while (!validateTime(timetable[found].departureHrs, timetable[found].departureMin));
				break;
			case 4:
				do {
					printf("Enter new Arrival Time (HH:MM): ");
					scanf("%d:%d", &timetable[found].arrivalHrs, &timetable[found].arrivalMin);
				} while (!validateTime(timetable[found].arrivalHrs, timetable[found].arrivalMin));
				break;
			default:
				printf("Invalid option!\n");
				break;
			}
			int durationHrs, durationMin;
			calculateDuration(timetable[found].departureHrs, timetable[found].departureMin, timetable[found].arrivalHrs, timetable[found].arrivalMin, &durationHrs, &durationMin);
			timetable[found].durationHrs = durationHrs;
			timetable[found].durationMin = durationMin;

			target = fopen("train_schedule.dat", "wb");
			if (target == NULL) {
				printf("Error: Unable to open the file!!!\n");
				exit(-1);
			}
			for (int i = 0; i < count; i++) {
				fwrite(&timetable[i], sizeof(TrainSchedule), 1, target);
			}
			fclose(target);

			if (option <= 0 || option > 4) {
				printf("%sModified Schedule Cancelled!!%s\n", RED, RESET);
			}
			else {
				printf("\n\nModified Schedule:\n");
				printf("\n%-15s %-15s %-10s %-15s%-15s%-10s\n", "Origin", "Destination", "Train ID", "Departure", "Arrival", "Duration");
				printf("--------------------------------------------------------------------------------------------\n");
				printf("%-15s %-15s   %-10s %02d:%02d\t   %02d:%02d\t%d hours %d minutes\n",
					timetable[found].origin, timetable[found].destination, timetable[found].trainId, timetable[found].departureHrs,
					timetable[found].departureMin, timetable[found].arrivalHrs, timetable[found].arrivalMin,
					timetable[found].durationHrs, timetable[found].durationMin);

			}
		}

		printf("\nDo you want to modify another schedule ? (Y/N): ");
		rewind(stdin);
		scanf("%c", &choice);
		printf("\n");
		choice = toupper(choice);
		if (choice == 'Y') {
			system("cls");
			stafflogo();
			printf("\nModify Train Schedule\n\n");
		}
	} while (choice == 'Y');
	backMenu();
}

//remove specific schedule
void deleteSchedule() {
	char confirm;
	TrainSchedule timetable[50];
	char inputOrigin[40];
	char inputDestination[40];
	int count = 0, found = -1;

	FILE* target;
	target = fopen("train_schedule.dat", "rb");
	if (target == NULL) {
		printf("Error: Unable to open the file for modifying!!!\n");
		exit(-1);
	}
	while (fread(&timetable[count], sizeof(TrainSchedule), 1, target)) {
		count++;
	}
	fclose(target);

	printf("Enter Origin: ");
	rewind(stdin);
	scanf("%[^\n]", inputOrigin);

	printf("Enter Destination: ");
	rewind(stdin);
	scanf(" %[^\n]", inputDestination);

	int foundOrigin = 0, foundDestination = 0;
	for (int i = 0; i < count; i++) {
		if (strcmp(timetable[i].origin, inputOrigin) == 0) {
			foundOrigin = 1;
		}
		if (strcmp(timetable[i].destination, inputDestination) == 0) {
			foundDestination = 1;
		}
	}

	if (!foundOrigin || !foundDestination) {
		printf("\nError: Origin or destination not found in the schedule.\n\n");
		return; // Exit the function
	}


	printf("\n\n\n%-5s %-15s %-15s %-10s\n", "Index", "Origin", "Destination", "Train ID");
	printf("---------------------------------------------\n");
	for (int i = 0; i < count; i++) {
		if (strcmp(timetable[i].origin, inputOrigin) == 0 && strcmp(timetable[i].destination, inputDestination) == 0) {
			printf("%-5d %-15s %-15s %-10s\n", i, timetable[i].origin, timetable[i].destination, timetable[i].trainId);
		}
	}

	int indexToDelete;
	printf("\nEnter the index of the schedule you want to delete: ");
	scanf("%d", &indexToDelete);

	if (indexToDelete >= 0 && indexToDelete < count) {
		printf("\nAre you sure you want to delete this schedule? (Y/N): ");
		rewind(stdin);
		scanf("%c", &confirm);

		if (confirm == 'Y' || confirm == 'y') {
			for (int i = indexToDelete; i < count - 1; i++) {
				timetable[i] = timetable[i + 1];
			}
			count--;

			target = fopen("train_schedule.dat", "wb");
			if (target == NULL) {
				printf("Error: Unable to open the file!!!\n");
				exit(-1);
			}
			for (int i = 0; i < count; i++) {
				fwrite(&timetable[i], sizeof(TrainSchedule), 1, target);
			}
			fclose(target);

			printf("\nSchedule deleted successfully.\n\n");
		}
		else {
			printf("\nSchedule deletion canceled.\n\n");
		}
	}
	else {
		printf("\nInvalid index entered.\n\n");
	}
}

//Booking Module Sales Report function
void dailysaleReport() {
	int selection;

	system("cls");
	stafflogo();
	do {
		printf("\nGenerate Sales Report for a Specific Day of 2024\n");
		printf("\n1. Today");
		printf("\n2. Other");
		printf("\n\nEnter your selection > ");
		scanf("%d", &selection);

		switch (selection) {
		case 1:
			todayReport();
			break;
		case 2:
			otherReport();
			break;
		default:
			rewind(stdin);
			system("cls");
			stafflogo();
			break;
		}

	} while (selection != 1 && selection != 2);
}

void todayReport() {
	struct PaymentDetail payment[500];
	SYSTEMTIME t;
	GetLocalTime(&t);
	int totalRecord;
	double totalAmount = 0, found = 0;
	readpayment(payment, &totalRecord);

	system("cls");
	stafflogo();

	printf("\n\n\n     Sales Report of %02d-%02d-%d ", t.wDay, t.wMonth, t.wYear);
	printf("\n------------------------------------");
	printf("\n%-10s  %-15s %-10s\n", "BookingID", "Account Number", "Amount");
	for (int i = 0; i < totalRecord; i++) {
		if (payment[i].pdate.year == t.wYear) {
			if (payment[i].pdate.month == t.wMonth) {
				if (payment[i].pdate.day == t.wDay) {
					printf("\n%-10s", payment[i].bookingid);
					printf("  %-15s", payment[i].accountno);
					printf(" %5.2f", payment[i].amount);
					totalAmount += payment[i].amount;
					found = 1;
				}
			}
		}
	}
	if (found == 1) {
		printf("\n\n------------------------------------");
		printf("\nTotal Amount : %.2f", totalAmount);
	}
	else {
		printf("\nNo Record Found");
	}
	printf("\n\n\n");
	backMenu();
}

void otherReport() {
	struct PaymentDetail payment[500];
	SYSTEMTIME t;
	GetLocalTime(&t);
	int totalRecord;
	double totalAmount = 0;
	int found = 0;
	readpayment(payment, &totalRecord);
	Date tempDate;

	system("cls");
	stafflogo();

	//01-05-2024 && 02-05-2024 && 03-05-2024 Got Booking Record
	printf("\n\nEnter Date (DD-MM-YYYY) : ");
	scanf("%d-%d-%d", &tempDate.day, &tempDate.month, &tempDate.year);

	printf("\n\n     Sales Report of %02d-%02d-%d ", tempDate.day, tempDate.month, tempDate.year);
	printf("\n------------------------------------");
	printf("\n%-10s  %-15s %-10s\n", "BookingID", "Account Number", "Amount");
	for (int i = 0; i < totalRecord; i++) {
		if (tempDate.year == payment[i].pdate.year) {
			if (tempDate.month == payment[i].pdate.month) {
				if (tempDate.day == payment[i].pdate.day) {
					printf("\n%-10s", payment[i].bookingid);
					printf("  %-15s", payment[i].accountno);
					printf(" %5.2f", payment[i].amount);
					totalAmount += payment[i].amount;
					found = 1;
				}
			}
		}
	}
	if (found == 1) {
		printf("\n\n------------------------------------");
		printf("\nTotal Amount : %.2f", totalAmount);
	}
	else {
		printf("\nNo Record Found!!!\n\n");
	}
	printf("\n\n\n");
	backMenu();
}


//Staff and Member Share function
int readMember(struct Member member[], int* lastindex) {

	FILE* readmember;
	int count = 0;

	readmember = fopen("member_details2.txt", "r");

	if (readmember == NULL) {
		printf("file cannot open");
		exit(-1);
	}

	while (fscanf(readmember, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c\n", member[count].memberid, member[count].email, member[count].password, member[count].detail.name, member[count].detail.ic, member[count].detail.contactno, &member[count].detail.gender) != EOF) {
		count++;
	}
	fclose(readmember);

	*lastindex = count;

}

int checkEmailFormat(char* email) {
	int validEmail = 0;

	if (strchr(email, '@') != NULL && strchr(email, '.') != NULL) {
		return validEmail = 1;
	}
	else {
		return validEmail;
	}
}

void checkPhoneNoFormat(char* phoneNo, int* validPhone) {

	int valid = 1;
	int lenPhNo = strlen(phoneNo);
	if (lenPhNo == 11 || lenPhNo == 12) {
		if (phoneNo[0] == '0') {
			for (int i = 1; i < 3; i++) {
				if (!isdigit(phoneNo[i])) {
					valid = 0;
				}
			}
			if (valid) {
				//Check 7th character is '-'
				if (phoneNo[3] != '-') {
					valid = 0;
				}
				else {
					//Check 7th and 8th character is digit
					for (int i = 4; i < lenPhNo; i++) {
						if (!isdigit(phoneNo[i])) {
							valid = 0;
							break;
						}
					}
				}
			}
		}
		else {
			valid = 0;
		}
	}
	else {
		valid = 0;
	}
	*validPhone = valid;

}

void checkICFormat(char* ic, int* validIC) {
	int valid = 1;

	if (strlen(ic) == 14) {
		//Check first 6 character is digit
		for (int i = 0; i < 6; i++) {
			if (!isdigit(ic[i])) {
				valid = 0;
			}
		}
		if (valid) {
			//Check 7th character is '-'
			if (ic[6] != '-') {
				valid = 0;
			}
			else {
				//Check 7th and 8th character is digit
				for (int i = 7; i < 9; i++) {
					if (!isdigit(ic[i])) {
						valid = 0;
					}
				}
				if (valid) {
					//Check 9th character is '-'
					if (ic[9] != '-') {
						valid = 0;
					}
					else {
						for (int i = 10; i < 14; i++) {
							//Check last 4 character is digit
							if (!isdigit(ic[i])) {
								valid = 0;
							}
						}
					}
				}
			}
		}
	}
	else {
		valid = 0;
	}
	*validIC = valid;
}

//Member and Ticket Booking Share Function
void readBookingRecord(struct bookingDetail booking[], int* totalBooking) {

	FILE* read = fopen("bookingrecord.dat", "rb");

	if (read == NULL) {
		printf("Cannot open file!");
		exit(-1);
	}

	int i = 0;
	while (fread(&booking[i], sizeof(struct bookingDetail), 1, read) != 0) {
		i++;
	}

	*totalBooking = i;

	fclose(read);
}


//Member Module 
int memberMainMenu() {
	struct Member member[1000];
	int lastindex, current = 0, pw = 0;
	int choice;
	char login;

	do {
		readMember(member, &lastindex);
		memberlogo();
		printf("\n1. Log In");
		printf("\n2. Sign Up");
		printf("\n3. Forgot Password");
		printf("\n0. Back");

		printf("\n\n\nEnter your choice > ");
		scanf("%d", &choice);
		rewind(stdin);

		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			choice = loginMember(member, &current);
			if (choice == 3) {
				memberMenu(member, current);
			}
			break;
		case 2:
			choice = addMember(member);
			if (choice == 2) {
				printf("\n\nYour Member ID is %s", member[lastindex].memberid);
				printf("\nPlease Log In Again\n\n");
				do {
					printf("Proceed (Y) > ");
					rewind(stdin);
					scanf("%c", &login);
				} while (toupper(login) != 'Y');
			}
			break;
		case 3:
			resetPwMember(member, &pw);
			if (pw == 1) {
				printf("\n\n%sPassword Changed!!%s", GREEN, RESET);
				printf("\n\nKindly wait for a few second");
				Sleep(3000);
			}
			break;
		default:
			rewind(stdin);
			choice = -1;
			break;
		}
	} while (choice != 0);

}

int addMember(struct Member member[]) {
	char idno[5];
	int id;
	int cmpEmail, cmpIC, validPhNo;
	int index = 0, sameIndex = 0, confirm = 0;
	int lastindex;
	readMember(member, &lastindex);

	FILE* addmember;

	do {
		memberlogo();
		printf("\nSign Up Member\n");
		printf("\nEnter [%s0%s] as name to back\n", RED, RESET);

		printf("\n%-10s : ", "Name");
		rewind(stdin);
		scanf("%[^\n]", member[lastindex].detail.name);

		if (strcmp(member[lastindex].detail.name, "0") == 0) {
			return -1;
		}

		do {
			getMemberEmail(&member[lastindex].email, lastindex);
			compareEmail(member, member[lastindex].email, &cmpEmail, &sameIndex);
			if (cmpEmail == 1) {
				printf("\n%sThis Email already exist!%s\n", RED, RESET);
			}
		} while (cmpEmail == 1);

		printf("%-10s : ", "Password");
		rewind(stdin);
		scanf("%[^\n]", member[lastindex].password);

		do {
			getMemberIC(&member[lastindex].detail.ic, lastindex);
			compareIC(member, member[lastindex].detail.ic, &cmpIC, &sameIndex);
			if (cmpIC == 1) {
				printf("\n%sThis IC already exist!%s\n", RED, RESET);
			}
		} while (cmpIC == 1);

		do {
			printf("%-10s : ", "Contact No");
			rewind(stdin);
			scanf("%[^\n]", member[lastindex].detail.contactno);
			checkPhoneNoFormat(member[lastindex].detail.contactno, &validPhNo);

			if (validPhNo != 1) {
				printf("Invalid Contact Number!\n");
				printf("Contact Number format > XXX-XXXXXXX\n");
			}
		} while (validPhNo != 1);

		do {
			printf("%-10s: ", "Gender(F/M)");
			rewind(stdin);
			scanf("%c", &member[lastindex].detail.gender);
		} while (toupper(member[lastindex].detail.gender) != 'F' && toupper(member[lastindex].detail.gender) != 'M');

		confirm = displayNewMember(member[lastindex].detail.name, member[lastindex].email, member[lastindex].password, member[lastindex].detail.ic, member[lastindex].detail.contactno, member[lastindex].detail.gender);

		if (confirm == 2) {
			backMenu();
			return -1;
		}

	} while (confirm != 1);

	//Generate member id
	index = lastindex - 1;
	sscanf(member[index].memberid, "%[^0-9]%d", &member[lastindex].memberid, &id);
	id++;
	//turn int id into string idNo
	itoa(id, idno, 10);
	strcat(member[lastindex].memberid, idno);

	addmember = fopen("member_details2.txt", "a");
	if (addmember == NULL) {
		printf("file does not exist");
		exit(-1);
	}
	fprintf(addmember, "%s|%s|%s|%s|%s|%s|%c\n", member[lastindex].memberid, member[lastindex].email, member[lastindex].password, member[lastindex].detail.name, member[lastindex].detail.ic, member[lastindex].detail.contactno, member[lastindex].detail.gender);
	fclose(addmember);

	return 2;
}

int displayNewMember(char* name, char* email, char* password, char* ic, char* phNo, char gender) {
	char correct;
	
	memberlogo();
	printf("\nNew Member Detail");
	printf("\n--------------------------");
	printf("\n%-10s : %s", "Name", name);
	printf("\n%-10s : %s", "Email", email);
	printf("\n%-10s : %s", "Password", password);
	printf("\n%-10s : %s", "IC", ic);
	printf("\n%-10s : %s", "Contact No", phNo);
	printf("\n%-10s : %c\n", "Gender", gender);

	do {
		printf("\nConfirm all correct ? (Y/N) > ");
		rewind(stdin);
		scanf("%c", &correct);
		correct = toupper(correct);
	} while (correct != 'Y' && correct != 'N');

	if (correct == 'Y') {
		return 1;
	}
	else {
		printf("\n");
		return 2;
	}

}

int loginMember(struct Member member[], int* memberLogin) {
	int current;
	char email[30], password[30];
	int loginSuccess = 0, loginCount = 0;
	int validEmail, validOption, pw;
	char option;
	int resetpw;

	memberlogo();
	printf("\nMember Log In\n");
	printf("\nEnter [%s0%s] as email to Back\n", RED, RESET);
	do {

		do {
			printf("\nEmail: ");
			rewind(stdin);
			scanf("%[^\n]", email);

			//Allow user back to login
			if (strcmp(email, "0") == 0) {
				rewind(stdin);
				return -1;
			}

			validEmail = checkEmailFormat(email);

			if (validEmail != 1) {
				printf("\nPlease enter correct email!");
			}

		} while (validEmail != 1);

		printf("Password: ");
		rewind(stdin);
		scanf("%[^\n]", password);

		//compare email and password entered
		current = compareEmailPw(member, email, password);
		if (current != -1) {
			*memberLogin = current;
			loginSuccess = 1;
			return 3;
		}
		else {
			printf("\nYour email or password is wrong, try again!");
			loginCount++;
		}

		if (loginCount >= 2) {

			do {
				printf("\n\nForgot password ? (Y/N) >");
				rewind(stdin);
				scanf("%c", &option);
				option = toupper(option);

				if (option == 'Y') {
					//Member proceed to Reset Password
					resetpw = resetPwMember(member, &pw);
					if (resetpw == -1) {
						return -1;
					}
					if (pw == 1) {
						printf("\n\n%sPassword Changed!!%s", GREEN, RESET);
						printf("\n\nPlease Log in Again");
						printf("\nKindly wait for a few second");
						Sleep(3000);
						loginCount = 0;
					}
					memberlogo();
					printf("Member Log In\n");
					validOption = 1;
				}
				else if (option == 'N') {
					validOption = 0;
				}
				else {
					printf("\nEnter only Y (yes) or N (no) !!!");
					validOption = -1;
				}
			} while (validOption == -1);

		}

	} while (loginSuccess != 1);
}

int compareEmailPw(struct Member member[], char* email, char* pw) {

	int lastindex, current;
	readMember(member, &lastindex);

	for (current = 0; current < lastindex; current++) {
		if (strcmp(email, member[current].email) == 0) {
			if (strcmp(pw, member[current].password) == 0) {
				return current;
			}
		}
	}
	current = -1;
	return current;
}

int resetPwMember(struct Member member[], int* pw) {
	int lastindex, current;
	int correctEmail = 0, validEmail;
	char email[30];
	char password[30];
	char confirm, back;
	readMember(member, &lastindex);

	memberlogo();
	printf("\nMember Change Password\n");
	do {

		do {
			printf("\nEnter Email: ");
			rewind(stdin);
			scanf("%[^\n]", email);

			//check if email follow format
			validEmail = checkEmailFormat(email);
			if (validEmail != 1) {
				printf("\nPlease enter valid email!");
			}
		} while (validEmail != 1);

		//email is valid,so now compare email in the file
		for (int i = 0; i < lastindex; i++) {
			if (strcmp(email, member[i].email) == 0) {
				current = i;
				correctEmail = 1;
			}
		}
		//cant find the same email
		if (correctEmail != 1) {
			printf("\nEmail is incorrect.");
			printf("\nPlease enter a correct email\n");
		}

	} while (correctEmail != 1);

	if (correctEmail == 1) {
		memberlogo();
		printf("\n%sEmail Found%s",GREEN,RESET);
		printf("\nReset Password\n");
		printf("\nEmail        : %s ", email);
	}

	printf("\nNew password : ");
	rewind(stdin);
	scanf("%[^\n]", &password);

	do {
		printf("\nConfirm to change password to %s%s%s ? (Y/N) > ",RED, password, RESET);
		rewind(stdin);
		scanf("%c", &confirm);
		confirm = toupper(confirm);
	} while (confirm != 'Y' && confirm != 'N');

	if (confirm == 'Y') {
		printf("\nPassword changing.....\n");
		Sleep(2500);

		strcpy(member[current].memberid, member[current].memberid);
		strcpy(member[current].email, member[current].email);
		strcpy(member[current].password, password);
		strcpy(member[current].detail.name, member[current].detail.name);
		strcpy(member[current].detail.ic, member[current].detail.ic);
		strcpy(member[current].detail.contactno, member[current].detail.contactno);
		member[current].detail.gender = member[current].detail.gender;

		modifyMemberFile(member, lastindex);

		*pw = 1;
	}
	else {
		printf("\n");
		do {
			printf("Back to login (Y) > ");
			rewind(stdin);
			scanf("%c", &back);
		} while (toupper(back) != 'Y');
		system("cls");
		*pw = 0;
	}
}

int memberMenu(struct Member member[], int current) {
	int option;
	memberlogo();
	printf("Welcome %s !\n", member[current].detail.name);
	do {
		printf("\n1. Train Schedule and Details");
		printf("\n2. Booking Ticket");
		printf("\n3. Search Booking Detail");
		printf("\n4. Booking history");
		printf("\n5. Personal Account Detail");
		printf("\n\n0. Log out");
		printf("\n\nEnter your choice: ");
		scanf("%d", &option);

		switch (option) {
		case 0:
			//Back to system big menu
			return systemMainMenu();
			break;
		case 1:
			//Display Train Schedule
			trainMainMember();
			break;
		case 2:
			//Buy ticket and other booking function
			bookingMenu(member, current);
			break;
		case 3:
			//Search for booking detail
			do {
				option = searchBookingDetail(member, current);
			} while (option == 0);
			break;
		case 4:
			//Display Booking history
			option = displayBookingHistory(member, current);
			break;
		case 5:
			//Proceed to account detail menu
			memberAccDetailMenu(member, current);
			break;
		default:
			rewind(stdin);
			memberlogo();
			printf("Welcome %s !\n", member[current].detail.name);
			break;
		}
	} while (option != 0);
}

int memberAccDetailMenu(struct Member member[], int current) {
	int choice;
	memberlogo();
	printf("\nMember Account Details\n");
	do {
		printf("\n1. Show and Update Personal Detail");
		printf("\n2. Delete Account");
		printf("\n0. Back to Menu");

		printf("\n\nEnter your choice > ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			memberlogo();
			break;
		case 1:
			displayMemberDetail(member, current);
			break;
		case 2:
			deleteMember(member, current);
			break;
		default:
			rewind(stdin);
			memberlogo();
			printf("\nMember Account Details\n");
		}
	} while (choice != 0);

}

void displayMemberDetail(struct Member member[], int current) {
	char choiceEdit;
	int valid = 0;
	memberlogo();
	printf("\nPersonal Account Detail\n");

	printf("\n%-10s : %s", "Memberid", member[current].memberid);
	printf("\n%-10s : %s", "Name", member[current].detail.name);
	printf("\n%-10s : %c", "Gender", member[current].detail.gender);
	printf("\n%-10s : %s", "IC", member[current].detail.ic);
	printf("\n%-10s : %s", "Contact No", member[current].detail.contactno);
	printf("\n%-10s : %s\n", "Email", member[current].email);

	do {
		printf("\nEdit details? (Y/N): ");
		rewind(stdin);
		scanf("%c", &choiceEdit);

		switch (toupper(choiceEdit)) {
		case 'Y':
			modifyMemberDetail(member, current);
			break;
		case 'N':
			printf("\n");
			backMenu();
			memberlogo();
			break;

		default:
			printf("\nEnter either [ Y ] or [ N ] !\n");
			valid = -1;
		}

	} while (valid != 0);

}

void modifyMemberDetail(struct Member member[], int current) {
	int lastindex, sameIndex;
	int cmpIC, cmpEmail;
	int validPhNo;
	readMember(member, &lastindex);

	struct Member modify;

	memberlogo();
	printf("\nUpdate Personal Detail");
	printf("\n%sNote!!Member ID is not allow to be change!!%s\n", RED, RESET);

	printf("\n%-10s : %s ", "Member ID", member[current].memberid);
	printf("\n%-10s : ", "Name");
	rewind(stdin);
	scanf("%[^\n]", &modify.detail.name);

	do {
		getMemberEmail(&modify.email, lastindex);
		compareEmail(member, modify.email, &cmpEmail, &sameIndex);
		if (sameIndex == current) {
			cmpEmail = 0;
		}
		if (cmpEmail == 1) {
			printf("\n%sThis Email already exist!%s\n", RED, RESET);
		}
	} while (cmpEmail == 1 && sameIndex != current);

	do {
		getMemberIC(&modify.detail.ic, lastindex);
		compareIC(member, modify.detail.ic, &cmpIC, &sameIndex);
		if (sameIndex == current) {
			cmpIC = 0;
		}
		if (cmpIC == 1) {
			printf("\n%sThis IC already exist!%s\n", RED, RESET);
		}

	} while (cmpIC == 1 && sameIndex != current);

	do {
		printf("%-10s : ", "Contact No");
		rewind(stdin);
		scanf("%[^\n]", modify.detail.contactno);
		checkPhoneNoFormat(modify.detail.contactno, &validPhNo);

		if (validPhNo != 1) {
			printf("Invalid Contact Number!\n");
			printf("Contact Number format > XXX-XXXXXXX\n");
		}
	} while (validPhNo != 1);

	do {
		printf("%-10s : ", "Gender(F/M)");
		rewind(stdin);
		scanf("%c", &modify.detail.gender);
	} while (toupper(modify.detail.gender) != 'F' && toupper(modify.detail.gender) != 'M');

	strcpy(member[current].memberid, member[current].memberid);
	strcpy(member[current].email, modify.email);
	strcpy(member[current].password, member[current].password);
	strcpy(member[current].detail.name, modify.detail.name);
	strcpy(member[current].detail.ic, modify.detail.ic);
	strcpy(member[current].detail.contactno, modify.detail.contactno);
	member[current].detail.gender = modify.detail.gender;

	modifyMemberFile(member, lastindex);

	memberlogo();
	printf("\n%sDetails Updated!!%s\n", GREEN, RESET);

	printf("\nNew Detail");
	printf("\n--------------------------");
	printf("\n%-10s : %s", "Memberid", member[current].memberid);
	printf("\n%-10s : %s", "Name", member[current].detail.name);
	printf("\n%-10s : %c", "Gender", member[current].detail.gender);
	printf("\n%-10s : %s", "IC", member[current].detail.ic);
	printf("\n%-10s : %s", "Contact No", member[current].detail.contactno);
	printf("\n%-10s : %s\n\n", "Email", member[current].email);

	backMenu();
	memberlogo();
}

void getMemberEmail(char* email, int lastindex) {
	int validEmail;
	do {
		printf("%-10s : ", "Email");
		rewind(stdin);
		scanf("%[^\n]", email);
		validEmail = checkEmailFormat(email);

		if (validEmail != 1) {
			printf("\nPlease enter correct email!\n");
		}
	} while (validEmail != 1);
}

void compareEmail(struct Member member[], char* email, int* cmpEmail, int* sameIndex) {
	int lastindex;
	int emailSame = 0;
	readMember(member, &lastindex);

	for (int i = 0; i < lastindex; i++) {
		if (strcmp(email, member[i].email) == 0) {
			emailSame = 1;
			*sameIndex = i;
		}
	}

	if (emailSame == 1) {
		*cmpEmail = 1;
	}
	else {
		*cmpEmail = 0;
	}
}

void getMemberIC(char* ic, int lastindex) {
	int validIC;
	do {
		printf("%-10s : ", "IC ");
		rewind(stdin);
		scanf("%[^\n]", ic);
		checkICFormat(ic, &validIC);
		if (validIC != 1) {
			printf("Invalid IC Number!\n");
			printf("IC Number format > XXXXXX-XX-XXXX\n");
		}
	} while (validIC != 1);
}

void compareIC(struct Member member[], char* ic, int* cmpIC, int* sameIndex) {
	int lastindex;
	int icSame = 0;
	int index = 0;
	readMember(member, &lastindex);

	for (int i = 0; i < lastindex; i++) {
		if (strcmp(ic, member[i].detail.ic) == 0) {
			icSame = 1;
			*sameIndex = i;
		}
	}

	if (icSame == 1) {
		*cmpIC = 1;
	}
	else {
		*cmpIC = 0;
	}
}

void modifyMemberFile(struct Member member[], int lastindex) {
	FILE* modifymember;
	modifymember = fopen("member_details2.txt", "w");

	if (modifymember == NULL) {
		printf("\nFile dont found\n");
		exit(-1);
	}
	for (int i = 0; i < lastindex; i++) {
		fprintf(modifymember, "%s|%s|%s|%s|%s|%s|%c\n", member[i].memberid, member[i].email, member[i].password, member[i].detail.name, member[i].detail.ic, member[i].detail.contactno, member[i].detail.gender);
	}
	fclose(modifymember);
}

void deleteMember(struct Member member[], int current) {

	int lastindex;
	char sure;
	FILE* deleteMember;

	readMember(member, &lastindex);

	memberlogo();
	printf("\nDelete Account\n");

	do {
		printf("\nAre you sure to delete your account ? (Y/N) ");
		rewind(stdin);
		scanf("%c", &sure);

		if (toupper(sure) == 'N') {
			memberlogo();
			return;
		}

	} while (toupper(sure) != 'Y');

	do {
		printf("\n\n%sNote!!Your Account Will Be Deleted!!%s\n", RED, RESET);
		printf("Confirm to deleted account ? (Y/N) ");
		rewind(stdin);
		scanf("%c", &sure);
		if (toupper(sure) == 'N') {
			memberlogo();
			return;
		}
	} while (toupper(sure) != 'Y');

	for (int i = current; i < lastindex - 1; i++) {
		member[i] = member[i + 1];
	}

	deleteMember = fopen("member_details2.txt", "w");
	if (deleteMember == NULL) {
		printf("File cannot open.");
		exit(-1);
	}

	lastindex--;
	for (int i = 0; i < lastindex; i++) {
		fprintf(deleteMember, "%s|%s|%s|%s|%s|%s|%c\n", member[i].memberid, member[i].email, member[i].password, member[i].detail.name, member[i].detail.ic, member[i].detail.contactno, member[i].detail.gender);
	}
	fclose(deleteMember);

	printf("\n\n%sAccount has been deleted!!%s\n", RED, RESET);
	Sleep(3000);
	system("cls");
	printf("\n\n\nTHANKS FOR USING OUR SYSTEM");
	Sleep(3000);
	systemMainMenu();
}

//Search and Display Booking Detail of Member
int searchBookingDetail(struct Member member[], int current) {
	struct bookingDetail booking[1000];
	char bookingID[6];
	int totalBook, num = 0, foundID = 0;
	int i = 0;
	char option;
	int currentMember = current;
	readBookingRecord(booking, &totalBook);

	memberlogo();
	printf("Search for booking detail\n\n");

	printf("Enter Booking ID: ");
	rewind(stdin);
	scanf("%s", &bookingID);

	do {
		if (strcmp(bookingID, booking[i].bookingid) == 0) {
			if (strcmp(member[currentMember].memberid, booking[i].memberid) == 0) {
				printf("\nBooking ID: %s", booking[i].bookingid);
				printf("\nDeparture Date: %02d-%02d-%d", booking[i].departuredate.day, booking[i].departuredate.month, booking[i].departuredate.year);
				printf("\nOrigin & Destination: %s --> %s", booking[i].scheduleBook.origin, booking[i].scheduleBook.destination);
				printf("\nDeparture & Arrival : %02d:%02d --> %02d:%02d", booking[i].scheduleBook.departureHrs, booking[i].scheduleBook.departureMin, booking[i].scheduleBook.arrivalHrs, booking[i].scheduleBook.arrivalMin);
				printf("\n==================================================");
				printf("\n%-15s %-15s %-6s", "Name", "IC", "Seat");
				printf("\n--------------------------------------------------");
				printf("\n%-15s %-15s %c%03d", booking[i].name, booking[i].ic, booking[i].typeseat, booking[i].seat);
				printf("\n==================================================");
				printf("\n");
				foundID = 1;
			}
			else {
				printf("\nBooking ID incorrect !!");
			}
		}
		i++;
	} while (i < totalBook);

	if (foundID != 1) {
		foundID = -1;
	}

	while (foundID == -1 || foundID == 1) {
		if (foundID == -1) {
			printf("\nBooking ID not found\n");
		}
		printf("\nContinue search ? (Y/N) > ");
		rewind(stdin);
		scanf("%c", &option);
		option = toupper(option);

		if (option == 'Y') {
			foundID = 0;
			return foundID;
		}
		else if (option == 'N') {
			foundID = 2;
			printf("\n\n");
			backMenu();
			memberlogo();
			return foundID;

		}
		else {
			rewind(stdin);
			printf("\nEnter a valid option!");
		}
	}

}

int displayBookingHistory(struct Member member[], int current) {
	struct bookingDetail booking[1000];
	int totalBooking;
	int i = 0, foundHistory = 0;
	char option;
	readBookingRecord(booking, &totalBooking);

	memberlogo();
	printf("Booking History\n");

	do {
		if (strcmp(member[current].memberid, booking[i].memberid) == 0) {
			printf("\nBooking ID: %s", booking[i].bookingid);
			printf("\nDeparture Date: %02d-%02d-%d", booking[i].departuredate.day, booking[i].departuredate.month, booking[i].departuredate.year);
			printf("\nOrigin & Destination: %s --> %s", booking[i].scheduleBook.origin, booking[i].scheduleBook.destination);
			printf("\nDeparture & Arrival : %02d:%02d --> %02d:%02d", booking[i].scheduleBook.departureHrs, booking[i].scheduleBook.departureMin, booking[i].scheduleBook.arrivalHrs, booking[i].scheduleBook.arrivalMin);
			printf("\n==================================================");
			printf("\n%-15s %-15s %-6s", "Name", "IC", "Seat");
			printf("\n--------------------------------------------------");
			printf("\n%-15s %-15s %c%03d", booking[i].name, booking[i].ic, booking[i].typeseat, booking[i].seat);
			printf("\n==================================================");
			printf("\n");
			foundHistory = 1;
		}
		i++;
	} while (i < totalBooking);

	if (foundHistory != 1) {
		printf("\nYou Have No Booking Yet!\n");
	}
	while (foundHistory != 1 || foundHistory == 1) {
		printf("\nBack to menu (Y) > ");
		rewind(stdin);
		scanf("%c", &option);

		if (toupper(option) == 'Y') {
			foundHistory = 2;
			memberlogo();
			return foundHistory;
		}
		else {
			printf("\nEnter [ Y ] to Back to Menu !!");
			foundHistory = -1;
		}
	}

}



//Train time schedule module and booking module share function
void displayclassP() {
	printf("\t-----------------Class : Platinum------------------\n\n");
	printf("\t\t   01      02         03      04        \n\n");
	printf("\t\t   05      06         07      08        \n\n");
	printf("\t\t   09      10         11      12        \n\n");
	printf("\t\t   13      14         15      16        \n\n");
	printf("\t\t   17      18         19      20        \n\n");
	printf("\t\t   21      22         23      24        \n\n");
	printf("\t\t   25      26         27      28        \n\n");
	printf("\t\t   29      30         31      32        \n\n");
	printf("\t\t   33      34         35      36        \n\n");
	printf("\t\t   37      38         39      40        \n\n");
}

void displayclassG() {
	printf("\t-------------------Class : Gold--------------------\n\n");
	printf("\t 01      02         03      04        05      06\n\n");
	printf("\t 07      08         09      10        11      12\n\n");
	printf("\t 13      14         15      16        17      18\n\n");
	printf("\t 19      20         21      16        22      23\n\n");
	printf("\t 24      25         26      27        28      29\n\n");
	printf("\t 30      31         32      33        34      35\n\n");
	printf("\t 36      37         38      39        40      41\n\n");
	printf("\t 42      43         44      45        46      47\n\n");
	printf("\t 48      49         50      51        52      53\n\n");
	printf("\t 54      55         56      57        58      60\n\n");
}

void displayclassS() {
	printf("\t------------------Class : Silver-------------------\n\n");
	printf("\t 01    02        03    04    05    06        07    08\n\n");
	printf("\t 09    10        11    12    13    14        15    16\n\n");
	printf("\t 17    18        19    20    21    22        23    24\n\n");
	printf("\t 25    26        27    28    29    30        31    32\n\n");
	printf("\t 33    34        35    36    37    38        39    40\n\n");
	printf("\t 41    42        43    44    45    46        47    48\n\n");
	printf("\t 49    50        51    52    53    54        55    56\n\n");
	printf("\t 57    58        59    60    61    62        63    64\n\n");
	printf("\t 65    66        67    68    69    70        71    72\n\n");
	printf("\t 73    74        75    76    77    78        79    80\n\n");
}


//Train Time Schedule Module of Member
//menu for member
int trainMainMember() {
	int option;
	int member = 2;
	memberlogo();
	printf("Train Schedule and Details\n");
	do {
		printf("\n1.Display Daily Schedule\n");
		printf("2.View Details for train seat and price\n");
		printf("3.Search for specific train\n");
		printf("0.Back\n");

		printf("\nEnter your option > ");
		scanf("%d", &option);

		switch (option) {
		case 0:
			memberlogo();
			return 0;
			break;
		case 1:
			displaySchedule(member);
			break;
		case 2:
			viewDetails();
			break;
		case 3:
			searchSchedule();
			break;
		default:
			memberlogo();
			printf("Train Schedule and Details\n");
			break;
		}
	} while (option != 4);
}

//display seat detail
void viewDetails() {
	memberlogo();

	printf("\t--------------------SEAT MATRIX--------------------\n\n");

	displayclassP();

	displayclassG();

	displayclassS();

	printf("\nPLATINUM\t\t\tGOLD\t\t\t\tSILVER\n");
	printf("-------------------\t\t-------------------\t\t-------------------\n");
	printf("Available Seat : 40\t\tAvailable Seat : 60\t\tAvailable Seat : 80\n\n");
	printf("Price:\t\t\t\tPrice:\t\t\t\tPrice:\n");
	printf(" - Adult:RM40\t\t\t - Adult:RM30\t\t\t - Adult:RM20\n");
	printf(" - Child:RM35\t\t\t - Child:RM25\t\t\t - Child:RM15\n\n\n\n");

	backMenu();
	memberlogo();
}

//search origin and destination for viewing specific schedule
void searchSchedule() {
	char inputOrigin[40];
	char inputDestination[40];
	int found = 0;

	memberlogo();
	printf("Search for Train Schedule\n\n");

	printf("Enter Origin: ");
	rewind(stdin);
	scanf("%[^\n]", inputOrigin);
	printf("Enter Destination: ");
	rewind(stdin);
	scanf("%[^\n]", inputDestination);

	FILE* target;
	target = fopen("train_schedule.dat", "rb");
	if (target == NULL) {
		printf("Error: Unable to open the file for searching!!!\n");
		exit(-1);
	}
	printf("\n\n\n%-15s %-15s %-10s %-15s%-15s%-10s\n", "Origin", "Destination", "Train ID", "Departure", "Arrival", "Duration");
	printf("--------------------------------------------------------------------------------------------\n");

	TrainSchedule temp;
	while (fread(&temp, sizeof(TrainSchedule), 1, target) == 1) {
		if (strcmp(inputOrigin, temp.origin) == 0 && strcmp(inputDestination, temp.destination) == 0) {
			printf("%-15s %-15s   %-10s %02d:%02d\t   %02d:%02d\t%d hours %d minutes\n",
				temp.origin, temp.destination, temp.trainId, temp.departureHrs,
				temp.departureMin, temp.arrivalHrs, temp.arrivalMin,
				temp.durationHrs, temp.durationMin);
			found = 1;
		}
	}
	fclose(target);
	if (!found) {
		printf("No schedule found for the given origin and destination.\n\n\n");
	}
	printf("\n\nThis is a DAILY SCHEDULE!!!\n\nIt will only be changed during special holidays!!!\n\n\n");
	backMenu();
	memberlogo();
}



//Booking Module
int bookingMenu(struct Member member[], int current) {
	int option;
	memberlogo();
	printf("\nTicket Booking\n");

	do {
		printf("\n1.Book");
		printf("\n2.Modify Ticket Time");
		printf("\n3.Cancel Booking");
		printf("\n0.Back\n");

		printf("\nEnter your option: ");
		rewind(stdin);
		scanf("%d", &option);

		switch (option) {
		case 1:
			searchSelection(member, current);
			break;
		case 2:
			modifyBookingRecord(member, current);
			break;
		case 3:
			cancelBooking(member, current);
			break;
		case 0:
			memberlogo();
			return;
			break;
		default:
			rewind(stdin);
			memberlogo();
			break;
		}
	} while (option != 0);
}

void searchSelection(struct Member member[], int current) {
	struct bookingDetail bd;
	int found = 0, selectNo;
	int scheduleCount = 0;
	TrainSchedule temp[MAX_TRAIN];
	TrainSchedule tempBook;

	SYSTEMTIME t;
	GetLocalTime(&t);
	int day = t.wDay;
	int month = t.wMonth;
	int year = t.wYear;

	FILE* target;

	target = fopen("train_schedule.dat", "rb");
	if (target == NULL) {
		printf("Cannot open file");
		exit(-1);
	}
	memberlogo();
	printf("\nTicket Booking\n");
	printf("\nDate: %02d-%02d-%d", day + 1, month, year);
	printf("\nFrom: ");
	rewind(stdin);
	scanf("%[^\n]", bd.scheduleBook.origin);

	printf("To: ");
	rewind(stdin);
	scanf("%[^\n]", bd.scheduleBook.destination);

	printf("\n%-6s %-15s %-15s %-10s %-15s%-15s%-20s%-10s\n", "No", "Origin", "Destination", "Train ID", "Departure", "Arrival", "Duration", "Available Seat");
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	while (fread(&temp[scheduleCount], sizeof(TrainSchedule), 1, target) != 0) {
		if (strcmp(bd.scheduleBook.origin, temp[scheduleCount].origin) == 0 && strcmp(bd.scheduleBook.destination, temp[scheduleCount].destination) == 0) {
			struct bookingDetail existingbd[1000];
			int totalBooking;

			readBookingRecord(existingbd, &totalBooking);

			int s = 80, g = 60, p = 40;

			for (int i = 0; i < totalBooking; i++) {
				if (strcmp(existingbd[i].scheduleBook.origin, bd.scheduleBook.origin) == 0 && strcmp(existingbd[i].scheduleBook.destination, bd.scheduleBook.destination) == 0
					&& existingbd[i].scheduleBook.departureHrs == temp[scheduleCount].departureHrs && existingbd[i].scheduleBook.departureMin == temp[scheduleCount].departureMin) {

					switch (existingbd[i].typeseat) {
					case 'S':
						s--;
					case 'G':
						g--;
					case 'P':
						p--;
					}
				}
			}

			printf("%2d     %-15s %-15s   %-10s %02d:%02d\t   %02d:%02d\t%d hours %d minutes  S:%d G:%d P:%d\n", scheduleCount + 1,
				temp[scheduleCount].origin, temp[scheduleCount].destination, temp[scheduleCount].trainId, temp[scheduleCount].departureHrs,
				temp[scheduleCount].departureMin, temp[scheduleCount].arrivalHrs, temp[scheduleCount].arrivalMin,
				temp[scheduleCount].durationHrs, temp[scheduleCount].durationMin, s, g, p);

			found = 1;
			scheduleCount++;
		}
	}

	if (found != 1) {
		printf("\n%sNo schedule found for the given origin and destination.%s\n\n\n", RED, RESET);
	}
	else {
		do {
			printf("\nEnter Select No: ");
			scanf("%d", &selectNo);
			for (int j = 1; j <= scheduleCount; j++) {
				if (selectNo == j) {
					tempBook = temp[j - 1];
				}

				if (selectNo<1 || selectNo>scheduleCount) {
					printf("\nPlease enter a valid number!");
					break;
				}
			}
		} while (selectNo<1 || selectNo>scheduleCount);

		addBooking(member, current, tempBook, bd);
	}
}

void addBooking(struct Member member[], int current, TrainSchedule tempBook, struct bookingDetail bd) {
	struct bookingDetail tempBooking;
	struct bookingDetail memberBook;
	double amount;
	int totalqty;
	int validTypeSeat = 0;
	int validAdultNum = 0, validChildNum = 0;
	int validIC, validEmail;

	SYSTEMTIME t;
	GetLocalTime(&t);
	int day = t.wDay;
	int month = t.wMonth;
	int year = t.wYear;

	FILE* br;
	br = fopen("bookingrecord.dat", "ab");
	if (br == NULL) {
		printf("Cannot open the file");
		exit(-1);
	}

	do {
		printf("\nEmail : ");
		rewind(stdin);
		scanf("%[^\n]", tempBooking.email);
		validEmail = checkEmailFormat(tempBooking.email);

		if (validEmail != 1) {
			printf("\nPlease enter correct email!\n");
		}
	} while (validEmail != 1);

	do {
		printf("\nQuantity for Adult: ");
		rewind(stdin);
		if (scanf("%d", &tempBooking.qtyadult) == 1) {
			validAdultNum = 1;
		}
		else
		{
			printf("Invalid. Please reenter a valid Quantity. \n");
		}
	} while (validAdultNum == 0);

	do {
		printf("Quantity for Child: ");
		rewind(stdin);
		if (scanf("%d", &tempBooking.qtychild) == 1) {
			validChildNum = 1;
		}
		else
		{
			printf("Invalid. Please reenter a valid Quantity. \n");
		}
	} while (validChildNum == 0);

	do {
		printf("\nSilver(S)/Gold(G)/Platinum(P): ");
		rewind(stdin);
		scanf("%c", &tempBooking.typeseat);
		if (tempBooking.typeseat == 'S' || tempBooking.typeseat == 'G' || tempBooking.typeseat == 'P')
		{
			validTypeSeat = 1;
		}
		else
		{
			printf("Invalid seat type. Please reenter a valid seat type. \n");
		}
	} while (validTypeSeat == 0);

	seatSelection(tempBooking.typeseat, tempBooking.qtyadult, tempBooking.qtychild, &totalqty);
	randomId(&tempBooking.bookingid);

	int currentSeats[80];

	for (int i = 0; i < totalqty; i++) {
		int validSeat = 0, validName = 0, validIc = 0;
		do {
			printf("Enter Name : ");
			rewind(stdin);
			scanf("%[^\n]", tempBooking.name);
			if (isValidName(tempBooking.name) == 1) {
				validName = 1;
			}
			else
			{
				printf("Invalid Name. Please reenter a valid name. \n");
			}
		} while (validName == 0);

		do {
			printf("IC         : ");
			rewind(stdin);
			scanf("%[^\n]", tempBooking.ic);
			checkICFormat(tempBooking.ic, &validIC);
			if (validIC != 1) {
				printf("Invalid IC Number!\n");
				printf("IC Number format > XXXXXX-XX-XXXX\n");
			}
		} while (validIC != 1);

		do {
			printf("Select Seat: ");
			rewind(stdin);
			scanf("%d", &tempBooking.seat);

			if (inCurrentBooking(tempBooking.seat, currentSeats) == 0 && seatchoose(tempBooking, tempBook, currentSeats) == 0)
			{
				validSeat = 1;
				currentSeats[i] = tempBooking.seat;
			}
		} while (validSeat == 0);


		strcpy(memberBook.bookingid, tempBooking.bookingid);
		strcpy(memberBook.memberid, member[current].memberid);
		strcpy(memberBook.name, tempBooking.name);
		strcpy(memberBook.ic, tempBooking.ic);
		strcpy(memberBook.email, tempBooking.email);
		memberBook.qtyadult = tempBooking.qtyadult;
		memberBook.qtychild = tempBooking.qtychild;
		memberBook.typeseat = tempBooking.typeseat;
		memberBook.seat = tempBooking.seat;
		memberBook.scheduleBook = tempBook;
		memberBook.departuredate.day = day + 1;
		memberBook.departuredate.month = month;
		memberBook.departuredate.year = year;


		fwrite(&memberBook, sizeof(struct bookingDetail), 1, br);

	}
	fclose(br);

	amount = calPayment(tempBooking.typeseat, tempBooking.qtyadult, tempBooking.qtychild);
	payment(memberBook.bookingid, amount);

	displayNewBooking(memberBook, totalqty);
}

void seatSelection(char typeseat, int qtyadult, int qtychild, int* totalqty) {

	do {
		switch (typeseat) {
		case'S':
			printf("\n");
			displayclassS();
			printf("\n");
			break;
		case'G':
			printf("\n");
			displayclassG();
			printf("\n");
			break;
		case'P':
			printf("\n");
			displayclassP();
			printf("\n");
			break;
		default:
			rewind(stdin);
			printf("Unavilable Select");
			break;
		}
	} while (typeseat != 'S' && typeseat != 'G' && typeseat != 'P');

	*totalqty = qtyadult + qtychild;

}

void payment(char* bookingid, double amount) {
	SYSTEMTIME t;
	GetLocalTime(&t);
	struct PaymentDetail pay;

	FILE* recordPayment;

	printf("\nTotal Payment: %.2f\n", amount);

	int validNum = 0;
	do {
		printf("\nAccount Number: ");
		rewind(stdin);
		scanf("%[^\n]", pay.accountno);
		if (isValidNum(pay.accountno) == 1) {
			validNum = 1;
		}
		else {
			printf("Invalid. Please reenter a valid Account Number. \n");
		}
	} while (validNum == 0);

	strcpy(pay.bookingid, bookingid);
	pay.amount = amount;
	pay.pdate.day = t.wDay;
	pay.pdate.month = t.wMonth;
	pay.pdate.year = t.wYear;
	pay.hrs = t.wHour;
	pay.min = t.wMinute;

	recordPayment = fopen("paymentRecord.bin", "ab");

	if (recordPayment == NULL) {
		printf("Payment Record File Cannot Open!!");
		exit(-1);
	}

	fwrite(&pay, sizeof(struct PaymentDetail), 1, recordPayment);
	fclose(recordPayment);
}

void readpayment(struct PaymentDetail payment[], int* totalRecord) {
	int i = 0;
	FILE* read;
	read = fopen("paymentRecord.bin", "rb");

	if (read == NULL) {
		printf("Payment File Cannot Open");
		exit(-1);
	}

	while (fread(&payment[i], sizeof(struct PaymentDetail), 1, read) != 0) {
		i++;
	}
	*totalRecord = i;
	fclose(read);
}

void randomId(char* bookingID) {

	char bookingno[5];
	int randomno;

	srand(time(NULL));
	randomno = rand() % (3000 + 1 - 1000) + 1000;
	sprintf(bookingno, "%d", randomno);

	strcpy(bookingID, "B");

	strcat(bookingID, bookingno);
}

void displayNewBooking(struct bookingDetail currentBook, int totalqty) {
	struct bookingDetail allBooking[1000];
	int totalBooking;
	char classtype[15];
	SYSTEMTIME t;
	GetLocalTime(&t);

	readBookingRecord(allBooking, &totalBooking);
	int current = totalBooking - totalqty - 1;

	memberlogo();

	printf("\nThanks for booking!\n");

	printf("\nPayment Date: %02d-%02d-%d", t.wDay, t.wMonth, t.wYear);
	printf("\nPayment Time: %02d:%02d\n", t.wHour, t.wMinute);

	printf("\nNew Booking Record");
	printf("\n==================================================");
	printf("\nTotal Amount of Ticket Booked < %d > ", totalqty);
	printf("\nBooking ID : %s", currentBook.bookingid);
	printf("\nEmail  : %s", currentBook.email);
	printf("\nOrigin : %s\nDestination : %s", currentBook.scheduleBook.origin, currentBook.scheduleBook.destination);
	printf("\nDeparture Time: %02d:%02d", currentBook.scheduleBook.departureHrs, currentBook.scheduleBook.departureMin);
	printf("\nArrival   Time: %02d:%02d", currentBook.scheduleBook.arrivalHrs, currentBook.scheduleBook.arrivalMin);
	if (currentBook.typeseat == 'P') {
		strcpy(classtype, "Platinum (P)");
	}
	else if (currentBook.typeseat == 'G') {
		strcpy(classtype, "Gold (G)");
	}
	else {
		strcpy(classtype, "Silver (S)");
	}
	printf("\nClass Type : %s", classtype);
	printf("\n==================================================");
	printf("\n%-15s %-15s %-6s", "Name", "IC", "Seat");
	printf("\n==================================================");
	while (current < totalBooking) {
		if (strcmp(currentBook.bookingid, allBooking[current].bookingid) == 0) {
			printf("\n%-15s", allBooking[current].name);
			printf(" %-15s", allBooking[current].ic);
			printf(" %c%03d", allBooking[current].typeseat, allBooking[current].seat);
		}
		current++;
	}
	printf("\n==================================================\n\n");
	backMenu();
	memberlogo();
}

void modifyBookingRecord(struct Member member[], int current) {
	struct bookingDetail booking[1000];
	char bookingID[1000];
	int count = 0, found = 0, selectNo;
	int foundIndex = 0;
	int found2[1000];
	int scheduleCount = 0;
	TrainSchedule temp[MAX_TRAIN];
	TrainSchedule tempBook;
	readBookingRecord(booking, &count);

	FILE* modify, * target;
	target = fopen("train_schedule.dat", "rb");

	if (target == NULL) {
		printf("Cannot open file");
		exit(-1);
	}
	memberlogo();
	printf("\nUpdate Ticket Booking Details");
	printf("\n%sNote!! You can only modify departure time!%s\n", RED, RESET);

	printf("\nEnter Booking ID: ");
	rewind(stdin);
	scanf("%[^\n]", bookingID);

	for (int i = 0; i < count; i++) {
		if (strcmp(bookingID, booking[i].bookingid) == 0) {
			if (strcmp(booking[i].memberid, member[current].memberid) == 0) {
				found2[foundIndex] = i;
				foundIndex++;
			}
		}
	}

	if (foundIndex == 0) {
		printf("\nBooking ID Not found\n\n");
	}
	else {
		printf("\n%-6s %-15s %-15s %-10s %-15s%-15s%-10s\n", "No", "Origin", "Destination", "Train ID", "Departure", "Arrival", "Duration");
		printf("--------------------------------------------------------------------------------------------\n");
		while (fread(&temp[scheduleCount], sizeof(TrainSchedule), 1, target) != 0) {
			if (strcmp(booking[found2[0]].scheduleBook.origin, temp[scheduleCount].origin) == 0 && strcmp(booking[found2[0]].scheduleBook.destination, temp[scheduleCount].destination) == 0) {
				printf("%2d     %-15s %-15s   %-10s %02d:%02d\t   %02d:%02d\t%d hours %d minutes\n", scheduleCount + 1,
					temp[scheduleCount].origin, temp[scheduleCount].destination, temp[scheduleCount].trainId, temp[scheduleCount].departureHrs,
					temp[scheduleCount].departureMin, temp[scheduleCount].arrivalHrs, temp[scheduleCount].arrivalMin,
					temp[scheduleCount].durationHrs, temp[scheduleCount].durationMin);
				found = 1;
				scheduleCount++;
			}
		}

		fclose(target);

		if (found != 1) {
			printf("\nNo schedule found for the given origin and destination.\n\n\n");
		}
		else {
			do {
				printf("\nEnter Select No: ");
				scanf("%d", &selectNo);
				for (int j = 1; j <= scheduleCount; j++) {
					if (selectNo == j) {
						tempBook = temp[j - 1];
					}

					if (selectNo<1 || selectNo>scheduleCount) {
						printf("\nPlease enter a valid number!");
					}
				}
			} while (selectNo<1 || selectNo>scheduleCount);

			printf("\n%sModify successfully%s\n\n", GREEN, RESET);
		}

		for (int i = 0; i < foundIndex; i++)
		{
			booking[found2[i]].scheduleBook.departureHrs = tempBook.departureHrs;
			booking[found2[i]].scheduleBook.departureMin = tempBook.departureMin;
			booking[found2[i]].scheduleBook.arrivalHrs = tempBook.arrivalHrs;
			booking[found2[i]].scheduleBook.arrivalMin = tempBook.arrivalMin;
		}

		modify = fopen("bookingrecord.dat", "wb");
		if (modify == NULL) {
			printf("Cannot open the file");
			exit(-1);
		}
		for (int i = 0; i < count; i++) {
			fwrite(&booking[i], sizeof(struct bookingDetail), 1, modify);
		}
		fclose(modify);
	}
	backMenu();
	memberlogo();
}

void cancelBooking(struct Member member[], int current) {
	char cancel, search;
	struct bookingDetail bd[1000];
	int count = 0, foundIndex = 0;
	int crrBook;
	int found2[1000];
	char bookingID[6];
	readBookingRecord(bd, &count);
	FILE* target;

	memberlogo();
	printf("\nCancel Booking\n");
	do {
		printf("\nEnter Booking ID: ");
		rewind(stdin);
		scanf("%[^\n]", bookingID);

		for (int i = 0; i < count; i++) {
			if (strcmp(bookingID, bd[i].bookingid) == 0) {
				if (strcmp(bd[i].memberid, member[current].memberid) == 0) {
					printf("\nFrom: %s\n", bd[i].scheduleBook.origin);
					printf("To: %s\n", bd[i].scheduleBook.destination);
					printf("Date: %02d-%02d-%d\n", bd[i].departuredate.day, bd[i].departuredate.month, bd[i].departuredate.year);
					printf("Departure Time: %02d:%02d\n", bd[i].scheduleBook.departureHrs, bd[i].scheduleBook.departureMin);
					found2[foundIndex] = i;
					crrBook = i;
					foundIndex++;
				}
				else {
					foundIndex = -1;
				}
			}
		}

		if (foundIndex == -1) {
			printf("\nBooking id not found");
			printf("\nContinue search ? > ");
			do {
				rewind(stdin);
				scanf("%c", &search);
				if (search == 'Y') {
					foundIndex = 8;
				}
				else if (search == 'N') {
					foundIndex = 2;
					backMenu();
					memberlogo();
					return;
				}
				else {
					printf("\nEnter [Y] = Yes [N] = No");
					foundIndex = 0;
				}
			} while (foundIndex != 8);
		}
	} while (foundIndex == 8);

	if (foundIndex > 0) {
		printf("\n%sNote!!You will cancel all the ticket with Booking ID %s%s", RED, bookingID, RESET);
		printf("\nConfirm Cancel? (Y/N): ");
		rewind(stdin);
		scanf("%c", &cancel);
		cancel = toupper(cancel);
		if (cancel == 'Y') {
			for (int i = found2[0]; i < count - foundIndex; i++) {
				bd[i] = bd[i + foundIndex];
			}

			target = fopen("bookingrecord.dat", "wb");
			if (target == NULL) {
				printf("Cannot open the file");
				exit(-1);
			}
			for (int i = 0; i < count - foundIndex; i++) {
				fwrite(&bd[i], sizeof(struct bookingDetail), 1, target);
			}
			fclose(target);
			printf("\n%sBooking Cancel Successfully%s\n\n", GREEN, RESET);
			backMenu();
			memberlogo();
		}
		else {
			printf("\n%sBooking cancellation Failed%s\n\n", RED, RESET);
			backMenu();
			memberlogo();
		}
	}
	else {
		printf("\nInvalid Booking ID\n\n");
		backMenu();
		memberlogo();
	}
}

int seatchoose(struct bookingDetail tempBooking, TrainSchedule tempBook) {
	struct bookingDetail bd[1000];
	int totalBooking;
	int found[1000], foundIndex = 0;

	readBookingRecord(bd, &totalBooking);


	for (int i = 0; i < totalBooking; i++) {
		if (strcmp(bd[i].scheduleBook.origin, tempBook.origin) == 0 && strcmp(bd[i].scheduleBook.destination, tempBook.destination) == 0
			&& bd[i].scheduleBook.departureHrs == tempBook.departureHrs && bd[i].scheduleBook.departureMin == tempBook.departureMin
			&& bd[i].typeseat == tempBooking.typeseat && bd[i].seat == tempBooking.seat) {
			printf("Seat %d is already booked\n", tempBooking.seat);
			found[foundIndex] = i;
			foundIndex++;
			break;
		}
	}

	if (foundIndex == 0) {
		printf("Seat %d booked for you\n\n", tempBooking.seat);
	}

	return foundIndex;
}

double calPayment(char typeseat, int qtyadult, int qtychild) {
	double total;

	switch (typeseat) {
	case'S':
		total = (20 * qtyadult) + (15 * qtychild);
		return total;
	case'G':
		total = (30 * qtyadult) + (25 * qtychild);
		return total;
	case'P':
		total = (40 * qtyadult) + (35 * qtychild);
		return total;
	default:
		return 0;
	}
}

int inCurrentBooking(int seatNumber, int currentSeats[])
{
	for (int i = 0; i < sizeof(currentSeats) / sizeof(currentSeats[0]); i++)
	{
		if (seatNumber == currentSeats[i]) {
			printf("Seat %d is already booked\n", seatNumber);
			return 1;
		}
	}

	return 0;
}

int isValidName(const char* str) {
	while (*str) {
		if (!(isAlpha(*str))) {
			return 0; // Return 0 if a non-alphabet character is found
		}
		str++;
	}
	return 1; // All characters were alphabetic
}

int isAlpha(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ';
}

int isValidNum(const char* str) {
	while (*str) {
		if (!(isDigit(*str))) {
			return 0; // Return 0 if a non-digit character is found
		}
		str++;
	}
	return 1; // All characters were digits
}

int isDigit(char ch) {
	return (ch >= '0' && ch <= '9');
}
