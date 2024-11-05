#include <iostream>
#include <string>
#include <optional>
#include <vector>

class Nota
{


    friend class Catalog;
private:
    int m_valoare;
    std::string m_data;
    std::string m_materie;

public:
    Nota(const int val, const std::string& data, const std::string& materie)
    {
        this->m_valoare = val;
        this->m_data = data;
        this->m_materie = materie;
    }

  

    Nota(const Nota& objNota)
    {
        this->m_valoare = objNota.m_valoare;
        this->m_data = objNota.m_data;
        this->m_materie = objNota.m_materie;
    }

    Nota& operator=(const Nota& nota)
    {
        this->m_valoare = nota.m_valoare;
        this->m_data = nota.m_data;
        this->m_materie = nota.m_materie;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Nota& printObj);
    ~Nota() {}
    
};

std::ostream& operator<<(std::ostream& out, const Nota& nota)
{
    out << nota.m_materie << ": " << nota.m_valoare << " | " << nota.m_data;
    return out;
}

class Absenta
{
private:
    std::string m_data;
    std::string m_materie;
    bool m_motivata{ false };

public:

    Absenta(const std::string& data, const std::string& materie, bool motivata) {

        this->m_data = data;
        this->m_materie = materie;
        this->m_motivata = motivata;
    }


    Absenta(const Absenta& objAbsenta) {
        this->m_data = objAbsenta.m_data;
        this->m_materie = objAbsenta.m_materie;
        this->m_motivata = objAbsenta.m_motivata;
    }

    Absenta& operator=(const Absenta& absenta)
    {
        m_data = absenta.m_data;
        m_materie = absenta.m_materie;
        m_motivata = absenta.m_motivata;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Absenta& printObj);

    ~Absenta() {}
};

std::ostream& operator<<(std::ostream& out, const Absenta& absenta)
{
    if (absenta.m_motivata)
    {
        out << absenta.m_materie << ": " << absenta.m_data << " - " << "Motivata";
    }
    else
    {
        out << absenta.m_materie << ": " << absenta.m_data << " - " << "Nemotivata";
    }

    return out;
}


class Profesor
{

private:
    std::string m_nume;
    std::string m_prenume;
    std::string m_materie;
    std::optional<std::string> m_clasa_diriginte;

public:

    Profesor(const std::string& nume, const std::string& prenume, const std::string& materie, std::optional<std::string> clasa_diriginte = std::nullopt) {
        
        this->m_nume = nume;
        this->m_prenume = prenume;
        this->m_materie = materie;
        this->m_clasa_diriginte = clasa_diriginte;
    }



    Profesor(const Profesor& objProfesor)
    {
        this->m_nume = objProfesor.m_nume;
        this->m_prenume = objProfesor.m_prenume;
        this->m_materie = objProfesor.m_materie;
        this->m_clasa_diriginte = objProfesor.m_nume;
    }

    Profesor& operator=(const Profesor& profesor)
    {
        m_nume = profesor.m_nume;
        m_prenume = profesor.m_prenume;
        m_materie = profesor.m_materie;
        if (profesor.m_clasa_diriginte.has_value())
        {
            m_clasa_diriginte = profesor.m_clasa_diriginte;
        }

        return *this;
    }

    std::string get_full_name() const
    {
        return m_nume + " " + m_prenume;
    }

    friend std::ostream& operator<<(std::ostream& out, const Profesor& printObj);

    ~Profesor() {}
    friend class Catalog;
};

std::ostream& operator<<(std::ostream& out, const Profesor& profesor)
{
    if (profesor.m_clasa_diriginte.has_value())
    {
        out << profesor.m_nume << " " << profesor.m_prenume << " - " << profesor.m_materie << ". Diriginte la clasa " << profesor.m_clasa_diriginte.value();
    }
    else
    {
        out << profesor.m_nume << " " << profesor.m_prenume << " - " << profesor.m_materie << ". Nu este diriginte";
    }
    return out;
}

