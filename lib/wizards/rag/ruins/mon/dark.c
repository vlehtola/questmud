inherit "obj/monster";
int i;
string desc;

reset(arg) {
        ::reset(arg);
	if(arg) { return; }
        i = random(3);
        if(i == 0) {desc = "young";}
        if(i == 1) {desc = "sturdy";}
        if(i == 2) {desc = "veteran";}
        set_level(29+i*5+random(3+i));
        set_experience(query_exp()*5/100+query_exp());
        set_name("soldier");
        set_short("A "+desc+" shadow soldier");
	set_long("The shadow soldiers are the main troops of the Lich King's army. They are\n"+
		"strong and devious and they posses very impressive battle prowess. Some say\n"+
		"that shadow soldiers were once normal men but they were corrupted by the Lich\n"+
		"King's dark magicks. No one knows how long they have served as his minions\n"+
		"or will they die of diseases or of aging.\n");

        set_al(-45-i*5);
        set_aggressive(0);
        set_al_aggr(400);
}
