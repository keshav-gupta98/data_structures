
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;
class Node
{
    int val;
    Node left;
    Node right;
    Node()
    {
        
    }
    Node(int a)
    {
        val = a;
        left = null;
        right = null;
    }
    
}
public class Main
{
    public static Node insert(Node root, int key)
    {
        if(root == null)
        {
            Node temp = new Node(key);
            return temp;
        }
        if(root.val == key){};
        if(root.val < key)
        {
            root.right = insert(root.right,key);
        }
        else
        {
            root.left = insert(root.left,key);
        }
        return root;
    }
    public static ArrayList<Integer> print(Node root)
    {
        Stack<Node> s = new Stack<Node>();
        Node curr = new Node();
        curr = root;
        //System.out.print(curr.val);
        ArrayList<Integer> al = new ArrayList<Integer>();
        while(curr != null || !s.isEmpty())
        {
            while(curr!= null)
            {
                s.push(curr);
                curr = curr.left;
            }
            Node temp = new Node();
            temp = s.peek();
            if(temp.right == null)
            {
                al.add(temp.val);
                s.pop();
                while(!s.isEmpty() && s.peek().right == temp)
                {
                    temp = s.peek();
                    s.pop();
                    al.add(temp.val);
                }
                if(!s.isEmpty())
                {
                    curr = s.peek().right;
                }
            }
            else
            {
                curr = temp.right;
            }
        }
        return al;
    }
    public static Node find(Node root , int key)
    {
        if(root.left == null && root.right == null)
        return null;
        if(root.left != null && root.left.val == key)
        return root;
        if(root.right != null && root.right.val == key)
        return root;
        if(root.val < key)
        return find(root.right,key);
        else
        return find(root.left,key);
    }
    public static void deleteNode(Node root, int key)
    {
        Node temp = new Node();
        if(root.right.val == key)
        {
            temp = root.right;
            if(temp.left== null && temp.right == null)
            {
                root.right = null;
            }
            else if(temp.right == null)
            {
                root.right = temp.left;
            }
            else if(temp.left == null)
            {
                root.right = temp.right;
            }
            else
            {
                Node temp1 = new Node();
                temp1 = temp.right;
                root.left = temp.left;
                temp = temp.left;
                while(temp.right!=null)
                {
                    temp = temp.right;
                }
                temp.right = temp1;
            }
        }
        else
        {
            temp = root.left;
            if(temp.left == null && temp.right == null)
            {
                root.left = null;
            }
            else if(temp.left == null)
            {
                root.left = temp.right;
            }
            else if(temp.right == null)
            {
                root.right = temp.left;
            }
            else
            {
                Node temp1 = new Node();
                temp1 = temp.right;
                root.left = temp.left;
                temp = temp.left;
                while(temp.right!=null)
                {
                    temp = temp.right;
                }
                temp.right = temp1;
            }
        }
    }
    public static void printin(Node root)
    {
        if(root == null)
        return;
        printin(root.left);
        System.out.print(root.val+" ");
        printin(root.right);
    }
	public static void main(String[] args) {
		System.out.println("Hello World");
		Node root = new Node();
		root= null;
		root = insert(root,15);
		root = insert(root,10);
		root = insert(root,20);
		root = insert(root,8);
		root = insert(root,12);
		root = insert(root,7);
		root = insert(root,9);
		ArrayList<Integer> al = new ArrayList<Integer>(print(root));
		System.out.println(al);
		Node r = find(root,10);
		deleteNode(r,10);
		ArrayList<Integer> dl = new ArrayList<Integer>(print(root));
		System.out.printin(dl);
	}
}
