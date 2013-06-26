#include <string.h>

class ServerConn 
{
   int s;
   public:
       ServerConn(int s): s(s)
       {
       }
       void writeline(std::string line)
       {
           send(s, line.c_str(), line.length(), MSG_WAITALL);
           send(s, "\n", 1, MSG_WAITALL);
       }
       std::string get_line()
       {
           std::string line("");
           char buf[2];
           buf[1] = 0;
           while (buf[0] != '\n')
           {
              int err = recv(s, buf, 1, MSG_WAITALL);
              
              if (err < 1)
                 continue;
              if (buf[0] != '\n' && buf[0] != '\r')
                  line += buf;
           }
           return line;
       }

};

class Server
{
    int s;
    public:
        Server(): s(-1)
        {
            struct sockaddr_in addr;
            s = socket(AF_INET, SOCK_STREAM, 0);
            addr.sin_port = 27002;
            addr.sin_family = AF_INET;
            memset(&(addr.sin_addr), INADDR_ANY, sizeof(in_addr));
        }
        ServerConn runonce()
        {
            return ServerConn(accept(s, NULL, NULL));
        }
};