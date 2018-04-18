/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * 24.10.2017
 */

#ifndef YAPILAR_H
#define YAPILAR_H

#define rows 15
#define columns 15

char *puzzleFile = (char*) "puzzle.txt";
char *searchedWordFile = (char*) "searchedwords.txt";

struct searchedWord {
	int id;
	char* word;
	int wordLength;
};

char **puzzleArray;
char **finalPuzzleArray;

int numberWords;

searchedWord *wordsArray;

#endif