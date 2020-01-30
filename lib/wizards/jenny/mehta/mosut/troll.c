inherit "obj/monster";

reset(arg) {
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(65);
    set_max_hp(query_max_hp()*2);
    set_experience(16325839);
    set_str(query_str()*2);
    set_dex(query_dex()*2);
    set_name("clubbah");
    set_alias("troll");
    set_race("troll");
    set_short("Clubbah, a HUGE cave troll");
    set_long("Very strong looking cave troll called Clubbah, he is wearing\n"+
             "oddly glowing armlets and it looks very mean and ugly. It is\n"+
             "told that Clubbah has been terrorizing this forest for some\n"+
             "centuries already and still keeps doing it.\n");
    set_al(10);
    set_aggressive(1);
    set_gender(3);
    set_skill("kick", 100);
    set_skill_chance("kick", 100);
    set_skill("bare hands", 100);
    set_skill("attack", 100);
    set_skill("punch", 100);
    set_skill("critical", 60);
    set_skill("counter spell", 50);
    set_skill("reflect spell", 40);
    set_skill("throw weight", 60);
    set_skill("enhance criticals", 50);
    set_skill("inner strength", 100);
    set_skill("dodge", 100);
    set_skill("alertness", 100);
    set_skill("foresee attack", 100);
    set_skill("stun", 100);
    set_skill("double hit", 100);
    set_log();

        armour = clone_object("/wizards/jenny/mehta/rojut/bracers.c");
        move_object(armour, this_object());
        init_command("wear bracers");

        weapon = clone_object("/wizards/jenny/mehta/rojut/maul.c");
        move_object(weapon, this_object());
        init_command("wield maul");

}
