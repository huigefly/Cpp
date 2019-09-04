EXECUTEFILE=helloworld
OBJECTS=main.o
$(EXECUTEFILE):$(OBJECTS)
	g++ -o $(EXECUTEFILE) $(OBJECTS)

%.o:%.cpp
	g++ -c $< -o $@

.PHONY:clean
clean:
	-rm -f $(EXECUTEFILE) $(OBJECTS)
