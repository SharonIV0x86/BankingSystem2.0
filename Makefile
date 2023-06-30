CC = g++
CFLAGS = -Wall -g
BANK = g++ Bank.cpp -o Bank -std=c++23 -lssl -lcrypto
RUN = ./Bank
recompile:
	$(BANK)
	$(RUN)

Bank.cpp: BankHeaders.cpp BankHeaders.h #required files
BankHeaders.cpp: BankHeaders.h 

delete: Bank
	rm -rf Bank
