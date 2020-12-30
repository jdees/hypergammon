all:
	cl /EHsc hypergammon.cpp
	hypergammon.exe

OBJECTS=hypergammon.o

SRC_EXT = cpp

DEPS = $(OBJECTS:.o=.d)
-include $(DEPS)

CXXFLAGS=-std=c++2a -Wall

hypergammon: $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $@ ${LIBS}

.PHONY: clean
clean:
	rm $(OBJECTS)

%.o: %.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@
