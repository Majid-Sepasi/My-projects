import java.util.*;
public class Game {
    private Player player1;
    private Player player2;
    private int n, m;
    private Key table[][];
    Game(int n, int m){
        if(n < 6)
            n = 6;
        if(m < 3)
            m = 3;
        this.n = n;
        this.m = m;
        table = new Key[n][m];
        player1 = new Player();
        player2 = new Player();
        player1.addKey(new Key("King", "☻", new Point(0, m / 2), "Red", "Player1"));
        player1.addKey(new Key("Soldier", "◄", new Point(0, m / 2 - 1), "Red", "Player1"));
        player1.addKey(new Key("Soldier", "►", new Point(0, m / 2 + 1), "Red", "Player1"));
        player1.addKey(new Key("Soldier", "▼", new Point(1, m / 2), "Red", "Player1"));
        player1.addKey(new Key("Soldier", "DL", new Point(1, m / 2 - 1), "Red", "Player1"));
        player1.addKey(new Key("Soldier", "DR", new Point(0, m / 2 + 1), "Red", "Player1"));
        
        player2.addKey(new Key("King", "☻", new Point(n - 1, m / 2), "BLUE", "Player2"));
        player2.addKey(new Key("Soldier", "◄", new Point(n - 1, m / 2 - 1), "BLUE", "Player2"));
        player2.addKey(new Key("Soldier", "►", new Point(n - 1, m / 2 + 1), "BLUE", "Player2"));
        player2.addKey(new Key("Soldier", "▲", new Point(n - 2, m / 2), "BLUE", "Player2"));
        player2.addKey(new Key("Soldier", "UL", new Point(n - 2, m / 2 - 1), "BLUE", "Player2"));
        player2.addKey(new Key("Soldier", "UR", new Point(n - 2, m / 2 + 1), "BLUE", "Player2"));
        
        table[0][m / 2] = player1.getKeys().get(0);
        table[0][m / 2 - 1] = player1.getKeys().get(1);
        table[0][m / 2 + 1] = player1.getKeys().get(2);
        table[1][m / 2] = player1.getKeys().get(3);
        table[1][m / 2 - 1] = player1.getKeys().get(4);
        table[1][m / 2 + 1] = player1.getKeys().get(5);
        
        table[n - 1][m / 2] = player2.getKeys().get(0);
        table[n - 1][m / 2 - 1] = player2.getKeys().get(1);
        table[n - 1][m / 2 + 1] = player2.getKeys().get(2);
        table[n - 2][m / 2] = player2.getKeys().get(3);
        table[n - 2][m / 2 - 1] = player2.getKeys().get(4);
        table[n - 2][m / 2 + 1] = player2.getKeys().get(5);
        
    }

    public Key[][] getTable() {
        return table;
    }
    
