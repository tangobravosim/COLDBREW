#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>
#include <stdbool.h>
#include "gruvbox.h"

struct gruvbox gruvbox;
struct widgetVar { int w; int h; bool darkTheme; bool waitEnd; } widget;

//	wchar_t ulCorner = L'\u256D'; // Upper left corner
//	wchar_t urCorner = L'\u256E'; // Upper right corner
//	wchar_t llCorner = L'\u2570'; // Lower left corner
//	wchar_t lrCorner = L'\u256F'; // Lower right corner
//	wchar_t hLine    = L'\u2500'; // Horizontal line
//	wchar_t vLine    = L'\u2502'; // Vertical line

// Move cursor to x, y
void brewCursor(int cX, int cY){
	printf("\033[%d;%dH", cY, cX );
}


// Draw Matrix of defined character at specific position and defined size
void brewMatrix(char *mChar, int cursorX, int cursorY, int mWidth, int mHeight){
	brewCursor(cursorX, cursorY);
	int x, y;
	for(y = 0; y < mHeight; y++){
		printf("\033[%dG", cursorX);
		for(x = 0; x < mWidth; x++){
			printf("%s", mChar);
		}
		printf("\n");
	}
}

void drawWindow(){
	
}
	

// Initialise coldbrew - 130,10 is iSH default. Independent.
void brewInit(int wWidth, int wHeight, bool themeIsDark, bool cWait){
	
	setlocale(LC_ALL, "en_US.UTF-8");
	
	// Initialise widget variables
	widget.w = wWidth;
	widget.h = wHeight;
	widget.darkTheme = themeIsDark;
	widget.waitEnd = cWait;
			
			
	// Initialise color scheme
	if(widget.darkTheme == true){
		gruvbox = gruvbox_dark;
	}else{
		gruvbox = gruvbox_light;
	}
	
	// Set background, foreground color.
	printf("\033[2J");
	printf("\033[1;1H");
	printf("\033[48;5;%dm", gruvbox.bg);
	printf("\033[38;5;%dm", gruvbox.fg);
	
	
	// Draw background matrix.
	int x, y;
	for(y = 0; y < widget.h; y++){
		for(x = 0; x < widget.w; x++){
			printf(" ");
		}
		printf("\n");
	}
	
}

void brewEnd(){
	printf("\033[0m");
	printf("\033[%d;1H", widget.h+1);
	if(widget.waitEnd){
		getchar();
	}
}

int main(){
	brewInit(138,10,true,false);
	brewBlock(2,2,5,5);
	brewEnd();
}