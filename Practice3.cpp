// *
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {


		vector<vector<int>>ans;
		if (!root)
			return ans;
		queue<TreeNode *>q;
		q.push(root);
		int p = 0;
		while (!q.empty())
		{
			int sz = q.size();
			vector<int>temp;
			while (sz--)
			{
				TreeNode *curr = q.front();
				q.pop();
				temp.push_back(curr->val);

				if (curr->left)
					q.push(curr->left);
				if (curr->right)
					q.push(curr->right);

			}
			if (p == 1)
				reverse(temp.begin(), temp.end());
			ans.push_back(temp);
			p ^= 1;
		}
		return ans;
	}
};