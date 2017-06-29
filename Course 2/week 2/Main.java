package min;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {

	public static void main(String[] args) throws IOException {
		// Construct the graph from the data file
		String filePath = "C:/Users/hp/Desktop/dijsktra.txt";
		Graph g = new Graph(filePath);
		
		// Calculate the shortest paths to all nodes from node 1
		double initial = System.nanoTime();
		int[] shortestPaths = g.shortestPaths(g.getVertices().get(1));
		double end = System.nanoTime();
		System.out.println(end - initial);
		int outputs[] = {7,37,59,82,99,115,133,165,188,197}; // nodes for which shortest path answers are needed
		List<Integer> outputList = new ArrayList<Integer>();
		for(int i : outputs) {
			outputList.add(i);
		}
		
		// Print out shortest to all nodes specified in the assignment
		for(int i = 1; i < shortestPaths.length; i++) {
			if(outputList.contains(i))
				System.out.print(shortestPaths[i] + ",");
		}
		
	}
}