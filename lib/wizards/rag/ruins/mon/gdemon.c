inherit "obj/monster";
int i;
string desc;

reset(arg) {
        ::reset(arg);
	if(arg) { return; }
        i = random(3);
        if(i == 0) {desc = "lesser";}
        if(i == 1) {desc = "big";}
        if(i == 2) {desc = "greater";}
        set_level(32+i*5+random(3+i));
	set_experience(query_exp()*5/100+query_exp());
        set_name("demon");
        set_short("A "+desc+" guardian demon");
        set_long("The "+desc+" guardian demon is a fearsome sight. It has thick red skin and\n"+
                "glowing eyes. It's horns are curved and pieces of flesh are hanging from them.\n"+
                "It has bulging muscles and sharp claws and teeth. It is wearing some protective\n"+
                "equipment but it seems to fit only the corrupted life forms, like the demon\n"+
                "itself. The guardian isn't the lowest demon but it surely isn't a member of the\n"+
                "highest ranks.\n");

        set_al(-45-i*5);
        set_aggressive(0);
        set_al_aggr(400);
}
