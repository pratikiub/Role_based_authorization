C=g++
CXXFLAGS= -std=c++11

rbac: main.o role.o resource.o user.o query.o datastore.o 
	g++ -o $@ $^

main.o:	main.cc
	g++ -c -std=c++11 main.cc

role.o:	role.cc
	g++ -c -std=c++11 role.cc

resource.o: resource.cc
	g++ -c -std=c++11 resource.cc

user.o: user.cc
	g++ -c -std=c++11 user.cc

query.o: query.cc
	g++ -c -std=c++11 query.cc

datastore.o: datastore.cc
	g++ -c -std=c++11 datastore.cc

clean:
	rm -f *.o
