
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    string text;
    cout << "Enter your string: ";
    getline(cin, text);

    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCodes[ch];
    }

    int originalLength = text.length() * 8;
    int compressedLength = encoded.length();
    int tableLength = 0;
    for (auto& pair : huffmanCodes) {
        tableLength += 8 + pair.second.length();
    }
    int newLength = compressedLength + tableLength;

    cout << "\nFrequencies :\n";
    for (auto& pair : freq) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    cout << "\nHuffman Codes :\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << "\n";
    }

    cout << "\nOriginal Length : " << originalLength << "\n";
    cout << "Compressed message length : " << compressedLength << "\n";
    cout << "Table : " << tableLength << "\n";
    cout << "New length : " << newLength << "\n";

    return 0;
}
