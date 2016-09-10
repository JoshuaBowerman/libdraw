#include "libdraw.h"

void main(){
  	init(0);
  	struct Colour colour;

  	for(int i = 0; i < 256; i++){
	    	colour.red = i;
  		colour.blue = i;
  		colour.green = i;
	  	drawBox(100,100,900,700,colour);
	}
	colour.red=256;
  	colour.blue=0;
  	colour.green=0;
	drawGlyph(400,400,UnknownLetter,12,colour);
}
