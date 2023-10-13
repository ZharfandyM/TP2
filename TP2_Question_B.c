#include <stdio.h>
#include <ctype.h>          
#include <stdlib.h>         //Libary ctype.h, stdlib.h, string.h, stdbool.h are used for the error check funtion of the input
#include <string.h>
#include <stdbool.h>  

#define BUFFER_SIZE 2000

bool parse_int (char *string, int *integer){            //the error check funtion of the input
    int i = 0;

    while (isspace (string[i])) i++;        //skipping every whitespaces in the input

    int length = strlen (string);           //length variable to check the length of the string before \0

    if (length == i) return false;          //if every characters in the input

    char integer_buffer[BUFFER_SIZE];       //integer_buffer variable for storing the input string
    int integer_chars = 0;                  //integer_chars variable for counting the characters in integer_buffer

    if (string[i] == '-') return false;     //if there is a negative that means the input is incorrect

    while (i < length && !isspace (string[i])){         //checking every characters in the input
        if (!isdigit (string[i])) return false;         //if there is something other than an integer in the input, the input is incorrect

        integer_buffer[integer_chars] = string[i];      //assigning every qualified characters into the integer_buffer

        integer_chars++;                                
        i++;
    }

    integer_buffer[integer_chars] = '\0';           //adding \0 into the end of the integer_buffer

    while (isspace (string[i])) i++;                //skipping every whitespaces at the end of the input

    if (string[i] != '\0') return false;            //if there is still something after the \0 the input is incorrect

    *integer = atoi (integer_buffer);               //assigning the input into the integer variable

    if (*integer <= 0) return false;

    return true;
}

enum month {Januari = 1,            //enum is used to name the number 1-12 with the name of every month 
            Februari = 2, 
            Maret = 3, 
            April = 4, 
            Mei = 5, 
            Juni = 6, 
            Juli = 7, 
            Agustus = 8, 
            September = 9, 
            Oktober = 10, 
            November = 11, 
            Desember = 12};

