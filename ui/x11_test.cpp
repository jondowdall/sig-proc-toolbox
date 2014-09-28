/*******************************************************************************
 * File: x11_test.cpp
 *
 * Description:
 * Test file for x11 interface.
 */

#include <iostream>
#include <sys/time.h>

#include <X11/X.h>
#include <X11/Xutil.h>

#include <GL/glx.h>


#include "x11_display.hpp"

#define SLEEP_TIME (1.0 / 30.0);

using namespace std;

/******************************************************************************
 *
 * 'get_time()' - Return an increasing clock time in seconds...
 *
 */
double get_time() {
    struct timeval current_time; /* Current time */

    gettimeofday(&current_time, NULL);
    return ((double)current_time.tv_sec + 1e-6 * (double)current_time.tv_usec);
}

/******************************************************************************
 *
 * Wait for an xwindow notification
 *
 */
static Bool wait_for_notify(Display *d, XEvent *event, char *arg) {
    return (event->type == MapNotify) && (event->xmap.window == (Window)arg);
}

#if 1
/******************************************************************************
 *
 * Handle a resize of the main window
 *
 * This function is called from the control thread so just sets the flags in
 * the window data structure to indicate the the main window has been resized
 * and let the rendering thread handle resizing the GL windows. This is to
 * allow the rendering thread to keep the GL contexts.
 *
 */
void handle_resize (Display *display, Window win, XExposeEvent *event) {
    Window        root;
    int           x, y;
    unsigned int width;
    unsigned int height;
    unsigned int border_width;
    unsigned int depth;

    if (event->count == 0) {
      XGetGeometry(display, win, &root, &x, &y,
                   &width, &height, &border_width, &depth);

      //change_size(width, height);
    }
}

/******************************************************************************
 *
 * Check that the event type matches that given by arg
 */
int check_for_event(Display* display, XEvent *event, XPointer arg) {
    return event->type == *arg;
}

/******************************************************************************
 * Function: key_press
 *
 * Description:
 */
void key_press(KeySym key, unsigned int state) {
    switch (key) {
        case XK_q:
            break;
            
        default:
            break;
    }
}

/******************************************************************************
 * Function: key_release
 * 
 * Description:
 */
bool key_release(KeySym key, unsigned int state) {
	bool done = false;
    switch (key) {
        case XK_q:
            done = true;
            break;
            
        default:
            break;
    }
    return done;
}

/******************************************************************************
 *
 * Wait for the next X event and process it
 *
 */
bool process_event(Display *display, Window win) {
    /*
    * Handle resizes.  When a resize happens, we need to re-allocate
    * the background pixmap.  Note that the bigger the window, the
    * larger the area that needs to get copied, and therefore the
    * slower the program gets.
    */
    XEvent    event;
    bool done = false;
    long mask = KeyPressMask | KeyReleaseMask| PointerMotionMask | ExposureMask;
    if (XCheckWindowEvent(display, win, mask, &event)) {
        switch (event.type) {
			case Expose:
				handle_resize (display, win, (XExposeEvent *) &event);
				break;

			case KeyPress:
				do {
					key_press(XLookupKeysym(&event.xkey, 0), event.xkey.state);
				} while (XCheckIfEvent(display, &event, check_for_event, (char *)&event.type));
			break;

			case KeyRelease:
				do {
					done = key_release(XLookupKeysym(&event.xkey, 0), event.xkey.state);
				} while (XCheckIfEvent(display, &event, check_for_event, (char *)&event.type));
			break;

			case MotionNotify:
				break;

			default:
				break;
		}
    }
    return done;
}

/******************************************************************************
 *
 * Handle_X_Error
 *
 * Handle errors reported by the X server
 *
 * Since this could have been triggered by the cleanup functionality all we'll
 * do for now is report the error and return
 *
 */
int
Handle_X_Error(Display *display, XErrorEvent *error) {
#define ERROR_STRING_LENGTH     1024

  char error_string[ERROR_STRING_LENGTH];

  XGetErrorText(display, error->error_code, error_string,
                ERROR_STRING_LENGTH);

  return 0;
#undef ERROR_STRING_LENGTH

} /* Handle_X_Error */
#endif

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
    visual_info = glXChooseVisual(display, display.default_screen(),
                                  visual_attrib_list);

    cmap = XCreateColormap(display, display.root_window(visual_info->screen),
                            visual_info->visual, AllocNone);
    window_attributes.colormap = cmap;
    window_attributes.border_pixel = 0;
    window_attributes.event_mask = StructureNotifyMask;

    Window win = display.create_window(100, 100, 800, 600, 0,
                                       display.default_depth(),
                                       InputOutput, visual_info->visual,
                                       CWBorderPixel | CWColormap | CWEventMask,
                                       &window_attributes);
    GLXContext glx_context;
    glx_context = glXCreateContext(display, visual_info, NULL, GL_TRUE);
    if(!glx_context) {
    }
    glXMakeCurrent(display, win, glx_context);
    //cout << win << endl;
                      
    XMapWindow(display, win);

    XEvent event;
    XIfEvent(display, &event, wait_for_notify, (char*)win);
    long mask = KeyPressMask | KeyReleaseMask | PointerMotionMask |
                  ExposureMask | ButtonPressMask | ButtonReleaseMask;
    XSelectInput (display, win, mask);
                                       
    bool done = false;
    double wait = SLEEP_TIME;
    double time;
    double last_time;
    struct timespec sleep;
    while (not done) {
		time = get_time();
        done = process_event(display, win);
        last_time = get_time();
        glXSwapBuffers(display, win);
        wait = SLEEP_TIME - get_time() - time;
        sleep.tv_sec = int(wait);
        sleep.tv_nsec = int((wait - sleep.tv_sec) * 1e9);
        nanosleep (&sleep, NULL);
	}
}
