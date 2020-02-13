build: 
	g++ -Wall -std=c++11 frati.cpp -o frati.exe
	g++ -Wall -std=c++11 numaratoare.cpp -o numaratoare.exe
	g++ -Wall -std=c++11 ursi.cpp -o ursi.exe
	#g++ -Wall -std=c++11 planificare.cpp -o planificare.exe
	

run-p1:
	./frati.exe
	
run-p2:
	./ursi.exe

#run-p3:
#	./planificare.exe

run-p4:
	./numaratoare.exe
	
clean:
	rm -rf *.exe *.o
