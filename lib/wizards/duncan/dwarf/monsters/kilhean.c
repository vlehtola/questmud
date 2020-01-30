inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) { return; }
 set_level(23);
 set_name("kil'hean");
 set_alias("seamstress");
 set_alias("kilhean");
 set_short("Kil'hean the dwarven seamstress {working}");
 set_long("Kil'hean is a young dwarven woman with long, silver-coloured hair and deep\n"+
          "blue eyes. She is very skilled seamstress, therefore she decided to open an\n"+
          "own shop in here. Earlier she was working in a shop like this, but it wasen't\n"+
          "her own and it didn't offer enough challenge to her.\n");
 set_al(100);
 set_aggressive(0);
 set_race("dwarf");
 set_gender(2);
}
                                                                                                                       
