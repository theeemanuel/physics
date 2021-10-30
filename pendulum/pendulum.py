import numpy as np
import matplotlib.pyplot as plt 
import matplotlib.animation as animation
from matplotlib import colors

g = 2.5
l = 30
c = -1.24

dimX = 80
dimY = 50
fig = plt.figure(figsize=(5, 4))
ax = fig.add_subplot(autoscale_on=False, xlim=(0, dimX), ylim=(0, dimY))
ax.set_aspect('equal')
ax.grid()
line, = ax.plot([], [], '-o', lw=2)
t = 0

def init():
    line.set_data([], [])
    return line,

def f(t):
    return (c*np.sin(((g/l)**(1/2))*t))

def animate(i):
    x = l*np.cos(f(i)+4.712) + (dimX//2)
    y = l*np.sin(f(i)+4.712) + (dimY-10)

    u = [(dimX//2), x]
    v = [(dimY-10), y]

    line.set_data(u, v)
    return line,

anim = animation.FuncAnimation(fig, animate, init_func=init, interval=60, blit=True)
#anim.save('pendulum.gif', writer='imagemagick', fps=60)
plt.show()
