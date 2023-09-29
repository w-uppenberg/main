using System;
using System.Collections.Generic;
using Font = System.Collections.Generic.KeyValuePair<int, Color>;
using Text = System.Collections.Generic.KeyValuePair<string, System.Collections.Generic.KeyValuePair<int, Color>>;

public class Paper
{
	List<KeyValuePair<string, Font>> information;
	public Paper()
	{
		information = new List<Text>();
	}

	public void Inscript(int size, Color color, string text) {
		information.Add(new Text(text, new Font(size, color)));
	}

	public string ReadPaper() {
		string ret = "";
		foreach (Text t in information) {
			ret += t.Key;
			ret += "\n";
		}
		return ret;
	}
}
