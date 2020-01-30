inherit "obj/monster";

reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_level(23);
 set_name("stormbird");
 set_short("A large yellow stormbird");
 set_long("A bird called stormbird. Legendary bird which flies before the storm clouds.\n");
 set_race("animal");
 set_gender(0);
}
