inherit "obj/monster";
object weapon, mail, bracers, amulet;
int i;

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        i = random(3);
        set_race("drow");
        set_name("bloodwind");
        set_alias("general");
        set_gender(1);
        set_short("General Bloodwind is here overseeing the training");
        set_long("General Bloodwind is the commander of the Lich King's armies. He is a tall\n"+
                 "and powerful-looking drow. He looks like a very ruthless man and that is\n"+
                 "probably the reason why he has gained respect from the Lich King. The scars\n"+
                 "on his face show that he doesn't just command the army, he also leads the\n"+
                 "attacks. He is wearing simple robes under his scale mail.\n");

        set_level(62+random(3)+i*4);
	set_max_hp(query_max_hp()*3/2);
	set_hp(query_max_hp());
	set_str(query_str()*3/2);
	set_int(query_int()*4/3);
        set_al(-65);
        set_aggressive(0);
        set_al_aggr(400);
        set_log();

        if(!weapon) {
                weapon = clone_object("/wizards/rag/ruins/eq/burn_sword");
                move_object(weapon,this_object());
                init_command("wield sword");
        }
        if(!mail) {
                mail = clone_object("/wizards/rag/ruins/eq/sbmail");
                move_object(mail,this_object());
                init_command("wear mail");
        }
        if(!bracers && i) {
                bracers = clone_object("/wizards/rag/ruins/eq/sbbra");
                move_object(bracers,this_object());
                init_command("wear bracers");
        }
        if(!amulet && i == 2) {
                amulet = clone_object("/wizards/rag/ruins/eq/amulet");
                move_object(amulet,this_object());
                init_command("wear amulet");
        }
}
