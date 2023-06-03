// Maria Pilar Isabel S. Aguire
// CMSC 21 Lecture Assignment

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
// Declaration of the two functions to be used
void scan_word(int occurences[26]);
bool is_anagram(int occurences1[26],int occurences2[26]);

int main(void){
	
	int i,
		occurences1[26]={0},
		occurences2[26]={0};
	// passes the occurences1 array to the scan word function	
	printf("Enter first word: ");
	scan_word(occurences1);
	// passes the occurences2 array to the scan word function
	printf("Enter second word: ");
	scan_word(occurences2);	
	
	// determines if the two words are anagrams
	if(is_anagram(occurences1, occurences2)){
		printf("The words are anagrams.\n");}
	else{
		printf("The words are not anagrams.\n");}
		
}

// scan word function

void scan_word(int occurences[26]){
// temporary variable c to get user input one char at a time
	char c;
	while(( c = getchar())!=  '\n'){
		if(isalpha(c)){
			// if the character scanned is a letter adds one to the designated memory address
			*(occurences+(toupper(c) -'A'))+=1;}
			}
	}
// is anagram function - determines if the given two words are anagrams	
bool is_anagram(int occurences1[26],int occurences2[26]){
	bool anagram = true;
	for(int i=0;i<26;i++){
		// determines from the number of occurences if they are anagrams
		// If the number of occurences at a certain index do not match, anagram is set to false and the loop breaks
		if(!(*(occurences1+i)==*(occurences2+i))){ anagram = false; break;}
		}
	// returns true if anagram and false if not
	return anagram;
		}

