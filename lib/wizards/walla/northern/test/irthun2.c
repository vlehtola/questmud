inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(10+random(4));
    set_name("irthun");
    set_alias("dwarf");
    set_short("Irthun the dwarf");
    set_long("Before you stands a young dwarf, that looks different from\n"+
             "the other dwarves that you've seen here. This dwarf looks\n"+
             "happy, eventhough the rest of the castle is darkened with\n"+
             "trouble and anger.\n");
    set_race("dwarf");
    set_gender(1);
    set_al(50);
    set_aggressive(0);
 
   
}
 

catch_tell(str) {
  object ob,player;
  string tmp,tmp2;
  ::catch_tell(str);
  if(sscanf(str,"%s gives %s to you.",tmp,tmp2) == 2) {
    if(ob = present("eku1")) {
        player = find_player(lower_case(tmp));
        say("Irthun says 'Thanks!'\n");
        destruct(ob);
        call_out("give",3,player);
        return 1;
    }
  }
}

give(pl) {
        tell_object(pl,"Monsu gives you <eku>.\n");
        move_object(clone_object("/wizards/walla/eku2"), pl);
	pl->set_quest("Wierd Walla-quest");
	return 1;
}