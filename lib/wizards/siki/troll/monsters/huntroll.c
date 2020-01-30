inherit "obj/monster";

int q;

object weapon;
reset(arg) {

    q = random(4);
    ::reset(arg);
    if(arg) { return; }

    set_str(query_str()*5/3);
    set_exp(query_exp()*4/3);
    set_level(30+random(3));
    set_name("troll");
    set_race("troll");
    set_alias("hunter");
    set_short("A sturdy troll hunting");
    set_long("A muscular and strong looking troll hunting. He moves quietly and\n"+
             "swiftly, trying to surprise his prey.\n");
      

    set_al(-30);
    set_aggressive(0);
    set_al_aggr(371);
    set_gender(1);
    set_skill_chance("strike",33);
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
