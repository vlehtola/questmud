inherit "obj/monster";
reset(arg) {
	object armour,dagger,arms;
        ::reset(arg);
        if(arg) {return; }
        set_name("goblin");
        set_level(40+random(6));
        set_al(-30);
        set_gender(1);
        set_race("goblin");
        set_short("An important looking goblin");
        set_long("This goblin looks much taller then average goblin. He has a important\n"+
                 "look on his face. \n");
        set_skill("strike", 100);
        armour = clone_object("/wizards/neophyte/village/eq/armour.c");
        move_object(armour, this_object());
        arms = clone_object("/wizards/neophyte/village/eq/arms.c");
        move_object(arms, this_object());
        dagger = clone_object("/wizards/neophyte/village/eq/dagger.c");
        move_object(dagger, this_object());
        init_command("wear all");
        init_command("wield dagger");
        set_special(100);
        set_log();
}
special_move() {
	object skill;
	string st;
	if(!random(15)) testit();
  if(!this_object()->query_stunned() && !this_object()->query_use_skill()) {
	  st = "strike";
	  skill = clone_object("guilds/obj/skill");
	  this_object()->set_use_skill(skill);
	  skill->start_skill(st);
  return 1;
  }
}

testit() {
	this_object()->heal_self(50000);
	say("The goblin uses somekind of magic and looks much healthier.\n");
	return 1;
}