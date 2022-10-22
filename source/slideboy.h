/* Define useful constants for the SlideBoy application
*
* Author: Josh McIntyre
*/

// How many frames to keep one image on screen
#define SLIDE_INTERVAL 200

// Video mode
#define VIDMODE 3

// Background layer 2
#define DCNT_BG2 0x0400

// Important register information
#define MEM_IO 0x04000000
#define MEM_VRAM 0x06000000

// Video functionality
#define REG_DISPCNT *((volatile u32*)(MEM_IO+0x0000))
#define vid_mem ((u16*)MEM_VRAM)

// Framerate functionality
#define REG_VCOUNT *(vu16*)0x04000006

void vsync()
{
    while(REG_VCOUNT >= 160);   // wait till VDraw
    while(REG_VCOUNT < 160);    // wait till VBlank
}