CC = gcc

TARGET = sdldemo.exe

INC_DIR = -I.\sdllib\SDL2-devel-2.32.4-mingw\SDL2-2.32.4\x86_64-w64-mingw32\include
LIB_DIR = -L.\sdllib\SDL2-devel-2.32.4-mingw\SDL2-2.32.4\x86_64-w64-mingw32\lib 

LLIB = -lmingw32 -lSDL2main -lSDL2 

CFLAGS = -Wall
CFLAGS = -Wunused-parameter
CFLAGS = --save-temps
CFLAGS += -Wextra
CFLAGS += -std=c99
CFLAGS += --input-charset=UTF-8 --exec-charset=GBK
CFLAGS += $(INC_DIR)

LFLAGS += $(LIB_DIR)
LFLAGS += $(LLIB)

BUILD_DIR = build

SRCS = $(wildcard demo*.c)
CONFIG_FILE_NAME = active

$(BUILD_DIR)/$(TARGET): $(BUILD_DIR)/$(CONFIG_FILE_NAME).o 
	$(CC) $< $(LFLAGS) -o $@

$(BUILD_DIR)/$(CONFIG_FILE_NAME).o: $(CONFIG_FILE_NAME).c $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY:
	clean run

clean:
	rm -rf $(BUILD_DIR)/*.d $(BUILD_DIR)/*.exe $(BUILD_DIR)/*.o $(BUILD_DIR)/*.i $(BUILD_DIR)/*.s

run: $(BUILD_DIR)/$(TARGET)
	cd $(BUILD_DIR) && ./$(TARGET) && cd ..