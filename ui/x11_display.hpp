/*******************************************************************************
 * File: x11_display.hpp
 *
 * Description:
 * Interface to x11 display functions.
 */
#ifndef _X11_DISPLAY_
#define _X11_DISPLAY_

#include <X11/Xlib.h>
#include <string>

namespace X11 {

/*******************************************************************************
 * Class: Display
 *
 * Description:
 * Wrapper of X11 display variable.
 */
class Display {
public:
    /***************************************************************************
     * Constructor
     *
     * Description:
     * Open connection to default display.
     */
    Display();

    /***************************************************************************
     * Constructor
     *
     * Description:
     * Open interrface to specific display.
     */
    Display(std::string name);

    /***************************************************************************
     * typecast operator: Display *
     *
     * Description:
     * Return a Display * for use of objects in std function calls.
     */
    operator ::Display *() {return _display;}

    /***************************************************************************
     * Method: create_window
     *
     * Description:
     * Create an X11 window.
     */
    Window create_window(int x, int y, unsigned int width,
                         unsigned int height, unsigned int border_width,
                         int depth, unsigned int win_class, Visual *visual,
                         unsigned long valuemask,
                         XSetWindowAttributes *attributes);

    /***************************************************************************
     * Method: default_screen
     *
     * Description:
     * Return the screen number of the default screen of this display.
     */
    int default_screen() {return DefaultScreen(_display);}

    /***************************************************************************
     * Method: default_screen
     *
     * Description:
     * Return the screen number of the default screen of this display.
     */
    int default_depth() {return DefaultDepth(_display, default_screen());}

    /***************************************************************************
     * Method: default_screen
     *
     * Description:
     * Return the screen number of the default screen of this display.
     */
    int default_depth(int screen) {return DefaultDepth(_display, screen);}

#if 0
    /***************************************************************************
     * Method: create_window
     *
     * Description:
     * Create an X11 window.
     */
    Window create_window(Window parent, int x, int y, unsigned int width,
                         unsigned int height, unsigned int border_width,
                         int depth, unsigned int win_class, Visual *visual,
                         unsigned long valuemask,
                         XSetWindowAttributes *attributes);
#endif

protected:

private:
    ::Display *_display;

};

}

#endif
