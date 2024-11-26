typedef struct TreeNode Tree;

Tree * constructMaximumBinaryTree(const int * const nums, const int numsLen){
	if (0 == numsLen){
		return NULL;
	}

	int maxIdx = 0;
	for (int i = 1; i < numsLen; i += 1){
		if (nums[i] > nums[maxIdx]){
			maxIdx = i;
		}
	}

	Tree * const pTree = (Tree *)malloc( sizeof (Tree) );

	pTree->val = nums[maxIdx];
	pTree->left = constructMaximumBinaryTree(nums, maxIdx);
	pTree->right = constructMaximumBinaryTree( nums + (maxIdx + 1), numsLen - (maxIdx + 1) );

	return pTree;
}
