import sys
import md5

sys.exit(1 if md5.md5(sys.argv[1]).hexdigest() == md5.md5(sys.argv[2]).hexdigest() else 0)