
using System;

namespace MyWriter { 
    class Program {
        static void Main(string[] args)
        {
            bool q = false;
            Paper paper = new Paper();
            Pen defaultPen = new Pen(Color.Black, 12);

            while (!q)
            {
                Console.WriteLine("What do you want to do? \n1: Write\n2: Read\n3: Quit\n\n");
                var input = Console.ReadKey(true);
                if (input.KeyChar.Equals('1'))
                {
                    Console.WriteLine("What do you want to write?");
                    string? str = Console.ReadLine();
                    if (str != null)
                    {
                        defaultPen.Write(paper, str);
                    }
                }
                else if (input.KeyChar.Equals('2'))
                {
                    Console.Clear();
                    Console.Write(paper.ReadPaper());

                    Console.ReadKey();
                }
                else if (input.KeyChar.Equals('3'))
                {
                    q = true;
                }
                Console.Clear();
            }
        }
    }
}