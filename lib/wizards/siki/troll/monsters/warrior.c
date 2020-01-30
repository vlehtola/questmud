inherit "obj/monster";

int q;

object weapon;
reset(arg) {

    q = random(4);
    ::reset(arg);
    if(arg) { return; }

    set_str(query_str()*5/3);
    set_level(40+random(3));
    set_name("troll");
    set_race("troll");
    set_alias("warrior");
    set_short("A muscular troll warrior");
    set_long("A huge and muscular troll warrior ready to fight for his tribe. He\n"+
             "has some bloodstains on his hairy skin and the blood is defenetly\n"+
             "not his.\n");
      

    set_al(-30);
    set_aggressive(0);
    set_al_aggr(371);
    set_gender(1);
    set_skill_chance("strike",20);
    set_skill("strike",80);


    if(q==0) {  weapon = clone_object("/wizards/siki/troll/eq/maul");
    move_object(weapon,this_object());
    init_command("wield maul");
    }
    if(q==1) {  weapon = clone_object("/wizards/siki/troll/eq/warhammer");
    move_object(weapon,this_object());
    init_command("wield warhammer");
    }
    if(q==2) {  weapon = clone_object("/wizards/siki/troll/eq/morningstar");
    move_object(weapon,this_object());
    init_command("wield morningstar");
    }
    if(q==3) {  weapon = clone_object("/wizards/siki/troll/eq/mace");
    move_object(weapon,this_object());
    init_command("wield mace");
    }

}
