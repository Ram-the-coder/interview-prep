/*
	Given an undirected graph and a number m, 
	determine if the graph can be coloured with at most m colours 
	such that no two adjacent vertices of the graph are colored with the same color. 

	Here coloring of a graph means the assignment of colors to all vertices.
*/


/*
	Solution
	Time Complexity: O(m^v) -> However the average time complexity is less
	Space Complexity: O(v^2) -> To store adjacency matrix
*/
class Graph {
public:
	int num_vertices, num_colors;
	vector<vector<int>> adjacency;
	vector<int> colors_available;
	vector<int> vertex_color;

	Graph(int v, int m) {
		num_vertices = v;
		num_colors = m;
		colors_available.resize(v, (1 << v) - 1);
		adjacency.resize(v, vector<int>(v, 0));
		vertex_color.resize(v, -1);
	}

	void get_edges(int e) {
		int from, to;
		for(int i=0; i<e; ++i) {
			cin >> from >> to;
			adjacency[from-1][to-1] = adjacency[to-1][from-1] = 1;
		}
	}
	

	int is_possible_to_color(int start_vertex) {

		if(start_vertex == num_vertices) return 1;

		for(int color=0, mask=1; color < num_colors; ++color, mask <<= 1) {
			// If color not available, go to next color
			if((colors_available[start_vertex] | mask) != colors_available[start_vertex]) continue;

			// Assign the color to this vertex and remove it from the available colors in the current and adjancent vertices
			// Also before removing this color from the adjacent vertices, save their colors_available.
			vertex_color[start_vertex] = color;
			colors_available[start_vertex] &= ~mask;
			vector<int> adjacent_masks(num_vertices, 1);
			for(int i=0; i<num_vertices; ++i) {
				if(adjacency[start_vertex][i]) {
					adjacent_masks[i] = colors_available[i];
					colors_available[i] &= ~mask;
				}
			}

			if(is_possible_to_color(start_vertex + 1)) return 1;

			// Unassign the color to this vertex
			// And restore the colors available in the adjacent vertices and also the current vertex
			vertex_color[start_vertex] = -1;
			colors_available[start_vertex] |= mask;
			for(int i=0; i<num_vertices; ++i) {
				if(adjacency[start_vertex][i]) {
					colors_available[i] = adjacent_masks[i];
				}
			}
		}

		return 0;
	}
};