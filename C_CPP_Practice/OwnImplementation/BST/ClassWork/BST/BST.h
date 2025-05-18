class BST{

    private:
        struct node{
            int data;
            node* left;
            node* right;
        };
        node* root;
        void AddNodePrivate(int key, node* ptr);
        void PrintInorderPrivate(node* ptr);
        node* ReturnNodePrivate(int key, node* ptr);
        int FindSmallestItemPrivate(node* ptr);
        node* DeleteNodePrivate(int key, node* ptr);
        void inverseTreePrivate(node* ptr);

    public:
        BST();
        node* CreateLeaf(int key);
        void AddNode(int key);
        void PrintInorder();
        node* ReturnNode(int key);
        int ReturnValRoot();
        void PrintChildrens(int key);
        int FindSmallestItem();
        void DeleteNode(int key);
        
        // à implementer 
        void InverseTree();

};