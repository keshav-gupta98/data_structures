// Copy elements of tree in an array in inorder.Then perform PostOrder Traversal of tree and copy values from array to the nodes.

import java.util.*;  
class Node 
{ 
    int data; 
    Node left, right;
    Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    } 
};  
public class BinaryTreeToMaxHeap {
    static int i;
    public static void main(String[] args) {
        Node root = new Node(4);
        root = insert(root,2);
        root = insert(root,6);
        root = insert(root,1);
        root = insert(root,3);
        root = insert(root,5);
        root = insert(root,7);
        ArrayList<Integer> al = new ArrayList<Integer>(); 
        inorder(al,root);
        convertBinaryTreeToMaxHeap(al,root);
        PostOrder(root);
    }
    public static Node insert(Node root, int key)
    {
        if(root == null)
        {
            Node n = new Node(key);
            return n;
        }
        if(root.data>key)
        {
            root.left = insert(root.left,key);
        }
        if(root.data<key)
        {
            root.right = insert(root.right,key);
        }
        return root;
    }
    public static void inorder(ArrayList<Integer> al, Node root)
    {
        i = 0;
        if(root == null)
        return;
        inorder(al,root.left);
        al.add(root.data);
        inorder(al, root.right);
    }
    public static void convertBinaryTreeToMaxHeap(ArrayList<Integer> al , Node root)
    {
        if(root==null)
        return;
        convertBinaryTreeToMaxHeap(al, root.left);
        convertBinaryTreeToMaxHeap(al, root.right);
        root.data = al.get(i++);
    }
    public static void PostOrder(Node root)
    {
        if(root == null)
        return;
        PostOrder(root.left);
        PostOrder(root.right);
        System.out.print(root.data + " ");
    }   
}