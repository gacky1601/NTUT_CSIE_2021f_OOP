.PHONY: directories clean stat

all: directories bin/ut_all

CFLAGS = -std=c++11 -Wfatal-errors
SRC = src/school_member.h src/student.h src/teacher.h src/school.h
TEST = test/ut_student.h test/ut_teacher.h test/ut_school.h

bin/ut_all: test/ut_main.cpp $(SRC) $(TEST)
	g++ $(CFLAGS) test/ut_main.cpp -o bin/ut_all -lgtest -pthread

directories:
	mkdir -p bin

clean: directories
	rm -rf bin

stat:
	wc src/* test/*
