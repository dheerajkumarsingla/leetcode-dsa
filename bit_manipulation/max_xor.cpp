// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
class Solution {
public:
    struct TrieNode {
        TrieNode* children[2];
    };
    TrieNode* newNode() {
        TrieNode *node = new TrieNode();
        node->children[0] = NULL;
        node->children[1] = NULL;
        return node;
    };
    void insert(int num, TrieNode* root) {
        TrieNode *node = root;
        for(int i=31;i>=0;i--) {
            int currentBitValue = (num>>i & 1);
            if(!node->children[currentBitValue]) {
                node->children[currentBitValue] = newNode();
            }
            node = node->children[currentBitValue];
        }
    }

    int findXor(int num, TrieNode* root) {
        TrieNode *node = root;
        int xorValue = 0;
        for(int i=31;i>=0;i--) {
            int currentBitValue = (num>>i & 1);
            if(node->children[currentBitValue^1]) {
                xorValue += pow(2,i);
                node = node->children[currentBitValue^1];
            }
            else {
                node = node->children[currentBitValue];
            }
        }
        return xorValue;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        TrieNode *rootNode = newNode();

        for(int i=0;i<n;i++) {
            insert(nums[i], rootNode);
        }

        int maxXorValue = 0;
        for(int i=0;i<n;i++) {
            maxXorValue = max(maxXorValue, findXor(nums[i], rootNode));
        }

        return maxXorValue;
    }
};