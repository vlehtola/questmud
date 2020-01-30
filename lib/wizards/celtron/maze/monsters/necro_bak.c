inherit "obj/monster";

hit_with_spell(arg1,arg2,arg3,arg4) {
  object mummy;

  mummy = present("mummy", environment(this_object() ));
  if(mummy && file_name(mummy)[0..30] == "/wizards/celtron/maze/monsters/") {
    tell_room(environment(this_object()), "...but the mummy blocks the blast!\n");
    return mummy->hit_with_spell(arg1,arg2,arg3,arg4);
  }
  ::hit_with_spell(arg1,arg2,arg3,arg4);
}


reset(status arg) {
  int i;
  ::reset(arg);
  if(arg) return;
  set_level(90);
  set_special(21);
  set_name("hriak");
  set_alias("necromancer");
  set_short("Hriak, the evil necromancer");
  set_long("Hriak is dressed in black. He looks very powerful and skilled.\n"+
        "His eyes are red, he's propably an orc although you can't see his face.\n");
  move_object(clone_object("/wizards/celtron/maze/eq/cloak02"), this_object());
  move_object(clone_object("/wizards/celtron/maze/eq/robes02"), this_object());
  init_command("wear robes");
  init_command("wear cloak");
  set_mage(1);
  set_log();
  set_max_hp(query_max_hp()*6);
  set_hp(query_max_hp());
  set_aggressive(1);
}

catch_tell(str) {
  string tmp,tmp2;
  object ob,aave;
  if(!random(2)) return;
  if(sscanf(str, "%s leaves %s", tmp,tmp2) == 2) {
    ob = find_player(lower_case(tmp));
    if(!ob) return;
    say("Hriak shouts dark words and a ghost raises from nearby grave!\n");
    aave = clone_object("/wizards/celtron/maze/monsters/aave");
    move_object(aave,this_object());
    aave->set_target(ob);
    return 1;
  }
}


