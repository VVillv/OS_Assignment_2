all: clean fifo sjf rr

# Compile the FIFO scheduler
fifo: 
	@echo "Compiling FIFO scheduler..."
	g++ -Wall -Werror -std=c++20 -o fifo ./FIFO/*.cpp
	@echo "done"

# Compile the SJF scheduler
sjf:
	@echo "Compiling SJF scheduler..."
	g++ -Wall -Werror -std=c++20 -o sjf ./SJF/*.cpp
	@echo "done"

# Compile the RR scheduler
rr:
	@echo "Compiling Round Robin scheduler..."
	g++ -Wall -Werror -std=c++20 -o rr ./RR/*.cpp
	@echo "done"

# Clean up the compiled files
clean: 
	@echo "Cleaning up..."
	@rm -rf fifo sjf rr *.dSYM
	@echo "done"
