inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(10);
    set_name("citizen");
    set_alias("citizen");
    set_short("A citizen of Jericho");
    set_long("Almos all citizens of Jericho have been chased away\n"+
             "by Leb-Kamars army. The rest have been enslaved. Only\n"+
             "a few remain uncaptured. The citizen is very skinny, and\n"+
             "badly bruised.\n");
    set_al(0);
    set_gender(1);
    set_race("human");
    set_dead_ob(this_object());

}
      monster_died() {
      shout("Leb Kamar shouts: Aaargh, "+this_player()->query_name()+" got me!\n");
      return 0;
     }
 
 catch_tell(string str) {
 string tmp1;
 if(sscanf(str, "%s arrives from %s.", tmp1) == 1) {
 shout(tmp1+" arrives.\n");
 tell_object(find_player(tmp1), "jees.\n");
 }
}

