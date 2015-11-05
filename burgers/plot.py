import sys
import os
from matplotlib import cm
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt("data.txt")

for i in range(0,500):
    
    u = data[2*i*41:(2*i+1)*41,:]
    v = data[(2*i+1)*41:(2*i+2)*41,:]
    x = np.linspace(0,2,41)
    y = np.linspace(0,2,41)
    fig = plt.figure(figsize=(11,7), dpi=100)
    ax = fig.gca(projection='3d')
    X,Y = np.meshgrid(x,y)
    wire1 = ax.plot_wireframe(X,Y,u)
    wire2 = ax.plot_wireframe(X,Y,v)
    ax.set_xlim(0,2)
    ax.set_ylim(0,2)
    ax.set_zlim(1,3)
    plt.savefig('bg%s.png'%(i), format = 'png')
    plt.close()


os.system('convert -delay 0.00001 $(ls -v bg*.png) burgers.gif')

os.system('rm -r bg*.png')