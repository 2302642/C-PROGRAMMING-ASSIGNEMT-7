/*!
@file       the name of source file is q.c
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Assignment 7
@date       file created on 22/10/2023
@brief      provide a brief explanation about what this source file does:
            
            This file is contains 2 function declaraction be to called by main in qdriver.
            Functions:
            - void encrypt(int *letter, char key);              // takes one char from the encrypt function in qdriver(*letter(pointing to the value contained in the varible in qdriver)) and a char from varible in qdriver
            - void decrypt(int *letter, char key);              // takes one char from the decrypt function in qdriver(*letter(pointing to the value contained in the varible in qdriver)) and a char from varible in qdriver

            using ASCII_COUNT defined in q.c to make sure the added or subtracted vales are in the range of ASCII number.
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

#include "q.h" // included because q.c requires access to ASCII_COUNT

// TODO2: include other C standard library headers. for reasons explained in previous assignments/labs, 
// think carefully about the need to add an include file before you do so ...
// TODO3: define functions encrypt and decrpyt ...
void encrypt(int *letter, char key){
    
    int ASCII_letter = *letter + key;       // added ASCII of *letter(refers to [input = fgetc(input_file)]{getting a char from input_file}).
                                            // and ASCII of key to get a encrypted char in ASCII form .
    if(ASCII_letter > ASCII_COUNT){         // check if ASCII_letter is more then ASCII_COUNT.
        ASCII_letter -= ASCII_COUNT;
    }
    else if(ASCII_letter < 0){              // check if ASCII_letter is less then ASCII_COUNT.
        ASCII_letter += ASCII_COUNT;
    }
    *letter = ASCII_letter;                 // resetting ASCII_letter to *letter / returning encryped value using *letter.
}
void decrypt(int *letter, char key){
    
    int ASCII_letter = *letter - key;       // subtract ASCII of *letter(refers to [input = fgetc(input_file)]{getting a char from input_file}). 
                                            // and ASCII of key to get a encrypted char in ASCII form.
    if(ASCII_letter < 0){                   // check if ASCII_letter is less then ASCII_COUNT.
        ASCII_letter += ASCII_COUNT;
    }
    else if(ASCII_letter > ASCII_COUNT){    // check if ASCII_letter is more then ASCII_COUNT.
        ASCII_letter -= ASCII_COUNT;
    }
    *letter = ASCII_letter;                 // resetting ASCII_letter to *letter / returning encryped value using *letter.
}
