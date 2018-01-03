#include <stdio.h> // Standard library included for file io
char *uppercase(char *text); // Returns upper-cased version of text
char *lowercase(char *text); // Returns lower-cased version of text
char *reverse(char *text); // Returns reversed-version of text
char *itos(long long int number); // Converts long-long-int to string
int arrlen(int arrsize); // Returns length of int array, takes sizeof(array) as parameter
int intint(int *arr, int n, int arrsize); // Searches array for int, returns 1 if found
int intlen(int number); // Returns int length
int infile(char *file_name, char *text); // Searches file for text, returns 1 if found
int maxint(int *arr, int arrsize); // Returns maximum int value from array
int minint(int *arr, int arrsize); // Returns minimum int value from array
void strsort(char **arr, int arrsize); // Sorts array of string / pointers in ascending
void intsort(int *arr, int size); // Sorts array of int in ascending
long long int sum(int *arr, int arrsize); // Returns sum of elements of int array
long long int multiply(int *arr, int arrsize); // Returns multipli. of elements of int array
double flsum(double *arr, int size); // Returns sum of elements of double array
double flmultiply(double *arr, int size); // Returns multipli. of elements of double array
int *intarr(int args, ...); // Returns array with args int
char **strarr(int args, ...); // Returns array with args str
char *timenow(); // Returns string of current time
void flwrite(char *file_name, char *text); // Writes text to file
void flappend(char *file_name, char *text); // Appends text to file; Creates new if !exist
int flread(char *file_name); // Reads and printf from file; Returns 0 if file doesn't exist
char *flreadline(FILE *fp); // Reads next line from file
void open_url(char *url); // Opens webpage containing the url
int catch_signal(int sig, void (*handler)(int)); // Catches and handles signals
void error(char *msg); // Displays error msg and exits program with exit code 1
int swapstream(int n_desc, int std_desc); // Swaps standard streams with others
int redstream(int n_desc, int std_desc); // Redirects standard streams
char **split(char *str, char split_char); // Splits a string and returns an array of strings
void ppause(char *msg); // Pauses a program; Waits for user input (char)
void psleep(int second); // Delays or pauses program for n second (n == second(arg))
void clear(); // Clears console screen
void failure(char *msg); // Displays task failure msg with error code
void strswap(char **str_one, char **str_two); // Swaps two strings
void intswap(int *int_one, int *int_two); // Swaps two ints
void flswap(float *fl_one, float *fl_two); // Swaps two floats

