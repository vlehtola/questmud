#include <ansi.h>

int in_use;
string name;
int rounds, wins;

reset(arg) {
  if (arg) { return; }
  name = "machine";
}

id(str) {
  return str == name;
}

short() { return "A onehanded robber-machine"; }

long() {
  write("This machine is used for gambling.\n");
  write("You must get 2 equal fruits to win 5k-10k bronze.\n");
  write("You must get 3 equal fruits to win 500k bronze.\n");
  write("To insert coin and play you must 'pull' lever.\n");
}

get() { return 0; }

init() {
  add_action("pull", "pull");
}

pull(str) {
  if (str == "lever") {
    if(in_use) {
        write("The machine is already occupied.\n");
        return 1;
    }
    if(this_player()->query_money(3) < 1000) {
      write("You must have atleast 1000 bronze coins to play.\n");
      return 1;
    }
    this_player()->reduce_money(1000,3);
    write("You insert 1000 bronze coins in the machine and pull the lever.\n");
    write("The machine starts shaking... ");
    in_use = 1;
    call_out("done", 3);
    return 1;
  }
  write("Pull on the lever, perhaps?\n");
  return 1;
}

done() {
  string result;
  int i, ii, iii, cash;
  in_use = 0;
  rounds += 1;
  i = allocate(3);
  i[0] = random(8); i[1] = random(8); i[2] = random(8);
  result = "";
  while(ii < 3) {
    if(i[ii] == 0) { result = result + RED_F + "Orange "; }
    if(i[ii] == 1) { result = result + CYAN_F + "Grapefruit "; }
    if(i[ii] == 2) { result = result + YELLOW_F + "Banana "; }
    if(i[ii] == 3) { result = result + MAGENTA_F + "Melon "; }
    if(i[ii] == 4) { result = result + GREEN_F + "Apple "; }
    if(i[ii] == 5) { result = result + WHITE_F + "Lemon "; }
    if(i[ii] == 6) { result = result + BLUE_F + "Pineapple "; }
    if(i[ii] == 7) { result = result + OFF + BOLD + "BAR "; }
    ii += 1;
  }
  if(i[0] == i[1]) { cash = (i[0]+1) * 400 + 5000; }
  if(i[1] == i[2]) { cash = (i[1]+1) * 400 + 5000; }
  if(i[0] == i[2]) {
    if(cash) { cash = 500000; }
    else { cash = (i[0]+1) * 500 + 5000; }
  }
  write("and promptly stops.\nThe result is: "+result+"\n");
  if(cash == 500000) { write("Yes! "+ BOLD +"JACKPOT!" + OFF); }  
  if(cash) {
    write(OFF + "You won "+cash+" bronze coins!\n");
    this_player()->add_money(cash,3);
  } else {
    write(OFF + "You lost.\n");
  }
  wins += cash;
  if(cash)
    log_file("ONEHAND_WINS", ctime(time())+" Played rounds: "+rounds+" Win: "+cash+" Total: "+wins+
        " ("+this_player()->query_name()+")\n");  
  return 1;
}


