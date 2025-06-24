// 哈夫曼树的构建与先序遍历输出
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct HuffmanNode
{
    int weight;
    HuffmanNode *left, *right;
    HuffmanNode(int w) : weight(w), left(nullptr), right(nullptr) {}
};

struct cmp
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->weight > b->weight;
    }
};

// 先序遍历输出哈夫曼树
void preorder(HuffmanNode *root)
{
    if (!root)
        return;
    cout << root->weight << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    cout << "请输入权值个数: ";
    int n;
    cin >> n;
    vector<int> weights(n);
    cout << "请输入" << n << "个权值: ";
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, cmp> pq;
    for (int w : weights)
        pq.push(new HuffmanNode(w));
    while (pq.size() > 1)
    {
        HuffmanNode *l = pq.top();// 取出权值最小的节点
        pq.pop();
        HuffmanNode *r = pq.top();// 取出第二小的节点
        pq.pop();
        HuffmanNode *parent = new HuffmanNode(l->weight + r->weight);// 创建父节点,权值为左右子节点之和
        // 连接父节点和子节点，并将父节点放入优先队列
        parent->left = l;
        parent->right = r;
        pq.push(parent);
    }
    HuffmanNode *root = pq.top();
    cout << "哈夫曼树先序遍历: ";
    preorder(root);
    cout << endl;
    return 0;
}
