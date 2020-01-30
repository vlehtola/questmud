inherit "obj/monster";
int i;
string desc;

reset(arg) {
        ::reset(arg);
	if(arg) { return; }
        i = random(3);
        if(i == 0) {desc = "An inexperienced";}
        if(i == 1) {desc = "A young";}
        if(i == 2) {desc = "A";}
        set_level(27+i*3+random(3+i));
	set_experience(query_exp()*5/100+query_exp());        
        set_name("soldier");
        set_short(desc+" soldier is here training");
	set_long("This soldier is a new member in the Lich King's army. Just like thousands\n"+
		 "of other mortal men, he has been corrupted by the power promised by the\n"+
		 "Lich King. He is practising the art of war to someday join the growing\n"+
		 "forces of darkness. His soul will soon be lost forever.\n");

        set_al(-25-i*5);
        set_aggressive(0);
        set_al_aggr(400);
}
