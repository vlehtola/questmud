

inherit "obj/monster";

reset(arg) {

object ase;
        ::reset(arg);
        if(arg) { return; }
        set_level(100);
        set_max_hp(query_max_hp()*2);
        set_gender(1);
        set_name("man");
        set_alias("human");
        set_short("A tall and muscular man");
        set_long("A muscular looking man working as a weapons dealer. He has\n" +
				"a light chainmail equipment on him and two fine steel\n" +
				"longswords sheathed on his waist. Calmly but decisively he\n" +
				"stands behind the counter waiting for customers to arrive.\n" +
				"The looks on his face is an expression of frustration, maybe\n" +
				"due to the lack of customers.\n");

        set_al(50);
        set_al_aggr(200);
        set_race("human");
        set_log();
        ase = clone_object("/wizards/yodin/areas/village/obj/sword");
		        move_object(ase, this_object());
        init_command("wield sword");
}
