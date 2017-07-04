/*
 author: Pooja Srivastava
 */

package coursera;

import java.io.File;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class FloydWarshall_APSP {
		private Set<Edge> graph = new HashSet<>();
	
	private int numNodes;
	
	public void readFile(String path) throws Exception{
		Scanner sc = new Scanner(new File(path));
		String regex = "\\s";
		String line = sc.nextLine();
		numNodes = Integer.parseInt(line.split(regex)[0]);
		int left, right;
		double cost;
		String[] strs;
		while(sc.hasNext()) {
			line = sc.nextLine();
			strs = line.split(regex);
			left = Integer.parseInt(strs[1]);
			right = Integer.parseInt(strs[0]);
			cost = Integer.parseInt(strs[2]);
			graph.add(new Edge(cost, left, right));
		}
		sc.close();
	}
	
	public void APSP() {
	
		double[][][] table = new double[numNodes+1][numNodes+1][2];
	
		for(int i = 0; i < numNodes+1; i++)
			for(int j = 0; j < numNodes+1; j++) {
				if(i == j)
					table[i][j][0] = 0;
				else
					table[i][j][0] = Double.MAX_VALUE;
			}
		int left, right;
		//shortest shortest path
		double ssp = Double.MAX_VALUE;
		for(Edge edge : graph) {
			left = edge.getLeft();
			right = edge.getRight();
			table[left][right][0] = edge.getCost();
		}
		for(int k = 1; k <= numNodes; k++) {
			for(int i = 1; i < numNodes+1; i++) {
				for(int j = 1; j < numNodes+1; j++) {
					table[i][j][k%2] = Math.min(table[i][j][(k-1)%2], 
							table[i][k][(k-1)%2] + table[k][j][(k-1)%2]);
					if(k == numNodes) {
						if(table[i][j][numNodes%2] < ssp)
							ssp = table[i][j][numNodes%2];
					}
				}
			}
		}
		//check for a negative cycle in the graph
		for(int i = 1; i < numNodes+1; i++) {
			if(table[i][i][numNodes%2] < 0) {
				System.out.println("there is a negative cycle in this graph");
				return;
			}
		}
		System.out.println("The shortest shortest path  is: " + ssp);
	}
	
	//main
	public static void main(String[] args) throws Exception{
		String path = "C://Users//hp//Desktop//g3.txt";
		FloydWarshall_APSP fw = new FloydWarshall_APSP();
		fw.readFile(path);
		fw.APSP();
	}
}