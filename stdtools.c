
/* =============================================================
 *
 *     Filename : stdtools.c
 *
 *  Description : A C library. Contains several useful small
 *                   C tools for reducing development time and 
 *                   faster production.
 *
 *      Version : 0.1.1.5
 *      Created : 12 December, 2017
 *     Compiler : gcc
 *
 * =============================================================
 */

#include "stdtools.h" // Function definitions
#include <string.h>   // String functions
#include <stdlib.h>   // Standard library functions
#include <stdio.h>    // Command prompt I/O
#include <stdarg.h>   // Standard argument handler
#include <time.h>     // Time 
#include <sys/signal.h>   // Signal handler
#include <errno.h>    // Error number 
#include <unistd.h>   // POSIX OS API
#define OS 1 // Define macro 'OS' as 1; *nix based OS is 1
#ifdef _WIN32 // Checks for OS; Redefines macro 'OS' to 0 if Windows
#include <windows.h>  // Windows functions; Only usable when compiled on Windows
#undef OS    // Undefine OS
#define OS 0 // Redefine OS to 0 
#endif // _WIN32

/*
 * Function: Converts text to uppercase
 * Checks if character of char pointer 'text' is between 'a' - 'z'
 * Assigns uppercase format of char to 'str' by subtracting 32 if true
 * Else, assigns default char to 'str'
 */
char *uppercase(char *text){
    char *str = malloc(strlen(text)); // Allocate storage for char pointer 'str'
    int i = 0;
    while (*text){ // If *text(char) is not NULL(\0) or 0
        if ((*text >= 'a') && (*text <= 'z')) // Check if char is in lowercase
            *(str + i) = *text - 32; // Convert to uppercase 
        else
            *(str + i) = *text; // Assign default char
        ++i;
        ++text; // Go to next char
    }
    return str;
}

/*
 * Function: Converts text to lowercase
 * Checks if character of char pointer 'text' is between 'A' - 'Z'
 * Assigns lowercase format of char to 'str' by adding 32 if true
 * Else, assigns default char to str
 */
char *lowercase(char *text){
    char *str = malloc(strlen(text)); // Allocates storage for char pointer 'str'
    int i = 0;
    while (*text){ // If *text(char) is not NULL(\0) or 0
        if ((*text >= 'A') && (*text <= 'Z')) 
            *(str + i) = *text + 32; // Convert char to lowercase
        else
            *(str + i)= *text; // Assign default char
        ++i;
        ++text; // Go to next char
    }
    return str;
}

/*
 * Function: Reverses a string
 * Assigns value from the end of 'text' to the beginning of 'reverse_str'
 */
char *reverse(char *text){
    char *reverse_str = malloc(strlen(text)); // Allocate storage for char pointer reverse_str
    int len = strlen(text) - 1, i = 0;
    while (len >= 0){
        // Assign char from end of text to start of reverse_str
        *(reverse_str + i) = *(text + len);
        --len;
        ++i;
    }
    return reverse_str;
}

/*
 * Function: Convert int to string
 * prints value of int num using sprintf to str
 */
char *itos(long long int num){
    char *str = malloc(sizeof(char *)); // Allocates storage for char pointer str
    sprintf(str, "%lld", num); // Prints value of num as string to str 
    return str;
}

/*
 * Function: Returns array of length
 * arrsize is (number of element * sizeof(int))
 * so number of element(arrlen) is arrsize / sizeof(int)
 */
int arrlen(int arrsize){
    return (arrsize / sizeof(int));
}

/*
 * Function: Checks int array for int
 * Take array(arr), int to find(n), size of array
 * Goes through each int in array
 * If int is equal to n, returns 1
 * If loop ends and not found, returns 0
 */
int intint(int *arr, int n, int arrsize){
    int i = 0, len = arrlen(arrsize); // arrsize is sizeof(arr)
    while (i < len){
        if (arr[i] == n){ // Checks if number 'i' element of arr is equal to n
            return 1; // Returns true
        }
        ++i;
    }
    return 0; // Returns false
}

/*
 * Function: Calculate length of int
 * For positive values, Divides number in loop
 * by 10 while number > 0, length of number 
 * is reduced by 1, and len is increased by 1
 * For negative values, same process as pos.
 * but loops condition is for number to be
 * less than 0
 * Length is 0 if number is 0
 */
