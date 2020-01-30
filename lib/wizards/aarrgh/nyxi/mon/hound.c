inherit "obj/monster";
reset(arg) {
  ::reset(arg);
  if(arg) { return; }

set_level(random(2)+38);
set_max_hp(query_max_hp() * 2);
set_hp(query_max_hp());
  set_name("hellhound");
set_alias("hound");
  set_short("A kerberos hellhound");
  set_long("This hellhound has been summoned from the deepest pits of hell.\n"
     	   "You see the mark of The Nyx on the forehead. Hellhound growls\n"
		   "angrily and is ready to attack.\n");

    set_skill("attack", 90);
  	set_skill("critical", 90);
  	set_skill("stun", 40);
        set_skill("kick", 50);
  	set_skill("dodge", 40);
  	set_skill("tumble", 10);
  	set_skill("alertness", 80);
  	set_special(20);
  	set_block_dir("north");

}


