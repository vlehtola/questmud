inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;

  set_short("The Telekinetics guild");
  set_long("This part of the psionic guild consentrates themself at the mental combat.\n"+
           "The guild room itself is a nicely decorated with balance of white and yellow\n"+
           "colour. A two large chandeliers is placed at both side of the room.\n");
  set_not_out();
  set_light(3);
  add_exit("east","/guilds/psi/psiguild");
  property = ({"no_summon"});

}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 15;
}

guild_name() {
    return "Telekinetics";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Psionicists") != 20) {
        write("You must complete the Psionicists - training before joining this guild.\n");
        return 0;
    }

    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);

  return sk;
}

get_bonuses(level) {
  return "con 1 , int 1";
}

skill_list(int guild_level) {
  int i;
  mapping skills;
    skills = ([ ]);

	if (guild_level >= 1) {

	skills += (["shake mind":(int) 50]);
	skills += (["mental drain":(int) 50]);
	skills += (["mental force":(int) 50]);
	skills += (["overload brain":(int) 50]);
	skills += (["simultaneous thought":(int) 50]);
	skills += (["evading thought":(int) 50]);
	skills += (["mental block":(int) 50]);


	}

	if (guild_level >= 2) {

	skills += (["shake mind":(int) 55]);
	skills += (["mental drain":(int) 55]);
	skills += (["mental force":(int) 55]);


}
if (guild_level >= 3) {

	skills += (["overload brain":(int) 55]);
	skills += (["simultaneous thought":(int) 55]);
	skills += (["evading thought":(int) 55]);
	skills += (["mental block":(int) 55]);

}
if (guild_level >= 4) {

	skills += (["shake mind":(int) 60]);
	skills += (["mental drain":(int) 60]);
	skills += (["mental force":(int) 60]);


}
if (guild_level >= 5) {


	skills += (["overload brain":(int) 60]);
	skills += (["simultaneous thought":(int) 60]);
	skills += (["evading thought":(int) 60]);
	skills += (["mental block":(int) 60]);

}
if (guild_level >= 6) {

	skills += (["shake mind":(int) 65]);
	skills += (["mental drain":(int) 65]);
	skills += (["mental force":(int) 65]);

}
if (guild_level >= 7) {


	skills += (["overload brain":(int) 65]);
	skills += (["simultaneous thought":(int) 65]);
	skills += (["evading thought":(int) 65]);
	skills += (["mental block":(int) 65]);

}
if (guild_level >= 8) {

	skills += (["shake mind":(int) 70]);
	skills += (["mental drain":(int) 70]);
	skills += (["mental force":(int) 70]);

}
if (guild_level >= 9) {


	skills += (["overload brain":(int) 70]);
	skills += (["simultaneous thought":(int) 70]);
	skills += (["evading thought":(int) 70]);
	skills += (["mental block":(int) 70]);

}
if (guild_level >= 10) {

	skills += (["shake mind":(int) 75]);
	skills += (["mental drain":(int) 75]);
	skills += (["mental force":(int) 75]);


}
if (guild_level >= 11) {


	skills += (["overload brain":(int) 75]);
	skills += (["simultaneous thought":(int) 75]);
	skills += (["evading thought":(int) 75]);
	skills += (["mental block":(int) 75]);

}
if (guild_level >= 12) {

	skills += (["shake mind":(int) 80]);
	skills += (["mental drain":(int) 80]);
	skills += (["mental force":(int) 80]);

}
if (guild_level >= 13) {


	skills += (["overload brain":(int) 80]);
	skills += (["simultaneous thought":(int) 80]);
	skills += (["evading thought":(int) 80]);
	skills += (["mental block":(int) 80]);

}
if (guild_level >= 14) {

	skills += (["shake mind":(int) 85]);
	skills += (["mental drain":(int) 85]);
	skills += (["mental force":(int) 85]);


}
if (guild_level >= 15) {

	skills += (["shake mind":(int) 100]);
	skills += (["mental drain":(int) 100]);
	skills += (["mental force":(int) 100]);
	skills += (["overload brain":(int) 100]);
	skills += (["simultaneous thought":(int) 100]);
	skills += (["evading thought":(int) 100]);
	skills += (["mental block":(int) 100]);

	}



  return skills;
}
