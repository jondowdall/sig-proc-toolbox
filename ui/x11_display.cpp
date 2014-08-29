/*******************************************************************************
 * File: x_display.cpp
 *
 * Description:
 * Implementation of x11 display functions.
 */
#include "x11_display.hpp"

using namespace std;

namespace X11 {

/*******************************************************************************
 * Constructor
 *
 * Description:
 * Open connection to default display.
 */
Display::Display()
 : _display(XOpenDisplay(NULL)) {
}

/*******************************************************************************
 * Constructor
 *
 * Description:
 * Open interrface to specific display.
 */
Display::Display(string name)
  : _display(XOpenDisplay(name.c_str())) {
}

/*******************************************************************************
 * Method: create_window
 *
 * Description:
 * Create an X11 window.
 */
Window Display::create_window(int x, int y, unsigned int width,
                     unsigned int height, unsigned int border_width,
                     int depth, unsigned int win_class, Visual *visual,
                     unsigned long valuemask,
                     XSetWindowAttributes *attributes) {
    ::Window win;
    win = XCreateWindow(_display, DefaultRootWindow(_display), x, y, width,
                        height, border_width, depth, win_class, visual,
                        valuemask, attributes);
    return win;
}


}
