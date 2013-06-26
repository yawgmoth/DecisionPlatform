import SimpleHTTPServer
import BaseHTTPServer
import communicator

class RequestHandler(SimpleHTTPServer.SimpleHTTPRequestHandler):
    def do_GET(self, *args, **kwargs):
        self.send_response(200)
        self.send_header("Content-type", 'text/html')
        self.end_headers()
        resp = communicator.communicate()
        self.wfile.write('<html><head><title>Decision platform</title></head><body>')
        self.wfile.write('<center><h1><b>' + str(communicator.result) + '</b></h1>')
        self.wfile.write('<form action="decision" method="GET"><input type="submit" text="AGAIN!"/></form>')
        self.wfile.write('</center>')
        self.wfile.write('</body></html>')
        return 0

def main():
    server_address = ('', 8000)
    httpd = BaseHTTPServer.HTTPServer(server_address, RequestHandler)
    httpd.serve_forever()


if __name__ == '__main__':
    main()