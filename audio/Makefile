PROJECT = sfml

SOURCES = sources/main.cpp
INCLUDES += -I includes
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
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
