inherit "obj/monster";

reset(arg) {

    object weapon,shield;
    ::reset(arg);
    if(arg) { return; }
    
    set_level(23+random(2));
    set_name("warrior");
    set_alias("orc warrior");
    set_race("orc");
    set_short("A strong orc warrior");
    set_long("A muscular and mean looking orc warrior. His eyes are dark red and he\n"+
             "has an evil grin on his face. His moves are slow but extremely smooth\n"+
             "and as he looks at you with his dark red eyes, you sense the presence\n"+
             "of death.\n");
             

    set_al(-25);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);

    weapon = clone_object("/wizards/siki/orc/eq/sword2");
    move_object(weapon,this_object());
    init_command("wield sword");

    shield = clone_object("/wizards/siki/orc/eq/shield2");
    move_object(shield,this_object());
    init_command("wield shield");
}

