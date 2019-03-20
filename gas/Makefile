PROJECT = sfml

SOURCES = sources/main.cpp sources/vector2.cpp sources/mat_point.cpp sources/ball.cpp
INCLUDES += -I includes
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
DEFINES =
CFLAGS = #-Wall -Wextra
COMP = g++ -std=c++11

OBJS = $(SOURCES:.cpp=.o)

CFLAGS += $(DEFINES) $(INCLUDES) $(DEFINES)

RM = rm -rf

.PHONY: all clean tags

link: $(OBJS)
	$(COMP) -o $(PROJECT) $(OBJS) $(LIBS)

all: clean link

clean:
	$(RM) $(PROJECT) $(OBJS)

%.o: %.cpp
	$(COMP) $(CFLAGS) -c $(@:.o=.cpp) -o $@

tags:
	ctags -R
