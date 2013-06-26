Thank you for obtaining a copy of the Gold Rubeberg Decision Platform!

At Gold Rubeberg Software we believe in using the BEST tool for each task, and are not afraid of wielding the power of every tool necessary to leverage synergies across technology platforms. The Decision Platform consists of a flexible client-server-structure and an extensible plugin-system with just-in-time compilation to manage different random number generators. 

Requirements:
 - Python, >= 2.6
 - g77 Fortran compiler
 - g++ C++ compiler
 - cpp C preprocessor
 - make
 - javac Java compiler and the Java runtime, if you wish to use the Java GUI
 - perl, any version, if you wish to use the Perl-plugin
(Tested on Windows XP and Windows 7, with cygwin 1.7.x, and on Ubuntu 64bit)

Installation:
 - copy all files in the distribution to some directory

Starting the server:
 - cd to the directory 'server' and run 'make'
 - (optional) modify options.xml to e.g. add additional users, change the used plugin, ...
 - run ./server.exe
 
Starting the GUI client:
 - cd to the directory 'clients/gui' and run 'make'
 - run 'java GuiClient'
 - in the settings-tab you have to enter the hostname and port (default: 31337) on which the server is running
 - in the main-tab you have to enter the username
 
Starting the WebServer Client:
 - cd to the directory 'clients/http' and run 'make'
 - run 'python httpclientserver.py' (web server and decision server have to run on the same host!)
 - open 'http://hostname:8000/decision' in your browser, where 'hostname' is the name of the host on which the webserver is running
 
Starting the Android Client:
 - Import eh Android Client into an eclipse workspace, and run it as an Android Application in either the emulator or an actual device
 - Since it is only a beta version, further support for the Android client will not be provided at the moment
 
Random Number Generation Plugins:
 - xkcd-plugin: Simple and fast plugin with slightly decreased randomness. However, the high-pass filter used in post-processing mitigates this problem nicely
 - perl-plugin: More advanced random number generator based on the fact that there is no greater source of randomness than perl syntax. Will need more resources than the xkcd-plugin, though
 - write your own: Check out the two plugins to find out how to write your own!

Version history:
---------------------

v1.0, Released August 2008
- Initial Release, containing the server and a command line client

v1.1, Released September 2008
- Fixed Makefiles
- Fixed issue where server would terminate unexpectedly
- Fixed bug in client when illegal arguments were passed

v2.0, Released April 2009
- Adapted protocol to use strings instead of binary data; This allows easier implementation of different clients
- Added Java GUI client

v2.1, Released July 2009
- Redesigned protocol
- Allow re-use of protocol code in C and Java; protocol.h is provided to customers to allow them to write their own clients

v2.2, Released December 2010
- Added authentication to protocol
- Added version number to protocol

v2.3, Released January 2011
- Fixed a bug in protocol.h that broke all clients
- Bumped version number of protocol to 2, to indicate working protocol version

v3, Released August 2011
- Authentication is now optional
- protocol.h now also supporty python
- Added http server client; http authentication is planned for one of the next releases

v3.1, Released November 2011
- Improved authentication from comparing cleartext strings to use md5 hashes (optional)
- Added authentication method negotiation to protocol, bumped version number to 3; available authentication methods are now 'basic' and 'md5'

v4, Released February 2012
- Customer surveys have indicated that the random number generator needed a major overhaul. In stage one of this rework, the old fixed RNG has been replaced with a plugin-system

v4.1, Released August 2012
- To mitigate unrealistic random number sequences with long runs of 'yes's and 'no's, our newly appointed numerical analyst designed a postprocessing method of the random number sequence. If you have any input on the matter, do not hesistate to contact him directly via our website

v4.2, Released April 2013
- Basic authentication has been removed since it has been deemed to be too insecure, protocol version has been bumped to 4 to mirror this decision
- Introduced a smoothing factor to determine how much the high-pass filter should affect the random number series
- Please note that our previous numerical analyst is due to retire soon, if you still have any open enquiries

v5, Released June 2013
- Added a beta-version of our Android client
- Removed obsolete command-line client
- Reworked the high-pass filter
- Added authentication option to plugins; not yet used, but will be fully supported in the next version
- Slightly redesigned protocol to reduce overhead, bumped version number to 5 accordingly

