
#if LANG == 1
#include "cppsupport.h"
#else
#if LANG == 2
#include "javasupport.h"
#else
#include "pythonsupport.h"
#endif

#endif

#define IS_ERROR(msg) msg == EMPTY_STRING_CONST
#define MAKE_IF(cond, blk) if (cond) IF_BEGIN blk IF_END
#if LANG == 3
#define MAKE_IF_ELSE(cond, blk, blk1) return pyifelse(cond, blk, blk1)
#define REALRET(x) return x
#else
#define MAKE_IF_ELSE(cond, blk, blk1) if (cond) IF_BEGIN blk IF_ELSE blk1 IF_END
#define REALRET(x) RET(x)
#endif

#if SERVER == 1
#define FROMCLIENT(msg) m = readdata(); r = handle_##msg(m); MAKE_IF(IS_ERROR(r), QUIT_FUNC)
#define FROMSERVER(msg) send_data(r);
#define INIT_MESSAGE EMPTY_STRING_CONST
#else
#define FROMSERVER(msg) m = readdata(); r = handle_##msg(m); MAKE_IF(IS_ERROR(r), QUIT_FUNC)
#define FROMCLIENT(msg) send_data(r);
#define INIT_MESSAGE "5"
#endif


#if SERVER == 1
RETURN_TYPE_MESSAGE handle_vers(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "5"), RET("5"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_ackvers(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "ack"), RET("start"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_authlist(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "authlist"), RET("md5"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_selectauthtype(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "md5"), RET("user"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_user(VAR_TYPE_MSG msg) FUNC_BEGIN
    username = msg;
    REALRET("reqpwd")
    FUNC_END
    
RETURN_TYPE_MESSAGE handle_pwd(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(checkpwd(username, msg), RET("okpwd"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_cmd(VAR_TYPE_MSG msg) FUNC_BEGIN
    cmd = msg;
    REALRET("okcmd")
    FUNC_END
    
RETURN_TYPE_MESSAGE handle_reqresult(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "reqresult"), RET(do_cmd(cmd)), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_close(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "close"), RET("okclose"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_quit(VAR_TYPE_MSG msg) FUNC_BEGIN
    REALRET("")
    FUNC_END
#else
RETURN_TYPE_MESSAGE handle_serververs(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "5"), RET("ack"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_start(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "start"), RET("authlist"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_authtypes(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "md5"), RET("md5"), RET(""))
    FUNC_END
    
RETURN_TYPE_MESSAGE handle_reqauth(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "user"), RET(username), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_reqpwd(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "reqpwd"), RET(pwd), RET(""))
    FUNC_END
    
RETURN_TYPE_MESSAGE handle_okpwd(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "okpwd"), RET("decision"), RET(""))
    FUNC_END
    
RETURN_TYPE_MESSAGE handle_okcmd(VAR_TYPE_MSG msg) FUNC_BEGIN
    MAKE_IF_ELSE(CMP(msg, "okcmd"), RET("reqresult"), RET(""))
    FUNC_END

RETURN_TYPE_MESSAGE handle_result(VAR_TYPE_MSG msg) FUNC_BEGIN
    RESULTPREFIX
    result = msg;
    REALRET("close")
    FUNC_END

RETURN_TYPE_MESSAGE handle_okclose(VAR_TYPE_MSG msg) FUNC_BEGIN
    REALRET("quit")
    FUNC_END

RETURN_TYPE_MESSAGE handle_nothing(VAR_TYPE_MSG msg) FUNC_BEGIN
    REALRET("")
    FUNC_END
#endif

RETURN_TYPE_VOID onemessage() FUNC_BEGIN
    MESSAGE_TYPE r = INIT_MESSAGE END_LINE
    MESSAGE_TYPE m = EMPTY_STRING_CONST END_LINE
    FROMCLIENT(vers)
    FROMSERVER(serververs)
    FROMCLIENT(ackvers)
    FROMSERVER(start)
    FROMCLIENT(authlist)
    FROMSERVER(authtypes)
    FROMCLIENT(selectauthtype)
    FROMSERVER(reqauth)
    FROMCLIENT(user)
    FROMSERVER(reqpwd)
    FROMCLIENT(pwd)
    FROMSERVER(okpwd)
    FROMCLIENT(cmd)
    FROMSERVER(okcmd)
    FROMCLIENT(reqresult)
    FROMSERVER(result)
    FROMCLIENT(close)
    FROMSERVER(okclose)
    FROMCLIENT(quit)
    FUNC_END
