        DEPLIBS = $(DEPXLIB)
LOCAL_LIBRARIES = -lX11 -lGL -lGLU
  SYS_LIBRARIES = -lm
CFLAGS = -O2

SRCS = x11_test.cpp x11_display.cpp
OBJS = x11_test.o x11_display.o

all: model

model: $(OBJS)
	g++ $(OBJS) -o x11_test $(SYS_LIBRARIES) $(LOCAL_LIBRARIES)

clean:
	rm -f $(OBJS)
