CC = clang
CFLAGS = -Wall -Wextra -std=c99

TARGET = program.exe
SRCDIR = src
INCDIR = inc
OBJDIR = obj
TSTSRCDIR = tst/src
TSTINCDIR = tst/inc

SOURCES = $(SRCDIR)/main.c $(SRCDIR)/lkp18c2p1.c $(SRCDIR)/unity.c $(TSTSRCDIR)/test_lkp18c2p1.c
OBJECTS = $(OBJDIR)/main.o $(OBJDIR)/lkp18c2p1.o $(OBJDIR)/unity.o $(OBJDIR)/test_lkp18c2p1.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.c
	@if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(TSTINCDIR) -c $< -o $@

$(OBJDIR)/lkp18c2p1.o: $(SRCDIR)/lkp18c2p1.c
	@if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(TSTINCDIR) -c $< -o $@

$(OBJDIR)/unity.o: $(SRCDIR)/unity.c
	@if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(TSTINCDIR) -c $< -o $@

$(OBJDIR)/test_lkp18c2p1.o: $(TSTSRCDIR)/test_lkp18c2p1.c
	@if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(TSTINCDIR) -c $< -o $@

clean:
	del /Q $(OBJDIR)\*.o $(TARGET)

.PHONY: all clean run test test-cat test-all

run: $(TARGET)
	$(TARGET)

test: $(TARGET)
	$(TARGET) --test 1> RESULT.TXT

test-read: test
	chcp 65001 && type RESULT.TXT

test-all: test test-read

