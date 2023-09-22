all: 
	$(MAKE) clean
	$(MAKE) fifo
	$(MAKE) sjf
	$(MAKE) rr

fifo: 
	@echo making fifo...
	g++ -Wall -Werror -std=c++2a -g ./FIFO/*.cpp -o fifo
	@echo "done"

sjf:
	@echo making sjf...
	g++ -Wall -Werror -std=c++2a -g ./SFJ/*.cpp -o sjf
	@echo "done"

rr:
	@echo making rr...
	g++ -Wall -Werror -std=c++2a -g ./RR/*.cpp -o rr
	@echo "done" 

# Clean by going into each directory and running make clean
clean: 
	@echo "cleaning up..."
	@rm -rf fifo sjf rr *.dSYM
	@echo "done"
