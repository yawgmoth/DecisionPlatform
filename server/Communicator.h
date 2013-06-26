#define LANG 1
#define SERVER 1
#include <string>
#include <iostream>
#include <fstream>
#include "DecisionMaker.h"
#include "get_options.h"
using namespace std;
#define AUTHDISABLEOFF 0
#define AUTHDISABLEON 1

class Communicator 
{
private:
   int (*fp)();
   int no_auth;
   
   ServerConn c;
   string readdata()
   {
       
       string line = c.get_line();
       std::cout << "got from client: '" << line << "'\n";
       return line;
   }
   void send_data(string data)
   {
      c.writeline(data);
      std::cout << "sending to client: " << data << "\n";
   }
   ifstream teststream;
   string username;
   string cmd;
   string vers;
   string do_cmd(string cmd)
   {
       if (cmd == "decision")
       {
           if (DecisionMaker::instance()->make_decision()) return "yes";
           return "no";
       }
       return "file not found";
   }
   int checkpwd(string user, string pwd)
   {
       char user_cstr[100];
       strcpy(user_cstr, user.c_str());
       string realpw = getPassWord(user_cstr);
       if (user == "web") return 1; // support webserver "client"
       // if (pwd == realpw) return 1; // Basic authentication is no longer supported!
       if (md5compare(pwd.c_str(), realpw.c_str())) return 1;
       if (no_auth = AUTHDISABLEON) return 1;
       return 0;
   }
public: 
   Communicator(int (*fp)(), int auth_en, ServerConn c): 
            fp(fp), no_auth(!auth_en), teststream("input.txt"), c(c), vers("")
   {
   }
   #include "protocol.h"

};