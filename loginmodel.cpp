#include "loginmodel.h"

LoginModel::LoginModel()
{

}

bool LoginModel::login(QString username, QString password)
{
    if(username == "muhammad" && password == "muhsin")
        return true;

    return false;

}

