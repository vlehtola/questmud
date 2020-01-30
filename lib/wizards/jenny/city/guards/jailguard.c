inherit "obj/monster";
int cost;
reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_name("guard");
  set_alias("jailguard");
  set_level(100);
  set_log();
  set_str(query_str()*10);
  set_exp(1);
  set_short("A sturdy looking jailguard");
  set_long("A sturdy looking guard is guarding the jail. He looks\n"+
        "mean and he will kill if he sees any kind of attempt to break\n"+
        "out. You can check the 'cost' to see how much you need to pay\n"+
        "to get out.\n");

}

init() {
  ::init();
  add_action("cost", "cost");
  add_action("pay", "pay");
}

cost() {
  write("\n");
  write("Guard goes to check the cost for you.\n");
  write("You must pay "+this_player()->query_level()*300+" bronze coins to get out.\n");
  write("\n");
  return 1;
}

  pay(str) {
  int cost;
  cost = (this_player()->query_level())*300;

  if(this_player()->query_money(3) < cost) {
    write("Guard booms: 'You don't have enough money!\n");
    return 1;
  }
  this_player()->reduce_money(cost,3);
  write("You pay the guard "+cost+" coins.\n");
  say(this_player()->query_name()+" pays the guard and leaves.\n", this_player());
  this_player()->vapaudu();
  this_player()->move_player("city#/world/city/cs.c");
  return 1;
}
