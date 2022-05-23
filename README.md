# SDA-PrelucrareaDatelor
Prelucrarea si analizarea datelor secventiale
###############################################################################
############################ README - Tema_1 SDA ##############################
###############################################################################

Implementarea temei a fost realizata in 2 fisere de tip c."list.c" ce contine
functiile necesare lucrului cu liste dublu inlantuite (print, push, free etc.),
iar "tema1.c" in care sunt rezolvate task-urile propriu-zise ale temei.
Majoritatea parcurgerilor au fost realizate de la tail spre head, datorita
citirii elementelor prin adaugare la inceputul listei, ceea ce a dus la o lista
"inversata".
Argumentele primite in linia de comanda vor fi parcurse, urmand sa se apeleze
functiile necesare ce modifica lista. La finalul apelurilor de functii se
afiseaza lista modificata.

############################### TASK 1 - e1 ###################################

Am implementat 2 functii "average" si "deviation", ce primesc ca argumente un
nod, calculeaza media si deviatia dintre nodul respectiv si urmatoarele 4, iar
la final returneaza valoarea. Functia "task1" parcurge lista de la inceput pana
la ultimul element ce permite calculul, apeleaza cele 2 functii mentionate si
inlocuieste timestamp-ul elementelor ce necesita eliminare in "-1". Se mai
realizeaza o parcurgere pentru stergerea elementelor.

############################## TASK 2.1 - e2 ##################################

Functia "sort" primeste ca argument un nod, copiaza valorile nodului si a
urmatoarelor 4 intr-o noua lista auxiliara. Realizeaza sortarea elementelor,
apoi intoarce valoarea mediana. Functia "task2_1" parcurge lista de la inceput
pana la ultimul element ce permite sortarea si adauga pe rand intr-o noua lista
valorile mediane. In final head-ul si tail-ul listei initiale vor "pointa"
catre head-ul, respectiv tail-ul noii liste de valori mediane.

############################## TASK 2.2 - e3 ##################################

Pentru calculul mediei am folosit functia "average" descrisa la TASK 1. Functia
"task2_1" parcurge lista de la inceput pana la ultimul element ce permite
calculul mediei. Adauga intr-o noua lista valorile mediane, iar in final
head-ul si tail-ul listei initiale vor "pointa" catre head-ul, respectiv
tail-ul noii liste de valori mediane.

################################ TASK 3 - u ###################################

Functia "task3" parcurge intreaga lista, verifica diferenta dintre timestamp-ul
elementului curent si a precedentului, apoi (daca este necesar) recalculeaza
valoarea si timestamp-ul nodului curent.

################################ TASK 4 - c ###################################

Functia "task4" calculeaza intitial constantele w03, w13, w23, apoi parcurge
lista verificand daca este necesara adaugarea de noi noduri. Daca da, se
initializeaza valorile capetelor intervalului, iar cat timp nu se depaseste
timestamp-ul capatului superior, calculeaza valorile conform formulelor si
introduce nodurile in lista.

############################### TASK 5 - st ###################################

Am implementat functia "delta" ce extrage valoarea delta din argumentul primit
in linia de comanda. Functia "task5" sorteaza lista crescator, apoi calculeaza
capetele primului interval, folosindu-se de valoarea minima din lista. Se
parcurg elementele, incrementand un contor pentru oricare element aflat in
interval. Cand se intalneste o valoare ce depaseste capatul superior, functia
afiseaza, reseteaza contorul si recalculeaza capetele pentru urmatorul
interval. La finalul parcurgerii, se realizeaza o afisare a ultimului interval.

###############################################################################
  Facultatea de Automatica si Calculatoare - Anul 1 2021-2022 - Grupa 312CCa
          PETCU Andrei - Structuri de Date si Algoritmi - TEMA 1 ©
###############################################################################
