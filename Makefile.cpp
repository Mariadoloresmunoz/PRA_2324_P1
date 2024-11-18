bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

clean:
	rm -r *.o *.gch bin
	
bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
        g++ -c testCircle.cpp
        mkdir -p bin
        g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o