int main (){
    char alphabet_input, buffer[BUFFER_SIZE], repeat;       
    bool parsed_correct = true;             //variable for the return value from the error check function
    enum month bulan;           //variable month to be assigned with the name of the chosen month
    int month_input;        //variable month_input to be assigned with the chosen number for the month

    system ("cls");         //clear the screen
    printf ("Selamat datang di program nama bulan.");

    do {    
        do {
            printf ("\n\nMasukkan satu huruf antara A-Z  : ");
            scanf (" %c", &alphabet_input);

            if (isalpha (alphabet_input) == 0){         //error check for the alphabet input
                printf ("\nEror, input salah.");
            }
        
        } while (isalpha (alphabet_input) == 0);            //while alphabet_input is not an alphabet, repeat the statements

        if (alphabet_input == 'A' || alphabet_input == 'a'){      
            
            do {
                printf ("\n(1) April\n(2) Agustus\n\nPilih salah satu  : ");

                scanf (" %s", buffer);         
                
                parsed_correct = parse_int (buffer, &month_input);   

                if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."  

                if (month_input != 1 && month_input != 2){          //if the month_input is not 1 and 2, the input is incorrect
                    
                    parsed_correct = false;                     //error check for the month_input

                    printf ("\nEror, input salah.\n");      
                }

                if (month_input == 1){
                    
                    bulan = April;              //if the user input 1, assign April to bulan
                }
                else if (month_input == 2){
                    
                    bulan = Agustus;
                }

            } while (!parsed_correct);          //while the month_input is incorrect, repeat the statements
        }
        else if (alphabet_input == 'D' || alphabet_input == 'd'){
            
            do {
                printf ("\n(1) Desember\n\nPilih salah satu  : ");          

                scanf (" %s", buffer);         
                
                parsed_correct = parse_int (buffer, &month_input);          //calling the error check for month_input

                if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."  

                if (month_input != 1){
                    
                    parsed_correct = false;                     //if the month_input is not 1, the input is incorrect, printf "Eror, input salah, and repeat the statements"

                    printf ("\nEror, input salah.\n");
                }

                if (month_input == 1){
                    
                    bulan = Desember;
                }

            } while (!parsed_correct);          //while month_input is incorrect, repeat the statements
        }
        else if (alphabet_input == 'F' || alphabet_input == 'f'){
            
            do {
                printf ("\n(1) Februari\n\nPilih salah satu  : ");

                scanf (" %s", buffer);         
                
                parsed_correct = parse_int (buffer, &month_input);          //calling the error check for the month_input

                if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."  

                if (month_input != 1){
                    
                    parsed_correct = false;             //if the month_input is not 1, the input is incorrect, printf "Eror, input salah."

                    printf ("\nEror, input salah.\n");
                }

                if (month_input == 1){
                    
                    bulan = Februari;              //assigning the name of the chosen month to bulan
                }

            } while (!parsed_correct);              //while month_input is incorrect, repeat the statements
        }
        else if (alphabet_input == 'J' || alphabet_input == 'j'){
            
            do {
                printf ("\n(1) Januari\n(2) Juni\n(3) Juli\n\nPilih salah satu  : ");

                scanf (" %s", buffer);         
                
                parsed_correct = parse_int (buffer, &month_input);   

                if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."  

                if (month_input != 1 && month_input != 2 && month_input != 3){      
                    
                    parsed_correct = false;         

                    printf ("\nEror, input salah.\n");          //if the month_input is not 1, 2, and 3, the input is incorrect, printf "Eror, input salah."
                }

                if (month_input == 1){
                    
                    bulan = Januari;
                }
                else if (month_input == 2){             //assigning the name of the month to bulan
                    
                    bulan = Juni;
                }
                else if (month_input == 3){
                    
                    bulan = Juli;
                }

            } while (!parsed_correct);          //while month_input is incorrect, repeat the statements
        }
        else if (alphabet_input == 'M' || alphabet_input == 'm'){
            
            do {
                printf ("\n(1) Maret\n(2) Mei\n\nPilih salah satu  : ");

                scanf (" %s", buffer);         
                
                parsed_correct = parse_int (buffer, &month_input);   

                if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."  

                if (month_input != 1 && month_input != 2){
                    
                    parsed_correct = false;

                    printf ("\nEror, input salah.\n");       //if the month_input is not 1 and 2, the input is incorrect, printf "Eror, input salah."
                }

                if (month_input == 1){
                    
                    bulan = Maret;
                }
                else if (month_input == 2){         //assigning the name of the chosen month to bulan
                    
                    bulan = Mei;
                }

            } while (!parsed_correct);          //while month_input is incorrect, repeat the statements
        }
        else if (alphabet_input == 'N' || alphabet_input == 'n'){
            
            do {
                printf ("\n(1) November\n\nPilih salah satu  : ");

                scanf (" %s", buffer);         
                
                parsed_correct = parse_int (buffer, &month_input);             //parsed_correct = the return value of the error check funtion of the month_input

                if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."  

                if (month_input != 1){
                    
                    parsed_correct = false;                     //if month_input is not 1, the input is incorrect, printf "Eror, input salah."

                    printf ("\nEror, input salah.\n");          
                }

                if (month_input == 1){
                    
                    bulan = November;           //assigning the name of the chosen month to bulan
                }

            } while (!parsed_correct);          //while month_input is incorrect, repeat the statements
        }
        else if (alphabet_input == 'O' || alphabet_input == 'o'){
            
            do {
                printf ("\n(1) Oktober\n\nPilih salah satu  : ");

                scanf (" %s", buffer);         
                
                parsed_correct = parse_int (buffer, &month_input);           //parsed_correct = the return value of the error check funtion of the month_input

                if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."  

                if (month_input != 1){
                    
                    parsed_correct = false;                     //if month_input is not 1, the input is incorrect, printf "Eror, input salah."

                    printf ("\nEror, input salah.\n");
                }

                if (month_input == 1){
                    
                    bulan = Oktober;            //assigning the name of the chosen month to bulan
                }

            } while (!parsed_correct);          //while month_input is incorrect, repeat the statements
        }
        else if (alphabet_input == 'S' || alphabet_input == 's'){
            
            do {
                printf ("\n(1) September\n\nPilih salah satu  : ");

                scanf (" %s", buffer);         
                
                parsed_correct = parse_int (buffer, &month_input);          //parsed_correct = the return value of the error check funtion of the month_input

                if (!parsed_correct) printf ("\nEror, input salah.\n");       //if the input is incorrect, print "Input salah."  

                if (month_input != 1){
                    
                    parsed_correct = false;                     //if month_input is not 1, the input is incorrect, printf "Eror, input salah."

                    printf ("\nEror, input salah.\n");
                }

                if (month_input == 1){
                    
                    bulan = September;          //assigning the name of the chosen month to bulan
                }

            } while (!parsed_correct);          //while month_input is incorrect, repeat the statements
        }
        else {
            printf ("\n\nTidak ada nama bulan yang dimulai dari huruf %c.", alphabet_input);            //if the user input alphabet that is not A or D or F or J or M or N or O or S, printf "Tidak ada nama bulan yang dimulai dari huruf %c."
        }

        //if bulan is either one of the month in a year, do the statements
        if (bulan == Januari || bulan == Februari || bulan == Maret || bulan == April || bulan == Mei || bulan == Juni || bulan == Juli || bulan == Agustus || bulan == September || bulan == Oktober || bulan == November || bulan == Desember){
        
            if (bulan == Januari){

                printf ("\nBulan Januari");
                
                printf ("\nJumlah karakter vokal  = 4");        //Januari have 4 vowels and 3 consonants

                printf ("\nJumlah karakter non vokal  = 3");
            }
            else if (bulan == Februari){

                printf ("\nBulan Februari");
            
                printf ("\nJumlah karakter vokal  = 4");        //Februari have 4 vowels and 4 consonants

                printf ("\nJumlah karakter non vokal  = 4");
            }
            else if (bulan == Maret){
                
                printf ("\nBulan Maret");

                printf ("\nJumlah karakter vokal  = 2");        //Maret have 2 vowels and 3 consonants
            
                printf ("\nJumlah karakter non vokal  = 3");
            }
            else if (bulan == April){

                printf ("\nBulan April");
            
                printf ("\nJumlah karakter vokal  = 2");        //April have 2 vowels and 3 consonants
            
                printf ("\nJumlah karakter non vokal  = 3");
            }
            else if (bulan == Mei){

                printf ("\nBulan Mei");
            
                printf ("\nJumlah karakter vokal  = 2");        //Mei have 2 vowels and 1 consonant
            
                printf ("\nJumlah karakter non vokal  = 1");
            }
            else if (bulan == Juni){

                printf ("\nBulan Juni");
            
                printf ("\nJumlah karakter vokal  = 2");       //Juni have 2 vowels and 2 consotants
            
                printf ("\nJumlah karakter non vokal  = 2");
            }
            else if (bulan == Juli){

                printf ("\nBulan Juli");
            
                printf ("\nJumlah karakter vokal  = 2");        //Juli have 2 vowels and 2 consonants
            
                printf ("\nJumlah karakter non vokal  = 2");
            }
            else if (bulan == Agustus){

                printf ("\nBulan Agustus");

                printf ("\nJumlah karakter vokal  = 3");        //Agustus have 3 vowels and 4 consonants
            
                printf ("\nJumlah karakter non vokal  = 4");
            }
            else if (bulan == September){

                printf ("\nBulan September");
            
                printf ("\nJumlah karakter vokal  = 3");        //September have 3 vowels and 6 consonants
            
                printf ("\nJumlah karakter non vokal  = 6");
            }
            else if (bulan == Oktober){

                printf ("\nBulan Oktober");
            
                printf ("\nJumlah karakter vokal  = 3");        //Oktober have 3 vowels and 4 consonants
            
                printf ("\nJumlah karakter non vokal  = 4");
            }
            else if (bulan == November){

                printf ("\nBulan November");
            
                printf ("\nJumlah karakter vokal  = 3");        //November have 3 vowels and 5 consonants
            
                printf ("\nJumlah karakter non vokal  = 5");
            }
            else if (bulan == Desember){

                printf ("\nBulan Desember");
            
                printf ("\nJumlah karakter vokal  = 3");        //Desember have 3 vowels and 5 consonants
            
                printf ("\nJumlah karakter non vokal  = 5");
            }
        }

        do {
            printf ("\n\nIngin coba lagi? (Y/N)  : ");          //asking if the user wants to repeat the program or not
            scanf (" %c", &repeat);
                
            if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n'){      //if the user input something other than Y, y, N, and n, the input is incorrect
                printf ("\nEror, input salah.\n");                                      //printf "Eror, input salah."
            }
            else{
            }
            
        } while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');     //if the user input something other than Y, y, N, and n, repeat the statements
        
    } while (repeat == 'Y' || repeat == 'y');       //if the user input Y or y, repeat the program

    printf ("\nTerima kasih.");

    return 0;
}