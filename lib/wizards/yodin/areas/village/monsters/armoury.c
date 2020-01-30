

inherit "obj/monster";

reset(arg) {

object staff;
        ::reset(arg);
        if(arg) { return; }
        set_level(100);
        set_max_hp(query_max_hp()*2);

        set_gender(1);
        set_name("man");
        set_alias("human");
        set_short("A tall and sturdy man");
        set_long("A sturdy looking man standing behind a counter. He looks as if he was waiting\n"+
		          "for something, propably customers to enter his store. Experience in his eyes\n"+
		          "tell that this man has been doing to same job for a long period of time.\n"+
		          "In his other hand there is a staff propably used as a walking support as well\n"+
		          "as a weapon for defending oneself, still he looks calm. Unlike one could imagine\n"+
		          "from his profession, the man is wearing only cloth robe and leather sandals.\n"+
                  "Exhaustion glimmers from his eyes as he waits for the day to be over.\n");
        set_al(50);
        set_al_aggr(200);
        set_race("human");
        set_log();
        staff = clone_object("/wizards/yodin/areas/village/obj/staff");
        move_object(staff, this_object());
        init_command("wield staff");
}
