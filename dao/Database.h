#pragma once
#include <string>
#include <vector>
#include <mysql.h>
#include "DbException.h"
#include "DbConnection.h"
using namespace std;

struct QueryResult
{
	vector<string> fileds;
	vector<vector<string>> rows;
};

class Database
{
private:
	const char* host = "localhost";
	const char* username = "root";
	const char* password = "123456";
	const char* database = "store";
	DbConnection db;
	
	static vector<string> getColNames(MYSQL_RES res);
	static vector<vector<string>> getRows(MYSQL_RES res);
	
public:
	Database();
	Database(string host, string username, string password, string database);

	QueryResult select(string col, string table, string condition="");
	QueryResult select(string sql);
	int insert(string table, string col, string values);
	//int insert(string table...);
    int insert(string sql);
	int update(string table, string col, string values, string condition);
    int update(string sql);
	int deleteRow(string table, string condition);
    int deleteRow(string sql);
};

