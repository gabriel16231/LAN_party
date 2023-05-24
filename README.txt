main:
se va citi din fisier c.i un vector care ne va indica cerintele

datele despre echipe se vor salva intr o lista prin adauare la inceput
iar fiecare echipa va avea asociat o lista de player la fel construita cu adaugare la inceput

task2:
-vom salva la fiecare echipa numarul de puncte al echipei
-determinam numarul maxim de echipe care trebuie sa ramana dupa eliminare
-eliminarea:(se va repeta pana cand vor ramnae suficiente echipe)
            se det nr min de puncte dintre toate echipele
            mai intai se elimina toate echipele consecutive cu nr min de puncte de la inceputul listei
            continuam sa verificam restul listei eliminand echipele cu nr min de puncte, acum ca lista incepe cu o echipa cu puncte mai mai multe decat cea minima

task3:
-mai intai din toate echipele ramase se va face prima runda care consta in grupare pe rand a doua cate 2 echipe
!!!!!prima runda este tratata separat iar urmatorul proces se va realiza (fara extragere din winners) inainte de a intra in while
-vom face pana cand vom ramane cu o singura echipa ramasa:
        -vom creea coada de matchuri extragand din winners echipele
        -afisam rundele
        -se separa in stive de winners si losers
        -se elibereaza mem pt stiva de losers
        -afisam winners

cand nr de echipe a a juns la 8 se vor salva separat pt task 4

task 4:
-adaugarea in bst:

primul element al listei va fi adaugat separat devenind root 

apoi pentru urmatoarele se va face urm proces:
daca nu am ajuns la o adresa NULL
vom verifica daca elementul pe care vrem sa il adaugam este mai mare sau mai mic ca cel actual 
si ne vom duce pe subraborele din dreapta, respectiv stanga
in cazulin care sunt egale comparatia se face cu un strchr in functie de ordinea lor alfabetica

se va afisa BST-ul recursiv de la dreapta la stanga(cele mai mari al cele mai mici punctaje)

task 5:

ne vom folosi de BST ul creat anterior pentru a face o lista
cu ceele 8 echipe ordonate 

cu aceasta lista am creat manual AVL ul
si se vor afisa cele 4 echipe aflate pe nivelul 2



