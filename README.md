Clase:

	-Librarie (nume, vector de caiete, vector de manuale de lucru, vector de manuale de liceu)

	-Caiet (nr. pagini, tipul (foaie "dictando", "velina", "mate"), stoc, pret)

	-Manual (clasa (in cifre), materia, stoc, pret)
	
	-Clase prin mostenire:  ManualLucru ( are in plus dificultatea(1- avansat, 2-mediu, 3-incepator) si rezolvari (0-nu are rezolvari, 1-are rezolvari)
				ManualLiceu ( are in plus profilul(mate-info, filo, stiinte)



In Librarie:

	-Functia adauga => verifica daca produsul exista deja, iar daca exista ii modifica stocul, daca nu, il adauga la librarie

	-Functia sterge => primeste ca parametru o cantitate si scade acea cantitate din stocul produsului
                => cand produsul are stocul 0 este eliminat din lista de produse
                => daca cantitatea ceruta este mai mare decat stocul disponibil => eroare stoc_insuficient
                
	-Functia compara => compara produsele (pentru manual verifica sa fie aceeasi materie si clasa iar pentru caiete verifica sa fie de acelasi tip)
                 => returneaza produsul cel mai ieftin
		 => daca produsul nu exista => eroare produs_inexistent
                 
	-constructor cu parametrii si desctructor

	-setter si getter pentru nume

	-overload pentru operatorul <<
                 
                 
                 
Atat pentru Manual cat si pentru Caiet am facut:

	-constructor de initializare cu parametrii si de copiere

	-overload la operatorii: ==, =, >, <, <<

	-setteri si getteri pentru stoc
	
	-getter pentru pret materie/tip



Pentru cele doua clase prin mostenire, ManualLucru si ManualLiceu:

	-constructor nou
	
	-am folosit unique_ptr
	
	-override la getPrice()
	
	-getter pentru profil/dificultate si rezolvari
