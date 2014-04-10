
CXX = g++

all: SampleApp.o CmdAppBase.o
	$(CXX) SampleApp.o CmdAppBase.o -o SampleApp

.cpp.o:
	$(CXX) -c $<

clean:
	rm *.o, SampleApp
