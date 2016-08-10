#include "mygl.h"
#include "definitions.h"
#include <stdio.h>

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
    /* Deltas */
    int dx = p2.getX() - p1.getX();
    int dy = p1.getY() - p2.getY();     // Inverted due to the inverted Y axis from the FB
    
    /* Increments */
    int e = 2 * dy;
    int ne = 2 * (dy - dx);
    int n = -dx;
    
    /* Start the navigation pixel and plot it */
    Pixel p = p1;
    drawPixel (p);
    
    /* Determine the octant the line belongs to */
    if (dx > 0 && dy > 0 && dx >= dy) {
        /* First octant */
        int d = 2 * dy - dx;
        while (p.getX() < p2.getX()) {
            if (d <= 0) {
                // Line below midpoint
                d += e;
                p.incX();
            } else {
                // Line above midpoint
                d += ne;
                p.incX();
                p.decY();
            }
            drawPixel (p);
        }
    } else if (dx > 0 && dy > 0 && dx < dy) { 
        // Second octant
        int d = dy - 2 * dx;
        while (p.getY() > p2.getY()) {
            if (d > 0) {
                // Line at midpoint's left
                d += n;
                p.decY();
                printf ("[d > 0] %d\n", d);
            } else {
                // Line at midpoint's right
                d += ne;
                p.incX();
                p.decY();
                printf ("[d <= 0] %d\n", d);
            }
        drawPixel (p);
        }
    } 
}