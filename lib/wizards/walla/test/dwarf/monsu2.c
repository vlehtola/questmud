inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(25+random(4));
    set_name("monsu");
    set_experience(1);             
    set_alias("monster");
    set_short("testimonsu 2");
    set_long("tassa lukee.\n"+
             "vaiheessa\n"+
             "jotain muutao\n"+
             "sitten ku teen.\n");
    set_al(0);
    set_gender(1);
    set_race("dwarf");
    set_aggressive(1);               
  
}




