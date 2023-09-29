using System;



public class Pen
{
	private Color color;
	private int size;


	public Pen(Color color, int size)
	{
		this.color = color;
		this.size = size;
	}

	public void Write(Paper paper, string text) {
		paper.Inscript(size, color, text);
	}
}
