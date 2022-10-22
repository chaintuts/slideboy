/* This file contains simple GBA slideshow code
*
* Author: Josh McIntyre
*/

#include <gba_types.h>
#include <gba_input.h>
#include <string.h>

#include "slideboy.h"
#include "img1.h"
#include "img2.h"
#include "img3.h"

/* The main entry point for the program */
int main(void) {

	// Load the Bitmap into memory using memcpy
	memcpy(vid_mem, img1Bitmap, img1BitmapLen);
	
	// Next, set the video mode to 3
	// Video mode 3 supports 240x160 pixel images with 16 bits per pixel
	REG_DISPCNT = VIDMODE | DCNT_BG2;

	int frame = 0;
	while (1) {
		vsync();
		frame++;
		
		if (frame == SLIDE_INTERVAL)
		{
			memcpy(vid_mem, img2Bitmap, img2BitmapLen);
		}
		else if (frame == SLIDE_INTERVAL * 2)
		{
			memcpy(vid_mem, img3Bitmap, img3BitmapLen);
		}
		else if (frame == SLIDE_INTERVAL * 3)
		{
			memcpy(vid_mem, img1Bitmap, img1BitmapLen);
			frame = 0;
		}
	}
	
	return 0;
}


