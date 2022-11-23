#include"DbConnection.h"
#include"DbException.h"

DbConnection::DbConnection(const char* host, const char* username, const char* password, const char* database)
{
     //初始化MySQL连接对象
     mysql_init(&connection);
     //通过设定数据库连接主机地址host、端口号3306，用户名username、密码passowrd和数据库名database等，建立与MySQL数据库的连接，连接失败抛出异常
     if(NULL == mysql_real_connect(&connection, host, username, password, database, 3306, nullptr, 0))
        throw DbException(mysql_error(&connection));
     //数据库自动重连
    char value = 1;
    mysql_options(&connection, MYSQL_OPT_RECONNECT, &value);
    //设置查询编码为UTF8
    mysql_query(&connection, "set names utf8");
}
DbConnection::~DbConnection(){
    mysql_close(&connection);
}
MYSQL_RES  DbConnection::executeQuery(const char* sql)
{
    //执行select命令
    int res = mysql_query(&connection, sql);
    if(res) //执行失败
        throw DbException(mysql_error(&connection));
    else
    {
        //获取结果集
        MYSQL_RES* res_ptr = mysql_store_result(&connection);
        //如果获取成功
        if(res_ptr)
            return *res_ptr;
        else throw DbException(mysql_error(&connection));
    }
}
 int DbConnection::executeSQL(const char* sql)
 {
    //执行insert、updatedelete或命令
    int res = mysql_query(&connection, sql);

    if(res) //执行失败
        throw DbException(mysql_error(&connection));
    else //执行成功，返回产生影响的记录数
    {
        return mysql_affected_rows(&connection);
    }
 }
