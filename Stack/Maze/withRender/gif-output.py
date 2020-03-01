'''
gif-output.py
GIF output script
Copyright 2020 by Algebra-FUN
ALL RIGHTS RESERVED.
'''

import imageio

n = 68

frames = []
for i in range(n):
    frames.append(imageio.imread(r'./temp/{}.png'.format(i)))
imageio.mimsave(r'./img/maze.gif', frames, 'GIF', duration = 0.1)