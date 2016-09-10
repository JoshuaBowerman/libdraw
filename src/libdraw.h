/* license */
#ifndef LIBDRAW_H
#define LIBDRAW_H
#include <stdio.h>
#include <linux/fb.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

	char *framebufferPointer = 0;
	int fbfd;
	struct fb_var_screeninfo vinfo;
  	struct fb_fix_screeninfo finfo;

	struct Screen_Resolution{
	  int vertical;
	  int horizontal;
	};

	struct Colour{
	  int red;
	  int green;
	  int blue;
	};

	int init(int mode);
	struct Screen_Resolution getResolution();
	void drawDot(int x, int y, struct Colour colour);
	void drawBox(int x1,int y1, int x2, int y2, struct Colour colour);
	void drawGlyph(int x, int y, char ch, int size, struct Colour colour);
	//void drawArc(int x1,int y1, int x2, int y2, int vertexX, int vertexY,struct Colour colour);
	//void clearScreen(struct Colour colour);
	//void drawText(int x, int y, int fontID, int size,struct Colour colour);





#endif /* LIBDRAW_H */
