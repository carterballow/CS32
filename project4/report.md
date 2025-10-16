Project 4 Report - carter ballow 806389359
Big-O Analysis Summary
Thiss table is for the time complexity for all of my structures and algorithms that are used in the project

Structure/Algorithm

Best Case

Average Case

Worst Case

Stable?

Hash Table (Insert/Find/Erase)

O(1)

O(1)

O(n)

N/A

BST (Insert/Find/Erase)

O(log n)

O(log n)

O(n)

N/A

Insertion Sort

O(n)

O(n²)

O(n²)

Yes

Merge Sort

O(n log n)

O(n log n)

O(n log n)

Yes

Notes: The worst case O(n) for the Hash Table occurs when all keys hash to the same bucket, which basically makes it a singly linked listt The worst case O(n) for the BST occurs when the tree becomes unbalanced and one fo them goes too far

BST Two-Child Deletion Strategy
To handle the deletion of a node with two children, this implementation uses the inorder successor method. This approach ensures that the Binary Search Tree properties are maintained after the node is removed.

The process goes like this:

When the node to be deleted is found and confirmed to have two children, we do not remove it directly. Instead, we locate its inorder successor.

The inorder successor is defined as the smallest which is the left most node in the right subtree of the node being deleted.

The value of the successor node is copied over the value of the original node we intended to delete.

Finally, the successor node which is become a duplicate is deleted from the right subtree. This final deletion is simpler because the successor, by definition, has at most one child (a right child).

This method preserves the BST structure efficiently by replacing the deleted node with the next highest value in the tree.

Design Choice: Hash Table Sizing Guardrail
A key design choice was implemented in the HashTable constructor to act as a guardrail against invalid input. The constructor prevents the creation of a hash table with zero buckets, which would lead to a divide-by-zero error during hash index calculation with thekey % buckets_.size()).

The implementation uses a ternary operator to enforce a minimum size:
buckets_(bucketCount ? bucketCount : 1)

This line checks if bucketCount is nonzero. If it is the table is created with the requested number of buckets. If bucketCount is zero, it safely defaults to creating one bucket. This small check ensures program abilittey without relying on the user to provide valid input.
