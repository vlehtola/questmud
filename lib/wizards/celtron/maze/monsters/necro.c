inherit "obj/monster";
int t = random(3);
int y = random(3);
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
  set_level(92);
  set_special(20);
  set_name("hriak");
  set_alias("necromancer");
  set_short("Hriak, the evil necromancer");
  set_long("Hriak is dressed in black. He looks very powerful and skilled.\n"+
        "His eyes are red, he's propably an orc although you can't see his face.\n");
  set_mage(1);
  set_log();
  set_max_hp(query_max_hp()*3);
  set_hp(query_max_hp());
  set_aggressive(1);
  set_skill("cast essence", 100);
  set_skill("cast ice", 100);
  set_skill("cast fire", 100);
  set_skill("cast electric", 100);
  set_skill("cast bolt", 100);
  set_skill("theory of electricity", 100);
  set_skill("lore of cold", 100);
  set_skill("knowledge of heat", 100);

  if(t==0) {
    move_object(clone_object("/wizards/celtron/maze/eq/robes02"), this_object());
    init_command("wear robes");
  }

  if(y==0) {
    move_object(clone_object("/wizards/celtron/maze/eq/ring02"), this_object());
    init_command("wear ring");
  }
  
  if(t==1) {
    move_object(clone_object("/wizards/celtron/maze/eq/cloak02"), this_object());
    init_command("wear cloak");
  }
  
  if(y==1) {
    move_object(clone_object("/wizards/celtron/maze/eq/amulet02"), this_object());
    init_command("wear amulet");
  }

  if(t==2) {
    move_object(clone_object("/wizards/celtron/maze/eq/boots02"), this_object());
    init_command("wear boots");
  }

  if(y==2) {
    move_object(clone_object("/wizards/celtron/maze/eq/crown02"), this_object());
    init_command("wear crown");
}
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
