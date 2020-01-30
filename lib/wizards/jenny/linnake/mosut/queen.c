inherit "obj/monster";
reset(arg) {
        object crown;
        ::reset(arg);
        if(arg) {return; }
        set_name("dreia");
        set_alias("queen");
        set_race("human");
        set_mage(1);
        set_level(75+random(15));
        set_max_hp(query_max_hp()*3);
        set_experience(12353432);
        set_int(query_int()*4);
        set_wis(query_wis()*2);
        set_con(query_con()*3);
        set_al(30);
        set_special(100);
        set_gender(2);
        set_short("Dreia, the queen of Roxen");
        set_long("Beatiful young queen of Roxen, she has deep green eyes\n"
                 "and long red hair. She is wearing queen's normal outfit\n"+
                 "and oddly radiating crown. She doesn't look very strong,\n"+
                 "but she has the hands of a sorceress. She looks happy, but\n"+
                 "she does give the king some mean looks every now and then.\n");
        set_skill("stun", 100);
        set_skill("bare hands", 40);
        set_skill("attack", 50);
        set_skill("inner strength", 20);
        set_skill("cast essence", 100);
        set_skill("cast ice", 100);
        set_skill("cast fire", 100);
        set_skill("cast electric", 100);
        set_skill("cast bolt", 100);
        set_skill("mana control", 100);
        set_skill("knowledge of heat", 100);
        set_skill("lore of cold", 100);
        set_skill("theory of electricity", 100);
        set_skill("proximity blast", 100);
        set_skill("stunning blast", 100);
        set_skill("counter spell", 100);
        set_skill("reflect spell", 70);
        set_skill("invoke ethereal mana", 100);
        set_skill("power channeling", 70);
        set_skill("power concentration", 70);
        set_skill("power focusing", 70);
        set_log();

        crown = clone_object("/wizards/jenny/linnake/rojut/crown.c");
        move_object(crown, this_object());
        init_command("wear crown");

}
special_move() {
  object ob;
  ob = present("august", environment(this_object()));
  if(attacker_ob && ob) {
    tell_room(environment(this_object()), "The king shouts: 'Leave her alone.'\n");
    ob->attack_object(attacker_ob);
    return 1;
  

  }

}