#define ALPHA "/daemons/alpha"

cmd_guilds(string str) {
  mapping guilds, guildsit;
  string *lvl, name, level, *stats, stats_b, *stats_c;
  int i,y,j,b,c, b_str, b_dex, b_con, b_int, b_wis, o_str, o_dex, o_con, o_int, o_wis;
  int ov_str, ov_dex, ov_con, ov_wis, ov_int;
  object ob;
  
  
  ov_str = 0;
  ov_dex = 0;
  ov_con = 0;
  ov_wis = 0;
  ov_int = 0;
  
  stats_c = ({ });
    
	guildsit = ([
		"fighters" : "/guilds/fighter/fighter.c",
		"weaponmasters" : "/guilds/fighter/weapon_master.c",
		"blademasters" : "/guilds/fighter/blades.c",
		"bludgeonists" : "/guilds/fighter/bludgeons.c",
		"barbarians" : "/guilds/fighter/barbarian.c",
		"warriors" : "/guilds/fighter/warrior.c",
		"veterans" : "/guilds/fighter/veterans.c",
		"body builders" : "/guilds/fighter/body_builders.c",
		"acrobats" : "/guilds/fighter/acrobats.c",
		"smith" : "/guilds/fighter/smith.c",
		"axers" : "/guilds/fighter/axes.c",
		"defenders" : "/guilds/fighter/defender.c",
		"berserkers" : "/guilds/fighter/berserker.c",
		"rangers" : "/guilds/fighter/ranger.c",
		
		"apprentice clerics":"/guilds/channel/appr_cleric.c",
		"adept clerics":"/guilds/channel/adept_cleric.c",
		"high clerics":"/guilds/channel/high_cleric.c",
		
		"abjurers" : "/guilds/abjurer/abjurers.c",
		"masters of sorcery": "/guilds/abjurer/masters_of_sorcery.c",
		"masters of abjuration": "/guilds/abjurer/masters_of_abjuration.c",
		"masters of vulnerability": "/guilds/abjurer/masters_of_vulnerability.c",
		
		"psionicists": "/guilds/psi/psiguild.c",
		"emphatics":"/guilds/psi/caster_psionicists.c",
		"telekinetics": "/guilds/psi/fighter_psionicists.c",
		
		"martial artist": "/guilds/artists/base_guild.c",
		"mind focusers": "/guilds/artists/mind_focusers.c",
		"body focusers": "/guilds/artists/body_focusers.c",
		"path of masters": "/guilds/artists/path_of_masters",
		
		"merchants": "/guilds/mage/merchant.c",
		"navigators": "/guilds/mage/navigators.c",
		"fire school": "/guilds/mage/fire_adept.c",
		"scroll scribblers" : "/guilds/mage/scroll_scribblers.c",
		"illusionists" : "/guilds/mage/illusionists.c",
		"advanced mages" : "/guilds/mage/adv_mages.c",
		"ice school" : "/guilds/mage/ice_adept.c",
		"master mages" : "/guilds/mage/master_mage.c",
		"apprentice mages" : "/guilds/mage/apprmage.c",
		"poison school" : "/guilds/mage/poison_adept.c",
		"arcaners" : "/guilds/mage/arcaners.c",
		"electricity school" : "/guilds/mage/electric_adept.c",
		
		"school of dark power" : "/guilds/necro/dark_power.c",
		"necromancers" : "/guilds/necro/base_guild.c",
		"master animators" : "/guilds/necro/animators.c",
		"apprentice controllers" : "/guilds/necro/control1.c",
		"adept controllers" : "/guilds/necro/control2.c",
		"unholy lords" : "/guilds/necro/unholy_lords.c",
		"necromancer adepts" : "/guilds/necro/necro.c",
		
		"warlocks" : "/guilds/warlock/warlock.c",
		"initiate of chaos" : "/guilds/warlock/warlock2.c",
		"master warlocks" : "/guilds/warlock/warlock3.c",
		"chaos fighters" : "/guilds/warlock/warlock4.c",
		"grand warlocks" : "/guilds/warlock/warlock5.c",
		"chaos masters" : "/guilds/warlock/warlock6.c"
					
		  ]);

  
  if(this_player()->query_guest()) { return call_other("/cmds/std/_help", "cmd_help", "guilds"); }
  if(str && this_player()->query_wiz()) ob = find_player(str);
  if(!ob) ob = this_player();

  guilds = ob->query_guild_level();
  lvl = m_indices(guilds);
  lvl = ALPHA->alpha(guilds);

  write("You are currently in the following guilds:\n");
  
  
  for(i=0; i < sizeof(lvl); i++) {
   
o_str = 0;
o_dex = 0;
o_con = 0;
o_wis = 0;
o_int = 0;
   
    name = capitalize(lvl[i]);
    level = "(L:"+guilds[lvl[i]]+")";

for(c = 0; c < guilds[lvl[i]]; c++) {
	
    name = lower_case(name);
    if(guildsit[name]->get_bonuses(guilds[c])) stats = guildsit[name]->get_bonuses(guilds[c]);
    else break;    


    
    name = capitalize(name);
    stats = explode(stats, ",");   // THIS
    stats_b = implode(stats, " "); //  IS
    stats = explode(stats_b, " "); // NICE
    stats_c = allocate(sizeof(stats));
   
   
 for(y=0;y < sizeof(stats); y++) {
 	if(stats[y] != "")stats_c[y] = stats[y];
 	
}

for(y = 0;y <sizeof(stats_c); y++) {
	if(stats_c[y] == 0) stats_c -= ({0});
	
}
  
stats = stats_c;

y = 0; //  Just
j = 0; //   to
b = 0; // be sure



for(y = 0; y < sizeof(stats); y++) {
	
	j = y;
	j += 1;
	
	b_str = 0;
	b_dex = 0;
	b_con = 0;
	b_wis = 0;
	b_int = 0;
	
	switch(stats[y]) {
		
		case "str" : b_str = stats[j]; break;
		case "dex" : b_dex = stats[j]; break;
		case "con" : b_con = stats[j]; break;
  		case "int" : b_int = stats[j]; break;
  		case "wis" : b_wis = stats[j]; break;
  		default: break;
  	}
  	y = j;
  
  b_str = to_int(b_str);
  b_dex = to_int(b_dex);
  b_con = to_int(b_con);
  b_wis = to_int(b_wis);
  b_int = to_int(b_int);
  	
  	o_str = o_str + b_str;
  	o_dex = o_dex + b_dex;
  	o_con = o_con + b_con;
  	o_wis = o_wis + b_wis;
  	o_int = o_int + b_int;
  	
  	  	
  	
  }
  
 }
  
  printf(" %22-s %8-s Stats: STR %3-d DEX %3-d CON %3-d WIS %3-d INT %3-d \n",name,level,o_str,o_dex,o_con,o_wis,o_int);
	ov_str = ov_str + o_str;
  	ov_dex = ov_dex + o_dex;
  	ov_con = ov_con + o_con;
  	ov_wis = ov_wis + o_wis;
  	ov_int = ov_int + o_int;
 /*   
 for( y = 0; y < sizeof(stats) ; y++) {
         b = y;
         b += 1;

 	b_str = stats[b];
 	
 	write("Bnarit: "+ stats[y] + " " +b_str+ "\n");

 	 y = b;
}
  */
  
    //stats = "   Bonuses: (" +guildsit[name]->get_bonuses(guilds[lvl[i]]) +") ";
    //write(name + level + stats +"\n");
    
    
}
 printf("\n %38-s STR %3-d DEX %3-d CON %3-d WIS %3-d INT %3-d \n","Overall bonuses:",ov_str,ov_dex,ov_con,ov_wis,ov_int);

  return 1;
}

