

inherit "obj/monster";


reset(arg) {
  ::reset(arg);
  if(arg) return;

    set_name("testimobsi");
    set_alias("testi");
    set_short("Wandering test-monster patrolling his predefined bugging route.");
    set_long("Look, its alive!\n");
    set_level(100);
    set_al(10);
      
}

init() {
	::init();

}

status kavele() {

	init_command("east");
}


