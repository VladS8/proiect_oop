#include "../headers/DatabaseHandler.h"
#include <iostream>

DatabaseHandler::DatabaseHandler(const std::string& path) : db(nullptr), dbPath(path) {}



bool DatabaseHandler::open() {
    int rc = sqlite3_open(dbPath.c_str(), &db);
    if (rc) {
        std::cerr << "Eroare la deschiderea bazei de date: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    std::cout << "Baza de date deschisă cu succes!" << std::endl;
    return true;
}

void DatabaseHandler::close() {
    if (db) {
        sqlite3_close(db);
        std::cout << "Baza de date închisă cu succes!" << std::endl;
        db = nullptr;
    }
}

bool DatabaseHandler::createTable(const std::string& tableName)
{
    std::string sql;
    if (tableName == "elev") {
        sql = "CREATE TABLE IF NOT EXISTS elev ("
              "NR_MATRICOL INTEGER PRIMARY KEY AUTOINCREMENT, "
              "ID_CLASA INTEGER, "
              "NUME VARCHAR(100) NOT NULL, "
              "PRENUME VARCHAR(100) NOT NULL, "
              "FOREIGN KEY (ID_CLASA) REFERENCES clasa(ID) ON DELETE CASCADE ON UPDATE CASCADE);";
    }
    else if (tableName == "clasa") {
        sql = "CREATE TABLE IF NOT EXISTS clasa ("
              "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
              "NUME VARCHAR(10) NOT NULL, "
              "CAPACITATE INTEGER NOT NULL CHECK (capacitate > 0 AND capacitate <= 32));";
    }
    else if(tableName == "materie") {
        sql = "CREATE TABLE IF NOT EXISTS materie ("
              "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
              "NUME VARCHAR(100) NOT NULL); ";
    }
    else if(tableName == "clasa_materie") {
        sql = "CREATE TABLE IF NOT EXISTS clasa_materie ("
              "ID_CLASA INTEGER, "
              "ID_MATERIE INTEGER, "
              "PRIMARY KEY (ID_CLASA, ID_MATERIE), "
              "FOREIGN KEY (ID_CLASA) REFERENCES clasa(ID) ON DELETE CASCADE ON UPDATE CASCADE, "
              "FOREIGN KEY (ID_MATERIE) REFERENCES materie(ID) ON DELETE CASCADE ON UPDATE CASCADE);";
    }
    else if(tableName == "nota") {
        sql = "CREATE TABLE IF NOT EXISTS nota ("
              "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
              "NR_MATRICOL INTEGER, "
              "ID_MATERIE INTEGER, "
              "VAL INTEGER NOT NULL, "
              "DATA VARCHAR(30) NOT NULL, "
              "FOREIGN KEY(NR_MATRICOL) REFERENCES elev(NR_MATRICOL) ON DELETE CASCADE ON UPDATE CASCADE, "
              "FOREIGN KEY(ID_MATERIE) REFERENCES materie(ID) ON DELETE CASCADE ON UPDATE CASCADE);";
    }
    else if(tableName == "absenta") {
        sql = "CREATE TABLE IF NOT EXISTS absenta ("
              "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
              "NR_MATRICOL INTEGER, "
              "ID_MATERIE INTEGER, "
              "DATA_ABSENTEI VARCHAR(30) NOT NULL, "
              "MOTIVATA BOOLEAN NOT NULL, "
              "FOREIGN KEY(NR_MATRICOL) REFERENCES elev(NR_MATRICOL) ON DELETE CASCADE ON UPDATE CASCADE, "
              "FOREIGN KEY(ID_MATERIE) REFERENCES materie(ID) ON DELETE CASCADE ON UPDATE CASCADE);";
    }

    else if(tableName == "profesor") {
        sql = "CREATE TABLE IF NOT EXISTS profesor ("
              "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
              "NUME VARCHAR(100), "
              "PRENUME VARCHAR(100)); ";
    }

    else {
        std::cerr << "Tabel necunoscut!" << std::endl;
        return false;
    }

    char *errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Eroare la crearea tabelului: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    } else {
        std::cout << "Tabelul " << tableName << " a fost creat cu succes!" << std::endl;
    }

    return true;
}

bool DatabaseHandler::executeQuery(const std::string &query) {
    char *errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "Eroare la executarea query-ului: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }

    return true;
}




DatabaseHandler::~DatabaseHandler() {
    close();
}