import Queue
intset =set()
intset.add(1)
intset.add(6)
max = 10**10
for i in range(10):
    next_set = set()
    for key in intset:
        next1 = key * 10 + 1
        next2 = key * 10 + 6
        if next1 <= max: next_set.add(next1)
        if next2 <= max: next_set.add(next2)
    intset |= next_set
mylist = list(intset)
mylist.sort()
goodnumber = set()
goodnumber.add(1)
myq = Queue.Queue()
myq.put(1)
while myq.empty() is False:
    key = myq.get()
    for mul in mylist:
        nextn = mul * key
        if nextn > max : break
        if nextn not in goodnumber:
            goodnumber.add(nextn)
            myq.put(nextn)
goodnumber = list(goodnumber)
goodnumber.sort()
print len(goodnumber)
pass

