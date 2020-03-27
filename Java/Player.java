public abstract class Player{
  String symbol;
  public String getSymbol(){
    return symbol;
  }
  public abstract int nextMove(Board b, Player opp);
}