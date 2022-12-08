class Solution {
    List<Integer> myList=new ArrayList();
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        inorderStore(root1);
        for(int n:myList) System.out.print(n+" ");
        boolean res=inorderCheck(root2);
        boolean s=myList.isEmpty();
        return res && s;
    }
    void inorderStore(TreeNode root){
        if(root==null) return;
        if(root.left==null && root.right==null){
            myList.add(root.val);
            return;
        }

        inorderStore(root.left);
        inorderStore(root.right);
    }
    boolean inorderCheck(TreeNode root){
        if(root==null) return true;
        if(root.left==null && root.right==null){
            if(!myList.isEmpty() && myList.get(0)==root.val){
                myList.remove(0);
                return true;
            }
            else return false;
        }
        boolean st1=inorderCheck(root.left);
        boolean st2=inorderCheck(root.right);
        return st1 && st2;
    }
}