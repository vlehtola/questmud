inherit "obj/monster";
reset(arg) {
	object armour,dagger;
        ::reset(arg);
        if(arg) {return; }
        set_name("goblin");
        set_level(35+random(6));
        set_al(-30);
        set_gender(1);
        set_race("goblin");
        set_short("A Goblin farmer");
        set_long("This goblin is farmer of the goblin village. He is wearing a dirty\n"+
                 "leather apron and a small scythe is wielded in his bouth hands. He\n"+
                 "is cutting grass at the moment.\n");
        set_skill("strike", 100);
        armour = clone_object("/wizards/neophyte/village/eq/armour.c");
        move_object(armour, this_object());
        dagger = clone_object("/wizards/neophyte/village/eq/dagger.c");
        move_object(dagger, this_object());
        init_command("wear all");
        init_command("wield dagger");
        set_special(50);
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