    void play(){
        Scanner input = new Scanner(System.in);
        int turn = 0;
        while(true){
            
            System.out.println("Turn : player" + (turn + 1));
            System.out.print("Point[x, y] : ");
            int x, y;
            x = input.nextInt();
            y = input.nextInt();
            
            x--;
            y--;
            while(x >= n || x < 0 || y < 0 || y >= m ||  table[x][y] == null || !table[x][y].getOwner().equals("Player" + (turn + 1)) || table[x][y].getType().equals("King"))
            {
                System.out.print(ConsoleColors.RED  + "Invalid point !! try again : " + ConsoleColors.RESET);
                x = input.nextInt();
                y = input.nextInt();
                x--;
                y--;
            }
            String direction = "U D L R UL UR DL DR";
            System.out.format("Direction[%s] : ", direction);
            int x2 = x, y2 = y;
            while(true){
                String dir = input.next().toUpperCase();
                x2 = x;
                y2 = y;
                switch (dir) {
                    case "U":
                        x2--;
                        break;
                    case "D":
                        x2++;
                        break;
                    case "L":
                        y2--;
                        break;
                    case "R":
                        y2++;
                        break;
                    case "UL":
                        x2--;
                        y2--;
                        break;
                    case "UR":
                        x2--;
                        y2++;
                        break;
                    case "DL":
                        x2++;
                        y2--;
                        break;
                    case "DR":
                        x2++;
                        y2++;
                        break;
                    default:
                        break;
                   
                }
                if(!direction.contains(dir) || !checkValidPoint(turn + 1,x2, y2))
                {
                     System.out.print(ConsoleColors.RED + "Invalid direction !! try again : " + ConsoleColors.RESET);
                     continue;
                }
                if(table[x2][y2] == null)
                {
                    table[x2][y2] = table[x][y];
                    table[x][y] = null;
                }
                else
                {
                    int x3 = x2 - x;
                    int y3 = y2 - y;
                    if(!checkPoint(x3, y3, table[x][y]))
                    {
                        System.out.print(ConsoleColors.RED + "Invalid direction !! try again : " + ConsoleColors.RESET);
                        continue;
                    }
                    if(table[x2][y2].getType().equalsIgnoreCase("King"))
                    {
                        System.out.println(ConsoleColors.PURPLE + "player " + (turn + 1) + " won the game !!" + ConsoleColors.RESET);
                        System.exit(0);
                    }
                    else if(player1.getKeys().isEmpty() && player2.getKeys().isEmpty()){
                        System.out.println(ConsoleColors.PURPLE + "Equal" + ConsoleColors.RESET);
                        System.exit(0);
                    }

                    else{
                        if(turn == 0)
                            player2.eraseKey(table[x2][y2]);
                        else
                            player1.eraseKey(table[x2][y2]);

                        table[x2][y2] = table[x][y];
                        table[x][y] = null;
                    }
                }
                 
               showTable();
               break;
            }
            turn ^= 1;
            if(turn == 0 && player1.getKeys().size() == 1)
                turn ^= 1;
            else if(turn == 1 && player2.getKeys().size() == 1)
                turn ^= 1;
        }
    }
    
    boolean checkValidPoint(int turn, int x, int y){
        if(x >= n || x < 0 || y < 0 || y >= m)
            return false;
        if(table[x][y] == null)
            return true;
        return !table[x][y].getOwner().equals("Player" + turn);
    }
    
    
    boolean checkPoint(int x, int y, Key key){
        
        if(x == -1 && y == -1 && !key.getDirection().equals("UL"))
            return false;
        if(x == -1 && y == 0 && !key.getDirection().equals("▲"))
            return false;
        if(x == -1 && y == 1 && !key.getDirection().equals("UR"))
            return false;
        if(x == 0 && y == -1 && !key.getDirection().equals("◄"))
            return false;
        if(x == 0 && y == 1 && !key.getDirection().equals("►"))
            return false;
        if(x == 1 && y == -1 && !key.getDirection().equals("DL"))
            return false;
        if(x == 1 && y == 0 && !key.getDirection().equals("▼"))
            return false;
       
        return !(x == 1 && y == 1 && !key.getDirection().equals("DR"));
    }
    
   
    void showTable(){
       System.out.println();
       for(int i = 1; i <= m; i++)
            System.out.print("\t" + i);
       System.out.println();
       for(int i = 1; i <= 8 * m + 3; i++)
           System.out.print("-");
        System.out.println();
       for(int i = 0; i < n; i++){
           System.out.print(i + 1 + "|\t");
           for(int j = 0; j < m; j++)
           {
               if(table[i][j] == null)
                   System.out.print("-\t");
               else
               {
                   if(table[i][j].getOwner().equals("Player1"))
                       System.out.print(ConsoleColors.BLUE);
                   else
                       System.out.print(ConsoleColors.RED);
                   System.out.print(table[i][j].getDirection() + "\t" + ConsoleColors.RESET);
               }
                    
           }
           System.out.println();   
       }
   }
    
}
