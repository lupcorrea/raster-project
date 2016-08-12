# Rasterisation Practice

### Brief Description and Credits
This is the source code used for the experiment described [here](https://tindied.wordpress.com/2016/08/12/computer-graphics-101-drawing-a-rainbow-ish-line). The experiment itself was based on an assignment for my Computer Graphics course, at the Federal University of Paraíba, in Brazil. The basic framework that allowed the code to simulate a framebuffer was generated by the professor [Christian Pagot](https://github.com/capagot), as you can see in his documentation inside the folder, if you can understand Portuguese.

### How does it work?

#### Pixel
All you need to know is that the code works all the time with a class called Pixel. It contains the basic information of an actual pixel: position (described by its X and Y coordinates) and color (determined using the RGBA color space). Nothing more complex than this.

#### mygl.cpp
This class contains all the complex magic described at the Tindied's post. There are three main functions there:

###### drawPixel (Pixel p1)
The bread and butter from the code. That's the function that allows you to, well, plot a pixel in your screen via the simulated framebuffer. It already has a conversion between the mathematical Y axis and the screen Y axis.

*Dang it, inverted Y axis.*

###### drawLine (Pixel p1, Pixel p2)
This one is the responsible for drawing a line, based on the classic Bresenham's algorithm. It works for all of the octants, so enjoy it while it works!

###### setNextColor (Pixel p1, Pixel p2, Pixel *p)
Finally, this one will build a rainbow of joy in your screen. Given two points p1 and p2, this function will do an interpolation of their colors in order to determine the color of the point p, based on the distance between them. **This was only tested for points belonging to a line between p1 and p2, I still have to test the other way.**

#### main.cpp
There is a callback function called MyGlDraw (void) in it. Put some code there and see the magic happening.

### To Do Hitlist
* Optimize the code for the color interpolation.
* Simplify the code for drawLine.
* Build an algorithm to detect if a given point is inside a triangle.
  ** Draw an animated hourglass to validate it.
* Adapt the libraries so that building it in Mac OS doesn't generate 10 to 11 warnings.
* Test the color interpolation function for points outside of a line, and avoid these cases from happening.

### General Stats
* As in version 1.6, 16 hours were invested in total (pure coincidence), including:
  * Research
  * Mathematics
  * Coding (and learning how to adapt the framework to Mac OS)
  * Debugging (and learning how to use LLDB)
  * Fixing the inverted Y axis (*seriously*)
  * Partially optimizing the code
  * Writing the post
* 4 glasses of wine
* 22 new discovered songs on Spotify
