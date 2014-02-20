.PHONY: install do

do:
	gcc -fPIC -c pam_irma.c
	gcc -shared -o pam_irma.so pam_irma.o -lpam
	rm -f pam_irma.o

install: pam_irma.so
	sudo cp pam_irma.so /usr/lib64/security/pam_irma.so