class Elev
{
    friend class Catalog;
private:
    std::string m_nr_matricol;
    std::string m_nume;
    std::string m_prenume;
    std::vector<Nota> m_note;
    std::vector<Absenta> m_absente;
    

public:
    // Elev(const std::string &nr_matricol, const std::string &nume, const std::string &prenume, std::vector<Nota> note, std::vector<Absenta> absente) : m_nr_matricol{nr_matricol}, m_nume{nume}, m_prenume{prenume}, m_note{note}, m_absente{absente} {}

    Elev(const std::string& nr_matricol, const std::string& nume, const std::string& prenume, std::vector<Nota> note, std::vector<Absenta> absente)
    {
        this->m_nr_matricol = nr_matricol;
        this->m_nume = nume;
        this->m_prenume = prenume;
        this->m_note = note;
        this->m_absente = absente;

    }

    //Elev(const Elev& objElev) : m_nr_matricol{ objElev.m_nr_matricol }, m_nume{ objElev.m_nume }, m_prenume{ objElev.m_prenume }, m_note{ objElev.m_note }, m_absente{ objElev.m_absente } {}

    Elev(const Elev& objElev) {
        this->m_nr_matricol = objElev.m_nr_matricol;
        this->m_nume = objElev.m_nume;
        this->m_prenume = objElev.m_prenume;
        this->m_note = objElev.m_note;
        this->m_absente = objElev.m_absente;
    }

    Elev& operator=(const Elev& elev)
    {
        m_nr_matricol = elev.m_nr_matricol;
        m_nume = elev.m_nume;
        m_prenume = elev.m_prenume;
        m_note = elev.m_note;
        m_absente = elev.m_absente;

        return *this;
    }

    std::string get_full_name() const
    {
        return m_nume + " " + m_prenume;
    }

    void adauga_nota(Nota& nota)
    {
        m_note.push_back(nota);
    }

    void adauga_absenta(Absenta& absenta)
    {
        m_absente.push_back(absenta);
    }

    /*int numar_note_elev() const {
        return m_note.size();
    }*/

    friend class Catalog;


    friend std::ostream& operator<<(std::ostream& out, const Elev& printObj);

    friend class Catalog;

    ~Elev()
    {
        this->m_absente.clear();
        this->m_note.clear();
    }
};

std::ostream& operator<<(std::ostream& out, const Elev& elev)
{
    out << elev.m_nr_matricol << " " << elev.m_nume << " " << elev.m_prenume << '\n';
    for (int i = 0; i < elev.m_note.size(); i++)
    {
        out << elev.m_note[i] << '\n';
    }
    out << '\n';
    for (int i = 0; i < elev.m_absente.size(); i++)
    {
        out << elev.m_absente[i] << '\n';
    }
       /* out << elev.m_note.size() << '\n';*/
 

    return out;
}

class Catalog {
private:
    std::vector<Elev> m_elevi;

public:
    Catalog() = default;

    Catalog(std::vector<Elev>& elevi) {
        this->m_elevi = elevi;
    }

    Catalog(const Catalog& objCatalog) {
        this->m_elevi = objCatalog.m_elevi;
    }

    Catalog& operator=(const Catalog& catalog) {
        this->m_elevi = catalog.m_elevi;
        return *this;
    }

    void adaugaElev(const Elev& elev) {
        m_elevi.push_back(elev);
    }

    friend std::ostream& operator<<(std::ostream& out, const Catalog& catalog) {
        out << "Catalog Elevi:\n";
        for (int i = 0; i < catalog.m_elevi.size(); ++i) {
            out << catalog.m_elevi[i];
        }
        return out;
    }

