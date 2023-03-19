#include <stdio.h>
#include <unistd.h>
#include "gruvbox.h"

// Set background color.
void brewBackgroundColor(int color){
	printf("\033[48;5;%dm", color);
}

// Set font color.
void brewForegroundColor(int color){
	printf("\033[38;5;%dm", color);
}

// Set cursor position.
void brewCursor(int pX, int pY){
	printf("\033[%d;%dH", pX, pY);
}

// Clears entire terminal
void brewClear(){
	printf("\033[2J");
}


// Draw a matrix of characters in a specific location, width, height and font Color.
void brewMatrix(char *string, int pX, int pY, int mX, int mY, int fgC){
	int x, y;
	brewForegroundColor(fgC);
	brewCursor(pX, pY);
	for(y = 0; y < mY; y++){
		printf("\033[%dG", mY);
		for(x = 0; x < mX; x++){
			printf("%s", string);
		}
		printf("\n");
	}
}


// Draw text in a specific location with specified color.
void brewText(char *string, int pX, int pY, int color){
	brewCursor(pX, pY);
	brewForegroundColor(color);
	printf("%s", string);
}


// Wait for enter key press, reset terminal to default.
void brewEnd(){
	getchar();
	printf("\033c");
}

// MAIN FUNCTION
int main(){
	brewMatrix("#",2,2,2,2,gruvbox.bg)
}
