inherit "obj/monster";
reset(arg) {
        object money;
        object gloves;
        ::reset(arg);
        if(arg) {return; }
        set_name("lucius");
        set_alias("lord");
        set_race("human");
        set_mage(1);
        set_level(77+random(10));
        set_special(10);
        set_max_hp(query_max_hp()*2);
        set_int(query_int()*6);
        set_wis(query_wis()*2);
        set_str(query_str()*2);
        set_con(query_con()*2);
        set_al(5);
        set_gender(1);
        set_short("Lucius Dagonus, oldest of Dagonus brothers");
        set_long("Lucius Dagonus is one of the three famous Dagonus\n"
                 "brothers, his other two little brothers Hader and Gron\n"+
                 "are quite famous, but not as famous as Lucius. He has short\n"+
                 "brown hair and he is glowing with some odd power. He is wearing\n"+
                 "normal clothes and odd looking gloves.\n");
        set_skill("stun", 100);
        set_skill("bare hands", 40);
        set_skill("attack", 80);
        set_skill("inner strength", 50);
        set_skill("cast essence", 100);
        set_skill("cast ice", 100);
        set_skill("enhance criticals", 40);
        set_skill("critical", 50);
        set_skill("tumble", 10);
        set_skill("find weakness", 30);
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
        set_skill("reflect spell", 60);
        set_skill("invoke ethereal mana", 100);
        set_skill("power channeling", 70);
        set_skill("power concentration", 70);
        set_skill("power focusing", 70);
        set_log();

        gloves = clone_object("/wizards/jenny/linnake/rojut/holy_glovet.c");
        move_object(gloves, this_object());
        init_command("wear gloves");
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Lucius raises his hands high and shouts ICE! You are hit\n"+
  "by A HUGE icepick!\n");
  say("Lucius raises his hands high and shouts ICE! "+ob->query_name()+" \n"+
  "is hit by A HUGE icepick!\n", ob);
  ob->hit_with_spell(3200, "cold");
}



