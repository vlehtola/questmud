
inherit "obj/monster";
   
   reset(arg) {
   ::reset(arg);
   if(arg) { return; }
   

   set_level(34);
   set_name("monk");
   set_gender(1);
   set_str(160);
   set_max_hp(6700);
   set_hp(6700);
   set_race("human");
   set_alias("Monk");
   set_short("A drunken monk");

   set_long("A well built monk clad in brown robes.\n"+
   "This monk seems to have found a friend in wine.\n");

}
