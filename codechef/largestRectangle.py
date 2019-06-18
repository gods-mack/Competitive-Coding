# hackerRank problem : stack : Largest Rectangle
# Problem URL:
""" https://www.hackerrank.com/challenges/largest-rectangle/problem?h_l=interview&playlist_slugs%5B%5D=interview-
preparation-kit&playlist_slugs%5B%5D=stacks-queues  """


def largestRectangle(h):
    stack = []
    max_area = 0
    h += [0,]
    for i, n in enumerate(h):
        if not stack or n >= stack[-1][1]:
            stack.append((i, n))
            print(i," ",n)
        else:
            while stack and stack[-1][1] >= n:
                p = stack.pop()
                max_area = max((i - p[0])*p[1], max_area)
            stack.append((p[0], n))
    return max_area


    
h = [4,2,8,9,6,5,7,3]

res = largestRectangle(h)
print(res)
    
