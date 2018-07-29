class Solution {
 public:
  class Node {
   public:
    Node() : index_(0) {}
    Node(int index) : index_(index) {}
    int GetIndex() { return index_; }
    void browse() {
      char layout = arrows_.empty() ? '\n' : '\t';
      for (auto it : arrows_) {
        cout << index_ << layout;
        cout << it.first << "\t" << it.second->GetIndex() << endl;
      }
    }
    unordered_map<char, Node *> &GetEdge() { return arrows_; };
    void AddArrow(char ch, Node *dst) { arrows_.insert(make_pair(ch, dst)); }
    int index_;
    unordered_map<char, Node *> arrows_;
  };

  const char empty = 0;
  const char star = '*';
  const char questionMark = '?';

  Node *startNode;
  Node *endNode;

  set<Node *> curNodes;

  void browseNFA(Node *node) {
    deque<Node *> nodes;
    nodes.push_back(node);
    while (nodes.empty() == false) {
      Node *n = nodes.front();
      nodes.pop_front();
      n->browse();
      for (auto it : n->GetEdge()) {
        if (it.second == n) {
          continue;
        }
        nodes.push_back(it.second);
      }
    }
  }
  void ConstructNFA(const string &pattern) {
    startNode = new Node();
    endNode = startNode;
    int index = 0;
    char ch = 0;
    for (std::size_t i = 0; i < pattern.size(); ++i) {
      ch = pattern[i];
      if (ch == star) {
        if (i + 1 <= (pattern.size() - 1) && pattern[i + 1] == star) continue;
        Node *node = new Node(endNode->index_);
        Node *tail = new Node(endNode->index_);
        node->AddArrow(questionMark, node);
        node->AddArrow(empty, tail);

        endNode->AddArrow(questionMark, node);
        endNode->AddArrow(empty, tail);

        endNode = tail;
      } else {
        Node *node = new Node(endNode->index_ + 1);
        endNode->AddArrow(ch, node);
        endNode = node;
      }
    }
  }
  void AddClosure(const int remainStep, Node *node) {
    auto empty = node->arrows_.find(0);
    if (endNode->index_ - node->index_ <= remainStep) {
      curNodes.insert(node);
      if (empty != node->arrows_.end()) {
        curNodes.insert(empty->second);
      }
    }
  }

  bool isMatch(string s, string p) {
    int slen = s.length();
    ConstructNFA(p);
    // browseNFA(startNode);
    int remainstep = endNode->index_;
    AddClosure(remainstep, startNode);
    for (int i = 0; i < slen; ++i) {
      char ch = s[i];
      remainstep = slen - i - 1;
      auto curNodesCopy = curNodes;
      curNodes.clear();
      for (auto it : curNodesCopy) {
        auto i1 = it->arrows_.find(ch);
        auto i2 = it->arrows_.find('?');

        if (i1 != it->arrows_.end()) {
          AddClosure(remainstep, i1->second);
        }
        if (i2 != it->arrows_.end()) AddClosure(remainstep, i2->second);
      }
    }
    for (auto it : curNodes) {
      if (it == endNode) return true;
    }
    return false;
  }
};
