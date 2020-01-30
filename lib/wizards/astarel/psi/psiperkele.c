inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  
  set_short("The Psionicist-guild\n");
  set_long("Tahan tulee joskus hiaaano desci ylistamaan psi-killan mahtavuutta.\n");
  set_light(3);
  
  add_exit("north","/guilds/psi/fighter_psionicists");
  add_exit("south","/guilds/psi/caster_psionicists");
  add_exit("cs","/world/city/cs");
  
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}

guild_name() {
    return "Apprentice Psionicists";
}

check_joining_rec() {

    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([5:"mental strike:20;"]);
  return sk;
}

get_bonuses(level) {
  return "con 1 , int 1, wis 1";
}

skill_list(int guild_level) {
  int i;
  mapping skills;
    skills = ([ ]);
	
	if (guild_level >= 1) {
		skills += (["mental strike":(int) 5]);
		skills += (["evading thought":(int) 5]);
		skills += (["mental block":(int) 5]);
		
	}
	if (guild_level >= 2) {
		skills += (["mental strike":(int) 10]);
		skills += (["mental denial":(int) 5]);
		skills += (["mental scan":(int) 5]);
		skills += (["mental view":(int) 5]);
		}
	
	if (guild_level >= 3) {
		skills += (["mental strike":(int) 15]);
		skills += (["simultaneous thought":(int) 5]);
		skills += (["mental drain":(int) 5]);
		skills += (["shake mind":(int) 5]);
		skills += (["iron will":(int) 5]);
		skills += (["mental balance":(int) 5]);
		skills += (["mental expansion":(int) 5]);
		skills += (["knowledge of mind":(int) 5]);
		
	}
	if (guild_level >= 4) {
		skills += (["mental strike":(int) 20]);
		skills += (["simultaneous thought":(int) 10]);
		skills += (["mental denial":(int) 10]);
		skills += (["charm":(int) 5]);
		skills += (["confuse":(int) 5]);
		skills += (["mental scan":(int) 10]);
		skills += (["mental view":(int) 10]);
	}
	if (guild_level >= 5) {
		skills += (["mental strike":(int) 25]);
		skills += (["simultaneous thought":(int) 15]);
		skills += (["mental force":(int) 5]);
		skills += (["overload brain":(int) 5]);
		skills += (["mental drain":(int) 10]);
		skills += (["shake mind":(int) 10]);
		skills += (["evading thought":(int) 10]);
		skills += (["mental block":(int) 10]);
		skills += (["iron will":(int) 10]);
		skills += (["mental balance":(int) 10]);
		skills += (["mental expansion":(int) 10]);
		
	}
	if (guild_level >= 6) {
		skills += (["mental strike":(int) 30]);
		skills += (["simultaneous thought":(int) 20]);
		skills += (["mental drain":(int) 15]);
		skills += (["shake mind":(int) 15]);
		skills += (["charm":(int) 10]);
		skills += (["confuse":(int) 10]);
		skills += (["mental scan":(int) 15]);
		skills += (["mental view":(int) 15]);
		skills += (["knowledge of mind":(int) 10]);
		skills += (["evading thought":(int) 15]);
		skills += (["mental block":(int) 15]);
	}
	if (guild_level >= 7) {
		skills += (["mental strike":(int) 35]);
		skills += (["simultaneous thought":(int) 25]);
		skills += (["mental force":(int) 10]);
		skills += (["overload brain":(int) 10]);
		skills += (["mental denial":(int) 15]);
		skills += (["mental scan":(int) 20]);
		skills += (["mental view":(int) 20]);
		skills += (["iron will":(int) 20]);
		skills += (["mental balance":(int) 20]);
		skills += (["mental expansion":(int) 20]);
	}
	if (guild_level >= 8) {
		skills += (["mental strike":(int) 40]);
		skills += (["simultaneous thought":(int) 30]);
		skills += (["mental drain":(int) 20]);
		skills += (["shake mind":(int) 20]);
		skills += (["charm":(int) 15]);
		skills += (["confuse":(int) 15]);
		skills += (["iron will":(int) 25]);
		skills += (["mental balance":(int) 25]);
		skills += (["mental expansion":(int) 25]);
		skills += (["evading thought":(int) 20]);
		skills += (["mental block":(int) 20]);
		skills += (["knowledge of mind":(int) 20]);
		
	}
	if (guild_level >= 9) {
		skills += (["mental strike":(int) 45]);
		skills += (["simultaneous thought":(int) 35]);
		skills += (["mental force":(int) 15]);
		skills += (["overload brain":(int) 15]);
		skills += (["mental denial":(int) 20]);
		skills += (["mental scan":(int) 25]);
		skills += (["mental view":(int) 25]);
		skills += (["evading thought":(int) 25]);
		skills += (["mental block":(int) 25]);
	}
	
	if (guild_level >= 10) {
		skills += (["mental strike":(int) 50]);
		skills += (["simultaneous thought":(int) 40]);
		skills += (["mental drain":(int) 25]);
		skills += (["shake mind":(int) 25]);
		skills += (["charm":(int) 20]);
		skills += (["confuse":(int) 20]);
		skills += (["mental scan":(int) 30]);
		skills += (["mental view":(int) 30]);
		skills += (["iron will":(int) 30]);
		skills += (["mental balance":(int) 30]);
		skills += (["mental expansion":(int) 30]);
		skills += (["knowledge of mind":(int) 25]);
		
	}
	if (guild_level >= 11) {
		skills += (["mental strike":(int) 55]);
		skills += (["simultaneous thought":(int) 45]);
		skills += (["mental force":(int) 20]);
		skills += (["overload brain":(int) 20]);
		skills += (["mental denial":(int) 25]);
		skills += (["iron will":(int) 35]);
		skills += (["mental balance":(int) 35]);
		skills += (["mental expansion":(int) 35]);
	}
	if (guild_level >= 12) {
		skills += (["mental strike":(int) 60]);
		skills += (["simultaneous thought":(int) 50]);
		skills += (["mental drain":(int) 30]);
		skills += (["shake mind":(int) 30]);
		skills += (["charm":(int) 25]);
		skills += (["confuse":(int) 25]);
		skills += (["mental scan":(int) 35]);
		skills += (["mental view":(int) 35]);
		skills += (["evading thought":(int) 30]);
		skills += (["mental block":(int) 30]);
	}
	if (guild_level >= 13) {
		skills += (["mental strike":(int) 65]);
		skills += (["mental force":(int) 25]);
		skills += (["overload brain":(int) 25]);
		skills += (["mental denial":(int) 30]);
		skills += (["mental scan":(int) 40]);
		skills += (["mental view":(int) 40]);
		skills += (["knowledge of mind":(int) 30]);
	}
	if (guild_level >= 14) {
		skills += (["mental strike":(int) 70]);
		skills += (["simultaneous thought":(int) 55]);
		skills += (["mental drain":(int) 35]);
		skills += (["shake mind":(int) 35]);
		skills += (["charm":(int) 30]);
		skills += (["confuse":(int) 30]);
		skills += (["evading thought":(int) 35]);
		skills += (["mental block":(int) 35]);
		
	}
	if (guild_level >= 15) {
		skills += (["mental strike":(int) 75]);
		skills += (["simultaneous thought":(int) 60]);
		skills += (["mental force":(int) 30]);
		skills += (["overload brain":(int) 30]);
		skills += (["mental denial":(int) 35]);
		skills += (["iron will":(int) 40]);
		skills += (["mental balance":(int) 40]);
		skills += (["mental expansion":(int) 40]);
		skills += (["knowledge of mind":(int) 35]);
		
	}
	if (guild_level >= 16) {
		skills += (["mental strike":(int) 80]);
		skills += (["simultaneous thought":(int) 65]);
		skills += (["mental drain":(int) 40]);
		skills += (["shake mind":(int) 40]);
		skills += (["mental scan":(int) 50]);
		skills += (["mental view":(int) 50]);
		skills += (["evading thought":(int) 40]);
		skills += (["mental block":(int) 40]);
	}
	if (guild_level >= 17) {
		skills += (["mental strike":(int) 85]);
		skills += (["mental force":(int) 35]);
		skills += (["overload brain":(int) 35]);
		skills += (["charm":(int) 35]);
		skills += (["confuse":(int) 35]);
		skills += (["mental denial":(int) 40]);
		skills += (["iron will":(int) 45]);
		skills += (["mental balance":(int) 45]);
		skills += (["mental expansion":(int) 45]);
		
	}
	if (guild_level >= 18) {
		skills += (["mental strike":(int) 90]);
		skills += (["simultaneous thought":(int) 70]);
		skills += (["mental force":(int) 40]);
		skills += (["overload brain":(int) 40]);
		skills += (["mental denial":(int) 45]);
		skills += (["mental drain":(int) 45]);
		skills += (["shake mind":(int) 45]);
		skills += (["evading thought":(int) 45]);
		skills += (["mental block":(int) 45]);
	}
	if (guild_level >= 19) {
		skills += (["mental strike":(int) 95]);
		skills += (["mental force":(int) 45]);
		skills += (["overload brain":(int) 45]);
		skills += (["charm":(int) 40]);
		skills += (["confuse":(int) 40]);
		skills += (["knowledge of mind":(int) 40]);
	}
	if (guild_level >= 20) {
		skills += (["mental strike":(int) 100]);
		skills += (["simultaneous thought":(int) 75]);
		skills += (["mental force":(int) 50]);
		skills += (["overload brain":(int) 50]);
		skills += (["mental drain":(int) 50]);
		skills += (["shake mind":(int) 50]);
		skills += (["charm":(int) 50]);
		skills += (["confuse":(int) 50]);
		skills += (["mental denial":(int) 50]);
		skills += (["iron will":(int) 50]);
		skills += (["mental balance":(int) 50]);
		skills += (["mental expansion":(int) 50]);
		skills += (["evading thought":(int) 50]);
		skills += (["mental block":(int) 50]);
		skills += (["knowledge of mind":(int) 50]);		
		
	}
	
  return skills;
}
