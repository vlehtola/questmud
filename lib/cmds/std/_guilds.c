#define ALPHA "/daemons/alpha"
#define GUILD_INIT "/guilds/guilds/guild_init"

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

  guildsit = GUILD_INIT->query_subguilds();
  
  if(this_player()->query_guest()) { return call_other("/cmds/std/_help", "cmd_help", "guilds"); }
  if(str && this_player()->query_wiz()) ob = find_player(str);
  if(!ob) ob = this_player();

  guilds = ob->query_guild_level();
  lvl = m_indices(guilds);
  lvl = ALPHA->alpha(guilds);

  write("You are currently in the following guilds: (the stats are percentual values)\n");
  
  
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

// Modified by Celtron to prevent runtime errors if guild is not in guild_init.c

    if(guildsit[name]) {
        stats = guildsit[name]->get_bonuses(guilds[c]);
    } else {
        // notify the user that this guild might be missing from the database
        name = capitalize(name);
        name = name + "(no stats)";
        break;    
    }

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

//Added the below lines to include the +1% allstats bonuses from levels. ++Celtron

  y = ob->query_level();
  if(y > 100) y = 100;

//Rebirth bonus -- Rag
  if ( ob->query_rebirth() > 2 && ob->query_level() > 150 ) y = y + ob->query_level() - 150;

  ov_str = ov_str + y;
  ov_dex = ov_dex + y;
  ov_con = ov_con + y;
  ov_wis = ov_wis + y;
  ov_int = ov_int + y;

// end of add

 printf(" %38-s STR %3-d DEX %3-d CON %3-d WIS %3-d INT %3-d \n"," (+1%allstats/lvl) bonus included:",ov_str,ov_dex,ov_con,ov_wis,ov_int);

  return 1;
}

