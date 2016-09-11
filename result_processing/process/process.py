#!/usr/bin/env python

"""Processes output of souce code in C++ in folder ../group_evaluation.
This code can make table with fixed speed, and plot comparative graph and
level plot.
"""

import numpy as np
import matplotlib as mp
import matplotlib.pyplot as plt
import os

FAST_SZ, UNIT_SZ, FAST_DEMO_SZ, UNIT_DEMO_SZ = 100, 100, 12, 50
FIRST_ALGO = 'ChoSahniOptimizer'
SECOND_ALGO = 'SchemaOptimizerBrute'

matrix_first, matrix_second = np.zeros((FAST_SZ + 1, UNIT_SZ + 1)), np.zeros((FAST_SZ + 1, UNIT_SZ + 1))


def read(filename):
   """ Reads file with address filename. Assumes that two algorithms
   are compared, and writes the first to matrix_first, the second to
   matrix_second.
   """
   data = open(filename, "r");
   data.readline();
   for line in data:
       tokens = line.split()
       fast = int(tokens[1])
       unit = int(tokens[2])
       first_quality = float(tokens[6])
       second_quality = float(tokens[8])
       matrix_first[fast][unit] = first_quality
       matrix_second[fast][unit] = second_quality

def compare_fixed(fast, speed):
    """ Plots graph comparing performance of
    Cho-Sahni, scheme for General R, and
    scheme for R = 0. Speed and amount of fast
    processors are fixed, number of unit processors
    varies.
    """
    x, y1, y2, y3 = [], [], [], []
    for i in range(1, FAST_SZ + 1):
        x.append(i)
        y1.append(matrix_first[fast][i])
        y2.append(matrix_second[fast][i])
        delta = float(fast) / float(i)
        s = speed
        y3.append(max(s, 2. + (s - 1.) / (s * delta + 1.)))

    fig, ax = plt.subplots()
    plt.title("speed = {0}, number of fast processors = {1}".format(speed, fast))
    plt.plot(x, y1, label = 'Cho-Sahni optimizer')
    plt.plot(x, y2, label = 'Schema for general R ')
    plt.plot(x, y3, label = 'Schema for case R = 0')
    plt.xlabel('Number of unit speed processors')
    plt.ylabel('Performance')
    legend = ax.legend(loc = 'upper left', shadow = True)
    plt.savefig('result/speed={0}-fast={1}.png'.format(speed, fast))
    plt.clf()

def make_levels(speed):
    """ Plots level-plot comparing Cho-Sahni algorithm with
    our approach (Schema). Depends on speed.
    """
    difference_matrix = np.zeros((FAST_SZ, UNIT_SZ))
    for i in range(FAST_SZ):
        for j in range(UNIT_SZ):
            difference_matrix[i][j] = - matrix_second[i][j] + matrix_first[i][j]
    x = range(1, FAST_SZ + 1)
    y = range(1, UNIT_SZ + 1)
    plt.xlabel('Number of fast processors')
    plt.ylabel('Number of unit processors')
    plt.title('ChoSahni minus Schema, \nspeed={0}'.format(speed))
    plt.contourf(x, y, difference_matrix)
    plt.colorbar()
    plt.savefig('result/contour-speed={0}.png'.format(speed))
    plt.clf()


def make_table(speed):
    """ Create latex table with fixed speed for our scheme.
    Amount of unit processors varies in [1, UNIT_DEMO_SZ].
    Amount of fast processors varies in [1, FAST_DEMO_SZ].
    """
    trg = np.zeros((FAST_DEMO_SZ, UNIT_DEMO_SZ))
    f = open("result/speed={}-table.tex".format(speed), "w")
    s = "{|c|"
    for i in range(FAST_DEMO_SZ):
        s += 'c|'
    s += "}"
    print >> f, "\\begin{table*}[ht]"
    print >> f, "\\tabcolsep=0.11cm"
    print >> f, "\\tiny"
    print >> f, "\\caption{Performance of Schema} "
    print >> f, "\\label{performance-table}"
    print >> f, "\\begin{tabular}" + s
    print >> f, "\\hline"
    print >> f, "head & ",
    for j in range(FAST_DEMO_SZ):
        print >> f, "fast = {0}".format(j + 1),
        if (j + 1 != FAST_DEMO_SZ):
            print >> f, "&",
        else:
            print >> f, "\\\\",

    print >> f, "\\hline"
    for j in range(UNIT_DEMO_SZ):
        print >>f, "unit = {}".format(j + 1), "&"
        for i in range(FAST_DEMO_SZ):
            trg[i][j] = round(matrix_second[i+1][j+1], 4)
            print >> f, trg[i][j],
            if (i + 1 != FAST_DEMO_SZ):
                print >> f, "&",
            else:
                print >> f, "\\\\",
        print >> f
        print >> f, "\\hline"
    print >> f, "\\end{tabular}"
    print >> f, "\\normalsize"
    print >> f, "\\end{table*}"
    f.close()


def do_all_for_speed(speed):
    """Plots levels, graphs and creates table for fixed speed."""
    speed_string = "{0:g}".format(speed)
    read('../group_evaluation/group-' + str(FIRST_ALGO) + '-' + str(SECOND_ALGO) + '-speed=' + str(speed_string) + '-fast_lower=1-fast_upper=' + str(FAST_SZ)
            + '-unit_lower=1-unit_upper=' + str(UNIT_SZ) + '.res');
    compare_fixed(7, speed)
    compare_fixed(2, speed)
    compare_fixed(9, speed)
    make_table(speed)
    make_levels(speed)


def main():
    do_all_for_speed(2.)
    do_all_for_speed(3.)
    do_all_for_speed(4.)
    do_all_for_speed(1.5)
    if not os.path.exists("result"):
        os.makedirs("result")

if __name__ == "__main__":
    main()


