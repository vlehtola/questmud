int cost;

reset(arg) {
  cost -= cost / 2;
  if(cost < 20) cost = 20;
  if(arg) return;
  cost = 20;
}

init() {
  add_action("push", "push");
}

id(str) { return str == "machine"; }

push(str) {
  int num;
  num = cost;
  if(str != "button") return;
  if(this_player()->query_money(3) < num) {
    write("The machine says: Sorry, but you don't have enough money.\n");
    return 1;
  }
  this_player()->reduce_money(num,3);
  if(this_player()->remove_scar())
    write("One of your scars vanishes!\n");
  else 
    write("You insert your money, but nothing happens.\n");
  cost += cost/10;
  return 1;
}

short() { return "Scar removal machine"; }

long() {
  write("A wierd iron machine stands 4 feet tall. There is a big yellow\n");
  write("button on it and some text under it: 'Push' to remove scar.\n");
  write("The current cost is "+cost+" bronze coins.\n");
}