    void Probabilitate_ascultare(const std::string& materie, const Elev& elev) {
        int nr_note_elev = 0;
        for (int i = 0; i < elev.m_note.size(); i++)
        {
            if (elev.m_note[i].m_materie == materie)
            {
                nr_note_elev++;
            }
        }

        int nr_note_total = 0;

        for (int i = 0; i < m_elevi.size(); i++)
        {
                for (int j = 0; j < m_elevi[i].m_note.size(); j++)
                {
                    if (m_elevi[i].m_note[j].m_materie == materie)
                    {
                        nr_note_total++;
                    }
                }
            
        }
        if (nr_note_total > 0)
        {
            float probabilitate = nr_note_elev - (nr_note_total / nr_note_elev);

            if (probabilitate <= 0)
            {
                std::cout << elev.get_full_name() << ": " << probabilitate << " <- probabilitate mare de ascultare la materia " << "[" << materie << "]" << '\n';
            }
            else
            {
                std::cout << elev.get_full_name() << ": " << probabilitate << " <- probabilitate mica de ascultare la materia " << "[" << materie << "]" <<'\n';
            }
        }
        else
        {
            std::cout << "Nu exista suficiente note la materia " << "[" << materie << "]" << " pentru a calcula probabilitatea.\n";
        }
    }

    void Medie_generala_materie(const std::string& materie, const Elev& elev) {
        int nr_note_elev = 0;
        int suma_notelor = 0;
        for (int i = 0; i < elev.m_note.size(); i++)
        {
            if (elev.m_note[i].m_materie == materie)
            {
                nr_note_elev++;
                suma_notelor += elev.m_note[i].m_valoare;
            }
        }
       std::cout << "Media la materia " << "[" << materie << "] este " << (float)suma_notelor / nr_note_elev;
    }

~Catalog() {}
};



int main()
{

    /*Nota nota1(5, "12-03-2004", "Sport");
    std::cout << nota1 << '\n';
    Elev elev1("1234", "Corvin", "Matei", {}, {});
    elev1.adauga_nota(nota1);
    std::cout << elev1 << '\n';*/



    Catalog catalog;
    Nota nota1(4, "23-11-2024", "Matematica");
    Nota nota2(7, "23-11-2024", "Matematica");
    Nota nota3(2, "23-11-2024", "Matematica");
    Nota nota4(8, "12-11-2024", "Matematica");
    Nota nota5(7, "12-11-2024", "Matematica");
    Nota nota6(9, "12-11-2024", "Matematica");
    Nota nota7(9, "12-11-2024", "Matematica");
    Nota nota8(8, "12-11-2024", "Matematica");
    Nota nota9(7, "12-11-2024", "Matematica");
    Nota nota10(9, "12-11-2024", "Matematica");
    /*Nota nota5(5, "24-11-2024", "Mate");
    Absenta absentaMate("25-11-2024", "Mate", false);
    Absenta absentaRomana("25-11-2024", "Romana", true);*/
    /*std::cout << nota4 << '\n';*/
    Elev elev1("1234", "Corvin", "Matei", {}, {});
    Elev elev2("123", "Stefan", "Vlad", {}, {});
    Elev elev3("1235", "Tudorache", "Ana", {}, {});
    /*std::cout << elev1 << '\n';*/       
    elev1.adauga_nota(nota10);
    elev1.adauga_nota(nota9);
    elev1.adauga_nota(nota8);
    elev1.adauga_nota(nota7);
    elev1.adauga_nota(nota6);
    elev1.adauga_nota(nota5);
    elev3.adauga_nota(nota4);
    elev3.adauga_nota(nota5);
    elev2.adauga_nota(nota3);
    elev2.adauga_nota(nota2);
    elev3.adauga_nota(nota1);

    /* numarTotalNote(elev1);*/
    /*std::cout << elev1 << '\n';*/
    /*std::cout << elev1.numar_note_elev();
    std::cout << '\n';
    std::cout << elev2.numar_note_elev();*/
    catalog.adaugaElev(elev1);
    catalog.adaugaElev(elev2);
    catalog.adaugaElev(elev3);
    std::cout << catalog;

    catalog.Probabilitate_ascultare("Matematica", elev2);

    catalog.Medie_generala_materie("Matematica", elev2);

    /*std::cout << nota5 << '\n';*/
    /* nota5 = nota4;
    std::cout << "Noua nota 5:  " << nota5 << '\n';
    std::cout << '\n';*/
    /*std::cout << absentaMate << '\n';
    std::cout << absentaRomana << '\n';*/
    /*td::cout << '\n';*/
    /*Profesor profesorMate("Corvin", "Matei", "Matematica", "XII A");
    Profesor profesorRomana("Alexandru", "Popescu", "Romana");
    std::cout << profesorMate << '\n';
    std::cout << profesorRomana << '\n';
    std::cout << profesorMate.get_full_name() << '\n';
    std::cout << '\n';*/
    /*Elev elev1("1234", "Corvin", "Matei", {}, {});
    elev1.adauga_nota(nota5);
    elev1.adauga_absenta(absentaRomana);
    Elev elev2(elev1);
    std::cout << elev2 << '\n';
    std::cout << elev1 << '\n';*/
}










