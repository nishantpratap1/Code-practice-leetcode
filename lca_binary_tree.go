package main

import (
	"fmt"
)

type TreeNode struct {
	data  int
	Left  *TreeNode
	Right *TreeNode
}

//

func LowestCommonAncestor(root *TreeNode, p *TreeNode, q *TreeNode) *TreeNode {

	if root == nil {
		return nil
	}

	if root.data == p.data || root.data == q.data {
		return root
	}
	lca1 := LowestCommonAncestor(root.Left, p, q)
	lca2 := LowestCommonAncestor(root.Right, p, q)
	if lca1 != nil && lca2 != nil {
		return root
	}
	if lca1 != nil {
		return lca1
	}
	return lca2
}

func main() {
	fmt.Println("lowest common ancestor of a tree")
	root := &TreeNode{data: 6}
	root.Left = &TreeNode{data: 2}
	root.Right = &TreeNode{data: 8}
	root.Left.Left = &TreeNode{data: 0}
	root.Left.Right = &TreeNode{data: 4}
	root.Right.Left = &TreeNode{data: 7}
	root.Right.Right = &TreeNode{data: 9}
	root.Left.Right.Left = &TreeNode{data: 3}
	root.Left.Right.Right = &TreeNode{data: 5}
	/*
	     	6
	      /   \
	     2     8
	    / \   / \
	   0   4 7   9
	      / \
	     3   5

	*/

	p := root.Left       // Node 2
	q := root.Left.Right // Node 4
	lca := LowestCommonAncestor(root, p, q)
	fmt.Println(lca.data) // Output: 2
}
