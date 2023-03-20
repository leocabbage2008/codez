package test;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class Main {
	public static ArrayList<ArrayList<String>> m(List<String> words) {
		ArrayList<ArrayList<String>> buckets = new ArrayList<ArrayList<String>>();
		for(int i = 0; i < 26; ++i) {
			buckets.add(new ArrayList<String>());
		}
		for(int i = 0; i < words.size(); ++i) {
			buckets.get(words.get(i).charAt(0)-97).add(words.get(i));
		}
		return buckets;
	}

	public static void main(String[] args) {
		ArrayList<String> words = new ArrayList<String>();
		words.add("ant");
		words.add("act");
		words.add("art");
		words.add("bad");
		words.add("bed");
		words.add("bad");
		words.add("cat");
		words.add("can");
		words.add("cot");
		words.add("dog");
		words.add("dig");
		System.out.println(m(words));
	}
}