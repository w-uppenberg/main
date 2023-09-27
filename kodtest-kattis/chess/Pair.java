public class Pair {
	private String letter;
	private Integer number;
	
	public Pair(String letter, Integer number) {
		this.letter = letter;
		this.number = number;
	}
	
	public Integer getNumber(){return number;}
	public String getLetter(){return letter;}
	
	@Override 
	public String toString() {
		return String.format("%s %d", letter, number);
    }
	@Override
    public boolean equals(Object o) {
		if (o == this) {
            return true;
        }
		
		if (!(o instanceof Pair)) {
            return false;
        }
        Pair c = (Pair) o;
         
        return letter.compareTo(c.getLetter()) == 0 && number == c.getNumber();
	}
}