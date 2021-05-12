# 树

## 概念

### 树

树（Tree）是$n(n\geq0)$个结点的有限集。$n=0$时称为空树。

在任意一颗非空树中：

* 有且仅有一个根节点（Root）;
* 当$n>1$时，其余节点可分为$m(m>0)$个互不相交的有限集，其中每一个集合本身又是一颗树，称为根的子树（Subtree）。



> 树是用递归定义的！递归是树的特性之一！常用递归解决树的相关问题！

### 结点

树的结点包含了一个**数据元素**以及**若干指向其子树的分支**。

结点拥有的子树数称为结点的**度**。

度为0的结点称为**叶结点**（Leaf），度不为0的结点称为分支结点，除根节点外，分支结点也称为内部结点。树的度是树内各结点的度的最大值。

结点的子树称为结点的孩子，该节点称为孩子的双亲。

结点的层次中，根为第一层，根的孩子为第二层，依次递增。树中结点的最大层次称为树的深度(Depth)或者高度。



## 二叉树

**特点**

* 每个结点最多有两颗子树。
* 左子树和右子树是有顺序的，次序不能颠倒。
* 即使树中某结点只有一颗子树，也要区分是左子树还是右子树。



**五种基本形态**

1. 空二叉树
2. 只有一个根结点
3. 根结点只有左子树
4. 根结点只有右子树
5. 根结点有左右子树



**特殊二叉树**

* 斜树：结点个数与二叉树深度相同
  * 左斜树：所有结点只有左子树
  * 右斜树：所有结点只有右子树

* 满二叉树：所有分支结点都有左右子树，并且所有叶子都在同一层。

  **特点**

  * 叶子只能出现在最下一层
  * 非叶子结点的度数一定是2
  * 在同样深度的二叉树中，满二叉树的结点个数最多，叶子数最多。

* 完全二叉树：对一颗具有$n$个结点的二叉树按层序编号，如果编号为$i(1\leq{i}\leq{n})$的结点与同样深度的满二叉树中编号为$i$的结点在二叉树中的位置完全相同，则这棵二叉树称为完全二叉树。满二叉树一定是完全二叉树，但完全二叉树不一定是满二叉树。

  **特点**

  * 叶子结点只能出现在最下两层。
  * 最下层的叶子一定集中在左部连续位置。
  * 倒数第二层，若有叶子结点，一定都在右部连续位置。
  * 如果结点度为1，则该结点只有左孩子，即不存在只有右子树的情况。
  * 同样结点数的二叉树，完全二叉树的深度最小。



## 性质

* 性质一：在二叉树的第$i$层上至多有$2^{i-1}$个结点$(i\geq 1)$。
* 性质二：深度为$k$的二叉树至多有$2^k-1$个结点$(k\geq 1)$。
* 性质三：对任何一颗二叉树$T$，如果其叶子结点数为$n_0$，度为2的结点数为$n_2$，则$n_0 = n_2 + 1$。
* 性质四：具有$n$个结点的完全二叉树的深度为$\lfloor log_2^n \rfloor + 1$。
* 性质五：将含有$n$个结点的完全二叉树按层序编号，从左到右，对任一结点$(1\leq{i}\leq n)$，有：
  * 当$i = 1$，则结点$i$是二叉树的根，无双亲；如果$i>1$，则其双亲是结点$\lfloor i/2 \rfloor$。
  * 如果$2i>n$，则结点$i$无左孩子（结点$i$为叶子结点），否则其左孩子是结点$2i$。
  * 如果$2i + 1 > n$，则结点$i$无右孩子，否则其右孩子是结点$2i+1$。



## 存储结构

顺序存储结果一般只用于完全二叉树，其余二叉树可以考虑二叉链表存储。

```c++
class TreeNode{
    elemType data;     // 数据域
    TreeNode* left;    // 左孩子
    TreeNode* right;   // 右孩子
}
```



## 二叉树的遍历

二叉树的遍历：从根结点出发，按照某种次序依次访问二叉树中的所有结点，使得每个结点被访问一次且仅被访问一次。

二叉树的遍历方式有四种：==前序遍历==，==中序遍历==，==后序遍历==，==层序遍历==。

