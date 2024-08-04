#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

void mainMenu(void);
void createAccount(void);
void login(void);
void getPassword(char *password);
void forgotPassword(void);
void help(void);

int main(void){
    mainMenu();
    return 0;
}

void mainMenu(void){
	system("cls");
    char letter[500] = "WELCOME TO BANK MANAGEMENT SYSTEM";
    char dots[500] = "==============================================================================";
    int choice;
    
    printf("%s\n", dots);
    printf("%s", "\t \t");
    
    for(int i = 0; i < 36; i++){
        printf("%c", letter[i]);
        Sleep(30);
    }
    
    puts("");
    for(int i = 0; i < 80; i++){
        printf("%c", dots[i]);
        Sleep(20);
    }
    
    printf("%s", "\n 1. CREATE ACCOUNT\n 2. LOGIN\n 3. FORGOT PASSWORD\n 4. HELP\n");
    printf("%s\n\n", dots);
    
start:
    printf("%s", "Please select your option: ");
    if(scanf("%d", &choice) != 1){
        printf("%s", "Ooops! Enter a number. Try again. \n");
        while(getchar() != '\n');
        goto start;
    }
    else if(choice < 1 || choice > 4){
        printf("%s", "Oops! Wrong choice. Try again. \n");
        while(getchar() != '\n');
        goto start;
    }
    
    while(getchar() != '\n');
    
    switch(choice){
        case 1:
            createAccount();
            break;
            
        case 2:
            login();
            break;
            
        case 3:
            forgotPassword();
            break;
            
        case 4:
            help();
            break;
            
        default:
            printf("\n%s\n", "Oops! Looks like there was a problem. ");
            break;
    }
}

