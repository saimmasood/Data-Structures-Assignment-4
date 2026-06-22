# Data-Structures-Assignment-4
Data Structures assignment 4 by sir Salman Muneer



Question 1: Binary Search Tree Insertion and Traversal (5 Marks)
Write a C++ program to create a Binary Search Tree (BST) and insert the following values:
50, 30, 70, 20, 40, 60, 80
Your program must perform the following tasks:
Create a Node structure or class containing data, left pointer, and right pointer.
Implement an insert() function to add values according to the BST rule.
Implement inorder traversal to display the BST values in sorted order.
Display the final output after all insertions.
Expected Output: 20 30 40 50 60 70 80


Question 2: AVL Tree Insertion with Rotation Analysis (5 Marks)
Write a C++ program to insert the following values into an AVL Tree:
10, 20, 30, 40, 50, 25
Your program must perform the following tasks:
Create an AVL node containing data, left pointer, right pointer, and height.
Implement functions to calculate height and balance factor.
Implement left rotation and right rotation functions.
Handle LL, RR, LR, and RL imbalance cases during insertion.
Display the final AVL Tree using inorder traversal.
Write a short explanation of which rotations are applied and why.
Note: The AVL Tree must remain balanced after each insertion.


Question 3: Student Record Management System using std::unordered_map (5 Marks)
Develop a menu-driven C++ program using std::unordered_map to manage student records efficiently.
Problem Requirements:
Use Student ID as the key.
Store Student Name, Semester, and CGPA as values.
Add a new student record.
Search a student record by Student ID using find().
Update the CGPA of an existing student.
Delete a student record using erase().
Display all student records using a loop over the unordered_map.
Display the current size and load factor of the unordered_map.
Sample Menu:
1. Add Student
2. Search Student
3. Update CGPA
4. Delete Student
5. Display All Records
6. Display Size and Load Factor
7. Exit
Expected Concepts to Use:
std::unordered_map
insert or [] operator
find()
erase()
range-based for loop
load_factor()
