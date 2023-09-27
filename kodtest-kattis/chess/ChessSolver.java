import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class ChessSolver {
    private ArrayList<Pair> whites = new ArrayList<Pair>();
    private ArrayList<Pair> blacks = new ArrayList<Pair>();
    private ArrayList<String> letters = new ArrayList<String>(Arrays.asList("A","B","C","D","E","F","G","H"));
	
    public void run() {
        Scanner scanner = new Scanner(System.in);
        int nrProblems = scanner.nextInt();
		constructWhiteList();
		
        for(int i = 0; i< nrProblems; i++) {
			String letter = scanner.next();
			Integer nr = scanner.nextInt();
			Pair start = new Pair(letter, nr);
			letter = scanner.next();
			nr = scanner.nextInt();
			Pair end = new Pair(letter, nr);
            solveProblem(start, end);
        }
    }
    
    private void solveProblem(Pair start, Pair end) {
		if (whites.contains(start) && !whites.contains(end)){
			System.out.println("Impossible");
			return;
		}
		if (!whites.contains(start) && whites.contains(end)){
			System.out.println("Impossible");
			return;
		}
		
		if (isDiagonallyConnected(start, end)) {
			System.out.println("Possible: " + start + " " + end);	
		} else {
			
			System.out.println("Possibly possible... " + start + " " + end);
		}
		
    }

    private void constructWhiteList() {
        for(int i = 0; i < 8; i++) {
            for(int j=0;j<8;j++){
				if(i%2 != j%2) {
                   whites.add(new Pair(letters.get(j), i+1)); 
                }
            }
        }
    }
	
	private void constructBlackList() {
        for(int i = 0; i < 8; i++) {
            for(int j=0;j<8;j++){
				if(i%2 == j%2) {
                   blacks.add(new Pair(letters.get(j), i+1)); 
                }
            }
        }
    }
	
	boolean isDiagonallyConnected(Pair start, Pair end) {
		int aL = letters.indexOf(start.getLetter());
		int bL = letters.indexOf(end.getLetter());
		int aN = start.getNumber() - 1;
		int bN = end.getNumber() - 1;
		
		if(aN == bN || aL == bL) {return false;}
		Pair testPair = new Pair("Z", 99);
		for(int i = 1; i < 8; i++) {
			if (aL + i < 8) {
				if (aN + i < 8) {
					testPair = new Pair(letters.get(aL + i), aN + i + 1);
					System.out.println("test " + testPair);
					if (testPair.equals(end)){
						return true;
					}
				}
				if (aN - i >= 0) {
					testPair = new Pair(letters.get(aL + i), aN - i + 1);
					System.out.println("test " + testPair);
					if (testPair.equals(end)){
						return true;
					}
				}
			}
			if (aL - i >= 0) {
				if (aN + i < 8) {
					testPair = new Pair(letters.get(aL - i), aN + i + 1);
					System.out.println("test " + testPair);
					if (testPair.equals(end)){
						return true;
					}
				}
				if (aN - i >= 0) {
					testPair = new Pair(letters.get(aL - i), aN - i + 1);
					System.out.println("test " + testPair);
					if (testPair.equals(end)){
						return true;
					}
				}				
			}
		}
		return false;
	}
}