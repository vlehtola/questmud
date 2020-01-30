inherit "obj/monster";
reset(arg) {
                ::reset(arg);
                if(arg) {return; }
                    set_name("wolfrider");
        set_level(random(5)+30);
        set_str(query_str()*2);
            set_con(query_con()*4);
            set_max_hp(query_hp()*3);
            set_hp(query_max_hp());

    set_alias("wolf");
    set_short("Wolfrider");
    set_long("This hairy animal looks quite big to be ordinary wolf.\n"+
             "Something seem to be sitting on the wolf and watching very\n"+
             "closely at you. Eyes of the wolf are constanly chasing someone.\n");
    set_animal();
    set_aggressive(1);
    set_skill("poison breath", 150);
        set_skill_chance("poison breath", 30);
    set_dead_ob(this_object());
 }
init() {
  add_action("block", "northwest");
  add_action("block", "northeast");
  add_action("block", "southeast");
  add_action("block", "southwest");
}

block() {
        if(this_player()->query_quest("bring sheep hide to goblin")) {
                write("Wolfrider gently steps away.\n");
                return 1;
        }

    write("Wolfrider won't let you go!\n");
    return 1;
}
monster_died() {
        object ob;
 move_object(clone_object("/wizards/neophyte/city/monst/rider.c"), environment(this_object()));
 say("Orc jumps from the wolf just before the wolf dies.\n");
}
