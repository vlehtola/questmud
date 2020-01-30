inherit "obj/monster";

reset(arg) {

    object armour;
    ::reset(arg);
    if(arg) { return; }
    
    set_level(60+random(5));
    set_name("sea monster");
    set_alias("monster");
    set_animal(1);
    set_str(query_str()*3);
   set_dex(query_dex()*5);
    set_short("A huge sea monster");
    set_long("A huge sea monster with long pointy teeth and red round eyes.\n"+
             "The flames of anger in the eyes of the monster shine extremely\n"+
             "brightly, almost blinding you. It has scales all over its thick\n"+
             "body. With its long arms and sharp nails it can easily do great\n"+
             "damage.\n");
    set_al(-120);
    set_aggressive(1);
    set_gender(0);
    set_log();
    set_skill("punch", 100);
    set_skill("deceived attack", 100);
    set_skill("doublehit", 100);


   set_skill("throw weight", 100);
   set_skill("critical", 100);
    set_skill("find weakness", 100);


    armour = clone_object("/wizards/siki/lizard/eq/head");
    move_object(armour,this_object());


}
