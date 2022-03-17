'''
    Problem Link https://www.hackerrank.com/challenges/contacts/
'''
class Node(object):
    def __init__(self, data, occurance=1):
        self.data = data
        self.occurance = occurance 
        self.children = []

    def add_child(self, obj):
        self.children.append(obj)
        return self.children[-1]

    def find_child_index(self, char):
        for i in range(len(self.children)):
            if (self.children[i].data == char):
                return i
        return -1


def count_childs(obj):
    count = 0
    for i in obj.children:
        count += i.occurance
    return count
    '''
    count = 0
    if (len(obj.children)==0):
        count = 1
    for child in obj.children:
        count += count_childs(child)
    return count
    '''

def add_to_tree(head, name):
    print("add_to_tree called with", name)
    for char in name:
        index = head.find_child_index(char)
        if (index == -1):
            new_node = Node(char)
            new_head = head.add_child(new_node)
            head = new_head
        else:
            head = head.children[index]
            head.occurance += 1

def treverse_tree(head, name):
    if (len(name) == 0):
        return -1
    for char_index in range(len(name)-1, -1, -1):
        child_index = head.find_child_index(name[char_index])
        if (child_index == -1):
            return -1
        if (len(name) == 1):
            return head.children[child_index];
        name.pop()
        return treverse_tree(head.children[child_index], name)


def print_tree(head, level=0):
    print(level*" ", head.data, head.occurance)
    level+=1
    for i in head.children:
        print_tree(i, level)

def contacts(queries):
    head = Node(0, 0);
    for query in queries:
        print("query", query)
        if (query[0] == "add"):
            add_to_tree(head, query[1])
        else:
            node = treverse_tree(head, list(reversed(query[1])) )
            if (node != -1):
                print(node.occurance)
            else:
                print(0)

    print_tree(head)

n = int(input())
queries = []
for _ in range(n):
    queries.append(input().split())

print(queries)

contacts(queries)
