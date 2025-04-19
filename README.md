# Leetcode-106.-Construct-Binary-Tree-from-Inorder-and-Postorder-Traversal
Construct Binary Tree from Inorder and Postorder Traversal
This repository contains a C++ implementation to construct a binary tree given its inorder and postorder traversal sequences. It applies recursive tree construction and handles node placement based on traversal logic.

🧠 Problem Statement
Given two integer arrays inorder and postorder, where:

inorder represents the inorder traversal (Left ➝ Root ➝ Right),

postorder represents the postorder traversal (Left ➝ Right ➝ Root),

Reconstruct and return the binary tree.

🧩 Key Concepts
Inorder Traversal: Left ➝ Root ➝ Right

Postorder Traversal: Left ➝ Right ➝ Root (but reversed in implementation for simplification)

Tree Reconstruction: Identify the root, split traversals, and recursively build left and right subtrees.

🚀 Approach
Reverse Postorder: Since postorder ends with the root, reversing the array helps treat it like preorder (Root ➝ Right ➝ Left) for simplified construction.

Find Root in Inorder: Use findindex() to locate root in inorder to determine left and right subtree bounds.

Recursion: Recursively build the right and left subtrees in this order.

Combine Subtrees: Attach left and right recursively to their parent node.

📂 Code Structure
buildTree(): Main driver function to initiate construction.

maketree(): Recursive function to divide traversals and build the tree.

findindex(): Utility to locate element index in inorder array.

⏱️ Time and Space Complexity
Time Complexity: O(N²) in the worst case due to repeated scanning in findindex().

Space Complexity: O(N) for recursive stack and the constructed tree.

✅ Optimization Tip: Use a hash map for inorder indexing to bring time complexity to O(N).

🧪 Example
cpp
Input:
inorder =   [9,3,15,20,7]
postorder = [9,15,7,20,3]

Output Tree:
      3
     / \
    9   20
       /  \
      15   7
📦 Applications
Building trees in compilers, interpreters, and expression parsers.

Restoring tree structures from saved data (e.g., deserialization).

Advanced tree-based question practice for interviews.
