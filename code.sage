from fractions import Fraction

# prime number generator function
def magic(end):
    primeroots=set()
    allprimes=set()
    for n in range(1,end+1,2):
        roots = set()
        prime=True
        for r in range(1,n):
            element=r/float(n)
            if element not in primeroots:
                roots.add(element)
            else:
                prime=False
                break
        if not prime:
            continue
        primeroots.update(roots)
        allprimes.add(n)
    if (end > 1):
        allprimes.add(2)
    return allprimes

# upper limit of #s to check for prime
top=1000

print("Starting Albert's Magic - " + str(top))
l1=magic(top)
print("Albert's Magic Found " + str(len(l1)) + " primes")
print(l1)