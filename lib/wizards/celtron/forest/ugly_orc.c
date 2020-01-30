inherit "obj/monster";
object victim;

reset(arg) {
    object weapon,armour,shield,misc,money;
    int i;
    ::reset(arg);
    if(arg) { return; }
    set_name("orc");
    set_race("orc");
    i = random(4);
    if (i == 0) {
	set_short("An ugly orc");
    	set_long("An ugly orc wearing somekind of orcish war gear. It's green skin\n" +
		"smells like shit and drool drips from yellow teeth.\n");
    } else if(i == 1) {
        set_short("A very ugly orc");
        set_long("A very ugly orc wearing somekind of orcish war gear. It's green skin\n" +
                "smells like shit and drool drips from yellow teeth.\n");
    } else if(i == 2) {
        set_short("An extremely ugly orc");
        set_long("An extremely ugly orc wearing somekind of orcish war gear. It's green skin\n"+
                "smells like shit and drool drips from yellow teeth.\n");
    } else if(i == 3) {
	set_short("An enormous Uruk-Hai");
	set_long("Uruk-Hai's are know to be the strongest and the most dangerous\n"+
		"creatures of the horrible orc race. This one is unforgettably ugly.\n");
    }
    set_level(25+i*4);
    set_exp(query_exp()*4/3);
    set_str(query_str()*4/3);
    set_al(-(i+1) * (10 + random(10)));
    i = random(i);
    if (i>1) { i = 1; }
    set_aggressive(i);
    weapon = clone_object("/wizards/celtron/forest/orc_sword");
    move_object(weapon, this_object());
    init_command("wield sword");
    armour = clone_object("/wizards/celtron/forest/orc_armour");
    move_object(armour, this_object());
    init_command("wear armour");
    shield = clone_object("/wizards/celtron/forest/orc_shield");
    move_object(shield, this_object());
    init_command("lwield shield");
    misc = clone_object("/wizards/celtron/forest/orc_helm");
    move_object(misc, this_object());
    init_command("wear helm");
    set_skill_chance("strike", 15);
    set_dead_ob(this_object());
}

monster_died() {
    call_other("/wizards/celtron/forest/map", "reduce_number");
}





