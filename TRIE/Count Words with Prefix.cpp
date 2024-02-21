int countWordsWithPrefix(string prefix) {
        Node* node = root;
        // Traverse to the node representing the prefix
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i]))
                return 0; // Prefix not found
            node = node->get(prefix[i]);
        }
        // Count all words under the node representing the prefix
        return countWords(node);
    }

    int countWords(Node* node) {
        int count = 0;
        if (node->isEnd())
            count++;
        // Recursively count words under each child node
        for (int i = 0; i < 26; i++) {
            if (node->links[i] != nullptr) {
                count += countWords(node->links[i]);
            }
        }
        return count;
    }