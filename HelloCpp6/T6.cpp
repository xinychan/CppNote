#include <iostream>

// 登录实例类
class LoginBean {
public:
    std::string userName;
    std::string userPwd;

    LoginBean(std::string userName, std::string userPwd)
            : userName(userName), userPwd(userPwd) {}
};

// 登录结果回调；全纯虚函数类
class ILoginResult {
public:
    virtual void loginSucc(int code, std::string msg, LoginBean loginBean) = 0;

    virtual void loginError(int code, std::string msg) = 0;
};

// 登录结果回调实现类
class ILoginResultImpl : public ILoginResult {
public:
    void loginSucc(int code, std::string msg, LoginBean loginBean) {
        std::cout << "ILoginResultImpl loginSucc:" << msg << std::endl;
    }

    void loginError(int code, std::string msg) {
        std::cout << "ILoginResultImpl loginError:" << msg << std::endl;
    }
};

// 登录操作
void loginAction(std::string userName, std::string userPwd, ILoginResult &loginResult) {
    if (userName.empty() || userPwd.empty()) {
        std::cout << "loginAction empty" << std::endl;
        return;
    }
    if ("clion" == userName && "123456" == userPwd) {
        loginResult.loginSucc(200, "loginSucc", LoginBean(userName, userPwd));
    } else {
        loginResult.loginError(404, "loginError");
    }
}

// C++ 回调
int main() {
    // 全纯虚函数类，必须先事先实现，否则不可实例化
    ILoginResultImpl loginResult;
    loginAction("clion", "123456", loginResult);
    loginAction("IDEA", "123456", loginResult);
    loginAction("", "", loginResult);
    return 0;
}
