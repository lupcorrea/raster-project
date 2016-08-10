#include "main.h"

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
	//*************************************************************************
	// Chame aqui as funções do mygl.h
	//*************************************************************************
    Pixel p0 (250, 250, 255, 0, 0, 255);
    Pixel p1 (500, 300, 255, 0, 0, 255);
    Pixel p2 (300, 500, 255, 0, 0, 255);
    Pixel p3 (200, 500, 255, 0, 0, 255);
    Pixel p4 (100, 300, 255, 0, 0, 255);
    Pixel p5 (100, 200, 255, 0, 0, 255);
    Pixel p6 (200, 100, 255, 0, 0, 255);
    Pixel p7 (300, 100, 255, 0, 0, 255);
    Pixel p8 (500, 200, 255, 0, 0, 255);
    
    /*
    drawPixel (p0);
    drawPixel (p1);
    drawPixel (p2);
    drawPixel (p3);
    drawPixel (p4);
    drawPixel (p5);
    drawPixel (p6);
    drawPixel (p7);
    drawPixel (p8);
    
    
    drawLine (p0, p1);
    drawLine (p0, p2);
    drawLine (p0, p3);
    drawLine (p0, p4);
    drawLine (p0, p5);
    drawLine (p0, p6);
    drawLine (p0, p7);
    drawLine (p0, p8);
    /* */
    
    drawTriangle (p0, p1, p2);
    drawTriangle (p0, p2, p3);
    drawTriangle (p0, p3, p4);
    drawTriangle (p0, p4, p5);
    drawTriangle (p0, p5, p6);
    drawTriangle (p0, p6, p7);
    drawTriangle (p0, p7, p8);
    drawTriangle (p0, p8, p1);
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	// Inicializações.
	InitOpenGL(&argc, argv);
	InitCallBacks();
	InitDataStructures();

	// Ajusta a função que chama as funções do mygl.h
	DrawFunc = MyGlDraw;	

	// Framebuffer scan loop.
	glutMainLoop();

	return 0;
}

