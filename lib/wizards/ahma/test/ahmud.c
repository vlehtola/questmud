inherit "obj/monster";
int i, total;

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_name("ahmud");
    set_alias("ahmud");
    set_short("Ahmud is leaning against the wall");
    set_long("This fellow here seems to be lacking very much\n" +
             "experience. He also seems very weak, just like a baby.\n" +
             "You wonder what is his purpose in this realm.\n");
    set_al(0);
    set_hp(1);
    set_exp(99999999999);
    set_aggressive(0);
    set_block_dir("west");

    armour = clone_object("/world/eq/armours/platemail");
    move_object(armour, this_object());
    init_command("wear mail");
  set_special(100);
}

special_move() {
  if(!i) {
    say("Ahmud shouts: 'I dare not fight you. Stop!'\n");
    stop_fight();
    i = 1;
  }
  query_attack()->stop_fight();
}
