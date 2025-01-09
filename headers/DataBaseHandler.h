#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <sqlite3.h>
#include <string>
/**
     * Constructs a DatabaseHandler object with a specified database file path.
     * The provided path is used to initialize the database file location.
     *
     * @param path The file path to the SQLite database.
 */
class DatabaseHandler {
private:
    sqlite3* db;
    std::string dbPath;

public:
    explicit DatabaseHandler(const std::string& path);
    ~DatabaseHandler();

    bool open();
    void close();

    bool createTable(const std::string& tableName);
    bool executeQuery(const std::string &query);
};

#endif // DATABASEHANDLER_H