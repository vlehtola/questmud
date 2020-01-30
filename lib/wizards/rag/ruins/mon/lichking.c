inherit "obj/monster";

reset(arg) {
	object weapon;
        ::reset(arg);
	if(arg) { return; }
        set_level(80);
        set_race("lich");
        set_name("lich king");
	set_alt_name("king");
        set_alias("lich");
        set_short("The dreadful Lich King");
        set_long("The Lich King if truly a dredful sight. He is the Terror of the Underworld.\n"+
        	 "He has slaughtered entire nations. He spreads horror everywhere he goes.\n"+
        	 "The Lich King seems to be between two worlds because one moment he looks like\n"+
        	 "a shadow and the other he seems to be flesh and blood. His eyes burn with an\n"+
        	 "unholy red glow. They seem to pierce your entire soul! The sceptre that he is\n"+
        	 "wielding seems to shift between worlds just like the Lich King.\n");

        set_mage(10);
        set_undead(1);
	set_log();
        set_al(-200);
        set_aggressive(0);
	set_al_aggr(400);
	if(!weapon) {
		weapon = clone_object("/wizards/rag/ruins/eq/sceptre");
		move_object(weapon,this_object());
		init_command("wield sceptre");
	}
}