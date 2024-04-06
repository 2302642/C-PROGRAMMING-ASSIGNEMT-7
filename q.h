/*!
@file       the name of source file is q.h
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Assignment 7
@date       file created on 22/10/2023
@brief      provide a brief explanation about what this source file does:
            
            This file is contains 2 function declaraction be to called by 
            main in qdriver. As well as, contain libaries and pre defined 
            value(ASCII_COUNT) to be used in q.c and qdrive.c
__________________________________________________________________________*/
#ifndef Q_H
#define Q_H
#include <stdio.h>
#include <string.h>
// Don't remove!!!
// We're limiting ASCII set to the basic character set
// with encoding from 0 to 127
#define ASCII_COUNT 128
// TODO2: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function encrypt
// TODO3: declaration for function encrypt
void encrypt(int *letter, char key)
// TODO4: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function decrypt
// TODO5: declaration for function decrypt
void decrypt(int *letter, char key);
#endif // Q_H
