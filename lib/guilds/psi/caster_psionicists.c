inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;

  set_short("The Emphatics guild");
  set_long("This part of the psionic guild teaches themself to use special mental\n"+
           "powers. The room is quite lightened and cosy, in here you feel perfect\n"+
           "mental balance.\n");
  set_not_out();
  set_light(3);
  add_exit("west","/guilds/psi/psiguild");
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
    return "Emphatics";
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
  return "int 1, wis 1";
}

skill_list(int guild_level) {
  int i;
  mapping skills;
    skills = ([ ]);

	if (guild_level >= 1) {

	skills += (["confuse":(int) 55]);
	skills += (["charm":(int) 55]);
	skills += (["mental scan":(int) 55]);
	skills += (["mental view":(int) 55]);
	skills += (["mental disrupt":(int) 50]);
	skills += (["mental expansion":(int) 50]);
	skills += (["stunned maneuvers":(int) 50]);
	skills += (["mental denial":(int) 50]);
	skills += (["mental balance":(int) 50]);
	skills += (["knowledge of mind":(int) 50]);
	skills += (["mental pocket":(int) 50]);

	}

	if(guild_level >= 2) {
	skills += (["mental expansion":(int) 55]);
	skills += (["stunned maneuvers":(int) 55]);
	skills += (["mental denial":(int) 55]);
	skills += (["mental balance":(int) 55]);
	skills += (["knowledge of mind":(int) 55]);

	}

	if(guild_level >= 3) {
	skills += (["confuse":(int) 60]);
	skills += (["charm":(int) 60]);
	skills += (["mental scan":(int) 60]);
	skills += (["mental view":(int) 60]);
	skills += (["mental disrupt":(int) 55]);
	}
	if(guild_level >= 4) {
	skills += (["mental expansion":(int) 60]);
	skills += (["stunned maneuvers":(int) 60]);
	skills += (["mental denial":(int) 60]);
	skills += (["mental balance":(int) 60]);
	skills += (["knowledge of mind":(int) 60]);

	}
	if(guild_level >= 5) {
	skills += (["confuse":(int) 65]);
		skills += (["charm":(int) 65]);
	skills += (["mental scan":(int) 65]);
	skills += (["mental view":(int) 65]);
	skills += (["mental disrupt":(int) 60]);
	}
	if(guild_level >= 6) {
	skills += (["mental expansion":(int) 75]);
	skills += (["stunned maneuvers":(int) 75]);
	skills += (["mental denial":(int) 75]);
	skills += (["mental balance":(int) 75]);
	skills += (["knowledge of mind":(int) 75]);

	}
	if(guild_level >= 7) {
	skills += (["confuse":(int) 70]);
		skills += (["charm":(int) 70]);
	skills += (["mental scan":(int) 70]);
	skills += (["mental view":(int) 70]);
	skills += (["mental disrupt":(int) 70]);
	skills += (["mental pocket":(int) 70]);
	}
	if(guild_level >= 8) {
	skills += (["mental expansion":(int) 80]);
	skills += (["stunned maneuvers":(int) 80]);
	skills += (["mental denial":(int) 80]);
	skills += (["mental balance":(int) 80]);
	skills += (["knowledge of mind":(int) 80]);

	}
	if(guild_level >= 9) {
	skills += (["confuse":(int) 75]);
		skills += (["charm":(int) 75]);
	skills += (["mental scan":(int) 75]);
	skills += (["mental view":(int) 75]);
	skills += (["mental disrupt":(int) 80]);
	}
	if(guild_level >= 10) {
	skills += (["mental expansion":(int) 85]);
	skills += (["stunned maneuvers":(int) 85]);
	skills += (["mental denial":(int) 85]);
	skills += (["mental balance":(int) 85]);
	skills += (["knowledge of mind":(int) 85]);

	}
	if(guild_level >= 11) {
			skills += (["charm":(int) 85]);
	skills += (["confuse":(int) 80]);
	skills += (["mental scan":(int) 80]);
	skills += (["mental view":(int) 80]);

	}
	if(guild_level >= 12) {
	skills += (["mental expansion":(int) 90]);
	skills += (["stunned maneuvers":(int) 90]);
	skills += (["mental denial":(int) 90]);
	skills += (["mental balance":(int) 90]);
	skills += (["knowledge of mind":(int) 90]);

	}
	if(guild_level >= 13) {
			skills += (["charm":(int) 95]);
	skills += (["confuse":(int) 85]);
	skills += (["mental scan":(int) 85]);
	skills += (["mental view":(int) 85]);

	}
	if(guild_level >= 14) {
	skills += (["mental expansion":(int) 95]);
	skills += (["stunned maneuvers":(int) 95]);
	skills += (["mental denial":(int) 95]);
	skills += (["mental balance":(int) 95]);
	skills += (["confuse":(int) 90]);
	skills += (["mental scan":(int) 90]);
	skills += (["mental view":(int) 90]);


	}
	if(guild_level >= 15) {

	skills += (["mental expansion":(int) 100]);
		skills += (["charm":(int) 100]);

	skills += (["stunned maneuvers":(int) 100]);
	skills += (["mental denial":(int) 100]);
	skills += (["mental balance":(int) 100]);
	skills += (["confuse":(int) 100]);
	skills += (["mental scan":(int) 100]);
	skills += (["mental view":(int) 100]);
	skills += (["knowledge of mind":(int) 100]);
	skills += (["mental disrupt":(int) 100]);
	skills += (["mental pocket":(int) 100]);
	}

  return skills;
}
