inherit "obj/monster";
reset(arg) {
	object armour,dagger;
        ::reset(arg);
        if(arg) {return; }
        set_name("goblin");
        set_level(25+random(6));
        set_al(-30);
        set_gender(1);
        set_race("goblin");
        set_short("A male Goblin");
        set_long("This goblin looks quite small and weak. He has a thin grey skin and there can\n"+
                 "be seen blood veins on the face of goblin. He has a grinning look on his round\n"+
                 "head and the eyes are constantly blinking, because of that light. He seems to\n"+
                 "be fearing something, maybe that light which is coming outside of the hut.\n");
        set_skill("strike", 100);
        armour = clone_object("/wizards/neophyte/village/eq/armour.c");
        move_object(armour, this_object());
        dagger = clone_object("/wizards/neophyte/village/eq/dagger.c");
        move_object(dagger, this_object());
        init_command("wear all");
        init_command("wield dagger");
        set_special(100);
}
special_move() {
	object skill;
	string st;
  if(!this_object()->query_stunned() && !this_object()->query_use_skill()) {
	  st = "strike";
	  skill = clone_object("guilds/obj/skill");
	  this_object()->set_use_skill(skill);
	  skill->start_skill(st);
  return 1; }
}