int intlen(int number){
    int len = 0;
    if (number > 0){ // Positive number approach
        while (number > 0){
            number /= 10; // Length of real number reduced by 1
            ++len; // But length of number is increased by 1
        }
    }
    else if (number < 0){ // Negative number approach
        while (number < 0){
            number /= 10;
            ++len;
        }
    }
    else
        len = 0; // Length is 0 if number is 0
    return len;
}

/*
 * Function: Searches for text in file
 * Takes file_name and text to search as arg
 * Searches file line by line for text
 * Returns 0 if file doesn't exist or 
 * text isn't in file
 * Returns 1 if text is in file
 */
int infile(char *file_name, char *text){
    char line[100];
    FILE *file;
    if (!(file = fopen(file_name, "r"))){ // Opens and checks for file's existence 
        fprintf(stderr, "\n File not found. \n");
        return 0;
    }
    while (fscanf(file, "%99[^\n]\n", line) == 1){ // Read file line by line
        if (strstr(line, text)) // Checks if text is present in line
            return 1;
    }
    return 0; // If end of file
}

/*
 * Function: Returns maximum int from array
 * Take array and sizeof(array) as arg
 * Assigns arr[index] to max if arr[index] > max
 */
int maxint(int *arr, int arrsize){
    int max = arr[0]; // Assign value of arr[0] to max
    int index = 1, len = arrlen(arrsize);
    while (index < len){
        if (max < arr[index]) // Checks if arr[index] is > max
            max = arr[index];
        ++index;
    }
    return max;
}

/*
 * Function: Returns minimum int from array
 * Take array and sizeof(array) as arg
 * Assigns arr[index] to max if arr[index] < max
 */
int minint(int *arr, int arrsize){
    int min = arr[0]; // Assign value of arr[0] to min
    int index = 1, len = arrlen(arrsize);
    while (index < len){
        if (min > arr[index]) // Checks if arr[index] < min
            min = arr[index];
        ++index;
    }
    return min;
}

/*
 * Function: Sorts array of strings / pointers
 * in alphabetical order.
 * Compares values of arr[index] and arr[index + 1]
 * If returned value is > 0, swap values
 */
