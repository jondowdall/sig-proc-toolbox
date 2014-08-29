        DEPLIBS = $(DEPXLIB)
LOCAL_LIBRARIES = -lX11 -lGL -lGLU
  SYS_LIBRARIES = -lm
CFLAGS = -O2

SRCS = main.cpp binary.cpp functions.cpp geometry_2d.cpp geometry_3d.cpp unary.cpp
OBJS = main.o binary.o functions.o geometry_2d.o geometry_3d.o unary.o

all: model

model: $(OBJS)
	g++ $(OBJS) -o devel $(SYS_LIBRARIES) $(LOCAL_LIBRARIES)

clean:
	rm -f $(OBJS)
