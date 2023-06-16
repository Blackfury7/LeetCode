class Solution {
public:
    #define ll long long
    ll mod = 1e9+7;
    struct Node{
        int value;
        Node* left;
        Node* right;
        Node(int val){
            value = val;
            left = NULL;
            right = NULL;
        }
    };

    ll fact[1001];
    void precalc() {
        fact[0] = 1;
        for(ll i = 1; i < 1001; i++)
            fact[i] =(fact[i - 1]*i)%mod;
            // fact[i]=fact[i-1]*i;
    }

    ll inv(ll x) {
        return x <= 1 ? x : mod - (long long)(mod/x) * inv(mod % x) % mod;
    }
    
    ll mul(ll x, ll y) {
        return ((x%mod) * 1ll * (y%mod)) % mod;
    }

    ll divide(ll x, ll y) {
        return mul(x, inv(y));
    }

    void insertBST(Node* root,int val){
        if(root->value>val){
            if(root->left==NULL){
                root->left = new Node(val);
            }
            else{
                insertBST(root->left,val);
            }
        }
        else if(root->value<val){
            if(root->right==NULL){
                root->right = new Node(val);
            }
            else{
                insertBST(root->right,val);
            }
        }
    }
    
    void printBST(Node* root){
        if(root==NULL) return;
        printBST(root->left);
        cout<<root->value<<" ";
        printBST(root->right);
    }

    
    ll compute(ll left,ll right){
        if(left==0 or right == 0) return 1LL;
        return divide(fact[left+right],mul(fact[left],fact[right]));
    }

    ll ans = 1;
    ll calculatePermutations(Node* root){
        if(root==NULL){
            return 0;
        }

        ll left = calculatePermutations(root->left);
        ll right = calculatePermutations(root->right);
        ll pnc = compute(left,right)%mod;
        ans = mul(ans,pnc);
        return 1+left+right;
    }
    int numOfWays(vector<int>& nums) {
        Node* root = new Node(nums[0]);
        //create BST
        for(int i = 0;i<nums.size();i++){
            insertBST(root,nums[i]);
        }

        precalc(); //precalculating the factorial till 1000
        calculatePermutations(root);
        return ans - 1;
    }
    
};