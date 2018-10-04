TARGET = main
CC = gcc

COMPILER_FLAGS = -g -Wall -Wno-pointer-to-int-cast -d
LINKER_FLAGS = -Wall

ODIR = obj
SRC_DIR = src

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OFILES = $(patsubst %.c,%.o,$(patsubst $(SRC_DIR)%,$(ODIR)%,$(SRC_FILES)))
HFILES = $(wildcard $(SRC_DIR)/*.h)

$(ODIR)/%.o: $(SRC_DIR)/%.c $(HFILES)
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(COMPILER_FLAGS)

$(TARGET): $(OFILES)
	$(CC) -o $@ $^ $(LINKER_FLAGS)

clean:
	-rm -rf $(ODIR)
	-rm -f $(TARGET)

default: $(TARGET)
all: default

.PHONY: clean default all

.PRECIOUS: $(TARGET) $(OFILES)

