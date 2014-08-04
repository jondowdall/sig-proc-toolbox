#include <X11/Xlib.h>
#include <string>

class X_Display {
    Display *_display;
public:
    Display();
    Display(std::string name);

    operator (Display *)() {return _display;}
}
