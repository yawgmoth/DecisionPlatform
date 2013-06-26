import getopt
import xml.dom.minidom

def show_help():
    print "Do not call this program directly, it is just used internally by DecisionEngine"

def main(args):
    xmlfile = "options.xml"
    tag = "options"
    resultfile = "result.exe" # TODO: come up with better extension for EXchangE format
    try:
       # TODO: figure out how this module works, may clear up some of the code below
       optlist, arglist = getopt.getopt_gnu(args, "+x:ht", ["xml-file=", "help", "tag="])
    except:
       pass
    store_xmlfile = False
    store_tag = False
    store_resultfile = False
    for a in args[1:]:
        if store_xmlfile:
            xmlfile = a
            store_xmlfile = False
            del args[0]
        if a == '--xml-file' or a == '-x':
            store_xmlfile = True
            del args[0]
        if a == '--help':
            usage()
            return 0
        if store_tag:
            tag = a
            del args[0]
        if a == '--tag' or a == '-t':
            store_tag = True
            del args[0]
        if store_resultfile:
            resultfile = a
            del args[0]

    del args[0] # remove program name
    d = xml.dom.minidom.parse(xmlfile)
    value = "NULL"
    for n in d.childNodes[0].childNodes:
        if n.toxml().strip().startswith("<" + tag):
            value = n.toxml().strip()[len(tag)+2:-len(tag)-3]
    f = open(resultfile, "w")
    if tag == "progoptions":
        import base64
        value = base64.b64decode(value)
    f.write(value)
    f.close()
            

if __name__ == '__main__':
    import sys
    main(sys.argv)