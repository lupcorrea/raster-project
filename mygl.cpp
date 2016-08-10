#include "mygl.h"
#include "definitions.h"

/* ---------- Pixel operations ---------- */
void drawPixel (Pixel p1) {
    // Find the position in the FB
    int curr_pos = 4*p1.getX() + 4*IMAGE_WIDTH*p1.getY();
    
    // Color the FB position
    if (p1.getX() < IMAGE_WIDTH && p1.getY() < IMAGE_HEIGHT) {
        FBptr[curr_pos] = p1.getR();
        FBptr[curr_pos + 1] = p1.getG();
        FBptr[curr_pos + 2] = p1.getB();
        FBptr[curr_pos + 3] = p1.getA();    
    }    
}

/* ---------- Line operations ---------- */
void drawLine (Pixel p1, Pixel p2) {
    Pixel p = p1;
    
    drawPixel (p);
    while (p.getX() < p2.getX()) {
        p.incX();
        drawPixel (p);
    }
}