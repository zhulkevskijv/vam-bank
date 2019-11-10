#ifndef DATABASECONNECT_H
#define DATABASECONNECT_H
#include <QString>
#include <vector>
#include <QSqlDatabase>
#include <QSqlQuery>
class IUser;
class IAccount;
class ICard;
class ITransaction;
class UserProxy;

class DatabaseConnect {
private:
    static DatabaseConnect* _instance;
    DatabaseConnect();
    static QString dbHost;
    static QString dbName;
    static QString dbPass;
    static QString dbUser;
    QSqlDatabase _db;
    QSqlQuery* _qrAddAccount;
    QSqlQuery* _qrAddUser;
    QSqlQuery* _qrAddTransaction;

    QSqlQuery* _qrRmAccount;
    QSqlQuery* _qrRmUser;

    QSqlQuery* _qrUpdCard;
    QSqlQuery* _qrUpdAccount;
    QSqlQuery* _qrUpdUser;

    QSqlQuery* _qrGetUserAccounts;
    QSqlQuery* _qrGetAccountCards;
    QSqlQuery* _qrGetAccountTransactions;
    QSqlQuery* _qrGetUsers;

public:
    static DatabaseConnect& getInstance();
    DatabaseConnect(const DatabaseConnect& )=delete;
    DatabaseConnect& operator=(const DatabaseConnect& )=delete;
    ~DatabaseConnect();

    void addAccount(const IAccount*);
    void addUser(const IUser*);
    void addTransaction(const ITransaction*);

    void removeUser(const std::string&);
    void removeAccount(const size_t);

    void updateUser(const IUser*);
    void updateAccount(const IAccount*);
    void updateCard(const ICard*);

    std::vector<UserProxy*> getUsers();
    std::vector<const ITransaction*> getAccountTransactions(const size_t);
    std::vector<IAccount*> getUserAccounts(const std::string&);
    std::vector<ICard*> getAccountCards(const size_t id);
};

#endif // DATABASECONNECT_H
