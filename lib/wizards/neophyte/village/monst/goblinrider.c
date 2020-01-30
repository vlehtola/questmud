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
        set_short("A goblin boat rider");
        set_long("This goblin looks little more muscular then average goblin.\n"+
                 "He has a quite muscular body and strong looking arms, they\n"+
                 "have probably start to growing when he accepted the job of\n"+
                 "boat rower. He has a green skin with lot of blood veins on\n"+
                 "the surface of face. He is wearing long leather cape, which\n"+
                 "seems to hold the water coming inside the clothes. He looks\n"+
                 "much more slave then worker.\n");
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