void strsort(char **arr, int size){
    char *temp = malloc(sizeof(char *)); // Allocates storage for char pointer temp
    int i, j, arrsize = arrlen(size);
    for (i = 0; i < arrsize; ++i){
        for (j = 0; j < arrsize - 1; ++j){
            if (strcmp(arr[j], arr[j + 1]) > 0){ // Compares arr[j] and arr[j + 1]
                // Swaps arr[j] and arr[j + 1] if true
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
 * Function: Sorts array of int
 * Takes array and sizeof(array) as arg
 * Compares values of arr[index] and arr[index + 1]
 * If arr[index] > arr[index + 1], swaps values
 */
void intsort(int *arr, int size){
    int arrsize = arrlen(size);
    int temp, i, j;
    for (i = 0; i < arrsize; ++i){
        for (j = 0; j < arrsize - 1; ++j){
            if (arr[j] > arr[j + 1]){ // Compares arr[j] and arr[j + 1]
                // Swaps arr[j] and arr[j + 1] if true
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
 * Function: Calculates sum of elements of int array
 * Takes array and sizeof(array) as arg
 * Adds value of arr[index] to sum in each loop
 */
long long int sum(int *arr, int size){
    int arrsize = arrlen(size), i;
    long long int sum = 0;
    for (i = 0; i < arrsize; ++i){
        sum += arr[i];
    }
    return sum;
}

/*
 * Function: Calculates multiplication of elements of int array
 * Takes array and sizeof(array) as arg
 * Adds value of (arr[index] * multiply) to multiply in each loop
 */
long long int multiply(int *arr, int size){
    int arrsize = arrlen(size), i;
    long long int multiply = 1;
    for (i = 0; i < arrsize; ++i){
        multiply *= arr[i];
    }
    return multiply;
}

/*
 * Function: Calculates sum of elements of double array
 * Takes array and sizeof(array) as arg
 * Adds value of arr[index] to sum in each loop
 */
double flsum(double *arr, int size){
    int arrsize = size / 8, i;
    double sum = 0;
    for (i = 0; i < arrsize; ++i){
        sum += arr[i];
    }
    return sum;
}

/*
 * Function: Calculates multiplication of elements of double array
 * Takes array and sizeof(array) as arg
 * Adds value of (arr[index] * multiply) to multiply in each loop
 */
double flmultiply(double *arr, int size){
    int arrsize = size / 8, i;
    double multiply = 1;
    for (i = 0; i < arrsize; ++i){
        multiply *= arr[i];
    }
    return multiply;
}

/*
 * Function: Creates array of int values
 * Takes argument count and int(s) as arg
 * Creates variadic list ap
 * Sets start point of ap to args
 * Assigns variadic arguments to *(arr + index)
 */
int *intarr(int args, ...){
    int *arr = malloc(sizeof(int) * args); // Allocates storage for int array
    int i;
    va_list ap; // Initialize variadic argument list
    va_start(ap, args); // Set start point of ap to args
    for (i = 0; i < args; ++i)
        /* Sets type of arguments to int
         * Assigns int to array
         */
        *(arr + i) = va_arg(ap, int);
    va_end(ap); // Ends list
    return arr;
}

/*
 * Function: Creates array of string values
 * Takes argument count and string(s) as arg
 * Creates variadic list ap
 * Sets start point of ap to args
 * Sets type of arguments to string / char pointer
 * Assigns variadic arguments to *(arr + index)
 */ 
char **strarr(int args, ...){
    char **arr = malloc(sizeof(char *) * args); // Allocate storage for string array
    int i;
    va_list ap; // Creates variadic argument list 
    va_start(ap, args); // Sets start point of ap to args
    for (i = 0; i < args; ++i)
        /* Sets type of arguments to string
         * Assigns int to array
         */
        *(arr + i) = va_arg(ap, char*); 
    va_end(ap); // Ends list
    return arr;
}

/*
 * Function: Returns current time in string format
 * Gets localtime using localtime()
 * Returns time in ASCII format
 */
char *timenow(){
    time_t t; // Creates variable t of type time_t to store current time
    time (&t);  // Stores current time in variable 't'
    return asctime(localtime(&t)); // Returns localtime in ASCII format
}

/*
 * Function: Writes text to file
 * Takes file_name and text as arg
 * Creates/Opens a file with file_name in write mode
 * Writes to file and closes
 */
void flwrite(char *file_name, char *text){
    FILE *fp = fopen(file_name, "w"); // Opens a file with file_name in writing format
    fprintf(fp, "%s", text); // Writes text to file
    fclose(fp); // Closes file
}

/*
 * Function: Appends text to file
 * Takes file_name and text as arg
 * Opens a file with file_name in append mode,
 * creates new if doesn't exist
 * Appends/writes to file, closes file
 */
void flappend(char *file_name, char *text){
    FILE *fp; // Creates a FILE pointer
    if (!(fp = fopen(file_name, "a"))) // Checks for file's existence
        fp = fopen(file_name, "w"); // Creates new file if file doesn't exist
    fprintf(fp, "%s", text); // Appends/writes to file
    fclose(fp); // Closes file
}

/*
 * Function: Reads a file line by line
 * Takes file_name as arg
 * Attempts to open file, returns 0 if file doesn't exist
 * Reads lines from file till NULL
 * Returns 1
 */
int flread(char *file_name){
    char line[100]; // Creates a char array to store lines from files
    FILE *fp; // Creates a FILE pointer
    if (!(fp = fopen(file_name, "r"))) // Attempts to open file in read mode
        return 0; // Returns 0 if attempt fails
    while (fscanf(fp, "%99[^\n]\n", line) == 1) // Reads lines from file till NULL
        printf("\n %s",line); // Prints line read from file
    return 1; // Returns 1 if function worked correctly
}

/* 
 * Function: Reads next line from file
 * Takes FILE pointer as arg
 * Returns next line from file
 */
char *flreadline(FILE *fp){
    char *line = malloc(sizeof(char *)); // Allocates storage for char pointer
    fscanf(fp, "%99[^\n]\n", line); // Reads next line from file
    return line; // Returns line
}

/* 
 * Function: Opens webpage in browser
 * Takes webpage url as arg
 * Opens webpage with url using system
 */
void open_url(char *url){
    char cmd[100]; // Creates char array for command
    sprintf(cmd, "cmd /c start %s",url); 
    system(cmd); // Opens webpage on Windows
    sprintf(cmd, "x-www-browser '%s' &",url);
    system(cmd); // Opens webpage on Linux
    sprintf(cmd, "open %s",url);
    system(cmd); // Opens webpage on Mac
}

/* 
 * Function: Catches signal from keyboard
 * Takes signal number and a function as args
 * Creates struct variable
 * Assign signal handler to function 'handler'
 * Sets additional flags to 0
 * Returns action
 */
int catch_signal(int sig, void (*handler)(int)){
    struct sigaction action; // Creates a struct action
    action.sa_handler = handler; // Sets handler function
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0; // Sets additional flags to 0
    return sigaction(sig, &action, NULL); // Returns action
}

/*
 * Function: Useful function to display error message
 * Takes msg as arg
 * Displays msg with error type and details
 * Terminates program
 */
void error(char *msg){
    fprintf(stderr, " %s : %s\n",msg,strerror(errno)); // Display msg with error type and details
    exit(1); // Exit with code 1
}

/*
 * Function: Swaps data streams 
 * Takes n_desc(new descriptor) and std_desc(standard descriptor) as arg
 * Swapping streams:
 * Creates duplicate standard descriptor to file's descriptor
 * Creates duplicate new descriptor to previous standard descriptor
 * Creates duplicate standard descriptor to n_desc(Previously new descriptor)
 * Swap complete
 * err_code set to -1 if task failed, else 1
 * Returns err_code
 */
int swapstream(int n_desc, int std_desc){
    FILE *fp = fopen("temp.txt","w"); // Opens file 'temp.txt' to use as a stream holder
    int err_code = ((dup2(std_desc, fileno(fp)) == -1) || (dup2(n_desc, std_desc) == -1) || (dup2(fileno(fp), n_desc) == -1)) ? -1 : 1; // Swaps stream and checks for errors
    fclose(fp); // Closes file
    system("rm temp.txt"); // Remove file 'temp.txt'
    return err_code; // Return error code
}

/*
 * Function: Redirects data stream
 * Takes n_desc(new descriptor) and std_desc(standard descriptor) as arg
 * Redirecting streams:
 * Creates duplicate n_desc to std_desc
 * Redirect complete
 * err_code set to -1 if task failed, else 1
 * Returns err_code
 */
int redstream(int n_desc, int std_desc){
    int err_code = (dup2(n_desc, std_desc) == -1) ? -1 : 1; // Redirects stream and checks for errors
    return err_code; // Returns error code
}

/*
 * Function: Splits a string and returns an array of strings/pointers
 * Takes str(char pointer) and split_char(char) as arg
 * Goes through each character of str
 * Assigns each char to array of pointer/strings
 * If character == split_char, current string ends
 * Allocates storage for new strings
 * Returns array of string/pointers
 */
char **split(char *str, char split_char){
    char **split_str = malloc(sizeof(char *) * 1000); // Allocates storage for array of strings with size of 1000 strings of sizeof char *
    int len = strlen(str); // Gets length of str
    int s_str_index = 0, char_index = 0, str_index = 0;
    *(split_str + s_str_index) = malloc(sizeof(char *)); // Allocates storage for first string of array
    while (*str){ // Loops until *str/char of str is not NULL or '\0'(0)
        if (*str == '\n') break; // Checks if char of str is last and char is '\n'
        if (*str != split_char){ // Checks if char of str is not equal to split_char
            *(*(split_str + s_str_index) + char_index) = *str; // Assigns char of str to char of index 'char_index' of string of index 's_str_index' 
            ++char_index; // Sets next character's index
        }
        else{
            ++s_str_index; // Sets next string's index
            char_index = 0; // Sets next character's index to 0
            if (str_index + 1 != len){ 
                *(split_str + s_str_index) = malloc(sizeof(char *)); // Allocates storage in array for new string
            }
        }
        ++str;
        ++str_index;
    }
    return split_str; // Return array of strings
}

/*
 * Function: Pauses a program
 * Takes msg as arg
 * Displays msg and waits for char input
 */
void ppause(char *msg){
    printf("\n %s",msg); // Displays msg
    getchar(); // Waits for char input
}

/*
 * Function: Delays or pauses program for 'n' second
 * Takes second as arg
 * Uses sleep function to sleep program
 */
void psleep(int second){
    printf("\n");
    if (OS) sleep(second); // sleep in Linux and other OS
    else Sleep(second * 1000); // Sleep in Windows
}

/*
 * Function: Clears console screen
 * Uses system function to clear console screen
 */
void clear(){
    if (OS) system("clear"); // Clears console screen in Linux and other OS
    else system("cls"); // Clears console screen in Windows
}