**前序遍历**：先访问树根，然后前序遍历左子树，再前序遍历右子树。

```c++
// 递归
void preOrder(TreeNode* root){
   if(root == nullptr) return;
   cout << root->val << endl;   // 结点数据
   preOrder(root->left);        // 前序遍历左子树
   preOrder(root->right);       // 前序遍历右子树
}

// 栈
vector<int> preOrder(TreeNode* root){
    vector<int> res;
    if(root == nullptr) return res;
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        TreeNode* p = stk.top();
        res.push_back(p->val);
        p.pop();
        if(p->right) stk.push(p->right);
        if(p->left) stk.push(p->left);
    }
    return res;    
}

```

**中序遍历**：中序遍历根结点的左子树，然后访问根结点，最后中序遍历根结点的右子树。

```c++
// 递归
void middOrder(TreeNode* root){
   if(root == nullptr) return;
   midOrder(root->left);
   cout << root->val << endl;
   midOrder(root->right);
}

// 栈
vector<int> midOrder(TreeNode* root){
    vector<int> res;
    if(root != nullptr){
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            if(!stk.empty()){
                root = stk.top();
                res.push_back(root->val);
                stk.pop();
                root = root->right;
            }
        }
    }
    return res;
}
```

**后序遍历**：从左到右先叶子后结点的方式遍历左右子树，最后访问根结点。

```c++
// 递归或栈实现
void postdOrder(TreeNode* root){
   if(root == nullptr) return;
   postOrder(root->left);
   postOrder(root->right);
   cout << root->val << endl;
}

// 栈 ,后序遍历可以看做前序遍历先右子树，最后结果再进行逆序
vector<int> postOrder(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> stk;
    stack<TreeNode*> stk2;
    if(root != nullptr){
      stk.push(root);
    }
    while(!stk.empty()){
        TreeNode* p = stk.top();
        stk.pop();
        stk2.push(p);
        if(p->left) stk.push(p->left); 
        if(p->right) stk.push(p->right);
        while(!stk2.empty()){
            res.push_back(stk2.top()->val);
            stk2.pop();
        }  
    }
    return res;
}
```

> 已知前中遍历，或者后中遍历可唯一确定一颗二叉树，但知前后遍历确不能确定一颗二叉树。

**层序遍历**：从树的第一层，也就是根结点开始访问，从上到下逐层访问，同一层从左到右对结点逐个访问。

```c++
// 层序遍历通常通过队列实现
void levelOrder(TreeNode* root){
   if(root == nullptr) return;
   queue<TreeNode*> que;
   que.push(root);
   while(!que.empty()){
       int cnt = que.size();
       for(int i = 0;i < size;i++){
          TreeNode* p = que.front();
          cout << p->val << endl;
          que.pop();
          if(root->left) que.push(root->left);
          if(root->right) que.push(root->right);
       }
   }
}
```

> 遍历的本质：将树中的结点变成某种意义上的线性序列。

> 不需要辅助栈的算法：Morris解法，即空间复杂度$O(1)$。



## 线索二叉树

背景：二叉链表空指针域太多，为了节约空间，提出线索二叉树。

指向前驱和后继的指针称为线索，加上线索的二叉链表称为线索链表，相应的二叉树称为线索二叉树。

线索二叉树将二叉树编程了一个双向链表，空左孩子指针域指向前驱结点，空右孩子指针域指向后继结点。

对二叉树以某种次序遍历使其变为线索二叉树的过程称做是线索化。线索化的实质就是将二叉链表中的空指针改为指向前驱或后继的线索。线索化的过程就是在遍历过程中修改空指针的过程。

```c++
typedef enum{link,Thead} PointerTag;  // 前驱/后继  左右孩子标志
class SearchTreeNode{
    elemType data;                 // 数据域
    SearchTreeNode* left ,right;   // 指针域
    PointerTag LTag,Rtag           // 标志位
}
```



## 哈夫曼树

哈夫曼树常用在数据压缩，编码，远距离通信领域。

哈夫曼树：带权路径长度WPL最小的二叉树。

规定哈夫曼树的左分支代表0，右分支代表1。从根结点到叶子结点所经过的路径分支组成的01序列便是该结点对应字符的哈夫曼编码。















