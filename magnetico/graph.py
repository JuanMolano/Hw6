import sys
import os
from matplotlib import cm
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

dat = np.loadtxt("points.txt")

x = dat[0,:]
y = dat[1,:]
z = dat[2,:]

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

o=fig.gca(projection='3d')
o.scatter(x,y,z)


o.set_xlabel('x')
o.set_ylabel('y')
o.set_zlabel('z')

plt.savefig('field.pdf')
