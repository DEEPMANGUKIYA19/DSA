 class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    vector<Node> seg;

    Node merge(Node a, Node b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

         
        for (int i = 0; i < k; i++) {
            res.cnt[i] += a.cnt[i];
        }

       
        for (int i = 0; i < k; i++) {
            int rem = (a.prod * i) % k;
            res.cnt[rem] += b.cnt[i];
        }

        return res;
    }

    void build(int id, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            seg[id].prod = rem;
            seg[id].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(id * 2, l, mid, nums);
        build(id * 2 + 1, mid + 1, r, nums);

        seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
    }

    void update(int id, int l, int r, int pos, int value) {
        if (l == r) {
            int rem = value % k;

            seg[id] = Node();
            seg[id].prod = rem;
            seg[id].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(id * 2, l, mid, pos, value);
        else
            update(id * 2 + 1, mid + 1, r, pos, value);

        seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
    }

    Node query(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[id];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(id * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(id * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(id * 2, l, mid, ql, qr);
        Node right = query(id * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();
        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

             
            update(1, 0, n - 1, index, value);

             
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};
