/*!
@file       the name of source file is qdrive.c
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   Assignment 7
@date       file created on 22/10/2023
@brief      provide a brief explanation about what this source file does:
            
			recives data from file to be encrypted or decrypted.

			encryption:
			- open 2 read and 1 write files for for encryption.
            - encrypt(int *letter, char key);              		// takes one char from the encrypt function in qdriver(*letter(pointing to the value contained in the varible in qdriver)) and a char from varible in qdriver
           
		   decryption:
			- open 2 read and 1 write files for for decryption.
			- decrypt(int *letter, char key);              		// takes one char from the decrypt function in qdriver(*letter(pointing to the value contained in the varible in qdriver)) and a char from varible in qdriver
			- close write file and re-openr to count number of words in the file.  

            using ASCII_COUNT defined in q.c to make sure the added or subtracted vales are in the range of ASCII number.
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________*/

#include "q.h"
char key[225];
int  counter = 0, input = 0, key_len = 0;

// TODO2: Add necessary C standard library headers ...
int main(void){
#ifdef ENCRYPT

	// TODO3: read characters from input file plain.txt and write the corresponding encrypted 
	// characters to output file cipher.txt using the keyword in file key.txt
	
	//Access and open file and check if file exist
	/*==============================================================================================================================================*/
		FILE *key_file = fopen("key.txt", "r"); 							// only read from file 
		FILE *input_file = fopen("plain.txt", "r"); 						// only read from file 
		FILE *output_file = fopen("cipher.txt", "w"); 						// only write to file
		
		if (key_file == NULL){ fprintf(stderr, "Unable to open file key.txt\n"); return 0;}			// fclose(key_file);
		if (input_file == NULL){ fprintf(stderr, "Unable to open file plain.txt\n"); return 0;}		// fclose(input_file);
		if (output_file == NULL){ fprintf(stderr, "Unable to open file cipher.txt\n"); return 0;}	// fclose(output_file); 
	/*==============================================================================================================================================*/

	// word encrypt
	/*==============================================================================================================================================*/
		if(fgets(key, sizeof(key), key_file) != NULL){						// to get the all text in the file till a null char is found
			key_len = (int)(strlen(key)-2);									//and get the lenght of the text in key_file
		}
		while((input = fgetc(input_file)) != EOF){
			encrypt(&input, key[counter++]);
			fputc(input, output_file);
			if(counter == key_len){counter = 0;}
		}
		fclose(key_file);													// closing key_file
		fclose(input_file);													// closing input_file
		fclose(output_file);												// closing output_file
	/*==============================================================================================================================================*/
	return 0;

#else 	
	// TODO4: read characters from input file cipher.txt and write the corresponding decrypted 
	// characters to output file out-plain.txt using the keyword in file key.txt
	
	// Access and open file and check if file exist
	/*==============================================================================================================================================*/
		FILE *key_file = fopen("key.txt", "r"); 							// only read from file 
		FILE *input_file = fopen("cipher.txt", "r"); 						// only read from file
		FILE *output_file = fopen("out-plain.txt", "w"); 					// only write to file 

		if (key_file == NULL){ fprintf(stderr, "Unable to open file key.txt\n"); return 0;}			//fclose(key_file);
		if (input_file == NULL){ fprintf(stderr, "Unable to open file plain.txt\n"); return 0;}		//fclose(input_file);
		if (output_file == NULL){ fprintf(stderr, "Unable to open file cipher.txt\n"); return 0;}	//fclose(output_file); 
	/*==============================================================================================================================================*/
	
	// word decrypt
	/*=============================================================================================================================================*/
		if(fgets(key, sizeof(key), key_file) != NULL){						// to get the all text in the file till a null char is found
			key_len = (int)(strlen(key)-2);									//and get the lenght of the text in key_file
		}
		while((input = fgetc(input_file)) != EOF){
			decrypt(&input, key[counter++]);
			fputc(input, output_file);
			if(counter == key_len){counter = 0;}
		}
		fclose(key_file);													// closing key_file
		fclose(input_file);													// closing input_file
		fclose(output_file);												// closing output_file
	/*==============================================================================================================================================*/
	
	// TODO5: write count of words into stderr  // word counter
	/*==============================================================================================================================================*/	
		FILE *error_file = fopen("out-plain.txt", "r");								// re-opening file that has been closed previously
		
		int ch, word_count = 0, char_check = 0;
		
		while((ch = fgetc(error_file)) != EOF){										// get the ASCII of char from char in error_file(point to data in out-plain.txt) and store into ch
			if (ch == 9 || ch == 10 || ch == 13 || ch == 32) {						// check if ch is 9 = tab('\t') or 10 = newline('\n') or 13 = carriagereturn('\r'), 32 = space(' ')
				char_check = 0;
			}
			else if (!char_check) {
				char_check = 1;
				word_count++;
			}
		}
		fprintf(stderr,"Words: %d\n", word_count);									// print word_count to file when error is active
		fclose(error_file);
	/*==============================================================================================================================================*/
	return 0;

#endif
	return 0;
}
