inherit "obj/monster";
int i, g;
string desc, pronoun;

reset(arg) {
        ::reset(arg);
	if(arg) { return; }
        i = random(3);
        if(i == 0) {desc = "sick";}
        if(i == 1) {desc = "weak";}
        if(i == 2) {desc = "tortured";}
        set_level(22+i*3+random(3+i));
	set_experience(query_exp()*5/100+query_exp());
        g = random(2)+1;
        set_gender(g);
        pronoun = query_pronoun();
        set_name("slave");
        set_short("A "+desc+" slave is digging a tunnel");
        set_long("This slave was, just like many others, captured by the Lich King's army.\n"+
capitalize(pronoun)+" has been tortured and it seems that "+pronoun+" hasn't eaten in days. "+
		capitalize(pronoun)+" is\n"+
                 "wearing filthy rags. All the slaves are digging some sort of a tunnel.\n");

        set_al(0);
        set_aggressive(0);
        set_al_aggr(400);
}
