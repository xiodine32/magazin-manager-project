Proiect POO 2
===

Query
---

 * **STOP** Opreste executia programului.
  
 * **adauga** Adauga stoc nou
 
 * **comanda** Incepe o noua comanda
 
 * **stats** Vezi statistici
 
 * **goale** Vezi stoc gol
 
 
STOP
---

Atunci cand se incarca programul, el continua de unde a fost lansat
ultima oara. Astfel, trebuie asigurata salvarea datelor din ziua curenta
intr-un program de backup, pentru a nu avea calculatorul deschis pe perioada
noptii si pentru a nu pierde baza de date in cazul unei pene de curent atunci cand
nimeni nu poate supraveghea server-ul.

Cand programul primeste comanda *STOP*, isi salveaza baza de date si se inchide
in cel mai scurt timp.

adauga
---

Adaugi stoc nou, din stoc existent sau stoc nou. 

comanda
---

O noua comanda cu clientul.

Comenzi posibile: 

 1. nume [trasaturi, ...] cantitate [unitate] - **cerere pentru produs**
 2. subtotal - **subtotatul curent**
 3. finalizare - **finalizare comanda**
 
Finalizarea comenzii scoate produsele din stoc si afiseaza produsele ce vor fi
livrate imediat clientului.

stats
---

Afiseaza statisticile despre produsele magazinului, mai exact:
 
 * Stocul pentru fiecare produs.Clientul poate cere: 
 * Profitul obtinut de cand a fost iniatilizat programul.
 * 