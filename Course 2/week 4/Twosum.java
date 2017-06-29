package coursera;

import java.io.*;
import java.util.*;

public class Twosum {
	
	public static void main(String[] args) throws FileNotFoundException{
		Scanner in = new Scanner(new File("C:/Users/hp/Desktop/prob-2sum.txt"));
		long[] numbers = new long[1000000];
		HashTable table = new HashTable(500000);
		for (int i = 0; i < 1000000; i++){
			long l = in.nextLong();
			numbers[i] = l;
			table.addLong(l);
		}
		int result = 0;
		HashSet<Integer> allSum = new HashSet<Integer>();
		for (long a : numbers){
			int i = (int) ((-a / table.RANGE) + 500000) / 2;
			for (int j = Math.max(0, i-1); j < 500000 && j <= i+1; j++){
				for (long b : table.table[j].list){
					long sum = (int) (a + b);
					if (sum < 10000 && sum > -10000){
						if (!allSum.contains((int) sum)){
							result++;
							allSum.add((int) sum);
						}
					}
				}
			}
		}
		System.out.println(result);
	}
}

class HashTable {
	public Contain[] table;
	public final int RANGE = 200000;
	
	public HashTable(int size){
		table = new Contain[size];
		for (int i = 0; i < size; i++){
			table[i] = new Contain();
		}
	}	
	public void addLong(long l){
		int index = (int) ((l / RANGE) + 500000) / 2;
		table[index].addLong(l);
	}
	public int bucketSize(int i){
		return table[i].size;
	}
}

class Contain{
	public ArrayList<Long> list;
	public int size = 0;
	
	public Contain(){
		list = new ArrayList<Long>();
	}
	public void addLong(long l){
		if (!list.contains(l)){
			list.add(l);
		}
		size++;
	}
}