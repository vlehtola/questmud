inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_level(38);
 set_name("rider");
 set_alias("rider");
 set_short("A strong looking stormbird rider");
 set_long("The rider has smaller wings than the others. He is wearing long white cape and\n"+
  "brown sandals. His white hair reaches to his shoulders and his short beard\n"+
  "covers half of his visible face.\n");
 set_race("angel");
 set_gender(1);
 set_al(30);
}
