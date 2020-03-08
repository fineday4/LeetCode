#include <stdio.h>

#include <vector>
#include <queue>

struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};

class Solution {
public:
    bool canFinish(int numCourses,
		std::vector<std::pair<int, int> >& prerequisites) {
			std::vector<int> degree;
			std::vector<GraphNode*> graph;
			for(int i = 0; i < numCourses; ++i){
				degree.push_back(0);
				graph.push_back(new GraphNode(i));
			}
			for(int i = 0; i < prerequisites.size(); ++i){
				++degree[prerequisites[i].first];  //first <- second;
				graph[prerequisites[i].second]->neighbors.push_back(graph[prerequisites[i].first]);
			}
			std::queue<GraphNode*> Q;
			for(int i = 0; i < degree.size(); ++i){
				if(degree[i] == 0){
					Q.push(graph[i]);
				}
			}
			while(!Q.empty()){
				GraphNode* tmp = Q.front();
				Q.pop();
				for(int i = 0; i < tmp->neighbors.size(); ++i){
					if(--degree[tmp->neighbors[i]->label] == 0){
						Q.push(tmp->neighbors[i]);
					}
				}
			}
			for(auto i : degree){
				if(i)
					return false;
			}
			return true;
    }
};

int main(){	
	std::vector<std::pair<int, int> > prerequisites;
	prerequisites.push_back(std::make_pair(1, 0));
	prerequisites.push_back(std::make_pair(0, 2));
	prerequisites.push_back(std::make_pair(2, 3));
	prerequisites.push_back(std::make_pair(3, 1));
	Solution solve;
	printf("(should be 0): %d\n", solve.canFinish(4, prerequisites));	
	return 0;
}
