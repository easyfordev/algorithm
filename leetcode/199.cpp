/*
LeetCode - 199. Binary Tree Right Side View

이건 테스트 못해보고 바로 제출해야겠다..

포인터 오랜만에 쓰니까 헷갈리네 ..ㅎㅎ 
값 참조 ->

C++에서 null은 없음. nullptr

아주 도움이 된 블로그
https://real-012.tistory.com/191
https://graffiti5.tistory.com/201
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        // 예외처리 : null 들어올 경우 그냥 바로 리턴
        if (root == nullptr) {
            return ans;
        }

        // 나머지 경우, BFS처럼 돌린다.
        queue<TreeNode*> q;

        // 시작점 초기화
        q.push(root);

        while(!q.empty()){
            // 이번 루프에서의 큐 크기 저장
            int size = q.size();

            // 다음 방문할 점 정하기
            for(int i=0;i<size;i++) {
                 // 큐에서 하나 꺼내기
                TreeNode* x = q.front();
                q.pop();

                // 정답(제일 오른쪽에 있는 노드인지) 체크
                if(i == size-1) { // 이번 레벨의 제일 마지막이면 정답에 넣는다.
                    ans.push_back(x->val);
                }

                // 다음 방문할 점 왼쪽 -> 오른쪽 순서대로 넣기
                if(x->left != nullptr) q.push(x->left);
                if(x->right != nullptr ) q.push(x->right);
            }
        }

        return ans;
    }
};

int main(){
}

