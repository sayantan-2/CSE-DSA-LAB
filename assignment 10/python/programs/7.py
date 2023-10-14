class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.lthread = True
        self.rthread = True


def insert(root, ikey):
    ptr = root
    par = None  # Parent of key to be inserted
    while ptr is not None:
        if ikey == (ptr.key):  # Duplicate key
            print("Duplicate Key! Not Allowed!")
            return root
        par = ptr  # Update parent pointer
        # Moving on left subtree.
        if ikey < ptr.key:
            if ptr.lthread == False:
                ptr = ptr.left
            else:
                break
        # Moving on right subtree.
        else:
            if ptr.rthread == False:
                ptr = ptr.right
            else:
                break

    # Create a new node
    tmp = Node(ikey)

    if par == None:
        root = tmp
        tmp.left = None
        tmp.right = None
    elif ikey < (par.key):
        tmp.left = par.left
        tmp.right = par
        par.lthread = False
        par.left = tmp
    else:
        tmp.right = par.right
        tmp.left = par
        par.rthread = False
        par.right = tmp

    return root


def inorder(root):
    if root is None:
        print("Tree is empty")
        return

    # Reach leftmost node of binary tree or subtree rooted with p.
    p = root
    while p.lthread == False:
        p = p.left

    # One by one print successors.
    while p is not None:
        print(p.key, end=" ")
        if p.rthread == False:
            p = p.right
        else:
            p = p.right


root = Node(6)
root = insert(root, 3)
root = insert(root, 1)
root = insert(root, 5)
root = insert(root, 9)
root = insert(root, 7)
root = insert(root, 11)
root = insert(root, 4)
root = insert(root, 8)
print("Inorder traversal of created threaded binary tree is:")
inorder(root)
