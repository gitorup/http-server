#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "lws_http.h"
#include "lws_http_plugin.h"

void lws_default_handler(lws_http_conn_t *c, int ev, void *p)
{
    struct http_message *hm = p;
    char data[1024] = {0};

    if (hm && ev == LWS_EV_HTTP_REQUEST) {
        if (c->send == NULL) {
            return ;
        }

        sprintf(data, "%s",
                  "<html><body><h>Enjoy your webserver!</h><br/><br/>"
                  "<ul style=\"list-style-type:circle\">"
                  "<li><a href=\"/hello\"> echo hello message </a></li>"
                  "<li><a href=\"/version\"> echo lws version </a></li>"
                  "</ul>"
                  "</body></html>");

        lws_http_respond(c, 200, c->close_flag, LWS_HTTP_HTML_TYPE, data, strlen(data));
    }
}

void lws_hello_handler(lws_http_conn_t *c, int ev, void *p)
{
    struct http_message *hm = p;
    char data[1024] = {0};

    if (hm && ev == LWS_EV_HTTP_REQUEST) {
        if (c->send == NULL) {
            return ;
        }

        sprintf(data, "%s",
                  "<html><body><h>Hello LWS!</h><br/><br/>"
                  "</body></html>");

        lws_http_respond(c, 200, c->close_flag, LWS_HTTP_HTML_TYPE, data, strlen(data));
    }
}

void lws_version_handler(lws_http_conn_t *c, int ev, void *p)
{
    struct http_message *hm = p;
    char data[1024] = {0};

    if (hm && ev == LWS_EV_HTTP_REQUEST) {
        if (c->send == NULL) {
            return ;
        }

        sprintf(data, "<html><body><h>LWS - version[%s]</h><br/><br/>"
                  "</body></html>", LWS_HTTP_VERSION);

        lws_http_respond(c, 200, c->close_flag, LWS_HTTP_HTML_TYPE, data, strlen(data));
    }
}

