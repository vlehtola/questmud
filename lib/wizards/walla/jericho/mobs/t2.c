inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_name("guard");
  set_level(69);
  set_race("human");
  set_experience(3030000);
  set_gender(1);
  set_str(query_str() + 135);
  set_dex(query_dex() + 150);
  set_max_hp(query_hp() + 15000);
  set_block_dir("up");
  set_short("A huge guard, armed to the teeth");
  set_long("A huge muscular man with foreign features guards the stairwell\n"+
        "entrance. He seems like quite a mean, bear-like bloke.\n");
}
 
init() {
  ::init();
  add_action("bribe", "bribe");
}
 
bribe(str) {
  int num;
  num=2100;
 
  if(str!="guard") { return 0; }
 
  if((this_player()->total_money()/100) < num) {
    write("Uhrac booms: 'That's not 'nuff you filthy ho!'\n");
    return 1;
  }
  this_player()->reduce_money(num, 3);
 
  write("The guard grins widely as you hand him "+num+" coins.\n");
  say("The guard leads "+this_player()->query_name()+" through the gate and reassumes his position blocking the way.\n", this_player(
));
  write("The guard leads you up the stairs and quickly reassumes his position guarding the entry.\n");
  move_object(this_player(),"/wizards/walla/workroom");
  command("look");
  return 1;
}




