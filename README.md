# Qt5-Spreadsheet
A simple Spreadsheet application made with Qt5, adapted from Mark Summerfield and Jasmin Blanchette's Book "C++ Programming with Qt4" 

## Building
After acquiring a copy of Qt5 (either commercial or open-source), clone this repository and use `qmake` to generate the makefile, then use `make` to build de application. It should work on every OS that Qt is compatible to. Tested on Kubuntu Linux.

## Notes
* The code of this app came from book descripted above. You can get a copy of the book here:
https://www.amazon.com/Programming-Prentice-Source-Software-Development/dp/0132354160

* Notice the `QIcon::fromTheme` will only work on Operating Systems that follow FreeDesktop Icon Naming Specification.
