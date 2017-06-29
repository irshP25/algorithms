package coursera;

import java.io.*;

public class MedianMaintenance {
	
	public static void main(String[] args){
		int median = 0; // median for each streaming input
		int sumMedian = 0; // sum of the median
		try{
			BufferedReader rd = new BufferedReader(new FileReader(FILENAME));
			while(true){
				String line = rd.readLine();
				if(line == null) break;
				median = findMedian(Integer.parseInt(line));
				sumMedian += median;
			}	
		}
		catch(IOException ex){
			System.out.println("not find the file \"" + FILENAME + "\"");
			System.exit(0);
		}
		System.out.println(" sum : " + sumMedian);
	}
	
	/* maintain 2 heaps of similar length (difference <= 1): 
	 * left side: max heap -- for smaller numbers; right side: min heap -- for larger numbers; 
	 * thus median = maxHeap's max.
	 */
	private static int findMedian(int input){
		if(input < minHeap.getMin()) {
			maxHeap.insert(input);
		} else{
			minHeap.insert(input);
		}
		if(maxHeap.getSize() - minHeap.getSize() > 1){
			minHeap.insert(maxHeap.extractMax());
		}
		if(minHeap.getSize() > maxHeap.getSize()){
			maxHeap.insert(minHeap.extractMin());
		}
		return maxHeap.getMax();
	}

	private static final String FILENAME = "C:/Users/hp/Desktop/Median.txt";
	
	private static MaxHeap maxHeap = new MaxHeap(); 
	private static MinHeap minHeap = new MinHeap();
	
}