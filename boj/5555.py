pattern = input()
n = int(input())

count = 0
for i in range(n) :
    ring = input()
    ring = ring + ring
    if ring.find(pattern) != -1 :
        count = count + 1
print(count)
    
