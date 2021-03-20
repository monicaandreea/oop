Clase:

	-Librarie (nume, vector de caiete, vector de manuale)

	-Caiet (nr. pagini, tipul (foaie "dictando", "velina", "mate"), stoc, pret)

	-Manual (clasa (in cifre), materia, stoc, pret)



In Librarie:

	-Functia adauga => verifica daca produsul exista deja, iar daca exista ii modifica stocul, daca nu, il adauga la librarie

	-Functia sterge => primeste ca parametru o cantitate si scade acea cantitate din stocul produsului
                => cand produsul are stocul 0 este eliminat din lista de produse
                => daca cantitatea ceruta este mai mare decat stocul disponibil se afiseaza "Atentie! Cantitatea ceruta este mai mare decat stocul."
                
	-Functia compara => compara produsele (pentru manual verifica sa fie aceeasi materie si clasa iar pentru caiete verifica sa fie de acelasi tip)
                 => returneaza produsul cel mai ieftin
                 
	-constructor cu parametrii si desctructor

	-setter si getter pentru nume

	-overload pentru operatorul <<
                 
                 
                 
Atat pentru Manual cat si pentru Caiet am facut:

	-constructor de initializare cu parametrii si de copiere

	-overload la operatorii: ==, =, >, <, <<

	-setteri si getteri pentru stoc
