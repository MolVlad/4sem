PROJECT = a.out

SOURCES = src/main.cpp src/Vector2.cpp
INCLUDES += -I includes
DEFINES =
CFLAGS = #-Wall -Wextra
COMP = g++

OBJS = $(SOURCES:.cpp=.o)

CFLAGS += $(DEFINES) $(INCLUDES) $(DEFINES)

RM = rm -rf

.PHONY: all clean tags

link: $(OBJS)
	$(COMP) -o $(PROJECT) $(OBJS)

all: clean link

clean:
	$(RM) $(OBJS) $(PROJECT)

%.o: %.cpp
	$(COMP) $(CFLAGS) -c $(@:.o=.cpp) -o $@

tags:
	ctags -R
