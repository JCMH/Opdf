Opdf
====

A free and cross-plataform  PDF viewer project in gtkmm and glade. The project still is at a experimental stage. Help is welcome.

Compile with

g++ -o opdf opdf.cc `pkg-config --cflags --libs gtkmm-2.4`

or

g++ -o opdf opdf.cc $(pkg-config --cflags --libs gtkmm-2.4)

In a Unix environment, run

./opdf

Author: Juan Carlos Moreno 
jmorenohenao3@gmail.com