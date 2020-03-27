import java.util.Scanner;
public class UserPlayer extends Player{
  private Scanner kb;
  
  public UserPlayer(){
    symbol = "O";
    kb = new Scanner(System.in);
  }
  
  public int nextMove(Board b, Player p){
    int c = 100;
    while(c<0||c>6){
      System.out.print("Choose a column to put your chip in.");
      c = kb.nextInt()-1;
    }
    return c;
  }
}