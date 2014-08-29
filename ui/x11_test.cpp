/*******************************************************************************
 * File: x11_test.cpp
 *
 * Description:
 * Test file for x11 interface.
 */

#include <iostream>

#include <X11/X.h>
#include <X11/Xutil.h>

#include <GL/glx.h>


#include "x11_display.hpp"

/*******************************************************************************
 * Function: main.cpp
 *
 * Description:
 * Test application entry point.
 */
int main(int argc, char *argv[]) {
    XVisualInfo         *visual_info;
    Colormap             cmap;
    XSetWindowAttributes window_attributes;
    int                  visual_attrib_list[] = {GLX_RGBA,
                                                 GLX_DOUBLEBUFFER,
                                                 GLX_DEPTH_SIZE, 16,
                                                 None};

    X11::Display display;

    /*
     * Create an appropriate visual for the rendering
     */
    visual_info = glXChooseVisual(display, display.default_screen(), visual_attrib_list);

    window_attributes.colormap = cmap;
    window_attributes.border_pixel = 0;
    window_attributes.event_mask = StructureNotifyMask;

    Window win = display.create_window(100, 100, 800, 600, 0,
                                       display.default_depth(),
                                       InputOutput, visual_info->visual,
                                       CWBorderPixel | CWColormap | CWEventMask,
                                       &window_attributes);

}
