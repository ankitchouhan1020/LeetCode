class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        if node in self.dict:
            return self.dict[node]

        self.dict[node] = Node(node.val, [])
        for neighbor in node.neighbors:
            self.dict[node].neighbors.append(self.cloneGraph(neighbor))

        return self.dict[node]

    dict = {}
