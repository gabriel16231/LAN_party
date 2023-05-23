build: 
	gcc -o lanParty main.c cerinta2.c cerinta3.c cerinta4.c cerinta_5.c citire_afisare.c free_mem.c functii.c operatii_liste.c 
clean: 
	rm -f lanParty
run:
	./lanParty c.in d.in r.out
