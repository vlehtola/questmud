inherit "obj/monster";

reset(arg) {
    object armour;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 45);
call_other(this_object(), "set_name", "guardian");
call_other(this_object(), "set_alias", "demon");
call_other(this_object(), "set_short", "Demon of the vengeance, guardian of the 'Xyn'");
call_other(this_object(), "set_long", "\n"
"\n"
"\n"
"\n");
    call_other(this_object(), "set_al", -10);
set_block_message("Guardian says: 'You are not going anywhere!'");
    call_other(this_object(), "set_aggressive", 0);
   set_block_dir("out");
   set_block_dir("east");
   set_race("demon");
   set_special(25);
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  if(ob->query_gender() != 1) return 0;
  tell_object(ob, "Cyclop kicks you in the balls!\n");
  say("Cyclop kicks "+ob->query_name()+" between his legs!\n", ob);
  ob->hit_with_area_spell(1000);
}
