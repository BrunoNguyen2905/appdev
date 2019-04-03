//this is main.c
#include<stdio.h>
#include<signal.h> 
#include<stdlib.h>
#include<time.h>
#include "screen.h" // for user-defined header, use double quotes
#include"sound.h"
int main(){
	FILE  *f;
	short sd[RATE]; // fll samples in 1 sec
	while(1){
		int ret = system(CMD);
		if(ret == SIGINT) break;
		f= fopen("test.wav", "r"); // open the file for read only
		clearScreen();
		setColors(CYAN, bg(BLACK));
		if(f==NULL){
			printf("Cannot open the file\n");
			return 1;
		}
		struct WAVHDR h; //instace if wav header
		fread(&h, sizeof(h),1,f); //read wav header to h
		displayWAVHDR(h);
		fread(sd, sizeof(sd), 1, f); // read wav header to h
		displayWAVDATA(sd);
		fclose(f); //close the opened file
	}
	resetColors();
}
