inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_level(20);
 set_hp(1);
 set_name("rimber");
 set_alias("dummy");
 set_short("Dummy");
 set_long("Test dummy.\n");
 set_race("human");

 set_gender(1);
 set_al(100);
}
