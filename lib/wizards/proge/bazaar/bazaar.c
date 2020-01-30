/* 
Bazaar for player2player item selling.

++ Proge (Jan 2003)

*/

inherit "room/room";

/*
   these three should be set manually and then update
   they're only to make things easier and faster
*/

int COUNTER_PRICE; // this is the price of counter room
int AVAILABLE;     // whether players can buy own counter or not
int CLOSED;        // if the counter rooms are closed for players
int i;
int items;
string player;

reset(arg)
{
  if(arg) return;
  COUNTER_PRICE = 10;
  AVAILABLE = 1;
  CLOSED == 0;
  add_exit("out", "/wizards/proge/lab");
  short_desc = "Fleamarket of Duranghom";
  long_desc = "Experimental Bazaar for Player2Player item-selling.\n"+
              "'look at plaque' for more information.\n";
}


init()
{
  add_action("go", "go");
  add_action("look", "look");
  add_action("buy", "buy");
  ::init();
}


/* show information about the bazaar */

look(str)
{
  if (str == "at plaque")
    {
      write("Counters:\n"+
            "----------------------\n"+
            read_file("/wizards/proge/bazaar/counters.list",4,0)+"\n"+
            "----------------------\n"+
            "Use 'go <player>' to see their counter.\n"+
            "    'buy counter' to buy your own counter.\n"+
            "Current cost for counter is "+COUNTER_PRICE+"\n");
      if(AVAILABLE == 1) {
        write("We are currently not selling counters.\n");
      }
      if(CLOSED == 1) {
        write("We are currently not open.\n");
      }
      return 1;
    }
  return;
}


/* move player to the counter room */

go(str) 
{
  string player;
  int items;
  int i;
  if(CLOSED == 1)
    { 
      write("We are currently closed.");
      return 1;
    }
  /* check if player str has a counter */ 
  i = 4;
  while(read_file("/wizards/proge/bazaar/counters.list",i,1)) 
    {
      sscanf(read_file("/wizards/proge/bazaar/counters.list",i,1), "%s\t\t%d", player, items);
      write("sscanf()  player: "+player+" items: "+items+"\n");
      if(lower_case(str) == lower_case(player))
        {
          /* move this player to the counter room of player str */
          move_object(this_player(), "/wizards/proge/bazaar/"+player);
          break;
        }
      i+=1;
  }
  /* if such counter doesn't exist */
  write("That player doesn't have a counter in here\n");
  return 1;
}


/* if player wants to buy own counter */

buy(str) 
{
  if(str == "counter") 
    {
    if (AVAILABLE == 0) 
      {
        write("We are currently not selling counters.\n");
        return 1;
      }
    write("This function is not ready yet.\n");
    return 1;
    }
  return;
}




