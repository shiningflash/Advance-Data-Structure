using System;
using System.Collections.Generic;

public class Program {
    public static void Main(string[] args) {
        string[] lines = System.IO.File.ReadAllLines("in.txt");

        // MapExercise me = new MapExercise();
        // me.run(lines);

        PriorityQueue<int> pq = new PriorityQueue<int>();
        pq.Add(12, 12);
        pq.Add(13, 13);
        pq.Add(2, 2);
        Console.WriteLine(pq.RemoveMin());
        Console.WriteLine(pq.Peek());
        Console.WriteLine(pq.RemoveMin());
        Console.WriteLine(pq.RemoveMin());
    }
}