/*------------------------------------CREATE ACCOUNT MENU------------------------------------ */
void createAccount(void){
	system("cls");
    char letter[500] = "CREATE ACCOUNT MENU";
    char dots[500] = "=============================================================================="; //80
    char f_name[500], l_name[500], email[500], userName[500], password[20], confirmPassword[20], contact[10];
    
    printf("\n%s\n", dots);
    printf("%s", "\t \t");
    
    for(int i = 0; i < 19; i++){
        printf("%c", letter[i]);
        Sleep(20);
    }
    
    printf("%s", "\n"); //prints a new line
    
    for(int i = 0; i < 80; i++){
        printf("%c", dots[i]);
        Sleep(20);
    }
    
    printf("%s", "\n");
    printf("%s", "\nEnter your first name: ");
    fgets(f_name, sizeof(f_name), stdin);
    f_name[strcspn(f_name, "\n")] = 0;  // Remove newline character
    
    printf("%s", "Enter your last name: ");
    fgets(l_name, sizeof(l_name), stdin);
    l_name[strcspn(l_name, "\n")] = 0;  // Remove newline character
    
    printf("%s", "Enter your email address: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0;  // Remove newline character
    
    printf("%s", "Enter your user name: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = 0;  // Remove newline character
    
    printf("%s", "Enter your contact number: ");
    fgets(contact, sizeof(contact), stdin);
    contact[strcspn(contact, "\n")] = 0;  // Remove newline character
    
    //getting password from the user
    
    while (1) {
        printf("Enter password: ");
        getPassword(password);
        
        if (strlen(password) == 0) {
            printf("Password can't be NULL. Please enter again.\n");
            continue;
        }
        
        if(strlen(password) < 5){
        	printf("\n%s", "Password too short. Please try again. \n");
        	continue;
		}
        
        printf("Confirm password: ");
        getPassword(confirmPassword);
        
        
        if (strcmp(password, confirmPassword) == 0) {
        	char lod[40] = "Loading please wait";
            char dot[10] = ".........";
    
            printf("\n%s", lod);
            for(int i = 0; i < 10; i ++){
                printf("%c", dot[i]);
                Sleep(500);
	        }
	        
	        char message[500] = "ACCOUNT CREATED SUCCESSFULLY!!!!!";
	        
	        puts("");
	        
	        for(int i = 0; i < 39; i ++){
	        	printf("%c", message[i]);
	        	Sleep(20);
			}
            
            break;
        } 
        
        else {
            printf("Passwords do not match. Please try again.\n");
        }
    }
    
    //creating a pointer variable to store the user information
    FILE *file1;
    FILE *file2;
    FILE *file3;
    char a[600], b[600], c[600];
    
    strcpy(a, f_name);
    strcat(a, l_name);
    strcat(a, ".txt");
    
    strcpy(b, password);
    strcat(b, ".txt");
	
	strcpy(c, userName);
	strcat(c, ".txt"); 
    
    file1 = fopen(a, "w"); //creating file for the user
    
    if(file1 == NULL){
        printf("%s", "\nError opening file. \n");
        return;
    }
    
    fprintf(file1, "%s\n", f_name);
    fprintf(file1, "%s\n", l_name);
    fprintf(file1, "%s\n", email);
    fprintf(file1, "%s\n", userName);
    fprintf(file1, "%s\n", contact);
    fprintf(file1, "%s\n", password);
    
    fclose(file1);  //closing file
    
    file2 = fopen(b, "w"); //creating password file for the user
    if(file2 == NULL){
        printf("%s", "\nError opening password file. \n");
        return;
    }
    
    fprintf(file2, "%s", password);
    
    fclose(file2); //closing file
    
    file3 = fopen(c, "w");
    if(file3 == NULL){
    	printf("\n%s", "Error opening user name file. \n");
    	return;
	}
	
	fprintf(file3, "%s", userName);
	
	fclose(file3); //closing user name file
    
    while(getchar() != '\n'); //clear input buffer
	
    mainMenu();
}

/* =============================LOGIN MENU=====================================*/
void login(void){
	system("cls");
    printf("%s", "NOTE: Under construction. \n\n");
    char letter[500] = "ACCOUNT LOGIN MENU";
    char dots[500] = "=============================================================================="; //80
    char f_name[500], l_name[500], email[500], userName[500], password[20], confirmPassword[20], contact[10];
    FILE *open;
    FILE *fptr;
    char login[800];
    
    printf("\n%s\n", dots);
    printf("%s", "\t \t");
    
    for(int i = 0; i < 19; i++){
        printf("%c", letter[i]);
        Sleep(20);
    }
    
    printf("%s", "\n"); //prints a new line
    
    for(int i = 0; i < 80; i++){
        printf("%c", dots[i]);
        Sleep(20);
    }
    
    start:
    printf("%s", "\n");
    printf("%s", "\nEnter your user name: ");
    fgets(userName, sizeof(userName), stdin);
    userName[strcspn(userName, "\n")] = 0;  // Remove newline character
    
    char a[900];
    char b[900];
    
    strcpy(a, userName);
    strcat(a, ".txt");
    
    open = fopen(a, "r");
    if(open == NULL){
    	printf("\nOops! No account was found wit %s username. Please make sure that the user name is correct and try again. \n", userName);
    	userName[strcspn(userName, "\n")] = 0;  // Remove newline character
    	//while(getchar() != '\n'); //clear input buffer
    	goto start;
	}
	
	
	try:
	printf("%s", "Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; //remove newline character
    
    strcpy(b, password);
    strcat(b, ".txt");
    
    fptr = fopen(b, "r");
    if(fptr == NULL){
    	printf("%s", "\nOops! Wrong password. Please try again. \n\n");
    	password[strcspn(password, "\n")] = 0; //remove newline character
    	goto try;
	}
	
	else{
		char lod[40] = "Loading please wait";
        char dot[10] = ".........";
    
        printf("\n%s", lod);
        for(int i = 0; i < 10; i ++){
            printf("%c", dot[i]);
            Sleep(900);
	    }
	    
		printf("\n%s", "Success!!!  Logging in......");
	}
	
	fclose(open);
	fclose(fptr); //close files
	
	system("cls");
	
	printf("\n=============================================%s ACCOUNT===============================================\n\n", userName);
	
	char lod[40] = "Loading please wait";
    char dot[10] = ".........";
    
    printf("\n%s", lod);
    for(int i = 0; i < 10; i ++){
        printf("%c", dot[i]);
        Sleep(900);
	} 
}

/* ============================GET PASSWORD=====================================*/
void getPassword(char *password){
    int index = 0;
    char ch;
    while ((ch = _getch()) != '\r'){ // '\r' is the Enter key
        if (ch == '\b') { // '\b' is the Backspace key
            if (index > 0) {
                index--;
                printf("\b \b"); // Erase the last character
            }
        } 
        else if (index < 19) {
            password[index++] = ch;
            printf("*"); // Print asterisk for each character
        }
    }
    password[index] = '\0'; // Null-terminate the string
    printf("\n");
}

/* =============================FORGOT PASSWORD MENU=====================================*/
void forgotPassword(void){
    printf("%s", "Why?\n");
}     

/* =============================HELP MENU=====================================*/
void help(void){
    printf("%s", "What help do you need? \n");
}
