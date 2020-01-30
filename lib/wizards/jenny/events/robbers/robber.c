inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    set_gender(1);
    set_level(10+random(15));
    set_name("bandit");
    set_alias("monster");
     set_short("A "+({ "stupid", "huge", "dirty and mean", "huge musceled", "lunatic",})[random(5)]+" bandit is looking for people to rob");
    set_long("A fearsome looking bandit who is obvisiously looking around to find\n"+
             "something valuable from the city of Duranghom. His hands are moving\n"+
             "all the time and his pockets seem to start weight more and more every\n"+
             "second.\n");
    set_al(-5);
    set_aggressive(1);
    set_move_at_random(3);
    set_whimpy(1);
    set_special(10);
    set_block_dir(({"north", "west", })[random(2)]);

      armour = clone_object("/wizards/jenny/events/robbers/armour.c");
    move_object(armour, this_object());
    init_command("wear armour");

 }
    special_move() {
  object ob, eq;
  ob = this_object()->query_attack();
  eq = all_inventory(ob)[random(sizeof(all_inventory(ob)))];
  if(!eq->drop()) {
  move_object(eq,this_object());
  tell_object(ob, "You feel someones hand passing by.\n");
  shout("Bandit shouts: 'Poor poor "+ob->query_name()+" , HAH!'\n");
  ob->update_stats();
  ob->fix_weight();
 }
}
