
#include "libdraw.h"

/*
 * Description: Initializes the screen for drawing
 * Input: integer mode see: documentation
 * Output:
 * 	-3 if failed to map frambuffer
 * 	-2 if failed because could not open /dev/fb0
 * 	-1 if failed because failed reading fixed info
 * 	0 if failed because failed reading variable info
 * 	1 if ready
 *
 */
int init(int mode){
	fbfd = 0;
 	fbfd = open("/dev/fb0", O_RDWR);

  	long int screensize = 0;


     	if (fbfd == -1) {
        	perror("Error: cannot open framebuffer device");
	     	return -2;
   	}

	if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        	perror("Error reading fixed information");
        	return -1;
 	}

    	// Get variable screen information
    	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
    		perror("Error reading variable information");
    	    	return 0;
    	}

	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    	// Map the device to memory
   	framebufferPointer = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    	if ((int)framebufferPointer == -1) {
        	perror("Error: failed to map framebuffer device to memory");
        	return  -3;
    	}
}

/*
 * Description: Returns the screen resolution
 * Output: returns a struct containing the screen resolution
 */
struct Screen_Resolution getResolution(){
	struct Screen_Resolution responseStruct;
	responseStruct.vertical =  vinfo.yres;
  	responseStruct.horizontal = vinfo.xres;
  	return responseStruct;
}

void drawDot(int x, int y, struct Colour colour){
	int location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
	*(framebufferPointer + location) = colour.blue / (256 / (2^vinfo.bits_per_pixel));
        *(framebufferPointer + location + 1) = colour.green / (256 / (2^vinfo.bits_per_pixel));
        *(framebufferPointer + location + 2) = colour.red / (256 / (2^vinfo.bits_per_pixel));
        *(framebufferPointer + location + 3) = 0;      // No transparency

}


void drawBox(int x1, int y1,int x2, int y2, struct Colour colour){
  	for(int y = y1; y <= y2; y++){
		for(int x = x1; x <= x2; x++){
			drawDot(x,y,colour);
		}
	}
}

void drawGlyph(int x, int y, int *Glyph, int size, struct Colour colour){
	for(int row = 0; row < 8; row++){
		for(int col = 0; col < 5; col++){
		  	int piece = (Glyph[row] >> (4*(4 - col))) & 0xf; // get the 4 bits at the col * 4 position
			if(piece){
			  	//if that piece contains a value that means that we should draw that piece
		  		drawBox(x + (col * size),y + (row * size),x + (col * size) + size,y + (row * size) + size, colour);
			}
		}
		printf("\n");
	}
}




