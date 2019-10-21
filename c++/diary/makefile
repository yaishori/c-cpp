CFLAGS  = -ansi -pedantic 

aprog : diaryTest.o diary.o meeting.o 
	g++ -o aprog diaryTest.o diary.o meeting.o 

diaryTest.o : diaryTest.cpp diary.h meeting.h TException_t.h
	g++ -c $(CFLAGS) diaryTest.cpp

diary.o : diary.cpp diary.h meeting.h
	g++ -c $(CFLAGS) diary.cpp

meeting.o : meeting.cpp TException_t.h
	g++ -c $(CFLAGS) meeting.cpp
