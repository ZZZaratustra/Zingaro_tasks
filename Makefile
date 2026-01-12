CC = clang
CFLAGS = -Wall -Wextra -std=c99

TARGET = program.exe
SRCDIR = src
INCDIR = inc
OBJDIR = obj
TSTSRCDIR = tst/src
TSTINCDIR = tst/inc

SRC_C_FILES := $(wildcard $(SRCDIR)/*.c)
TEST_C_FILES := $(wildcard $(TSTSRCDIR)/*.c)
ALL_C_FILES := $(SRC_C_FILES) $(TEST_C_FILES)

SRC_OBJ_FILES := $(SRC_C_FILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TEST_OBJ_FILES := $(TEST_C_FILES:$(TSTSRCDIR)/%.c=$(OBJDIR)/%.o)
ALL_OBJ_FILES := $(SRC_OBJ_FILES) $(TEST_OBJ_FILES)

all: $(TARGET)

$(TARGET): $(ALL_OBJ_FILES)
	$(CC) $(ALL_OBJ_FILES) -o $@

# 	@mkdir -p $(OBJDIR)

MKDIR = mkdir -p $(OBJDIR) 2>/dev/null || mkdir $(OBJDIR) 2>nul || exit 0
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(MKDIR)	
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(TSTINCDIR) -c $< -o $@

$(OBJDIR)/%.o: $(TSTSRCDIR)/%.c
	$(MKDIR)	
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(TSTINCDIR) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean run test test-read test-all

run: $(TARGET)
	./$(TARGET)

test: $(TARGET)
	./$(TARGET) --test 1> RESULT.TXT

test-read: test
	cat RESULT.TXT

test-all: test test-read