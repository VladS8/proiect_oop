#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <sqlite3.h>
#include <string>

class DatabaseHandler {
private:
    sqlite3* db;
    std::string dbPath;

    //static:
public:
    explicit DatabaseHandler(const std::string& path);
    ~DatabaseHandler();

    bool open();
    void close();

    bool createTable(const std::string& tableName);
    bool executeQuery(const std::string &query);
};

#endif // DATABASEHANDLER_H