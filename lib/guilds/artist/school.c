inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  object plaque;
  if(arg) return;
  if (!present("plaque")) {
    plaque = clone_object("guilds/guilds/plaque.c");
    move_object(plaque, this_object());
  }
  move_object(clone_object("/guilds/artist/suin"),this_object());
  add_exit("out","/guilds/artist/entrance");
  short_desc = "The School of Martial Arts";
  long_desc = short_desc+"\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}

guild_long_name() {
    return guild_name();
}
guild_name() {
    return "Artists";
}

check_joining_rec() {
  if(this_player()->query_level() > 0) {
    write("Only ones with a clear mind are accepted.\n");
    return 0;
  }
  write("Suin welcomes to the school of martial arts.\n");
  write("Suin gives a robe to you and says 'Wear this robe proudly.'\n");
//>  move_object(clone_object("/obj/robe"),this_player());
  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([4:"fast punch:20;kneekick:20;"]);
  sk += ([10:"sly hands:60;"]);
  sk += ([13:"massage:50;"]);
  sk += ([20:"spinkick:50;"]);
  return sk;
}

/*
  Stats:  
    30% Str
    40% Dex
    30% Con
    Hpregen: 5
*/

get_bonuses(level) {
  if(level >= 20) return;
  if(level >= 15) {
    return "str 3 , dex 2 , con 3 , epregen 1 , ";
  }
  return "str 1 , dex 2 , con 2 , hpregen 1 , ";
}

/*
  sly hands + sticky hands: 100
  massage: 100
  fast punch: 100
  power fist: 40
  kneekick: 100
  turnkick: 40
  spinkick: 100
*/
get_skill_max(num, how, lvl) {
    mapping skill;
    int skill_max, skill_num, i, guild_level;
    guild_level = this_player()->query_guild_level(guild_name());
    skill = ([ ]);

    if (lvl) {
         guild_level = lvl;
         if (guild_level > 20) { guild_level = 20; }
    }
    if (guild_level >= 1) {
      skill += (["fast punch":(int) 20]);
      skill += (["sly hands":(int) 20]);
      skill += (["attack":(int) 20]);
      skill += (["bare hands":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["fast punch":(int) 40]);
      skill += (["sly hands":(int) 20]);
      skill += (["kneekick":(int) 20]);
    }
    if (guild_level >= 3) {
      skill += (["sly hands":(int) 40]);
    }
    if (guild_level >= 4) {
      skill += (["massage":(int) 20]);
    }
    if (guild_level >= 5) {
      skill += (["fast punch":(int) 60]);
      skill += (["attack":(int) 40]);
      skill += (["bare hands":(int) 40]);
    }
    if (guild_level >= 6) {
      skill += (["kneekick":(int) 40]);
      skill += (["spinkick":(int) 30]);
    }
    if (guild_level >= 7) {
      skill += (["sly hands":(int) 60]);
      skill += (["sticky hands":(int) 20]);
    }
    if (guild_level >= 8) {
      skill += (["massage":(int) 40]);
      skill += (["mental balance":(int) 40]);
      skill += (["attack":(int) 60]);
      skill += (["bare hands":(int) 60]);
    }
    if (guild_level >= 8) {
      skill += (["sly hands":(int) 80]);
    }
    if (guild_level >= 9) {
      skill += (["fast punch":(int) 80]);
    }
    if (guild_level >= 10) {
      skill += (["kneekick":(int) 60]);
      skill += (["spinkick":(int) 50]);
    }
    if (guild_level >= 11) {
      skill += (["massage":(int) 60]);
    }
    if (guild_level >= 12) {
      skill += (["sticky hands":(int) 40]);
    }
    if (guild_level >= 13) {
      skill += (["kneekick":(int) 80]);
      skill += (["hit combing":(int) 20]);
    }
    if (guild_level >= 14) {
      skill += (["massage":(int) 80]);
      skill += (["mental balance":(int) 70]);
    }
    if (guild_level >= 15) {
      skill += (["sly hands":(int) 100]);
      skill += (["sticky hands":(int) 60]);
      skill += (["attack":(int) 80]);
      skill += (["bare hands":(int) 80]);
    }
    if (guild_level >= 16) {
      skill += (["turnkick":(int) 20]);
      skill += (["spinkick":(int) 70]);
    }
    if (guild_level >= 17) {
      skill += (["power fist":(int) 20]);
    }
    if (guild_level >= 18) {
      skill += (["sticky hands":(int) 80]);
    }
    if (guild_level >= 20) {
      skill += (["knowledge of kata":(int) 100]);
      skill += (["sticky hands":(int) 100]);
      skill += (["turnkick":(int) 40]);
      skill += (["spinkick":(int) 100]);
      skill += (["power fist":(int) 40]);    
      skill += (["massage":(int) 100]);
      skill += (["kneekick":(int) 100]);
      skill += (["fast punch":(int) 100]);
      skill += (["mental balance":(int) 100]);
      skill += (["hit combing":(int) 40]);
      skill += (["attack":(int) 100]);
      skill += (["knowledge of the way":(int) 20]);
      skill += (["bare hands":(int) 100]);
    }
    skill_num = m_indices(skill);
    skill_max = m_values(skill);
    if (how == 0) {
        while (i < sizeof(skill_max)) {
            if (skill_num[i] == num) {
                return skill_max[i];
            }
            i += 1;
        }  
    }
    if (how == 1) {
        return skill_max[num];
    }
    if (how == 2 || how == 3) {
        return skill_num[num];
    }
    if (how == 4) {
        return skill_max;
    }
}

