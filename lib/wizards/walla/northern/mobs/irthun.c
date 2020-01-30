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
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) return 1;
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) return;
      item_ob = present("crown0503246921", this_object());
      if (!item_ob) return;

      say("Irthun says: 'Oh thank you very much for the crown, now I can rule here.'\n"); 
      destruct(item_ob);
      destruct(present("irthun",environment( this_object() )));

  }
}
