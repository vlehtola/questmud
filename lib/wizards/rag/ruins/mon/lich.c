inherit "obj/monster";
int i;
string desc;

reset(arg) {
        ::reset(arg);
	if(arg) { return; }
        i = random(3);
        if(i == 0) {desc = "An apprentice";}
        if(i == 1) {desc = "A powerful";}
        if(i == 2) {desc = "A master";}
        set_level(36+i*4+random(3+i));
	set_experience(query_exp()*5/100+query_exp());
        set_race("lich");
        set_name("lich");
        set_alias("mage");
        set_short(desc+" lich mage");
        set_long("The lich mages are the personal assistents of the Lich King. They control\n"+
                "the lower creatures and strike at the King's enemies with unholy spells.\n"+
                "The lich mages are feared and loathed but some mages are known to value\n"+
                "their skills. The Lich King personally trains all liches.\n");

        set_mage(1);
        set_undead(1);
        set_al(-45-i*5);
        set_aggressive(0);
        set_al_aggr(400);
}
