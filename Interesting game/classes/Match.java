import java.util.*;
public class Match {
    public static void main(String[] args) {
       Scanner input = new Scanner(System.in);
       
       System.out.print("Size of table [n * m] : ");
       Game game = new Game(input.nextInt(), input.nextInt());
       game.showTable();
       game.play();
       
    }
    
}
