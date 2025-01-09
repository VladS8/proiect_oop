# Proiect Catalog Digital

## Descriere proiect



## Milestone #1

In acest Milestone am inceput implementarea claselor de baza folosite in proiect,
dar care ulterior au fost inlocuite datorita faptului ca am schimbat perspectiva
proiectului si am vrut sa incerc sa folosesc o baza de date in spate si o librarie(Qt)
pentru interfata.

## Milestone #2
Milestone-ul 2 l-am inceput prin adaugarea librariei Qt, iar mai apoi a plugin-ului
SqliteBrowser in aplicatia Clion.
Prima clasa creeata a fost DataBaseHandler, o clasa in mare parte folosita ca sa pot
incepe sa inteleg cum functioneaza acestea intr-un cod c++. 
Sqlitebrowser functioneaza pe cod C, fapt pentru care apare pe GitHub ca folosesc
99.4% cod C.
Clasa poate creea tabele, imi deschide baza de date, o inchide si contine un constructor,



Mai apoi am inceput prin introducerea clasei LoginWindow, care este folosita
ca un fel de MainWindow, deoarece e primul window care se deschide cand rulez proiectul
si are cele mai multe implementari in ea. In loginWindow am construit butoane care imi
fac interogari pe baza de date si ma pot trimite in restul ferestrelor. Aceasta fereastra
este mereu deschisa cand programul ruleaza deoarece folosesc functia hide() pe aceasta
cand deschid restul de ferestre cu show()

Similiar pentru registerWindow in loc sa fac interogari pe baza de date fac o insertie sql
pentru a imi creea tabelele direct din interfata.

Urmatoarea clasa creeate a fost PanelWindowElev care voiam sa o folosesc ca o pagina
principala in proiect in care sa am toate functionalitatile. Aceasta a ajuns sa fie
o clasa destul de simpla care contine cateva butoane si interogari sql.


## Milestone #3

In Milestone 3 am adaugata clasa de baza UserBase cu clasele derivate din aceasta:
Profesor, Elev, Diriginte. Aceste clase le folosesc in LoginWindow pentru a indentifica
dupa email ce fel de user incearca sa se logheze la panou. prin introducerea unui email
de tip vlad@gmail.com - email de elev mi se deschide PanelWindowElev, la fel si pentru 
restul entitatilor(Profesor, Diriginte).

Tot in acest Milestone am incercat sa rezolv cateva leak-uri de memorie si erori gasite
prin cod. Si am introdus design pattern-ul (Observer). Acest pattern imi anunta pagina
LoginWindow atunci cand un cont nou este creeat in RegisterWindow, clasele creeate pentru
folosirea pattern-ului Observer sunt, Subject folosita in RegisterWindow si Observer folosita
in LoginWindow.


## Resurse
https://github.com/
https://www.w3schools.com/
https://chatgpt.com/
https://stackoverflow.com/
AI Assistant-ul din Clion pentru crearea documentatiei pentru cod
