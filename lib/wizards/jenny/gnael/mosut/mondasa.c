inherit "obj/monster";
reset(arg) {
        object money;
        object axe,axe2,amulet,armour,head;
        ::reset(arg);
        if(arg) {return; }
        set_name("mondasa");
        set_alias("half-god");
        set_race("human");
        set_mage(1);
        set_level(103+random(2));
        set_special(2);
       set_exp(75014354);
        set_max_hp(query_hp() + 100000);
        set_int(query_int() + 300);
        set_wis(query_wis() + 100);
        set_str(query_str() + 200);
        set_con(query_con()*2);
        set_al(-100);
        set_gender(1);
        set_short("Mondasa the Half-God, The Bane Of The World");
        set_long("Mondasa is a human who served Odel in a dark war\n"
                 "a few thousand years ago. Odel gave him godly powers\n"+
                 "and Mondasa is now a half-god. The only difference there is\n"+
                 "between a god and a half-god is that half-god can die\n"+
                 "by the hands of mortal. He is glowing with pure power\n"+
                 "and his eyes are completely black.\n");
      set_skill("critical", 75);
      set_skill("enhance criticals", 75);
      set_skill("find weakness", 88);
      set_skill("deceived attack", 93);
      set_skill("bare hands", 100);
      set_skill("punch", 100);
      set_skill("throw weight", 100);
      set_skill("tremendous blow", 80);
      set_skill_chance("tremendous blow", 65);
      set_skill("dodge", 100);
      set_skill("parry", 100);
      set_skill("weapon parry", 100);
      set_skill("tumble", 30);
      set_skill("reflect spell", 100);
      set_skill("counter spell", 100);
      set_mage();
      set_spell_chance(65, "exs fla strm");
      set_skill("cast essence", 100);
      set_skill("cast electric", 100);
      set_skill("cast storm", 100);
      set_skill("theory of electricity", 100);
      set_skill("mana control", 60);
      set_skill("chanting", 100);
      set_skill("agility", 60);
        set_log();

        amulet = clone_object("/wizards/jenny/gnael/rojut/apo_amulet.c");
        move_object(amulet, this_object());
        init_command("wear amulet");

        armour = clone_object("/wizards/jenny/gnael/rojut/mirror_armour.c");
        move_object(armour, this_object());
        init_command("wear mail");

        axe = clone_object("/wizards/jenny/gnael/rojut/battle_axe.c");
        move_object(axe, this_object());
        init_command("wield axe");

        axe2 = clone_object("/wizards/jenny/gnael/rojut/battle_axe.c");
        move_object(axe2, this_object());
        init_command("wield axe");

        head = clone_object("/wizards/jenny/gnael/rojut/head.c");
        move_object(head, this_object());

}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Mondasa points at you and says: 'DIE!'\n");
  say("Mondasa points at "+ob->query_name()+" \n"+
  "and says: 'DIE!' \n", ob);
  ob->hit_with_spell(800000, "physical");
}
