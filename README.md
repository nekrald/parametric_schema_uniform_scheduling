# parametric_schema_uniform_scheduling

This repository contains source code and appendices for paper "...".

The structure of repository is the following:

1.Folder <i> <b> code </b> </i> contains source code written in C++. 
This code is used to provide bounds for algorithm of Cho and Sahni 
and our algorithm (bound is obtained by optimization of Parametric Schema presented in paper). 
Makefile is presented, so compilation is done with command:

'make release'

Note that we need GNU g++ with version > 5.3.1. that supports c++17.

In main.cpp one can specify amounts of fast and unit processors, and algorithm will provide bounds obtained by 
our algorithm and by algorithm of Cho and Sahni.

Result of execution is written to folder group_evaluation. 

2.Folder result_and_processing contains our launch results (in folder group_evaluation), as well as file 
(process.py, written in Python) used to prepare tables and graphs for publishing. Tables and graphs are present.

3.Folder appendix_A contains Appendix A of the paper, as well as Wolfram Mathematica notebook containing the same material.

4.Folder appendix_B contains Appendix B, which describes our computation approach.

5.Folder appendix_C contains Appendix C, which describes some generatlizations of our approach.
