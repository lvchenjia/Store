#include "Database.h"
#include <iostream>
Database::Database():db(host, username, password, database){}

Database::Database(string host, string username, string password, string database)
	:db(host.c_str(), username.c_str(), password.c_str(), database.c_str()) {}

QueryResult Database::select(string col, string table, string condition)
{
	string sql = "select " + col + " from " + table + " " + condition;
	MYSQL_RES res = db.executeQuery(sql.c_str());
	QueryResult result;
	result.fileds = getColNames(res);
	result.rows = getRows(res);
	return result;
}

QueryResult Database::select(string sql)
{
	MYSQL_RES res = db.executeQuery(sql.c_str());
	QueryResult result;
	result.fileds = getColNames(res);
	result.rows = getRows(res);
	return result; 
}

int Database::insert(string table, string col, string values)
{
	string sql = "insert into " + table + "(" + col + ") values(" + values + ")";
    cout<< sql << endl;
	return db.executeSQL(sql.c_str());
}

//int Database::insert(string table ...) {
//	string sql = "insert into " + table + "(";
//	va_list args;
//	va_start(args, table);
//	string col = va_arg(args, string);
//	while (col != "")
//	{
//		sql += col + ",";
//		col = va_arg(args, string);
//	}
//	sql = sql.substr(0, sql.length() - 1) + ") values(";
//	string value = va_arg(args, string);
//	while (value != "")
//	{
//		sql += value + ",";
//		value = va_arg(args, string);
//	}
//	sql = sql.substr(0, sql.length() - 1) + ")";
//	va_end(args);
//	return db.executeSQL(sql.c_str());
//}

int Database::insert(string sql)
{
    return db.executeSQL(sql.c_str());
}

int Database::update(string table, string col, string values, string condition)
{
	string sql = "update " + table + " set " + col + "=" + values + condition;
	return db.executeSQL(sql.c_str());
}

int Database::update(string sql)
{
    return db.executeSQL(sql.c_str());
}

int Database::deleteRow(string table, string condition)
{
	string sql = "delete from " + table + condition;
	return db.executeSQL(sql.c_str());
}

int Database::deleteRow(string sql)
{
    return db.executeSQL(sql.c_str());
}

vector<string> Database::getColNames(MYSQL_RES res)
{
	vector<string> colNames;
	unsigned int num_fields = mysql_num_fields(&res);
	MYSQL_FIELD* fields = mysql_fetch_fields(&res);
	for (unsigned int i = 0; i < num_fields; i++)
	{
		colNames.push_back(fields[i].name);
	}
	return colNames;
}

vector<vector<string>> Database::getRows(MYSQL_RES res)
{
	vector<vector<string>> rows;
	unsigned int num_fields = mysql_num_fields(&res);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(&res)))
	{
		vector<string> currow;
		for (unsigned int i = 0; i < num_fields; i++)
		{
			currow.push_back(((row[i] != NULL) ? row[i] : "NULL"));
		}
		rows.push_back(currow);
	}
	return rows;
}
