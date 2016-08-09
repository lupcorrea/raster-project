#include "mygl.h"
#include "definitions.h"

/* ---------- Pixel operations ---------- */
void drawPixel (Pixel p1) {
    // Find the position in the FB
    int curr_pos = 4*p1.getPosition().getY() + 4*IMAGE_WIDTH*p1.getPosition().getX();
    
    // Color the FB position
    FBptr[curr_pos] = p1.getCol().getR();
    FBptr[curr_pos + 1] = p1.getCol().getG();
    FBptr[curr_pos + 2] = p1.getCol().getB();
    FBptr[curr_pos + 3] = p1.getCol().getA();
}