//#include <iostream>
//#include <array>
//
//#include <Helper.h>
//
//int main() {
//    std::cout << "Hello, world!\n";
//    std::array<int, 100> v{};
//    int nr;
//    std::cout << "Introduceți nr: ";
//    /////////////////////////////////////////////////////////////////////////
//    /// Observație: dacă aveți nevoie să citiți date de intrare de la tastatură,
//    /// dați exemple de date de intrare folosind fișierul tastatura.txt
//    /// Trebuie să aveți în fișierul tastatura.txt suficiente date de intrare
//    /// (în formatul impus de voi) astfel încât execuția programului să se încheie.
//    /// De asemenea, trebuie să adăugați în acest fișier date de intrare
//    /// pentru cât mai multe ramuri de execuție.
//    /// Dorim să facem acest lucru pentru a automatiza testarea codului, fără să
//    /// mai pierdem timp de fiecare dată să introducem de la zero aceleași date de intrare.
//    ///
//    /// Pe GitHub Actions (bife), fișierul tastatura.txt este folosit
//    /// pentru a simula date introduse de la tastatură.
//    /// Bifele verifică dacă programul are erori de compilare, erori de memorie și memory leaks.
//    ///
//    /// Dacă nu puneți în tastatura.txt suficiente date de intrare, îmi rezerv dreptul să vă
//    /// testez codul cu ce date de intrare am chef și să nu pun notă dacă găsesc vreun bug.
//    /// Impun această cerință ca să învățați să faceți un demo și să arătați părțile din
//    /// program care merg (și să le evitați pe cele care nu merg).
//    ///
//    /////////////////////////////////////////////////////////////////////////
//    std::cin >> nr;
//    /////////////////////////////////////////////////////////////////////////
//    for(int i = 0; i < nr; ++i) {
//        std::cout << "v[" << i << "] = ";
//        std::cin >> v[i];
//    }
//    std::cout << "\n\n";
//    std::cout << "Am citit de la tastatură " << nr << " elemente:\n";
//    for(int i = 0; i < nr; ++i) {
//        std::cout << "- " << v[i] << "\n";
//    }
//    ///////////////////////////////////////////////////////////////////////////
//    /// Pentru date citite din fișier, NU folosiți tastatura.txt. Creați-vă voi
//    /// alt fișier propriu cu ce alt nume doriți.
//    /// Exemplu:
//    /// std::ifstream fis("date.txt");
//    /// for(int i = 0; i < nr2; ++i)
//    ///     fis >> v2[i];
//    ///
//    ///////////////////////////////////////////////////////////////////////////
//    ///                Exemplu de utilizare cod generat                     ///
//    ///////////////////////////////////////////////////////////////////////////
//    Helper helper;
//    helper.help();
//    ///////////////////////////////////////////////////////////////////////////
//    return 0;
//}
