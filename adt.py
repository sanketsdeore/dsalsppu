class set:
    def __init__(self):
        self.s = []
    
    def create(self):
        n = int(input("Enter no. of elements: "))
        for i in range(n):
            a = int(input("Enter element: "))
            self.s.append(a)

    def remove(self):
        a = int(input("Enter the element you wanna remove: "))
        if a in self.s:
            self.s.remove(a);
        else:
            print("Element ", a, " not found.")
    
    def contain(self):
        a = int(input("Enter the element you wanna search: "))
        if a in self.s:
            print("Element ", a , " present in set.")
        else:
            print("Element ", a, " not present in set.")
    
    def size(self):
        print("Size of set: ", len(self.s))
        
    def union(self, set1:set(), set2:set()):
        self.s = set1.s;
        for i in set2.s:
            if i not in set1.s:
                self.s.append(i)
        return self.s
        
    def intersection(self, set1:set(), set2:set()):
        for i in set1.s:
            if i in set2.s:
                self.s.append(i)
        return self.s
        
    def difference(self, set1:set(), set2:set()):
        for i in set1.s:
            if i not in set2.s:
                self.s.append(i)
        return self.s
    
    def display(self):
        return (self.s)

from ADT import set

e1 = set()
e2 = set()
e3 = set()
e4 = set()
e5 = set()

e1.create()
print("Set 1: ", e1.display())
e2.create()
print("Set 2: ", e2.display())
e1.remove()
print("Updated Set 1: ", e1.display())
e2.contain()

e3.union(e1, e2)
print("Union: ", e3.display())

e4.intersection(e1, e2)
print("Intersection: ", e4.display())

e5.difference(e1, e2)
print("Difference: ", e5.display())
