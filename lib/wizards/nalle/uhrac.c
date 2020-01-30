inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_name("uhrac");
  set_level(60);
  set_race("human");
  set_gender(1);
  set_block_dir("down");
  set_short("Uhrac El Aa'n, the dungeonkeeper");
  set_long("A big muscular man with foreign features guards the prison\n"+
        "entrance. He seems like quite a mean bloke\n");
}

init() {
  ::init();
  add_action("bribe", "bribe");
}

bribe(str) {
  int num; 
  num=200;

  if(str!="uhrac") { return 0; }

  if((this_player()->total_money()/100) < num) {
    write("Uhrac booms: 'That's not 'nuff you filthy ho!'\n");
    return 1;
  }
  this_player()->reduce_money(num, 3);

  write("Uhrac grins widely as you hand him "+num+" coins.\n");
  say("Uhrac leads "+this_player()->query_name()+" through the passage and reassumes his position blocking the way.\n", this_player());
  write("Uhrac leads you down the passage and quickly reassumes his position guarding the entry.\n");
  move_object(this_player(),"/wizards/nalle/workroom");
  return 1;

}
