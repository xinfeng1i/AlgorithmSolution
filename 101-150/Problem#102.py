import numpy as np

def containOrigin(ax, ay, bx, by, cx, cy):
    ab = [bx-ax, by-ay]
    ac = [cx-ax, cy-ay]
    ao = [0-ax, 0-ay]
    A = np.array([[np.inner(ab, ac), np.inner(ac, ac)], [np.inner(ab, ab), np.inner(ab, ac)] ])
    B = np.array([np.inner(ao, ac), np.inner(ao, ab)])
    
    u, v = np.linalg.solve(A, B)

    return u > 0 and v > 0 and u + v < 1

if __name__ == "__main__":

    cnt = 0
    with open("triangles.txt") as f:
        for line in f:
            ax, ay, bx, by, cx, cy = [int(x) for x in line.split()]
            if containOrigin(ax,ay,bx,by,cx,cy):
                cnt += 1

    f.close()
    print("The number of triangles contained origin: ", cnt)
