# parametric_schema_uniform_scheduling
===========================
This is a scientific project.
This repository contains source code and appendices for paper "...".
The code is a proof of concept on how to find upper bound and schema parameters of algorithm presented in paper. 

The structure of repository is the following:

1.Folder `code` contains source code written in C++. 
This code is used to provide bounds for algorithm of Cho and Sahni 
and our algorithm (bound is obtained by optimization of Parametric Schema presented in paper). 
Makefile is presented, so compilation is done with command:

`make release`

Note that we need GNU g++ with version > 5.3.1 (or some other C++ compiler that supports c++17).

One can run code by executing `./main`. Result of execution is written to folder `group_evaluation`. 

In main.cpp one can specify amounts of fast and unit processors, and algorithm will provide bounds obtained by 
our algorithm and by algorithm of Cho and Sahni.

2.Folder `result_and_processing` contains our launch results (in folder `group_evaluation`), as well as file 
(`process.py`, written in Python) used to prepare tables and graphs for publishing. Tables and graphs are presented, too.

3.Folder `appendix_A` contains Appendix A of the paper, as well as Wolfram Mathematica notebook containing the same material.

4.Folder `appendix_B` contains Appendix B, which describes our computation approach.

5.Folder `appendix_C` contains Appendix C, which describes some generatlizations of our approach.
