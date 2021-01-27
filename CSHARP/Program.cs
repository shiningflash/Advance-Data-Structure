using System;
using System.Collections.Generic;

public class Program {
    public static void Main(string[] args) {
        string[] lines = System.IO.File.ReadAllLines("in.txt");

        MapExercise me = new MapExercise();
        me.run(lines);
    }
}