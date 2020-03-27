import java.util.Scanner;
public class Connect4{
  public static void main(String[] args){
    Scanner kb = new Scanner(System.in);
    Player user = new UserPlayer();
    Player comp = new AIPlayer();
    Board b = new Board();
    int count = 0;
    while(b.winner().equals("-")){
      if(count%2==0){
        System.out.println("This is my move. --Mr. Computer");
        b.move(comp.nextMove(b, user), comp);
        System.out.print(b);
      }
      else{
        b.move(user.nextMove(b, comp), user);
        System.out.print(b);
      }
      count+=1;
    }
    System.out.print(b.winner()+" WINS!");
  }
}