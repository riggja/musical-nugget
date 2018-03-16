ODIR = output
OUT = $(ODIR)/swpong.a
CC = g++
SDIR = .
INC = -ISFML-2.4.2/include
LIBS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIB_DIR = -LSFML-2.4.2/lib
LINK_TARGET = $(ODIR)/swpong
MKDIR_P = mkdir -p

_OBJS = test.o menu.o Ball.o Paddle.o Scoreboard.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

all: directories $(LINK_TARGET)

$(LINK_TARGET): $(OBJS)
	$(CC) -g -o $@ $^ $(LIB_DIR) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $(INC) -o $@ $< $(CFLAGS) -D_GLIBCXX_USE_CXX11_ABI=0

$(OUT): $(OBJS)
	ar rvs $(OUT) $^

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(OUT) $(LINK_TARGET)

.PHONY: directories

directories: $(ODIR)

$(ODIR):
	$(MKDIR_P) $(ODIR)
