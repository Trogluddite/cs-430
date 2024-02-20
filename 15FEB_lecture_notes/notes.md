# Red Black trees
* what is
* kernel implementation thereof
## about
* visual example: https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
* Goal: quick retreival 
* maintains balance 
* Compared to a BST:
  * we _hope_ that a BST remains balanced, but insertion is a problem
  * BST's tend to become pretty similar to a linked list (consider alphabet -- each insertion is later than the last ... so you get a list)
* Rule is pretty straightforward: 
 * not more than one red node in a row
 * rebalance when the red node rule is broken
 * look into repaint vs. rebalance
 * (fill this in from wikipedia)
* repainting can have consequences
  * we may need to recursively re-balance up to the root
## AVL tree
* alternative balanced tree
* every node has an imbalance associated with it
* all nodes must fit AVL balance condition
* kernel provides red/black so we focus on that more

## where is RB tree in kernel?
* 

## reference double pointer syntax 
`struct rb_node **new = &(root.rb_node), *parent= NULL;`
why ** from & ? pointer to pointer? 
 - make sure we aren't getting a _copy_ of the root node; we want to follow the pointer to `root.rb_node`, thus `**new`

## macro: remember, pass by name (not reference)
