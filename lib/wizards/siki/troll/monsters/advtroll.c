inherit "obj/monster";

int q;

object weapon;
reset(arg) {

    q = random(4);
    ::reset(arg);
    if(arg) { return; }

    set_str(query_str()*5/3);
    set_exp(query_exp()*4/3);
    set_level(24+random(3));
    set_name("troll");
    set_race("troll");
    set_alias("adventurer");
    set_short("A young troll looking for adventures");
    set_long("A strong young troll looking for some excitement. His eyes are\n"+
             "full of life and enthusiasm.\n");
      

    set_al(-20);
    set_aggressive(0);
    set_al_aggr(381);
    set_gender(1);
    set_skill_chance("strike",10);
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
