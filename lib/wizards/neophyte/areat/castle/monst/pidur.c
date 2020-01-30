inherit "obj/monster";
object bracer,necklace,blud,shield,glovet;
int number_of_guards;
int e = random(3);

reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        number_of_guards = 0;
        set_level(55+random(10));
        set_name("pidur");
        set_race("human");
        set_alias("king");
        set_short("Pidur the king of castle");
        set_long("Pidur is the king of this castle. He doesn't belong to the royal family, but\n"+
                 "he assassinated the whole royal family and became king to this castle.\n"+
                 "He has been king only for short time. He was before the right hand of\n"+
                 "the former king.\n");
        set_al(-30);
        set_gender(1);
        set_extra(1);
        set_special(100);
        set_log();
        set_str(query_str()+200);
        set_skill("strike", 100);
        set_skill_chance("strike", 50);
        if(!e)eq_combo_0();
        if(e ==1)eq_combo_1();
        if(e ==2)eq_combo_2();
}



  extra() {
    object bodyguard;
    if (!attacker_ob) {
        return;
    }

    if(number_of_guards<3) {
    if(!random(10)) {
        bodyguard = clone_object("/wizards/neophyte/areat/castle/monst/bodyguard");
        move_object(bodyguard, environment(this_object()));
        say("Pidur calls more guards to aid him!\n");
        number_of_guards += 1;
    }
}
}

reduce_number() {
    number_of_guards -= 1;
}
special_move() {
  object ob;
  ob = present("zelcy", environment(this_object()));
  if(attacker_ob && ob) {
    ob->attack_object(attacker_ob);
    return 1;


  }

}
eq_combo_0() {
	        blud = clone_object("/wizards/neophyte/areat/castle/obj/bludgeon");
	        move_object(blud, this_object());
	        init_command("wield maul");
	        bracer = clone_object("/wizards/neophyte/areat/castle/obj/bracer");
	        move_object(bracer, this_object());
	        init_command("wear bracers");
	        shield = clone_object("/wizards/neophyte/areat/castle/obj/shields");
	        move_object(shield, this_object());
	        init_command("wield shield");
	        set_max_hp(query_hp()+50000);
	        set_hp(query_max_hp());
}

eq_combo_1() {
	        blud = clone_object("/wizards/neophyte/areat/castle/obj/bludgeon");
	        move_object(blud, this_object());
	        init_command("wield maul");
	        necklace = clone_object("/wizards/neophyte/areat/castle/obj/necklace");
	        move_object(necklace, this_object());
	        init_command("wear necklace");
	        bracer = clone_object("/wizards/neophyte/areat/castle/obj/bracer");
	        move_object(bracer, this_object());
	        init_command("wear bracers");
	        set_max_hp(query_hp()*2);
	        set_hp(query_max_hp());
}
eq_combo_2() {
	        blud = clone_object("/wizards/neophyte/areat/castle/obj/bludgeon");
	        move_object(blud, this_object());
	        init_command("wield maul");
	        glovet = clone_object("/wizards/neophyte/areat/castle/obj/glovet");
	        move_object(glovet, this_object());
	        init_command("wear gloves");
	        necklace = clone_object("/wizards/neophyte/areat/castle/obj/necklace");
	        move_object(necklace, this_object());
	        init_command("wear necklace");
	        set_max_hp(query_hp()*3);
	        set_hp(query_max_hp());
}
