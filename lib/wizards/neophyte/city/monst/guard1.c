inherit "obj/monster";
reset(arg) {
        object mace,armour;
                ::reset(arg);
                if(arg) {return; }
    set_level(random(5)+35);
    set_name("guard");
    set_alias("tguard");
    set_short("A tired looking guard");
    set_long("This guard looks rather tired. He is not wearing any basic armours.\n"+
             "He seems to be almost in sleep.\n");
    set_gender(1);
    set_race("human");
    set_aggressive(0);
    set_special(100);
    set_skill("strike", 100);
    set_skill("round blow", 110);
    set_skill_chance("round blow", 100);
    mace = clone_object("/wizards/neophyte/city/eq/sword.c");
    armour = clone_object("/wizards/neophyte/city/eq/armour1.c");
        move_object(mace, this_object());
        move_object(armour, this_object());
    init_command("wield sword");
    init_command("wear all");
 }


init() {
  add_action("block", "south");
}

block() {
        if(this_player()->query_attack()) {
                write("Guard blocks your path.\n");
                return 1;
  }
}
